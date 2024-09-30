#pragma once
#include "CCrewMember.h"
#include "string"
class CHost : public CCrewMember
{
private:

	enum eType { eRegular, eSuper, eCalcelan};

public:

	CHost(string name, eType type);
	
	void switchUniform() const override;

};

