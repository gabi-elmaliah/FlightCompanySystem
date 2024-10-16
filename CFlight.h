#pragma once
#include "CFlightInfo.h"
#include "CPlane.h"
#include "CCrewMember.h"
#include "CAddress.h"
#include "CCargo.h"
#include "CPilot.h"
#include "CHost.h"
#include <fstream>


class CFlightCompany;

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

	//construcotrs
	CFlight(const CFlightInfo& flightInfo,const  CPlane* plane=nullptr);
	CFlight(const CFlight & other);
	CFlight(ifstream& in,CFlightCompany& flightcompany) noexcept(false);
	virtual ~CFlight();

	//getters
	int getNumOfCrewMembers()const;
	int getFlightNumber()const ;
	const CPlane& getFlightPlane()const;
	const CFlightInfo& GetFlightInfo()const;

	void SetPlane(const CPlane* plane);

	// operators
	friend ostream& operator<<(ostream& os, const CFlight& p);
	const CFlight& operator=(const CFlight& p);
	bool operator==(const CFlight& p) const;
	CFlight* operator+(const CCrewMember* other) noexcept(false);

	bool TakeOff()  noexcept(false);
	int countPilots()const ;
	int countSuperHost()const ;

	friend class CFlightCompany; //  in order to allow CFlightCompany to access the plane member in AddFligh function


	
	
	

	


};

