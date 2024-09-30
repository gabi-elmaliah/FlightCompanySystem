#include <iostream>
#include <string>
using namespace std;
#include "CFlightCompany.h"

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
	os << "Flight Company: " << p.name<<endl;
	os << "There are " << p.numOfCrewMembers <<" Crew members"<< endl;
	for (int i = 0; i <p.numOfCrewMembers; i++)
	{
		os << *p.crewMembers[i];
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
			crewMembers[i] = new CCrewMember(*p.crewMembers[i]);
		}

		for (int i = 0; i < this->numOfFlights; i++)
		{
			flights[i] = new CFlight(*p.flights[i]);
		}

		for (int i = 0; i < this->numOfPlanes; i++)
		{
			planes[i] = new CPlane(*p.planes[i]);
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

	crewMembers[numOfCrewMembers] = new CCrewMember(p);
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
	planes[numOfPlanes] = new CPlane(p);
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
	CPlane plane = p.getFlightPlane();
	flights[numOfFlights] = new CFlight(p.getFlightInfo(),&plane);
	numOfFlights++;
	return true;
}


CCrewMember* CFlightCompany::getCrewMember(int crewMemberNum) const
{
	for (int i = 0; i < numOfCrewMembers; i++)
	{

		if (crewMembers[i]->getCrewMemberId()==crewMemberNum)
			return crewMembers[i];
	}

	return nullptr;


}

CFlight* CFlightCompany::getFlight(int flightNum) const
{

	for (int i = 0; i < numOfCrewMembers; i++)
	{

		if (flights[i]->getFlightNumber() == flightNum)
			return flights[i];
	}
	
	return nullptr;

}


void  CFlightCompany::AddCrewToFlight(int flightNumber, int crewMemberId)
{
	
	CFlight* flight = this->getFlight(flightNumber);
	CCrewMember* crewMember = this->getCrewMember(crewMemberId);
	if (flight == nullptr)
		return;
	if (crewMember == nullptr)
		return;

	flight = *flight + *crewMember;
	
}

const CPlane* CFlightCompany::GetPlane(int i) const
{
	if (i < 0 || i > numOfPlanes )
		return nullptr;

	return planes[i];
}










