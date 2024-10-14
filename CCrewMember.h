#pragma once
#include "CAddress.h"
#include <string>
#include "CAddress.h"
using namespace std;
#include <fstream>
class CCrewMember

{

protected:
	string name;
	int airTimeMinutes;

public :
	//constructors
	CCrewMember(string name, int airTimeMinutes = 0) noexcept(false);
	CCrewMember(ifstream& in);
	CCrewMember(const CCrewMember & other);

	virtual ~CCrewMember();

	//geters
	string getName()const ;
	int getAirTimeMinutes()const ;
	void setName(string name);


	bool IsEqual(CCrewMember& other)const ;

	// operators
	friend ostream& operator<<(ostream& os, const CCrewMember& p);
	friend istream& operator>>(istream& in,CCrewMember& p);
	virtual const CCrewMember& operator=(const CCrewMember& p);
	virtual void toOs(ostream& os) const {}
	virtual bool operator==(const CCrewMember& other) const;
	virtual const CCrewMember* operator+=(int minutes);
	virtual void fromOs(istream& in) {}
	virtual void recieveGift() const=0;
	virtual void switchUniform() const=0;
	virtual void Print(std::ostream& os)const = 0; 
	virtual CCrewMember* clone()const = 0;
	
		
};

