#pragma once
#ifndef AIRCRAFT_H
#define AIRCRAFT_H
#include <iostream>
#include "Array.h"
#include "Date.h"
#include "Part.h"
#include <iomanip>

using namespace std;
class Aircraft
{

	friend ostream& operator<<(ostream& out, Aircraft nAir);
public:
	Aircraft(const string&, const string&);
	~Aircraft();
	const string& getIdentify();
	string getType();
	void install(Part* nPart, Date& nDate);
	void takeFlight(int hours);
	Array<Part*> inspectionReport(Date&);

private:
	// The type of aircraft
	string type;
	// This is the unique identifier of the aircraft
	string registration;
	// The number of hours this aircraft has flown
	int flighthours;

	Array<Part*> part;


};
#endif

