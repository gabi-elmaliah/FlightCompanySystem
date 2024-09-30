#pragma once
#include <string>
using namespace std;
class CPlane
{
private:
	static int counter;
	string name;
	int numOfSeats;
	int serial_number;

public:
	
	CPlane(int numOfSeats, const string& name);
	CPlane(const CPlane& other);
	~CPlane();
	int getSerialNumber() const;
	string getName() const;
	int getNumOfSeats()const;
	void Print() const;
	bool IsEqual(const CPlane& other)const;

	friend ostream& operator<<(ostream& os, const CPlane& p);
	bool operator==(const CPlane& p) const;
	const CPlane& operator=(const CPlane& other);
	const CPlane& operator++();//prefix ++x
	CPlane operator++(int); //postfix x++



};




