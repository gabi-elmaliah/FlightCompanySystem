#pragma once
#include "CCrewMember.h"
#include "string"
class CHost : public CCrewMember
{


public:


	enum eType { eRegular, eSuper, eCalcelan };
	CHost(string name, eType type, int airTimeMinutes = 0);
	CHost(ifstream& in);
	CHost(const CHost& other);

	virtual void fromOs(istream& in) override;
	virtual void toOs(ostream& os)const override;
	void switchUniform() const override;
	virtual void recieveGift() const override;
	virtual void Print(std::ostream& os) const override;
	virtual const CHost& operator=(const CHost& p);
	virtual bool operator==(const CHost& other) const;
	eType getType()const ;
	virtual CCrewMember* clone()const override { return new CHost(*this); };
	


	
protected: 

	eType type;

};

