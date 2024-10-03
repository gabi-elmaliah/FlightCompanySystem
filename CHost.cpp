#include <iostream>
#include <string>
#include "CHost.h"
using namespace std;


CHost::CHost(string name, eType type, int airTimeMinutes):CCrewMember(name,airTimeMinutes),
type(type)
{

	
	
}

CHost::CHost(const CHost& other):CCrewMember(other)
{
	*this = other;
}

const CHost& CHost::operator=(const CHost& p)
{
	if (this == &p)
		return *this;
	CCrewMember::operator=(p);
	this->type = p.type;
	return *this;
}

void CHost::switchUniform() const 
{
	cout << name<<": I think the new uniform is very nice!" << endl;
}

void CHost::recieveGift() const
{
	cout<< name << " thanking the company for receiving the holiday gift.I wasn’t expecting it"<<endl;
}

bool CHost::operator==(const CHost& other) const
{
	if (!CCrewMember::operator==(other))
		return false;
	return true;
}

void CHost::Print(std::ostream& os) const
{
	const char* types[] = { "Regular", "Super", "Calcelan" };
	cout << "Host " << types[type] <<" "<< name << " minutes " << airTimeMinutes << endl;
}

CHost::eType CHost::getType()const
{
	return this->type;

}