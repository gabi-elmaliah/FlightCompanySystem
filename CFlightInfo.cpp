#include "CFlightInfo.h"
#include <string.h>
#include <iostream>
#include "FlightCompException.h"

using namespace std;

CFlightInfo::CFlightInfo(const  string& destination, int flightNumber, int flightTimeMinutes, int flightDistance) noexcept(false) 
{
	SetDest(destination);
	setFlightNumber(flightNumber);
	setFlightTimeMinutes(flightTimeMinutes);
	setFlightDistance(flightDistance);
}

CFlightInfo::CFlightInfo(ifstream& in)
{
	in >> destination>>flightNumber>>flightTimeMinutes>>flightDistance;
	
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

void CFlightInfo::setFlightNumber(int flightNumber) noexcept(false)
{
	if (flightNumber < 0)
		throw CCompStringException("error in flight info : negative flight number\n");
	else
		this->flightNumber = flightNumber;
	
	
}
void CFlightInfo::SetDest(string destination) noexcept(false)
{

	if (destination.length() >10)
		throw CCompStringException("error in the destination:to much characters in destination\n");
	else
		this->destination = destination;


}
void CFlightInfo::setFlightTimeMinutes(int minutes) noexcept(false)
{
	if (minutes < 0)
		throw CCompStringException("error in flight info: minutes cant be negative");
	else
		this->flightTimeMinutes =minutes;

}
void CFlightInfo::setFlightDistance(int distance)
{
	if (distance < 0)
		throw CCompStringException("error in flight info: negative distance");
	else
		this->flightDistance =distance;

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
	if (typeid(os) == typeid(ofstream))
	{
		os << p.destination << " " << p.flightNumber << " " << p.flightTimeMinutes << " " << p.flightDistance;
	}
	else
	{
		os << "Flight Fligh Info dest: " << p.destination
			<< " Number: " << p.flightNumber <<
			" minutes " << p.flightTimeMinutes
			<< " KM " << p.flightDistance << endl;
	}

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
