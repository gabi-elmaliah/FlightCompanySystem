#include <iostream>
#include <string>
#include "CPlane.h"
using namespace std;

int CPlane::counter = 100;

CPlane::CPlane(int numOfSeats, const string& name):name(name),serial_number(counter++)
{
	if (numOfSeats <= 0)
		this->numOfSeats = 1;
	else
		this->numOfSeats = numOfSeats;

}



CPlane::CPlane(const CPlane& other)
{
	*this = other;
}
CPlane::~CPlane()
{
	
}

int CPlane::getSerialNumber() const
{
	return  serial_number;
}
string CPlane::getName() const
{
	return name;

}
int CPlane::getNumOfSeats()const
{
	return numOfSeats;
}

void CPlane::Print() const
{
	cout << "Plane " << serial_number <<" degem " << name << " seats " << numOfSeats << endl;
}

bool CPlane::IsEqual(const CPlane& other) const
{
	return this->serial_number == other.serial_number;
}

ostream& operator<<(ostream& os, const CPlane& p)
{
	os << "Plane " << p.serial_number << " degem " << p.name << " seats " << p.numOfSeats << endl;
	p.toOs(os);
	return os;
}

const CPlane& CPlane::operator++()//prefix ++x
{
	this->numOfSeats++;
	return *this;
}

CPlane CPlane::operator++(int) //postfix x++
{
	CPlane temp(*this);

	this->numOfSeats++;
	return temp;
}

bool CPlane::operator==(const CPlane& p) const
{
	return this->serial_number == p.serial_number;
}

const CPlane& CPlane::operator=(const CPlane& other)
{
	if (this != &other)
	{
		this->serial_number = other.serial_number;
		this->name = other.name;
		this->numOfSeats = other.numOfSeats;
	}

	return *this;
}






