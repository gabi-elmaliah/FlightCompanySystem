#pragma once
#include "CFlightInfo.h"
#include "CPlane.h"
#include "CCrewMember.h"
#include "CAddress.h"

class CFlight
{
public :
	static const int MAX_CREW = 18;

private:

	CFlightInfo flightInfo;
	CPlane* plane;
	CCrewMember* crewMembers[MAX_CREW];
	int numOfCrewMembers;

public:
	CFlight(const CFlightInfo& flightInfo,const  CPlane* plane=nullptr);

	CFlight(const CFlight & other);
	~CFlight();
	int getNumOfCrewMembers()const;
	void setNumOFcrewMembers()const;
	int getFlightNumber()const ;
	const CPlane& getFlightPlane()const;
	const CFlightInfo& getFlightInfo()const;
	void SetPlane(const CPlane* plane);
	friend ostream& operator<<(ostream& os, const CFlight& p);
	const CFlight& operator=(const CFlight& p);
	bool operator==(const CFlight& p) const;
	CFlight* operator+(const CCrewMember& other);

	
	
	

	


};

