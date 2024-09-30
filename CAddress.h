#pragma once
#include <iostream>
using namespace std;
class CAddress
{
private:
	
	char* cityName;
	char* streetName;
	int houseNumber;

public :
	CAddress() = delete;
	CAddress(int houseNumber,const char* streetName,const char* cityName = "Tel Aviv");
	CAddress(const CAddress &other);
	~CAddress();
	const char* getcityName() const;
	const char* getStreetName() const;
	int getHouseNumber()const;
	

	void UpdateAddress(const char* cityName,const char* streetName,int houseNumber);

	friend ostream& operator<<(ostream& os, const CAddress& p);
	friend istream& operator>>(istream& in, CAddress& p);
	bool operator==(CAddress& p) const ;
	const CAddress& operator=(const CAddress& other) ;

	const char* getCurrentAddress()const ;



	

};

