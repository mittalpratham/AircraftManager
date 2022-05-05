#include "IT_Part.h"

IT_Part::IT_Part(const char* nName, int nNumber) :Part(nName)
{
    this->it_inspect = nNumber;
}


IT_Part::~IT_Part()
{

}

int IT_Part::getITInspect()
{
    return this->it_inspect;
}

bool IT_Part::inspection(Date& nDate)
{
    if (nDate.toDays() - this->installationDate.toDays() >= this->it_inspect) return true;
    return false;
}

ostream& operator<<(ostream& out, IT_Part nPart)
{
    // TODO: insert return statement here

    return out << "Inspect every:\t\t" << nPart.getITInspect() << " days installed" << endl;

}
