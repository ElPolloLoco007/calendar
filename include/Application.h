/*
 * C++
 * Project: Calendar
 * Author: Helgi Poulsen
 * Email: helgipoulsen@hotmail.com
 * 26-July-2019
 */

#include "Validator.h"
#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>
using namespace std;

#include "Calendar.h"
#include "Menu.h"

#ifndef Application_H
#define Application_H

class Application {
private:
  Menu menu;
  Event e;
  Validator v;

public:
  Application();
  void addEvent(shared_ptr<Calendar> c);
  void addEventDirectly(shared_ptr<Calendar> c,string fullEvent);

  void run(shared_ptr<Calendar> &c);
  void showEvents(shared_ptr<Calendar> c);
  void sortEvents(shared_ptr<Calendar> &c);
  void updateDeleteEvent(shared_ptr<Calendar> &c);

  int doMenuOption(int option);
  void clearScreen();
  void help();
  void returnToMenu();
  void returnToMenu1();
  void showMenu();
};

#endif
