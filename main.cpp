#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
using namespace std;

#include "CPlane.h"
#include "CFlightInfo.h"
#include "CCrewMember.h"
#include "CFlight.h"
#include "CFlightCompany.h"
#include "Caddress.h"
#include "CPilot.h"
#include "CCargo.h"
#include "CHost.h"
#include "FlightCompException.h"
#include "PlaneCrewFactory.h"

//const int CM_COUNT = 5;
//const int PLANE_COUNT = 4;
//const int FLIGHT_COUNT = 4;

void main()
{

	CFlightCompany* pDelta = NULL;
	try
	{

		pDelta = new CFlightCompany("Delta.txt", 0);
		cout << "This was in file " << endl;
		pDelta->Print(cout);

	}

	catch (const CFlightCompException& e) {
		e.Show();
		pDelta = new CFlightCompany("Delta");
	}
	

	//Checking some of the exception put try and catch for each section	
	try
	{
		CPlane p1(-34, "AirBus");
	}
	catch (const CFlightCompException& e) {
		e.Show();
	}
	try
	{
		CCargo c1(45, "Jumbo", -560, 200);
	}

	catch (const CFlightCompException& e) {
		e.Show();
	}
	cout << "3.counter is: " << CPlane::getCounter() << endl;

	try
	{
		CCargo c2(45, "Jumbo", 560, -200);
	}
	catch (const CFlightCompException& e) {
		e.Show();
	}


	try
	{
		CFlightInfo f1("London", -23, 120, 5000);
	}
	catch (const CFlightCompException& e) {
		e.Show();
	}

	try
	{
		CFlightInfo f2("LondonVeryLong", 23, 120, 5000);
	}
	catch (const CFlightCompException& e) {
		e.Show();
	}

	try
	{
		CFlightInfo f3("London", 23, -120, 5000);
	}
	catch (const CFlightCompException& e) {
		e.Show();
	}

	try
	{
		CFlightInfo f4("London", 23, 120, -5000);
	}
	catch (const CFlightCompException& e) {
		e.Show();
	}

	try
	{
		CCrewMember* pC1 = pDelta->GetCrewMember(-1);
	}
	catch (const CFlightCompException& e) {
		e.Show();
	}

	CCrewMember* pC2 = pDelta->GetCrewMember(0);

	
	try
	{
		(*pC2) += -4;
	}
	catch (const CFlightCompException& e) {
		e.Show();
	}

	try
	{
		CPlane p0 = (*pDelta)[9];
	}
	catch (const CFlightCompException& e) {
		e.Show();
	}

	cout << "------------checking get company from user------------------" << endl;
	CPlaneCrewFactory::GetCompanyDataFromUser(*pDelta);


	CFlight* pF = pDelta->GetFlightByNum(343);
	CCrewMember* pCmTemp;
	if (pF != NULL) {
		cout << "flight 343 was found " << endl;
		for (int i = 0; i < pDelta->GetCrewCount(); i++) {
			try
			{
				pCmTemp = pDelta->GetCrewMember(i);
				*pF + pCmTemp;  // Try adding the crew member to the flight
			}
			catch (CFlightCompException& ex) {
				ex.Show();
			}
		}
	}


	try
	{
		pDelta->SaveToFile("Delta.txt");
	}
	catch (const CFlightCompException& e) {
		e.Show();
	}


	delete pDelta;
	system("pause");
}