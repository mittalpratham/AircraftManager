#include "Airline.h"
#include "IT_Part.h"
#include "FH_Part.h"
#include "FHIT_Part.h"
#include "Array.h"


Airline::Airline(const string& nName)
{

    this->name = nName;
}

Airline::~Airline()
{

}

void Airline::addAircraft(const string& nType, const string& nReg)
{
    // TODO: Add your implementation code here.

    aircraft.add(new Aircraft(nType, nReg));
}


void Airline::addPart(const string& nPart, int fh_inspect, int it_inspect)
{

    // TODO: Add your implementation code here.
    Part* tmp;
    //string tmpStr= nPart;
    if (!fh_inspect) {

        tmp = new IT_Part(nPart.c_str(), it_inspect);

    }
    else if (!it_inspect) {

        tmp = new FH_Part(nPart.c_str(), fh_inspect);
    }
    else {

        tmp = new FHIT_Part(nPart.c_str(), fh_inspect, it_inspect);
    }
    part.add(tmp);

}


// This should retrieve the <Aircraft> with the given registration (if it exist) and have it takeFlight for the given number of hours.
void Airline::takeFlight(string reg, int hours)
{
    // TODO: Add your implementation code here.

    for (int i = 0; i < aircraft.getSize(); i++) {
        if (aircraft.get(i)->getIdentify() == reg) {
            aircraft.get(i)->takeFlight(hours);
        }
    }
}


void Airline::printAircraft()
{

    // TODO: Add your implementation code here.
    for (int i = 0; i < aircraft.getSize(); i++) {
        cout << *(aircraft.get(i));
    }
}


void Airline::printParts()
{
    // TODO: Add your implementation code here.
    int i;

    for (i = 0; i < part.getSize(); i++) {
        cout << *(part.get(i));
        cout << "Installation Date:\t";
        Date tmp = part.get(i)->getInstallationDate();
        cout << tmp;

        FH_Part* fh = dynamic_cast<FH_Part*>(part.get(i));
        IT_Part* it = dynamic_cast<IT_Part*>(part.get(i));

        if (fh != NULL) {
            cout << *fh;
        }
        if (it != NULL) {
            cout << *it;
        }


        cout << endl;

    }
}


// This should find the <Aircraft> with the given registration and print out the <Aircraft> registration and all the parts on that <Aircraft> that require inspection.
void Airline::inspectionReport(string reg, Date& nDate)
{

    // TODO: Add your implementation code here.
    int i = 0, k = 0;

    for (i = 0; i < aircraft.getSize(); i++) {
        if (aircraft.get(i)->getIdentify() == reg) {
            supplyNeed = aircraft.get(i)->inspectionReport(nDate);
            break;
        }
    }
    if (supplyNeed.getSize() > 0) {
        cout << endl << "The following parts from " << reg << " require inspection : " << endl;
        for (i = 0; i < supplyNeed.getSize(); i++) {
            cout << *(supplyNeed.get(i));
            cout << "Installation Date:\t";
            Date tmp = supplyNeed.get(i)->getInstallationDate();
            cout << tmp;

            FH_Part* fh = dynamic_cast<FH_Part*>(supplyNeed.get(i));
            IT_Part* it = dynamic_cast<IT_Part*>(supplyNeed.get(i));

            if (fh != NULL) {
                cout << *fh;
            }
            if (it != NULL) {
                cout << *it;
            }


            cout << endl;
        }
    }
}


// If there is an <Aircraft> with the given registration and a <Part> with the given name in the <Airline>, install that Part into the <Aircraft> and return true. If not, return false.
bool Airline::install(string nAirReg, string nPartName, Date& nDate)
{
    // TODO: Add your implementation code here.
    bool flagAir = false, flagPart = false;

    int i = 0, k = 0;
    for (i = 0; i < aircraft.getSize(); i++) {
        if (aircraft.get(i)->getIdentify() == nAirReg)
        {

            flagAir = true;
            break;
        }
    }

    for (k = 0; k < part.getSize(); k++) {
        if (part.get(k)->getPartName() == nPartName) {
            flagPart = true;
            break;
        }
    }
    if (flagAir && flagPart) {

        aircraft.get(i)->install(part.get(k), nDate);
        return true;
    }
    return false;
}
