#include <string>
#include <iostream>
#include "CAddress.h"
#include "CCrewMember.h"

using namespace std;

CCrewMember::CCrewMember(string name,int airTimeMinutes):name(name)
{
	if (airTimeMinutes < 0)
		this->airTimeMinutes = 0;
	else
		this->airTimeMinutes = airTimeMinutes;
}

CCrewMember::~CCrewMember() {}

CCrewMember::CCrewMember(const CCrewMember& other): name(other.name), 
airTimeMinutes(other.airTimeMinutes)
{


}
bool CCrewMember::UpdateMinutes(int minutes)
{
	if (minutes > 0)
	{
		this->airTimeMinutes += minutes;
		return true;
	}
	return false;
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
	os << "Crewmember " << p.name << " minutes " << p.airTimeMinutes << endl;
	return os;
}

const CCrewMember* CCrewMember::operator+=(int minutes)
{
	if (minutes < 0)
		return nullptr;
	this->airTimeMinutes += minutes;
	return this;
}






















