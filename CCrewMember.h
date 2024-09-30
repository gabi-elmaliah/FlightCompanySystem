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
	~CCrewMember();
	
	string getName()const ;
	const CAddress & getAddress() const;
	int getAirTimeMinutes()const ;

	void setName(string name);
	void setAddress(const CAddress& address);

	bool UpdateMinutes(int minutes);
	void Print()const;
	bool IsEqual(CCrewMember& other)const ;

	//operators

	friend ostream& operator<<(ostream& os, const CCrewMember& p);
	const CCrewMember& operator=(const CCrewMember& p);
	bool operator==(const CCrewMember& p)const;
	const CCrewMember* operator+=(int minutes);

	void recieveGift() const;
	virtual void switchUniform() const = 0;
	virtual void takeOff() const = 0;
	


	
};

