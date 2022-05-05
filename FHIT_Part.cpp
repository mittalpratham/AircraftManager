#include "FHIT_Part.h"

FHIT_Part::FHIT_Part(const char* nName, int nFH, int nIT) :FH_Part(nName, nFH), IT_Part(nName, nIT), Part(nName)
{

}
FHIT_Part::~FHIT_Part() {

}
bool FHIT_Part::inspection(Date& nDate)
{
	return FH_Part::inspection(nDate) || IT_Part::inspection(nDate);
}


ostream& operator<<(ostream& out, FHIT_Part nPart)
{
	// TODO: insert return statement here
	return out << "Inspect every:\t\t" << nPart.getITInspect() << " flight hours" << endl << "Inspect every:\t\t" << nPart.getFHInspect() << " days installed" << endl;
}
