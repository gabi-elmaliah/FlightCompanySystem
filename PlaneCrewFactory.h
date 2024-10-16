#pragma once


typedef enum PlaneType
{
	eRegular,
	eCargo,
	nofPlaneType
};

typedef enum CrewType
{
	eHost,
	ePilot,
	nofCrewType
};
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
using namespace std;


const string PlaneType_TITLE[nofPlaneType] = { "Regular","Cargo" };
const string CrewType_TITLE[nofCrewType] = { "Host","Pilot" };


class CPlane;
class CCrewMember;
class CFlightCompany;
class CAddress;
class CHost;
class CPilot;
class CFlight;

class CPlaneCrewFactory
{
public:

	static PlaneType GetPlaneType(const CPlane* pPlane);
	static CrewType GetCrewType(const CCrewMember* pCrew);
	static void GetCompanyDataFromUser(CFlightCompany& comp);
	static CFlight* GetFlightFromUser();
	static CFlight* GetFlightFromFile(ifstream& inFile,CFlightCompany& comp);
	static CPlane* GetPlaneFromUser()noexcept(false);
	static CCrewMember* GetCrewFromUser();
	static CCrewMember* GetCrewMemberFromFile(ifstream& inFile);
	static CPlane* GetPlaneFromFile(ifstream& inFile, int type);
	static void AddCrewMemberToFlight(CFlightCompany& comp)noexcept(false);
	static void AddPlaneToFlight(CFlightCompany& comp);
	static CPilot* getPilotFromUser(string name, int airTimeMinutes)noexcept(false);

	


private:
	CPlaneCrewFactory(void) { }
};
