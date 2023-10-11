#pragma once
#include "Employee.h"

class Professional : public Employee {
  public:
    Professional(int p, int v, int i);
    int weeklypay(double pay);
    int getpay() {return pay;}
    void vacationdays(int hours);
    int getvacation() {return vacation;}
    void insuranceamt(double pay);
    int getinsurance() {return insurance;}
};