#include "Aircraft.h"
#include "Date.h"
#include "Part.h"
#include <iomanip>

Aircraft::Aircraft(const string& nType, const string& nReg)
{
    this->type = nType;
    this->registration = nReg;
}

Aircraft::~Aircraft()
{
}

const string& Aircraft::getIdentify()
{
    // TODO: Add your implementation code here.

    return this->registration;
}

string Aircraft::getType()
{
    return this->type;
}


void Aircraft::install(Part* nPart, Date& nDate)
{
    // TODO: Add your implementation code here.

    nPart->install(nDate);

    part.add(nPart);
}


void Aircraft::takeFlight(int hours)
{
    // TODO: Add your implementation code here.
    this->flighthours += hours;
    for (int i = 0; i < part.getSize(); i++) {
        part.get(i)->addFlightHours(hours);
    }
}

Array<Part*> Aircraft::inspectionReport(Date& nDate)
{
    Array<Part*> supplyNeed;
    for (int i = 0; i < part.getSize(); i++) {
        if (part.get(i)->inspection(nDate))supplyNeed.add(part.get(i));
    }
    return supplyNeed;
}

ostream& operator<<(ostream& out, Aircraft nAir)
{
    // TODO: insert return statement here
    return out << "Aircraft:\t" << nAir.getType() << "\n" << "Registration:\t" << nAir.getIdentify() << endl;
}
