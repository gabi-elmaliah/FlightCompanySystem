#pragma once
#include <string>
#include<iostream>

using namespace std;

class CFlightInfo
{
private:

	int flightNumber;
	string destination;
	int flightTimeMinutes;
	int flightDistance;

public :

	//constructors
	CFlightInfo(const  string& destination,int flightNumber, int flightTimeMinutes, int flightDistance);
	~CFlightInfo();
	CFlightInfo(const CFlightInfo & other);

	//getters
	int GetFNum()const;
	string getDestination()const ;
	int getflightTimeMinutes()const;
	int getFlightDistance() const;

	//setterts
	void setFlightNumber(int flightNumber);
	void SetDest(string destination);
	void setFlightTimeMinutes(int minutes);
	void setFlightDistance(int distance);

	bool isEqual(const CFlightInfo& fligthInfo) const;
	void Print()const;

	friend ostream& operator<<(ostream& os, const CFlightInfo& p);

	bool operator==(const CFlightInfo& p)const;
	const CFlightInfo& operator=(const CFlightInfo& other);
	bool operator!=(const CFlightInfo& p)const ;

	operator int() const { return flightTimeMinutes; }

};
