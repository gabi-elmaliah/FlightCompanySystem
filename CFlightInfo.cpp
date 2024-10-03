#include "CFlightInfo.h"
#include <string.h>
#include <iostream>

using namespace std;

CFlightInfo::CFlightInfo(const  string& destination, int flightNumber, int flightTimeMinutes, int flightDistance):destination(destination)
{

	if (flightNumber < 0)
		this->flightNumber = 0;
	else
		this->flightNumber = flightNumber;

	if (flightDistance < 0)
		this->flightDistance = 0;
	else
		this->flightDistance = flightDistance;

	if (flightTimeMinutes < 0)
		this->flightTimeMinutes = 0;
	else
		this->flightTimeMinutes = flightTimeMinutes;
	
}
CFlightInfo::~CFlightInfo()
{
	
}

CFlightInfo::CFlightInfo(const CFlightInfo & other)
{
	*this = other;

}

int CFlightInfo::GetFNum()const
{
	return flightNumber;
}
string CFlightInfo::getDestination()const
{
	return destination;

}
int CFlightInfo::getflightTimeMinutes()const
{
	return flightTimeMinutes;

}
int CFlightInfo::getFlightDistance() const
{
	return flightDistance;

}

void CFlightInfo::setFlightNumber(int flightNumber)
{
	this->flightNumber = flightNumber;

}
void CFlightInfo::SetDest(string destination)
{

	this->destination = destination;
	
}
void CFlightInfo::setFlightTimeMinutes(int minutes)
{
	this->flightTimeMinutes = minutes;

}
void CFlightInfo::setFlightDistance(int distance)
{
	this->flightDistance = distance;
}

bool CFlightInfo::isEqual(const CFlightInfo& other) const
{
	return this->flightNumber == other.flightNumber;
}

void CFlightInfo::Print() const
{
	cout << "Flight Fligh Info dest: " <<destination 
		<< " Number: " << flightNumber << 
		" minutes " << flightTimeMinutes 
		<<" KM "<<flightDistance << endl;
}


ostream& operator<<(ostream& os, const CFlightInfo& p)
{
	os << "Flight Fligh Info dest: " << p.destination
		<< " Number: " << p.flightNumber <<
		" minutes " << p.flightTimeMinutes
		<< " KM " << p.flightDistance << endl;

	return os;

}

bool CFlightInfo::operator==(const CFlightInfo& p) const
{
	return this->flightNumber == p.flightNumber;
}

bool CFlightInfo::operator!=(const CFlightInfo& p) const
{
	return !(*this == p);
}

const CFlightInfo& CFlightInfo::operator=(const CFlightInfo& other)
{
	if (this != &other)
	{
		this->flightNumber = other.flightNumber;
		this->destination = other.destination;
		this->flightDistance = other.flightDistance;
		this->flightTimeMinutes = other.flightTimeMinutes;
	}

	return *this;
}
