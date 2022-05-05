#include "Part.h"

Part::Part()
{

}

Part::Part(const char* nName)
{
    this->name = nName;
    this->flightHours = 0;
}

Part::~Part()
{

}

string Part::getPartName()
{
    return this->name;
}

int Part::getFlightHours()
{
    return this->flightHours;
}

Date Part::getInstallationDate()
{
    return this->installationDate;
}

void Part::addFlightHours(int nTime)
{
    this->flightHours += nTime;
}

void Part::install(Date& nDate)
{
    this->installationDate = nDate;
}

bool Part::inspection(Date& nDate)
{
    if (nDate.toDays() - this->installationDate.toDays() >= this->flightHours) return true;
    return false;
}

//ostream& operator<<(ostream& out, Date& d) {
//    return out << d.getMonthName() << " " << d.getDay() << ", " << d.getYear() << endl;
//}

ostream& operator<<(ostream& out, Part nPart)
{
    // TODO: insert return statement here
    return out << "Part:\t\t\t" << nPart.getPartName() << endl << "Flight hours:\t\t" << nPart.getFlightHours() << endl;
}