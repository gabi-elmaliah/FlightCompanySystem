#pragma once
#include "CAddress.h"
#include <string>
#include "CAddress.h"
using namespace std;
class CCrewMember

{

protected:
	string name;
	int airTimeMinutes;

public :

	CCrewMember(string name, int airTimeMinutes = 0);
	CCrewMember(const CCrewMember & other);
	virtual ~CCrewMember();
	string getName()const ;
	int getAirTimeMinutes()const ;
	void setName(string name);


	bool UpdateMinutes(int minutes);
	bool IsEqual(CCrewMember& other)const ;


	friend ostream& operator<<(ostream& os, const CCrewMember& p);
	virtual const CCrewMember& operator=(const CCrewMember& p);
	virtual bool operator==(const CCrewMember& other) const;
	virtual const CCrewMember* operator+=(int minutes);
	virtual void recieveGift() const=0;
	virtual void switchUniform() const=0;
	virtual void Print(std::ostream& os)const = 0; 
	virtual CCrewMember* clone()const = 0;
	
		
};

