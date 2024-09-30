#include "CAddress.h"
#include <string>
using namespace std;



CAddress::CAddress(int houseNumber,const char* streetName,const char* cityName)
{

	if (streetName == NULL)
		this->streetName = _strdup(" ");
	else
		this->streetName = _strdup(streetName);
	
	if (cityName==NULL)
		this->cityName = _strdup(" ");
	else
		this->cityName = _strdup(cityName);

	if (houseNumber < 0)
		this->houseNumber = 0;
	else
		this->houseNumber = houseNumber;

}

CAddress::CAddress(const CAddress& other)
{
	*this = other;
}



CAddress::~CAddress()
{
	delete[] cityName;
	delete[] streetName;
	cityName = nullptr;
	streetName = nullptr;
}

const char* CAddress::getcityName() const
{
	return cityName;
}
const char* CAddress::getStreetName() const
{
	return streetName;
}
int CAddress::getHouseNumber()const
{
	return houseNumber;
}



void CAddress::UpdateAddress(const char* cityName, const char* streetName,int houseNumber)
{
	if (cityName == nullptr || streetName == nullptr)
		return;

	if (houseNumber < 0)
	{
		this->houseNumber = 0;
	}
	else
		this->houseNumber = houseNumber;
	delete[] this->cityName;
	delete[] this->streetName;
	this->cityName = _strdup(cityName);
	this->streetName = _strdup(streetName);

}

ostream& operator<<(ostream& os, const CAddress& p)
{

	 os <<p.streetName << " " << p.houseNumber << ", " << p.cityName << endl;
	 return os;

}

istream& operator>>(istream& in, CAddress& p)
 {
	 // Create temporary buffers to hold the input strings
	 char tempCity[100];
	 char tempStreet[100];

	 std::cout << "Please enter house number street name and city name:";
	 in >> p.houseNumber>>tempStreet>>tempCity;

	 // Deallocate previous memory and allocate new memory for the input strings
	 delete[] p.cityName;
	 delete[] p.streetName;
	 p.cityName, p.streetName = nullptr;

	 p.cityName = _strdup(tempCity);
	 p.streetName = _strdup(tempStreet);

	 return in;
 }

bool CAddress::operator==(CAddress& p) const
{
	if (strcmp(this->cityName, p.cityName) != 0 )
		return false;
	if (strcmp(this->streetName, p.streetName) != 0)
		return false;
	if (this->houseNumber != p.houseNumber)
		return false;

	return true;
}

const CAddress& CAddress::operator=(const CAddress& other) 
{
	if (this!=&other)
	{
		this->houseNumber = other.houseNumber;
		delete[]this->cityName;
		delete[]this->streetName;
		this->cityName = _strdup(other.cityName);
		this->streetName = _strdup(other.streetName);
	}

	return *this;
}

const char* CAddress::getCurrentAddress()const
{
	// Calculate the required buffer size
	size_t bufferSize = strlen(streetName) + strlen(cityName) + 15; 

	// Allocate memory for the address string
	char* address = new char[bufferSize];

	strcpy(address, streetName);            
	strcat(address, " ");                   
	strcat(address, to_string(houseNumber).c_str());        
	strcat(address, ", ");                  
	strcat(address, cityName);

	return address;
}








