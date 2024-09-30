#include "CFlight.h"
#include "CCrewMember.h"
#include <string>
using namespace std;



CFlight::CFlight(const CFlightInfo& flightInfo,const CPlane* plane):flightInfo(flightInfo)
{
	if (plane == nullptr)
		this->plane = nullptr;
	else
		this->plane = new CPlane(*plane);

	for (int i = 0; i < MAX_CREW; ++i) 
		crewMembers[i] = nullptr; 

	numOfCrewMembers = 0;
	
}

CFlight::CFlight(const CFlight &other):flightInfo(other.flightInfo)
{
	*this = other;
}
CFlight::~CFlight()
{
	delete plane;
	plane = nullptr;

	for (int i = 0; i < numOfCrewMembers; i++)
	{
		delete crewMembers[i];
		crewMembers[i] = nullptr;
	}
	
}

ostream& operator<<(ostream& os, const CFlight& p)
{
	os << p.flightInfo;
	if (p.plane == nullptr)
		os << "No plane assign yet"<<endl;
	else
		os << *p.plane;
	os << "There are " << p.numOfCrewMembers << " Crew members in flight" << endl;
	for (int i = 0; i < p.numOfCrewMembers; i++)
	{
		os << *p.crewMembers[i];
	}
		
	return os;
}

const CFlight& CFlight::operator=(const CFlight& other)
{
	if (this!= &other)
	{
		this->flightInfo = other.flightInfo;
		delete[]this->plane;
		this->plane = nullptr;
		if (other.plane != nullptr) 
		{
			this->plane =new CPlane(*other.plane);
		}
		else {
			this->plane = nullptr;
		}

		for (int i = 0; i < numOfCrewMembers; i++)
		{
			delete[] crewMembers[i];
			crewMembers[i] = nullptr;
		}

		numOfCrewMembers=other.numOfCrewMembers;
		for (int i = 0; i < numOfCrewMembers; i++)
		{
			crewMembers[i] = new CCrewMember(*other.crewMembers[i]);
		}
	}

	return *this;
}



void CFlight::SetPlane(const CPlane* plane)
{
	
	if (this->plane != plane && &plane!= nullptr)
	{
		if (this->plane != nullptr)
		{
			delete[] this->plane;
			this->plane = nullptr;

		}
		this->plane = new CPlane(*plane);
	}
}

bool CFlight::operator==(const CFlight& p) const
{
	return this->flightInfo == p.flightInfo;
}


CFlight* CFlight::operator+(const CCrewMember& other)
{
	if (this->numOfCrewMembers == CFlight::MAX_CREW)
		return nullptr ;

	// check if crew member already in the flight
	for (int i = 0; i < numOfCrewMembers; i++)
	{
		if (*this->crewMembers[i] == other)
			return nullptr;
	}
	
	this->crewMembers[numOfCrewMembers] = new CCrewMember(other);
	numOfCrewMembers++;

	return this;
	


}


int CFlight::getNumOfCrewMembers() const
{
	return this->numOfCrewMembers;
}


const CFlightInfo& CFlight::getFlightInfo() const
{
	return this->flightInfo ;
}

const CPlane& CFlight::getFlightPlane() const
{
	return *this->plane;
}

int CFlight::getFlightNumber()const
{
	return flightInfo.GetFNum();

}


