#pragma once

#ifndef AIRLINE_H
#define AIRLINE_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Array.h"
#include "Aircraft.h"
#include "Date.h"
#include "Part.h"
#include "FHIT_Part.h"
#include "FH_Part.h"
#include "IT_Part.h"

using namespace std;

class Airline {

	//friend ostream& operator<<(ostream& out, Date&);

public:
	//constructor
	Airline(const string&);

	~Airline();


private:

	string name;
	Array<Part*> part;
	Array<Part*> supplyNeed;
	Array<Aircraft*> aircraft;


public:

	Aircraft getAircraft(string&);

	Part getPart(string&);

	void addAircraft(const string& nType, const string& nReg);

	void addPart(const string& part, int fh_inspect, int it_inspect);

	// This should retrieve the <Aircraft> with the given registration (if it exist) and have it takeFlight for the given number of hours.
	void takeFlight(string reg, int hours);
	void printAircraft();
	void printParts();
	// This should find the <Aircraft> with the given registration and print out the <Aircraft> registration and all the parts on that <Aircraft> that require inspection.
	void inspectionReport(string reg, Date& nDate);
	// If there is an <Aircraft> with the given registration and a <Part> with the given name in the <Airline>, install that Part into the <Aircraft> and return true. If not, return false.
	bool install(string nAirReg, string nPartName, Date& nDate);
};
#endif
