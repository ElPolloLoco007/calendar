#include "Event.h"

void Event::getTimeNow()
{
  std::time_t t = std::time(0); // get time now
  std::tm *now = std::localtime(&t);
  // std::cout << (now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-'
  //           << now->tm_mday << '-' << now->tm_min << "\n";

  year = to_string(now->tm_year + 1900);
  setYear(year);

  if (now->tm_mon < 9)
  {
    month = "0";
    month += to_string(now->tm_mon + 1);
    setMonth(month);
  }
  else
  {
    month = to_string(now->tm_mon + 1);
    setMonth(month);
  }

  if (now->tm_mday < 10)
  {
    day = "0";
    day += to_string(now->tm_mday);
    setDay(day);
  }
  else
  {
    day = to_string(now->tm_mday);
    setDay(day);
  }

  today = day;
  today += "-";
  today += month;
  today += "-";
  today += year;
  setToday(today);
}

bool Event::isNumber(string s)
{
  for (int i = 0; i < s.length(); i++)
    if (isdigit(s[i]) == false)
      return false;

  return true;
}

int Event::rdn(int y, int m, int d)
{
  if (m < 3)
    y--, m += 12;
  return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
}

int Event::dateDifference(string pToday, string pFuture)
{
  string y1, m1, d1, y2, m2, d2;
  int ye1, mo1, da1, ye2, mo2, da2;
  d1 = pToday.substr(0, 2);
  m1 = pToday.substr(3, 2);
  y1 = pToday.substr(6, 4);

  d2 = pFuture.substr(0, 2);
  m2 = pFuture.substr(3, 2);
  y2 = pFuture.substr(6, 4);

  ye1 = stoi(y1);
  mo1 = stoi(m1);
  da1 = stoi(d1);

  ye2 = stoi(y2);
  mo2 = stoi(m2);
  da2 = stoi(d2);

  int days = rdn(ye2, mo2, da2) - rdn(ye1, mo1, da1);
  string tmp = to_string(days);

  return days;
}

int Event::timeDifference(string clock, string race)
{
  string h, m, h1, m1;
  int hour, min, hour1, min1;
  h = clock.substr(0, 2);
  m = clock.substr(3, 5);

  h1 = race.substr(0, 2);
  m1 = race.substr(3, 5);

  hour = stoi(h);
  min = stoi(m);

  hour1 = stoi(h1);
  min1 = stoi(m1);

  int timer = (hour1 * 60 + min1) - (hour * 60 + min);

  return timer;
}