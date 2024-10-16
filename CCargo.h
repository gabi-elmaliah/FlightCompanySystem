#pragma once
#include "CPlane.h"
#include <iostream>
class CCargo: public CPlane
{
private:
	float maxWeight;
	float maxVolume;
	float currentWeight;
	float currentVolume;

public:
		//constructors
		CCargo(int seats,string name,float maxWeight,float maxVolume)noexcept(false);
		CCargo(const CCargo& other);
		CCargo(ifstream& in);
		~CCargo(){}
		virtual void fromOs(istream& in)override;
		virtual void toOs(ostream& os) const override; //>> is is a global function so thats why we made ToOS which prints CCargo object ;
		const CCargo& operator=(const CCargo& p);
		bool Load(float weight, float volume);
		virtual CPlane* clone() const override { return new CCargo(*this); };
		void addMinutesToLogBookMessage(int minutes) const;
		
};

