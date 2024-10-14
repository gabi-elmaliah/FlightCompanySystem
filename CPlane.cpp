#include <iostream>
#include <string>
#include "CPlane.h"
#include "FlightCompException.h"
using namespace std;

int CPlane::counter = 100;

CPlane::CPlane(int numOfSeats, const string& name) noexcept(false) :name(name), serial_number(counter++) 
{
	if (numOfSeats <= 0)
		throw CCompStringException("error in CPlane: number of seats must be positive");
	else
		this->numOfSeats = numOfSeats;

}



CPlane::CPlane(const CPlane& other)
{
	*this = other;
}

CPlane::CPlane(ifstream &in)
{
	int lastId;
	in >> lastId>>serial_number>>name>>numOfSeats;
	
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
	if (typeid(os) == typeid(ofstream))
	{
		p.toOs(os);
	}
	else
		os << "Plane " << p.serial_number << " degem " << p.name << " seats " << p.numOfSeats << endl;
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






