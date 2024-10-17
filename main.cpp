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

		pDelta = new CFlightCompany("shalom.txt", 0);
		cout << "This was in file " << endl;
		pDelta->Print(cout);

	}

	catch (const CFlightCompException& e) {
		e.Show();
		pDelta = new CFlightCompany("Delta");
		CPlaneCrewFactory::GetCompanyDataFromUser(*pDelta);
	}
	

	//Checking some of the exception put try and catch for each section	
	try
	{
		CPlane p1(-34, "AirBus");
		CCargo c1(45, "Jumbo", -560, 200);
		CCargo c2(45, "Jumbo", 560, -200);
		CFlightInfo f1("London", -23, 120, 5000);
		CFlightInfo f2("LondonVeryLong", 23, 120, 5000);
		CFlightInfo f3("London", 23, -120, 5000);
		CFlightInfo f4("London", 23, 120, -5000);
		CCrewMember* pC1 = pDelta->GetCrewMember(-1);

		CCrewMember* pC2 = pDelta->GetCrewMember(0);
		(*pC2) += -4;
		CPlane p0 = (*pDelta)[9];
	}
	catch (const CFlightCompException& e) {
		e.Show();
	
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