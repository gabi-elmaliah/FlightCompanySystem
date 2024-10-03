#pragma once
#include "CCrewMember.h"
class CPilot: public CCrewMember
{

protected:

	bool isCaptain;
	CAddress* address;

public:

	CPilot(string name, bool isCaptain, const CAddress* address =nullptr, int airTimeMinutes = 0);
	CPilot(const CPilot& other);
	~CPilot();

	virtual void Print(std::ostream& os)const override;
	virtual void switchUniform() const override;
	virtual void recieveGift() const override;
	void comeToSimulatorMessage();
	virtual const CPilot& operator=(const CPilot& p);
	virtual bool operator==(const CCrewMember& other) const;
	const CCrewMember* operator+=(int minutes);
	virtual CCrewMember* clone()const override { return new CPilot(*this); };
};

