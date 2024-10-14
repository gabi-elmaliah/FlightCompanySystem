#include "PlaneCrewFactory.h"
#include "CCargo.h"
#include "CHost.h"
#include "CPilot.h"
#include "FlightCompException.h"

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
	while (!isValidData)
	{
		cout <<"You have 2 options:(please enter the option number)" << endl;
		cout << "1. Add plane to company" << endl;
		cout << "2. Add CrewMember to company" << endl;
		cin >> option;
		if (option == 1)
		{
			CPlane* plane=GetPlaneFromUser();
		}
		else
		{
			

		}
		

	}
	
}

CPlane* CPlaneCrewFactory::GetPlaneFromUser()
{
	int planeType;
	string degem;
	int numOfSeats;

	cout << "What is the type of the plane you want do add:(select the number of the option)" << endl;
	cout << "1.Regular Plane" << endl;
	cout << "2. Cargo Plane" << endl;
	cin >> planeType;

	if (planeType < 1 || planeType > nofPlaneType)
		throw WrongOptionException(planeType);

	

	cout << "\n Enter the the name of the plane"<<endl;
	cin >> degem;

	cout << "\n Enter the number of seats in the plane"<< endl;
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

		if (hasAddress != 'y' && hasAddress != 'Y' && hasAddress != 'n' && hasAddress != 'N')
			throw CCompStringException("Invalid input. Please enter 'y' or 'n'.");

		CAddress* address = nullptr;
		if (hasAddress == 'y' || hasAddress == 'Y') {
			int houseNumber;
			string streetName, cityName;
			cout << "Enter house number: ";
			cin >> houseNumber;
			cout << "Enter street name: ";
			cin >> streetName;
			cout << "Enter city name: ";
			cin >> cityName;
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
		return  new CPlane(inFile);
	}
	else // cargo
	{
		return new CCargo(inFile);
	}

}




