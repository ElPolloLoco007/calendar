/*
 * C++
 * Project: Calendar
 * Author: Helgi Poulsen
 * Email: helgipoulsen@hotmail.com
 * 28-July-2019
 */

#include <ctime>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

#ifndef Event_H
#define Event_H

class Event
{
private:
  int priority;
  string type;
  string date;
  string event;
  string time;

  string year;
  string month;
  string day;
  string today;

public:
  Event(){};
  Event(string pType, string pDate, string pTime, int pPriority, string pEvent)
      : type(pType), date(pDate), time(pTime), priority(pPriority), event(pEvent) {}

  bool operator==(const Event &obj)
  {
    return (type == obj.type) && (date == obj.date) && (time == obj.time) &&
           (priority == obj.priority) && (event == obj.event);
  }

  // Write the member variables to stream objects
  friend ostream &operator<<(std::ostream &out, const Event &obj)
  {
    out << obj.type << obj.date << " " << obj.time << " " << obj.priority << " "
        << obj.event << endl;
    return out;
  }

  // Read data from stream object and fill it in member variables
  friend std::istream &operator>>(std::istream &in, Event &obj)
  {
    in >> obj.type;
    in >> obj.date;
    in >> obj.time;
    in >> obj.priority;
    in >> obj.event;
    return in;
  }
  void setType(string pType) { type = pType; }
  void setDate(string pDate) { date = pDate; };
  void setEvent(string pevent) { event = pevent; }
  void setPriority(int pPriority) { priority = pPriority; }
  void setTime(string pTime) { time = pTime; }
  string getType() { return type; }
  int getPriority() { return priority; }
  string getDate() { return date; }
  string getEvent() { return event; }
  string getTime() { return time; }

  int dateDifference(string today, string future);
  int rdn(int y, int m, int d);
  int timeDifference(string clock, string race);
  void getTimeNow();
  bool isNumber(string s);

  void setYear(string y) { year = y; }
  void setMonth(string m) { month = m; }
  void setDay(string d) { day = d; }
  void setToday(string t) { today = t; }
  string getYear() { return year; }
  string getMonth() { return month; }
  string getDay() { return day; }
  string getToday() { return today; }
};

#endif
