#pragma once
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
class CPlane
{
protected:
	static int counter;
	string name;
	int numOfSeats;
	int serial_number;

public:


	CPlane(int numOfSeats, const string& name) noexcept(false);
	CPlane(const CPlane& other);
	CPlane(ifstream &in, bool isCargo);
	virtual ~CPlane() { counter--; }
	int getSerialNumber() const;
	string getName() const;
	int getNumOfSeats()const;
	void Print() const;
	bool IsEqual(const CPlane& other)const;
	static int getCounter(){ return counter; }//help function to help trach serial_number

	friend ostream& operator<<(ostream& os, const CPlane& p);
	friend istream& operator>>(istream& in, CPlane& p);
	virtual void fromOs(istream& in);
	virtual void toOs(ostream& os) const { os << CPlane::counter << " " << serial_number << " " << name << "  " << numOfSeats << endl; };
	bool operator==(const CPlane& p) const;
	virtual const CPlane& operator=(const CPlane& other);
	virtual CPlane* clone() const { return new CPlane(*this); };
	const CPlane& operator++();//prefix ++x
	CPlane operator++(int); //postfix x++


};




