#pragma once
#include <string>
#include <fstream>
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
	CPlane(ifstream &in );
	virtual ~CPlane();
	int getSerialNumber() const;
	string getName() const;
	int getNumOfSeats()const;
	void Print() const;
	bool IsEqual(const CPlane& other)const;

	friend ostream& operator<<(ostream& os, const CPlane& p);
	virtual void toOs(ostream& os) const { os << CPlane::counter << " " << serial_number << " " << name << "  " << numOfSeats << endl; };
	bool operator==(const CPlane& p) const;
	virtual const CPlane& operator=(const CPlane& other);
	virtual CPlane* clone() const { return new CPlane(*this); };
	const CPlane& operator++();//prefix ++x
	CPlane operator++(int); //postfix x++


};




