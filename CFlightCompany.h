#pragma once
#include <string>
#include "CCrewMember.h"
#include "CPlane.h"

#include "CPilot.h"
#include <fstream>

using namespace std;

class CFlight;
class CFlightCompany
{
public:
	static const int MAX_CREW = 18;
	static const int MAX_PLANES = 18;
	static const int MAX_FLIGHTS = 18;


private :
	string name;
	CCrewMember* crewMembers[MAX_CREW];
	int numOfCrewMembers;
	CPlane* planes[MAX_PLANES];
	int numOfPlanes;
	CFlight* flights[MAX_FLIGHTS];
	int numOfFlights;
	


public:

	CFlightCompany(string name);
	CFlightCompany(string name,int)noexcept(false);
	CFlightCompany(CFlightCompany& other);
	virtual ~CFlightCompany();


	string getCompanyName()const;
	void SetName(string name);
	bool AddCrewMember(const CCrewMember& p);
	bool AddPlane(const CPlane& p);
	bool AddFlight(const CFlight& p);

	void  AddCrewToFlight(int flightNumber, int crewMemberId);
	void Print(std::ostream& os)const noexcept(false);

	friend ostream& operator<<(ostream& os, const CFlightCompany& p);
	const CFlightCompany& operator=(const CFlightCompany& p);
	const CPlane& operator[](int index) const noexcept(false);
	CPlane& operator[](int index) noexcept(false);



	CFlight* GetFlightByNum(int flightNum) const noexcept(false);
	const CPlane* getPlaneById(int planeNumber) const noexcept(false);
	CCrewMember* GetCrewMember(int index) const;
	int GetCrewCount()const;
	int  GetCargoCount()const ;
	void PilotsToSimulator() const ;
	void CrewGetPresent()const;
	void CrewGetUniform()const;
	bool TakeOff(int flightNumber) noexcept(false);
	void SaveToFile(string fileName) const ;
	void ShowAllPlanes()const ;
	void ShowAllCrewMembers() const;
	void ShowAllFlights() const;

};

