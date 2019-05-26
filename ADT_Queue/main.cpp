// ADT Queue task for ADS lecture of Vilnius University
// By Žygimantas Sideravičius ISI
// MAIN TESTING FILE
#include <iostream>
#include <iomanip>
#include <string>
#include "adt.h"

int main(){
  adt::ADTQueue<int> test;
  std:: cout << "Size: " << test.size() << std::endl;
  test.enqueue(45);
  std:: cout << "Size: " << test.size() << std::endl;
  int temp;
  test.frontEl(temp);
  std:: cout << "Front element: " << temp << std::endl;
  test.enqueue(52);
  std:: cout << "Size: " << test.size() << std::endl;
  test.dequeue();
  test.frontEl(temp);
  std:: cout << "Size: " << test.size() << std::endl;
  std:: cout << "Front element: " << temp << std::endl;

  return 0;
}

/* Output:
Size: 0
Size: 1 (after adding 45)
Front element: 45
Size: 2 (after adding 52)
Size: 1 (after dequeuing)
Front element: 52 (now first element is 52)
*/