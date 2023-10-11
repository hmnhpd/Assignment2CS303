#pragma once
#include "Employee.h"

class NonProfessional : public Employee {
  private:
    int hours;
  public:
    NonProfessional(int p, int v, int i, int h);
    int weeklypay(double pay);
    int getpay() {return pay;}
    void vacationdays(int hours);
    int getvacation() {return vacation;}
    void insuranceamt(int hours);
    int getinsurance() {return insurance;}
};