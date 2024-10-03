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

		CCargo(int seats,string name,float maxWeight,float maxVolume);
		CCargo(const CCargo& other);
		virtual void toOs(ostream& os) const override;
		const CCargo& operator=(const CCargo& p);
		bool Load(float weight, float volume);
		virtual CPlane* clone() const override { return new CCargo(*this); };
		void addMinutesToLogBookMessage(int minutes) const;
		
};

