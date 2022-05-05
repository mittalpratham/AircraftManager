#pragma once
#ifndef FHIT_H
#define FHIT_H
#include "FH_Part.h"
#include "IT_Part.h"
class FHIT_Part :public FH_Part, public IT_Part
{
	friend ostream& operator<<(ostream& out, FHIT_Part nPart);
public:
	FHIT_Part(const char* nName, int nFH, int nIT);
	~FHIT_Part();
	virtual bool inspection(Date& nDate);

};
#endif
