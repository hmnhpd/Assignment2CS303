#pragma once

class Employee{ //abstract class for derived classes to inherit from
protected:
  double pay = 0;
  int vacation = 0;
  double insurance = 0;
public:
  Employee(int pay, int vacation, int insurance) ;   
  virtual int weeklypay(double pay) = 0;
  virtual void vacationdays(int hours) = 0;
  virtual void insuranceamt(int hours) = 0;
  virtual ~Employee();
};