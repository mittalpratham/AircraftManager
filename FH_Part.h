#pragma once
#ifndef FH_PART_H
#define FH_PART_H
#include "Part.h"
class FH_Part :public virtual Part
{
    friend ostream& operator<<(ostream& out, FH_Part nPart);
public:
    FH_Part();
    FH_Part(const char* nName, int nNumber);
    ~FH_Part();

    int getFHInspect();

    virtual bool inspection(Date& nDate);

private:
    int fh_inspect;
};

#endif

