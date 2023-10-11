#include <iostream>
#include "Single_Linked_List.h"
#include "Employee.h"
#include "NonProfessional.h"
#include "Professional.h"
using namespace std;

int main() {
  //Single_Linked_List<int> list;
  //list.push_front(6);
  //list.push_back(10);
  //list.push_front(3);
  //list.push_back(15);
  //cout << "Front: " << list.front() << endl;
  //cout << "Back: " << list.back() << endl;
  //list.insert(2, 8);
  //list.remove(1);
  //int value = 10;
  //size_t index = list.find(value);
  //if (index != list.size()) {
      //cout << "Found " << value << " at index " << index << endl;
  //}else {
      //cout << value << " not found in the list." << endl;
  //}
  //list.print();
  //list.empty();
  cout << "Non-Professional Employee Pay:" << endl;
  Professional employee1(96000,50,45); //creating the professional employee
  NonProfessional employee2(12, 14, 9, 40); //creating the part time employee
  cout << "Professional Employee Information: " << endl;
  cout << "Salary: " << employee1.getpay() << endl;
  int week1 = employee1.weeklypay(96000); //calculating pay
  cout << "Weekly Pay: " << week1 << endl;
  cout << "Vacation Days: " << employee1.getvacation() << endl;
  cout << "Insurance amount: " << employee1.getinsurance() << endl;
  cout << endl;
  cout << "Non-Professional/Hourly Employee Information: " << endl;
  cout << "Hourly Rate: " << employee2.getpay() << endl;
  int week = employee2.weeklypay(12); //calculating pay
  cout << "Weekly Pay: " << week << endl;
  employee2.vacationdays(40); //calculating vacation days
  cout << "Vacation Days: " << employee2.getvacation() << endl;
  employee2.insuranceamt(40); //calculating insurance amount 
  cout << "Insurance amount: " << employee2.getinsurance() << endl;
  cout << endl;
  
  return 0;
}

