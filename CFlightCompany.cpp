#include <iostream>
#include <string>
using namespace std;
#include "CFlight.h"
#include "CFlightCompany.h"
#include "FlightCompException.h"

CFlightCompany::CFlightCompany(string name) : name(name)
{
	numOfCrewMembers = 0;
	numOfFlights = 0;
	numOfPlanes = 0;

	for (int i = 0; i < CFlightCompany::MAX_CREW; i++)
	{
		crewMembers[i] = nullptr;
	}
	for (int i = 0; i < CFlightCompany::MAX_FLIGHTS; i++)
	{
		flights[i] = nullptr;
	}

	for (int i = 0; i < CFlightCompany::MAX_PLANES; i++)
	{
		planes[i] = nullptr;
	}

	
}

CFlightCompany::CFlightCompany(string Fname, int) noexcept(false)
{
	ifstream inFile(Fname, ios::trunc);
	if (!inFile)
		throw CCompFileException(Fname);

	getline(inFile, this->name);

	inFile >> numOfCrewMembers;

	if (numOfCrewMembers > MAX_CREW) {
		throw CCompLimitException(MAX_CREW);
	}

	// reading crew members from txt file
	for (int i = 0; i < numOfCrewMembers; i++)
	{
		int type;
		inFile>> type;
		if (type == 0)//if host 
		{
			crewMembers[i] = new CHost(inFile);
		}
		else // pilot
		{
			crewMembers[i] = new CPilot(inFile);
		}		
	}

	inFile >>numOfPlanes;

	if (numOfPlanes > MAX_FLIGHTS  ) {
		throw CCompLimitException(MAX_FLIGHTS);
	}

	// reading planes from txt file
	for (int i = 0; i < numOfPlanes; i++)
	{
		int type;
		inFile >> type;
		if (type == 0)//if regular plane 
		{
		//	planes[i] = new CPlane(inFile);
		}
		else // cargo
		{
			//planes[i] = new CCargo(inFile);
		}
	}

	inFile >> numOfFlights;

	// reading flights from txt file
	if (numOfFlights > MAX_FLIGHTS) {
		throw CCompLimitException(MAX_FLIGHTS);
	}

	for (int i = 0; i < numOfFlights; i++)
	{
		flights[i] = new CFlight(inFile,*this);
	}
}

CFlightCompany::CFlightCompany(CFlightCompany& other)
{
	*this = other;
}
CFlightCompany::~CFlightCompany()
{
	for (int i = 0; i <numOfCrewMembers; i++)
	{
		delete crewMembers[i];
		crewMembers[i] = nullptr;
	}


	for (int i = 0; i <numOfFlights; i++)
	{
		delete flights[i];
		flights[i]= nullptr;
	}

	for (int i = 0; i <numOfPlanes; i++)
	{
		delete planes[i];
		planes[i] = nullptr;
	}
	
}

void CFlightCompany::SaveToFile(string fileName) const
{
	ofstream outFile(fileName, ios::trunc);
	outFile << name << "\n" << numOfCrewMembers;
	//writing crew members to file 
	for (int i = 0; i < numOfCrewMembers; i++)
	{
		if (crewMembers[i] != nullptr)
		{
			CHost* temp = dynamic_cast<CHost*>(crewMembers[i]);
			if (temp)
			{
				outFile << 0 << " " << *crewMembers[i];
			}
			else
				outFile << 1 << " " << *crewMembers[i];
		}
		else
			break;
	}

	outFile << numOfPlanes << endl;
	// writing planes into text file
	for (int i = 0; i < numOfPlanes; i++)
	{
		if (planes[i] != nullptr)
		{
			CCargo* temp = dynamic_cast<CCargo*>(planes[i]);
			if (temp)
				outFile << 1 << " ";
			else
				outFile << 0 << " ";
			outFile << *planes[i];
		}
		else
			break;
	}

	outFile <<numOfFlights << endl;
	//writing flight into text file
	for (int i = 0; i < numOfFlights; i++)
	{
		outFile << *flights[i];
	}


}

string CFlightCompany::getCompanyName()const
{
	return this->name;
}
void CFlightCompany::SetName(string name)
{
	this->name = name;
}

void CFlightCompany::Print(std::ostream& os)const
{
	cout << *this<< endl;
}

ostream& operator<<(ostream& os, const CFlightCompany& p)
{
	if (p.name.empty())
		throw CCompStringException("error in printing flight company: name is empty");
	os << "Flight Company: " << p.name<<endl;
	os << "There are " << p.numOfCrewMembers <<" Crew members"<< endl;
	for (int i = 0; i <p.numOfCrewMembers; i++)
	{
		//os << *p.crewMembers[i];
		p.crewMembers[i]->Print(os);
		
	}
	os << "There are " << p.numOfPlanes << " Planes" << endl;
	for (int i = 0; i < p.numOfPlanes; i++)
	{
		os << *p.planes[i];
	}

	os << "There are " << p.numOfFlights << " Flights" << endl;
	for (int i = 0; i < p.numOfFlights; i++)
	{
		os << *p.flights[i];
	}
	return os;

}

const CFlightCompany& CFlightCompany::operator=(const CFlightCompany& p)
{
	if (this!= &p)
	{
		this->name = p.name;
		for (int i = 0; i < numOfCrewMembers; i++)
		{
			delete crewMembers[i];
			crewMembers[i] = nullptr;
		}

		for (int i = 0; i < numOfFlights; i++)
		{
			delete flights[i];
			flights[i] = nullptr;
		}

		for (int i = 0; i < numOfPlanes; i++)
		{
			delete planes[i];
			planes[i] = nullptr;
		}
		
		this->numOfCrewMembers = p.numOfCrewMembers;
		this->numOfFlights = p.numOfFlights;
		this->numOfPlanes = p.numOfPlanes;

		for (int i = 0; i < this->numOfCrewMembers; i++)
		{
		//	crewMembers[i] = new CCrewMember(*p.crewMembers[i]);
			crewMembers[i] =p.crewMembers[i]->clone();
			
		}

		for (int i = 0; i < this->numOfFlights; i++)
		{
			flights[i] = new CFlight(*p.flights[i]);
		}

		for (int i = 0; i < this->numOfPlanes; i++)
		{
			planes[i] = p.planes[i]->clone();
		}
	}

	return *this;

}

bool CFlightCompany::AddCrewMember(const CCrewMember& p)
{
	if (numOfCrewMembers == CFlightCompany::MAX_CREW)
		return false;

	//check if already exsist 
	for (int i = 0; i < numOfCrewMembers; i++)
	{
		if (*crewMembers[i] == p)
			return false;
	}

	//crewMembers[numOfCrewMembers] = new CCrewMember(p);
	crewMembers[numOfCrewMembers] = p.clone();
	numOfCrewMembers++;
	return true;

}

bool CFlightCompany::AddPlane(const CPlane& p)
{
	if (numOfPlanes == CFlightCompany::MAX_PLANES)
		return false;

	//check if already exsist 
	for (int i = 0; i < numOfPlanes; i++)
	{
		if (*planes[i] == p)
			return false;
	}

	//planes[numOfPlanes] = new CPlane(p);
	planes[numOfPlanes] = p.clone();
	numOfPlanes++;
	return true;
}

bool CFlightCompany::AddFlight(const CFlight& p)
{
	if (numOfFlights == CFlightCompany::MAX_FLIGHTS)
		return false;

	//check if already exsist 
	for (int i = 0; i < numOfFlights; i++)
	{
		if (*flights[i] == p)
			return false;
	}

	flights[numOfFlights] = new CFlight(p.GetFlightInfo(),p.plane); // CFlightCompany is a frind of CFLight
	numOfFlights++;
	return true;
}


CCrewMember* CFlightCompany::GetCrewMember(int index) const
{
	if (index<0 || index>numOfCrewMembers)
		throw CCompLimitException(numOfCrewMembers);

	return crewMembers[index];

}

CFlight* CFlightCompany::GetFlightByNum(int flightNum) const noexcept(false)
{
	if (flightNum <= 0)
		throw CCompStringException("error in finding flight: flight number must be greater than zero");
 	
	for (int i = 0; i < numOfCrewMembers; i++)
	{

		if (flights[i]->getFlightNumber() == flightNum)
			return flights[i];
	}
	return nullptr;

}


void  CFlightCompany::AddCrewToFlight(int flightNumber, int index)
{
	CFlight* flight = const_cast<CFlight*>(this->GetFlightByNum(flightNumber));
	CCrewMember* crewMember =const_cast<CCrewMember*>(this->GetCrewMember(index));
	if (flight == nullptr)
		return;
	if (crewMember == nullptr)
		return;

	flight = *flight + crewMember;
	
	
}


int  CFlightCompany::GetCargoCount()const
{
	int sum = 0;

	for (int i = 0; i < numOfPlanes; i++)
	{
		CCargo* temp = dynamic_cast<CCargo*>(planes[i]);
		if (temp)
			sum += 1;
	}

	return sum;
}


void CFlightCompany::PilotsToSimulator() const
{
	for (int i = 0; i < numOfCrewMembers; i++)
	{
		CPilot* temp = dynamic_cast<CPilot*>(crewMembers[i]);
		if (temp)
			temp->comeToSimulatorMessage();
	}
}

void CFlightCompany::CrewGetPresent()const
{
	for (int i = 0; i < numOfCrewMembers; i++)
	{
		crewMembers[i]->recieveGift();
	}

}

void CFlightCompany::CrewGetUniform()const
{
	for (int i = 0; i < numOfCrewMembers; i++)
	{
		crewMembers[i]->switchUniform();
	}
	
}

bool CFlightCompany::TakeOff(int flightNumber)
{
	
	CFlight* p =GetFlightByNum(flightNumber);
	
	if (p == nullptr)
		throw CCompStringException("error in TakeOff: there is now flight with the given number\n");

	return p->TakeOff();
}


const CPlane& CFlightCompany::operator[](int index) const   noexcept(false)
{
	if (index<0 || index>numOfPlanes)
		throw CCompLimitException(numOfPlanes);

	if (index > MAX_PLANES)
		throw CCompLimitException(MAX_PLANES);
	
	return *planes[index];
}

CPlane& CFlightCompany::operator[](int index) noexcept(false)
{
	if (index<0 || index>numOfPlanes)
		throw CCompLimitException(numOfPlanes);

	if (index>MAX_PLANES)
		throw CCompLimitException(MAX_PLANES);
	
	return *planes[index];

}

const CPlane* CFlightCompany::getPlaneById(int planeNumber) const noexcept(false)
{
	for (int i = 0; i < numOfPlanes; i++)
	{
		if (planes[i]->getSerialNumber() == planeNumber)
			return planes[i];
	}

	throw CCompStringException("Error in finding a plane with the given Id. Plane doesnt exsist");
}












