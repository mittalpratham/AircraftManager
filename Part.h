#pragma once
#ifndef PART_H
#define PART_H

#include <iostream>
#include "Date.h"
#include <iomanip>

using namespace std;

class Part
{

	friend ostream& operator<<(ostream& out, Date& nDate);
	friend ostream& operator<<(ostream& out, Part nPart);
public:
	Part();
	Part(const char* nName);

	~Part();

	//getter function
	string getPartName();

	int getFlightHours();

	Date getInstallationDate();

	void addFlightHours(int);

	void install(Date&);

	virtual bool inspection(Date&);

	Date installationDate;

	int flightHours;
private:

	//member variable
	string name;

};
#endif

