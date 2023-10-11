#include "NonProfessional.h"

//PRE: pay passed into function to determine weekly pay
int NonProfessional::weeklypay(double pay){ //calculating pay with formula given on handout
  int weeklypay = pay * hours;
  return weeklypay;
}
//POST: returning weekly pay to be printed to screen in main

//PRE: hours passed into function to determine vacation days
void NonProfessional::vacationdays(int hours){
  vacation = hours/8;
}
//POST: vacation days are set based on hours worked

//PRE: hours are passed into the function to determine insurance
void NonProfessional::insuranceamt(int hours){
  insurance = hours * .05;
}
//POST: insurance is calculated and set in function from hours worked

//Constructor for derived class setting base values
NonProfessional::NonProfessional(int p, int v, int i, int h) : Employee(p,v,i){
  pay = p;
  vacation = v;
  insurance = i;
  hours = h;
}