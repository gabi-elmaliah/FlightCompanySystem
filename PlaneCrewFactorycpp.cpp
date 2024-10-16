#include "PlaneCrewFactory.h"
#include "CCargo.h"
#include "CHost.h"
#include "CPilot.h"
#include "FlightCompException.h"
#include "CFlightCompany.h"
#include "CFlight.h"

PlaneType CPlaneCrewFactory::GetPlaneType(const CPlane* pPlane)
{
	if (typeid(*pPlane) == typeid(CCargo))
		return eCargo;
	return eRegular;
	
}

CrewType CPlaneCrewFactory::GetCrewType(const CCrewMember* pCrew)
{
	if (typeid(*pCrew) == typeid(CHost))
		return eHost;
	return ePilot;
}

void CPlaneCrewFactory::GetCompanyDataFromUser(CFlightCompany& comp)
{
	bool isValidData = false;
	int option;
	while (true)
	{
		cout << "You have 2 options (please enter the option number): " << endl;
		cout << "1. Add plane to company " << endl;
		cout << "2. Add CrewMember to company " << endl;
		cout << "3. Add  plane to flight" << endl;
		cout << "4. Add  crew member to flight" << endl;
		cout << "5. Add a Flight To Company " << endl;
		cout << "6. See company details " << endl;
		cout << "7. Exit" << endl; // Optional exit option
		cin >> option;
		
		try
		{
			switch (option)
			{
			case 1:
			{
				CPlane* plane = GetPlaneFromUser();
				comp.AddPlane(*plane);
				delete plane;
				break;
			}
			case 2:
			{
				CCrewMember* crewMember = GetCrewFromUser();
				comp.AddCrewMember(*crewMember);
				delete crewMember;
				break;
			}
			case 3:
			{
				AddPlaneToFlight(comp);
				break;
			}
			case 4:
			{
				AddCrewMemberToFlight(comp);
				break;
			}
			case 5:
			{
				CFlight* flight = GetFlightFromUser();
				comp.AddFlight(*flight);
				break;
			}
			case 6:
			{
				std::cout << comp;
				break;
			}
			case 7:
				return; // Exit the function

			default:
				cout << "Invalid option!" << endl;
				break;
			}
		}
		catch (CFlightCompException& ex)
		{
			ex.Show();
		}
	}
		
	
}



CPlane* CPlaneCrewFactory::GetPlaneFromUser()
{
	int planeType;
	string degem;
	int numOfSeats;

	cout << "What is the type of the plane you want do add:(select the number of the option) " <<endl;
	cout << "1.Regular Plane " << endl;
	cout << "2.Cargo Plane " << endl;
	cin >> planeType;

	if (planeType < 1 || planeType > nofPlaneType)
		throw WrongOptionException(planeType);

	

	cout << "Enter the the name of the plane ";
	cin >> degem;

	cout << "Enter the number of seats in the plane ";
	cin >> numOfSeats;
	
	if (planeType - 1 == eRegular)
	{
		return new CPlane(numOfSeats, degem);
	}
	else
	{
		float maxWeight, maxVolume;
		cout << "Enter max weight: ";
		cin >> maxWeight;
		cout << "Enter max volume: ";
		cin >> maxVolume;
		return new CCargo(numOfSeats, degem, maxWeight, maxVolume);
	}
}

CCrewMember* CPlaneCrewFactory::GetCrewFromUser()
{
	int crewType;
	cout << "Enter crew member type (0 for Host, 1 for Pilot): ";
	cin >> crewType;

	// Check for valid input and handle invalid choices
	if (crewType < 0 || crewType >= nofCrewType) {
		throw WrongOptionException(crewType);
	}

	// Collect common data
	string name;
	cout << "Enter the crew member's name: ";
	cin >> name;

	int airTimeMinutes;
	cout << "Enter the air time in minutes: ";
	cin >> airTimeMinutes;

	if (crewType == eHost) {
		// Get additional information for Host
		int hostType;
		cout << "Enter host type (0 for Regular, 1 for Super, 2 for Calcelan): ";
		cin >> hostType;

		// Validate the host type
		if (hostType < 0 || hostType >= 3) {
			throw WrongOptionException(hostType);
		}

		return new CHost(name, static_cast<CHost::eType>(hostType), airTimeMinutes);
	}
	else if (crewType == ePilot) {
		// Get additional information for Pilot
		int isCaptain;
		cout << "Is the pilot a captain? (0 for No, 1 for Yes): ";
		cin >> isCaptain;
		// Validate the host type
		if (isCaptain < 0 || isCaptain >1) {
			throw WrongOptionException(isCaptain);
		}

		// Handle the address (optional)
		char hasAddress;
		cout << "Does the pilot have an address? (y/n): ";
		cin >> hasAddress;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (hasAddress != 'y' && hasAddress != 'Y' && hasAddress != 'n' && hasAddress != 'N')
			throw CCompStringException("Invalid input. Please enter 'y' or 'n'.");

		CAddress* address = nullptr;
		if (hasAddress == 'y' || hasAddress == 'Y') {
			int houseNumber;
			string streetName, cityName;
			cout << "Enter house number: ";
			cin >> houseNumber;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Enter street name: ";
			getline(cin, streetName);
			cout << "Enter city name: ";
			getline(cin, cityName);
			address = new CAddress(houseNumber, streetName.c_str(), cityName.c_str());
		}

		return new CPilot(name, static_cast<bool>(isCaptain), address, airTimeMinutes);
	}

	return nullptr;  // This line should not be reached, provided the input validation works
}

CCrewMember* CPlaneCrewFactory::GetCrewMemberFromFile(ifstream& inFile)
{
	int type;
	inFile >> type;
	if (type == 0)//if host 
	{
		return new CHost(inFile);
	}
	else // pilot
	{
		return new CPilot(inFile);
	}
	
}

CPlane* CPlaneCrewFactory::GetPlaneFromFile(ifstream& inFile) 
{
	int type;
	inFile >> type;
	if (type == 0) //if regular plane 
	{
		return new CPlane(inFile, false);
	}
	else // cargo
	{
		return new CCargo(inFile);
	}


}

CFlight* CPlaneCrewFactory::GetFlightFromUser()// not neccecary 
{
	string destination;
	int flightNumber;
	int flightTimeMinutes;
	int flightDistance;

	cout << "Enter flight destination: ";
	cin >> destination;

	cout << "Enter flight number: ";
	cin >> flightNumber;

	cout << "Enter flight time in minutes: ";
	cin >> flightTimeMinutes;

	cout << "Enter flight distance: ";
	cin >> flightDistance;

	// Create the CFlightInfo object
	CFlightInfo flightInfo(destination, flightNumber, flightTimeMinutes, flightDistance);

	return new CFlight(flightInfo, nullptr);// 

	
}
void CPlaneCrewFactory::AddCrewMemberToFlight(CFlightCompany& comp) noexcept(false)
{

	cout << "These are the flight in the company: " << endl;
	comp.ShowAllFlights();

	// Step 2: Ask user to select a flight by its flight number
	int flightNumber;
	cout << "Enter the flight number to add crew members: ";
	cin >> flightNumber;

	CFlight* flight = comp.GetFlightByNum(flightNumber);  // Fetch the flight
	if (flight == nullptr) {
		throw CCompStringException("no flight with this number");
	}

	// Step 3: Show all crew members
	cout << "These are the all the crew member in the company: " << endl;
	comp.ShowAllCrewMembers();

	int crewMemberIndex;
	cout << "Enter the crew member number to add:(1,2,3...) ";
	cin >> crewMemberIndex;
	CCrewMember* crewMember = comp.GetCrewMember(crewMemberIndex -1);  // Fetch the crew member(index start from 0)
	comp.AddCrewToFlight(flightNumber, crewMemberIndex-1);
		

}

void CPlaneCrewFactory::AddPlaneToFlight(CFlightCompany& comp)
{


	cout << "These are the flights in the company: " << endl;
	comp.ShowAllFlights();

	
	int flightNumber;
	cout << "Enter the flight number to assign a plane: ";
	cin >> flightNumber;

	// Fetch the flight
	CFlight* flight = comp.GetFlightByNum(flightNumber);
	if (flight == nullptr) {
		throw CCompStringException("No flight with this number");
	}
	
	if (&flight->getFlightPlane()!=nullptr)
	{
		char choice;
		cout << "There is already a plane for this flight. Do you want to replace it with other plane? (y / n) ";
		cin >> choice;
		if (choice != 'y' && choice != 'Y')
		{
			return;
		}
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}


	// Show all planes
	cout << "These are the planes available in the company: " << endl;
	comp.ShowAllPlanes();

	// Step 4: Ask the user to select a plane
	int planeIndex;
	cout << "Enter the plane number to assign to the flight: (1, 2, 3...) ";
	cin >> planeIndex;
	CPlane plane = comp[planeIndex-1];
	// Step 5: Assign the selected plane to the flight
	flight->SetPlane(&plane);
	cout << "Plane successfully assigned to flight!" << endl;


}
CFlight* CPlaneCrewFactory::GetFlightFromFile(ifstream& inFile, CFlightCompany& comp)
{
	return new CFlight(inFile, comp);
}






