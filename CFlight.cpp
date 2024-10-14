#include "CFlight.h"
#include "CCrewMember.h"
#include <string>
#include "FlightCompException.h"
#include "CFlightCompany.h"
using namespace std;



CFlight::CFlight(const CFlightInfo& flightInfo,const CPlane* plane):flightInfo(flightInfo)
{
	if (plane == nullptr)
		this->plane = nullptr;
	else
	{
		this->plane = plane->clone();
	}

	for (int i = 0; i < MAX_CREW; ++i) 
		crewMembers[i] = nullptr; 

	numOfCrewMembers = 0;
	
}

CFlight::CFlight(ifstream& in, CFlightCompany& flightcompany) noexcept(false):
	flightInfo(in)
{
	int hasPlane;
	in >> hasPlane;
	if (hasPlane)
	{
		int planeNumber;
		in >> planeNumber;
		plane = const_cast<CPlane*>(flightcompany.getPlaneById(planeNumber));
	}
	else
		plane = nullptr;

	
	in >> numOfCrewMembers;
	if (numOfCrewMembers > MAX_CREW )
		throw CCompLimitException(MAX_CREW);
	
	for (int i = 0; i < numOfCrewMembers; i++)
	{
		int type;
		in>> type;
		if (type == 0)//if host 
		{
			crewMembers[i] = new CHost(in);
		}
		else // pilot
		{
			crewMembers[i] = new CPilot(in);
		}
	}

	
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
	if (typeid(os) == typeid(ofstream))
	{
		int hasPlane = (p.plane != nullptr) ? 1 : 0;
		os << p.flightInfo << " " << hasPlane << endl << p.numOfCrewMembers<<endl;
		for (int i = 0; i < p.numOfCrewMembers; i++)
		{
			os << *p.crewMembers[i];
		}
	}	
	else
	{
		os << p.flightInfo;
		if (p.plane == nullptr)
			os << "No plane assign yet" << endl;
		else
			os << *p.plane;
		os << "There are " << p.numOfCrewMembers << " Crew members in flight" << endl;
		for (int i = 0; i < p.numOfCrewMembers; i++)
		{
			//os << *p.crewMembers[i];
			p.crewMembers[i]->Print(cout);
		}

	}
	return os;
}

const CFlight& CFlight::operator=(const CFlight& other)
{
	if (this!= &other)
	{
		this->flightInfo = other.flightInfo;
		delete this->plane;
		this->plane = nullptr;
		if (other.plane != nullptr) 
		{
			this->plane = other.plane->clone();
		}
		else {
			this->plane = nullptr;
		}

		for (int i = 0; i < numOfCrewMembers; i++)
		{
			delete crewMembers[i];
			crewMembers[i] = nullptr;
		}

		numOfCrewMembers=other.numOfCrewMembers;
		for (int i = 0; i < numOfCrewMembers; i++)
		{
			crewMembers[i] = other.crewMembers[i]->clone();
		}
	}

	return *this;
}



void CFlight::SetPlane(const CPlane* plane)
{
	
	if (this->plane != plane)
	{
		if (this->plane != nullptr)// delete only if this->plane != nullptr
		{
			delete[] this->plane;
			this->plane = nullptr;

		}
		//this->plane = new CPlane(*plane);
		this->plane = plane->clone();
	}
}

bool CFlight::operator==(const CFlight& p) const
{
	return this->flightInfo == p.flightInfo;
}


CFlight* CFlight::operator+(const CCrewMember* other)
{
	if (this->numOfCrewMembers == CFlight::MAX_CREW)
		return nullptr ;

	// check if crew member already in the flight
	for (int i = 0; i < numOfCrewMembers; i++)
	{
		if (*this->crewMembers[i] == *other)
			return nullptr;
	}
	
	//this->crewMembers[numOfCrewMembers] = new CCrewMember(other);
	this->crewMembers[numOfCrewMembers] =other->clone();
	numOfCrewMembers++;
	return this;
	


}


int CFlight::getNumOfCrewMembers() const
{
	return this->numOfCrewMembers;
}


const CFlightInfo& CFlight::GetFlightInfo() const
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

bool CFlight::TakeOff() noexcept(false)
{
	if (this->plane == nullptr)
		throw CCompStringException("flight cant take off : there isnt a plane assinged yet");

	CCargo* temp = dynamic_cast<CCargo*>(this->plane);
	if (temp)//if Cargo Flight
	{
		if (countPilots() < 1)
			return false;
		temp->addMinutesToLogBookMessage(flightInfo.getflightTimeMinutes());
	}
	else // Passenger Flight
	{
		if (countPilots()!=1)
			return false;
		if (countSuperHost() > 1)
			return false;
	}
	
	for (int i = 0; i < numOfCrewMembers; i++)
	{
		*crewMembers[i] += flightInfo.getflightTimeMinutes();
	}

	return true;
}


int CFlight::countPilots()const
{
	int numOfPilots = 0;
	for (int i = 0; i < numOfCrewMembers; i++)
	{
		CPilot* temp = dynamic_cast<CPilot*>(crewMembers[i]);
		if (temp)
			numOfPilots++;
	}
	return numOfPilots;

}

int CFlight::countSuperHost()const
{
	int numOfSuperHost = 0;
	for (int i = 0; i < numOfCrewMembers; i++)
	{
		CHost* temp = dynamic_cast<CHost*>(crewMembers[i]);
		if (temp)
			if (temp->getType() == CHost::eType::eSuper)
				numOfSuperHost++;
	}
	return numOfSuperHost;
	
}

