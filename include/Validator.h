/*
 * C++
 * Project: Calendar
 * Author: Helgi Poulsen
 * Email: helgipoulsen@hotmail.com
 * 01-August-2019
 */

#include <iostream>
#include <string>
#include <ctime>
#include "Event.h"
using namespace std;

#ifndef Validator_H
#define Validator_H

class Validator {
private:


Event event;
public:
  Validator(){};

  string validateDate(string d);
  string validateTime(string t);
  int validatePriority(int p);
  string validateEvent(string e);

  
};

#endif
