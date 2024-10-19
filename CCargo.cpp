#include "CCargo.h"
#include "FlightCompException.h"

CCargo::CCargo(int seats, string name, float maxWeight, float maxVolume) noexcept(false) :CPlane(seats, name)
{
	if (maxWeight < 0)
	{
		counter--;//because the CPlane constructor add one do counter  so in case there is an exeption we wont create a plane 
		throw CCompStringException("error in CCargo C'tor: max weight should be greater than zero\n");
	}
	else
		this->maxWeight = maxWeight;

	if (maxVolume < 0)
	{
		counter--; //because the CPlane constructor add one do counter  so in case there is an exeption we wont create a plane 
		throw CCompStringException("error in CCargo C'tor: max volume should be greater than zero\n");
	}
	else
		this->maxVolume = maxVolume;

	currentVolume = 0;
	currentWeight = 0;
}

CCargo::CCargo(const CCargo& other) : CPlane(other)
{
	*this = other;
}

const CCargo& CCargo::operator=(const CCargo& p)
{
	if (this == &p)
		return *this;

	CPlane::operator=(p);
	this->currentVolume = p.currentVolume;
	this->currentWeight = p.currentWeight;
	this->maxVolume = p.maxVolume;
	this->maxWeight = p.maxWeight;
	return *this;
}

CCargo::CCargo(ifstream& in):CPlane(in)
{
	fromOs(in);
}

void CCargo::fromOs(istream& in)
{
	in >> maxVolume >> maxWeight >> currentVolume >> currentWeight;
}


bool CCargo::Load(float weight, float volume)
{
	if (weight <= 0 || volume <= 0)
		throw CCompStringException("error in load function: weight and voume must be poritive");

	if (currentVolume + volume > maxVolume)
		return false;
	if (currentWeight + weight > maxWeight)
		return false;
	currentVolume += volume;
	currentWeight += currentWeight;
	return true;
}


void CCargo::toOs(ostream& os) const
{
	if (typeid(os) == typeid(ofstream))
	{
		os << maxVolume << "   " << maxWeight << "  " << currentVolume << " " << currentWeight << endl;
	}
	else
	{
		os << "Cargo M_vol " << maxVolume << "M_Kg " << maxWeight << "C_vol " << currentVolume << "C_Kg" << currentWeight << endl;
	}
}


void CCargo::addMinutesToLogBookMessage(int minutes) const
{
	cout << "Need to add " << minutes << " to my log book" << endl;
}



