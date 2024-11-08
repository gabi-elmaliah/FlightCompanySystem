#include "CPilot.h"
#include "CAddress.h"


CPilot::CPilot(string name,bool isCaptain ,const CAddress* address, int airTimeMinutes):CCrewMember(name,airTimeMinutes),
isCaptain(isCaptain)
{
	if (address == nullptr)
		this->address = nullptr;
	else
		this->address = new CAddress(*address);

}

CPilot::CPilot(ifstream& in):CCrewMember(in)
{
	fromOs(in);
}

CPilot::~CPilot()
{
	delete address;
	address = nullptr;
}

CPilot::CPilot(const CPilot& other):CCrewMember(other)
{
	*this = other;
}

void CPilot::fromOs(istream& in)
{
	int hasAddress;
	in >> hasAddress;
	if (hasAddress == 1)
	{
		this->address = new CAddress(in);
	}
	else
		this->address = nullptr;
	int isCaptain;
	in >> isCaptain;
	if (isCaptain)
		this->isCaptain = true;
	else
		this->isCaptain = false;
	
}
const CPilot& CPilot::operator=(const CPilot& p)
{
	if (this == &p)
		return *this;
	this->isCaptain = p.isCaptain;
	CCrewMember::operator=(p);

	if (this->address != nullptr) {
		delete this->address;  
		this->address = nullptr;
	}
	if (p.address != nullptr) {
		this->address = new CAddress(*p.address);  // Deep copy of address
	}
	else {
		this->address = nullptr;
	}
	
	return *this;

}

bool CPilot::operator==(const CCrewMember& other) const
{

	if (!CCrewMember::operator==(other))
		return false;

	// Use dynamic_cast to check if 'other' is a CPilot
	const CPilot* temp = dynamic_cast<const CPilot*>(&other);

	if (temp == nullptr)
		return false;

	// If both addresses are nullptr, they are considered equal
	if (this->address == nullptr && temp->address == nullptr)
		return true;

	// If one is nullptr and the other is not, they are not equal
	if (this->address == nullptr || temp->address == nullptr)
		return false;

	// Dereference and compare the addresses
	return *this->address == *temp->address;
}



void CPilot::recieveGift() const
{
	cout << name << " thanking the company for receiving the holiday gift." << endl;
}

void CPilot::switchUniform() const
{
	cout <<name <<": this is the fifth time I get a new uniform – this is a waste of money!" << endl;
}

void CPilot::comeToSimulatorMessage()
{
	cout<<"Pilot " << name << " got the message will come soon" << endl;
}

void CPilot::Print(std::ostream& os) const
{
	string pilotPosition;
	if (isCaptain)
		pilotPosition = " a Captain";
	else
		pilotPosition = " Not a Captain";
	if(address!=nullptr)	
		cout <<"Pilot " << name << " minutes " << airTimeMinutes << " Home " << *address << pilotPosition << endl;
	else
		cout <<"Pilot " << name << " minutes " << airTimeMinutes<< pilotPosition << endl;

}

void CPilot::toOs(ostream& os) const
{
	if (typeid(os) == typeid(ofstream))
	{
		if (address != nullptr)
			os << 1 << " " << *address << " ";
		else
			os << 0 << " ";
		os << isCaptain<<endl;
	}
	else
		Print(os);
	

}


const CCrewMember& CPilot::operator+=(int minutes)
{
	if (isCaptain)
		return CCrewMember::operator+=(minutes + 0.1 * minutes);
	else
		return CCrewMember::operator+=(minutes);

}
