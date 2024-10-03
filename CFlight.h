#pragma once
#include "CFlightInfo.h"
#include "CPlane.h"
#include "CCrewMember.h"
#include "CAddress.h"
#include "CCargo.h"
#include "CPilot.h"
#include "CHost.h"


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
	virtual ~CFlight();
	int getNumOfCrewMembers()const;
	int getFlightNumber()const ;
	const CPlane& getFlightPlane()const;
	const CFlightInfo& GetFlightInfo()const;
	void SetPlane(const CPlane* plane);
	friend ostream& operator<<(ostream& os, const CFlight& p);
	const CFlight& operator=(const CFlight& p);
	bool operator==(const CFlight& p) const;
	CFlight* operator+(const CCrewMember* other);
	bool TakeOff();
	int countPilots()const ;
	int countSuperHost()const ;

	friend class CFlightCompany; //  in order to allow CFlightCompany to access the plane member in AddFligh function


	
	
	

	


};

