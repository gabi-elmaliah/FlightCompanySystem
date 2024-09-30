#include <string>
#include <iostream>
#include "CAddress.h"
#include "CCrewMember.h"

using namespace std;

CCrewMember::CCrewMember(string name,int airTimeMinutes, const  CAddress& address):name(name)
{
	if (airTimeMinutes < 0)
		this->airTimeMinutes = 0;
	else
		this->airTimeMinutes = airTimeMinutes;
}

CCrewMember::~CCrewMember() {}

CCrewMember::CCrewMember(const CCrewMember& other): name(other.name), address(other.address), 
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

const CAddress& CCrewMember::getAddress() const 
{ 
	return address;
}

int CCrewMember::getAirTimeMinutes()const
{
	return airTimeMinutes;
}




void CCrewMember::setName(string name)
{
	this->name = name;
}
void CCrewMember::setAddress(const CAddress &address)
{
	this->address.UpdateAddress(address.getcityName(), address.getStreetName(), address.getHouseNumber());
}

void CCrewMember::Print()const
{
	cout << "Crewmember " << name << " minutes " << airTimeMinutes << endl;
}

bool CCrewMember::IsEqual(CCrewMember& other)const
{
	return this->name == other.name;
}

const CCrewMember& CCrewMember::operator=(const CCrewMember& other)
{
	if (this != &other)
	{
		id = other.id;
		name = other.name;
		airTimeMinutes = other.airTimeMinutes;
		address = other.address;
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

void CCrewMember::recieveGift() const
{
	cout<<name  <<"thanking the company for receiving the holiday gift. I wasnt expecting it"<<endl;
}



















