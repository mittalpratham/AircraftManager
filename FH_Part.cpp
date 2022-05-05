#include "FH_Part.h"


FH_Part::FH_Part()
{

}
FH_Part::~FH_Part() {

}
FH_Part::FH_Part(const char* nName, int nNumber) :Part(nName)
{
    this->fh_inspect = nNumber;
}

int FH_Part::getFHInspect()
{
    return this->fh_inspect;
}

bool FH_Part::inspection(Date& nDate)
{
    // TODO: Add your implementation code here.
    if (this->flightHours >= this->fh_inspect)return true;
    return false;
}

ostream& operator<<(ostream& out, FH_Part nPart)
{
    // TODO: insert return statement here
    return out << "Inspect every:\t\t" << nPart.getFHInspect() << " flight hours" << endl;
}