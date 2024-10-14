#include <string>
#include <iostream>
#include "CAddress.h"
#include "CCrewMember.h"
#include "FlightCompException.h"

using namespace std;

CCrewMember::CCrewMember(string name,int airTimeMinutes) noexcept(false) :name(name)
{
	if (airTimeMinutes < 0)
	{
		throw CCompStringException("Air time cant be initlizied with a number lees than 0.\n");
	}
	else
		this->airTimeMinutes = airTimeMinutes;
}

CCrewMember::CCrewMember(ifstream& in)
{
	in >> *this;
}

CCrewMember::~CCrewMember() {}

CCrewMember::CCrewMember(const CCrewMember& other): name(other.name), 
airTimeMinutes(other.airTimeMinutes)
{


}


string CCrewMember::getName()const { return name;}



int CCrewMember::getAirTimeMinutes()const
{
	return airTimeMinutes;
}




void CCrewMember::setName(string name)
{
	this->name = name;
}



bool CCrewMember::IsEqual(CCrewMember& other)const
{
	return this->name == other.name;
}

const CCrewMember& CCrewMember::operator=(const CCrewMember& other)
{
	if (this != &other)
	{
		name = other.name;
		airTimeMinutes = other.airTimeMinutes;
	}

	return *this;

}

bool CCrewMember::operator==(const CCrewMember& p)const
{
	return this->name == p.name;
}



ostream& operator<<(ostream& os, const CCrewMember& p)
{
	if (typeid(os) == typeid(ofstream))
	{
		os << p.name <<" "<< p.airTimeMinutes;
	}
	else
		os << "Crewmember " << p.name << " minutes " << p.airTimeMinutes << endl;
	p.toOs(os);
	return os;
}

istream& operator>>(istream& in,CCrewMember& p)
{
	in>>p.name;
	in >> p.airTimeMinutes;
	p.fromOs(in);
	return in;
}

const CCrewMember* CCrewMember::operator+=(int minutes)
{
	if (minutes < 0)
		throw CCompStringException("can add amount of minutes that is positive\n");

	this->airTimeMinutes += minutes;
	return this;
}






















