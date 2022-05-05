#pragma once
#ifndef IT_PART_H
#define IT_PART_H
#include "Part.h"
class IT_Part :public virtual Part
{
    friend ostream& operator<<(ostream& out, IT_Part nPart);
public:
    IT_Part();
    IT_Part(const char* nName, int nNumber);

    ~IT_Part();
    int getITInspect();
    virtual bool inspection(Date& nDate);
private:
    int it_inspect;
};
#endif
