#pragma once
#include <iostream>
#include<string>
using namespace std;

class CFlightCompException
{
public:
	virtual void Show() const = 0;
	
};


class CCompStringException: public CFlightCompException
{
private :
	string msg;

public:
	CCompStringException(string msg): msg(msg) {}
	virtual void Show() const override { cout << msg<< endl; }

};

class WrongOptionException :public CFlightCompException
{
private :
	int option;
public:
	WrongOptionException(int option) : option(option) {}
	virtual void Show() const override { cout <<option << " is an invalid option." << endl; }
};

class CCompLimitException: public CFlightCompException
{
private:
	int index;
public :
	CCompLimitException(int index) :index(index) {}
	virtual void Show() const override 
	{
		if (index < 0)
			cout << "Invalid Index, Index cant be negative" << endl;
		else
			cout << "Invalid index, The max index you have is "<<index-1<< endl;
			
	}

};

class CCompFileException: public CFlightCompException
{
	string fileName;

public :
	CCompFileException(string fileName) : fileName(fileName){}
	virtual void Show() const override { cout << "error in file: " <<fileName<< endl; }
};



