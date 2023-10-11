#include "Professional.h"

//PRE: pay passed into function
int Professional::weeklypay(double pay){
  int weeklypay = (pay/12)/4; //
  return weeklypay;
}
//POST: returns weekly pay based off salary

//PRE: hours passed into function to derive from abstract class
void Professional::vacationdays(int hours){
  vacation = vacation; 
}
//POST: vcacation days stay the same because of salary

//PRE: pay passed in to determine insurance
void Professional::insuranceamt(double pay){
  insurance = pay * 0.8; //professionals have an increased insurance rate
}
//POST: insurance calculated and set based on salary

//CONSTRUCTOR
Professional::Professional(int p, int v, int i) : Employee(p,v,i){
  pay = p;
  vacation = v;
  insurance = i;
  
}