#include "CCargo.h"


CCargo::CCargo(int seats, string name, float maxWeight, float maxVolume) :CPlane(seats,name)
{
	if (maxWeight < 0)
	{
		this->maxWeight = 0;
	}
	else
		this->maxWeight = maxWeight;

	if (maxVolume < 0)
	{
		this->maxVolume = 0;
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

bool CCargo::Load(float weight, float volume)
{
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
	os << "Cargo M_vol " << maxVolume << "M_Kg " << maxWeight << "C_vol "<<currentVolume << "C_Kg" << currentWeight << endl;
}


void CCargo::addMinutesToLogBookMessage(int minutes) const
{
	cout << "Need to add " << minutes << " to my log book" << endl;
}



