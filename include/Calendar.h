#include <algorithm>
#include <cstring>
#include <ctime>
#include <dirent.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <sys/types.h>
#include <vector>

#include "Event.h"
using namespace std;

#ifndef CALENDAR_H
#define CALENDAR_H

class Calendar {
private:
  int priority;
  string date;
  string eventMsg;
  string time;
  vector<Event> vEvents;
  vector<Event> vTodayEvents;

public:
  Calendar(){};
  ~Calendar(){};

  void line();
  void printCalendar();
  void printSpecificeventMsg(shared_ptr<Event> e);
  void readFromCalendar(string tfile, shared_ptr<Event> pEvent);
  void writeToCalendar(string tfile, shared_ptr<Event> pEvent);
  void deleteOldEvents(string tfile, shared_ptr<Event> pEvent);

  void addCalendareventMsg(shared_ptr<Event> e);

  void sortByDate();
  void sortByDateToday();
};
#endif