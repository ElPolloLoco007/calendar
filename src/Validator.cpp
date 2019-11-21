#include "Validator.h"

string Validator::validateType(string t)
{
  if (t == "General")
  {
    return t;
  }
  if (t == "Event")
  {
    return t;
  }
  if (t == "Meeting")
  {
    return t;
  }
  if (t == "Work")
  {
    return t;
  }
  cout << "Please enter a valid type: General, Meeting or Event";
  return "";
}

string Validator::validateDate(string d)
{
  string ye, mo, da;
  int ye1, mo1, da1;
  string tmp = d;

  if (d.length() == 5)
  {
    tmp.replace(2, 1, 1, '-');
    da = d.substr(0, 2);
    mo = d.substr(3, 5);

    if (event.isNumber(da) && event.isNumber(mo))
    {
      da1 = stoi(da);
      mo1 = stoi(mo);
      if (mo1 <= 12 && da1 <= 31)
      {
        string year = "-2019";
        tmp += year;
        event.getTimeNow();
        if (event.dateDifference(event.getToday(), tmp) >= 0)
        {
          return tmp;
        }
        else
        {
          cout << "This date has already passed\n";
        }
      }
    }
    else
    {
      cout << "Please enter a valid date 30-11-2019 or 06-04!";
      return "";
    }
  }

  if (d.length() == 10)
  {
    tmp.replace(2, 1, 1, '-');
    tmp.replace(5, 1, 1, '-');

    da = d.substr(0, 2);
    mo = d.substr(3, 2);
    ye = d.substr(6, 4);

    if (event.isNumber(da) && event.isNumber(mo) && event.isNumber(ye))
    {
      da1 = stoi(da);
      mo1 = stoi(mo);
      ye1 = stoi(ye);

      if (mo1 <= 12 && da1 <= 31 && ye1 >= 2019)
      {
        event.getTimeNow();
        if (event.dateDifference(event.getToday(), tmp) >= 0)
        {
          return tmp;
        }
        else
        {
          cout << "This date has already passed\n";
        }
      }
    }
  }
  else
  {
    cout << "Please enter a valid date 30-11-2019 or 06-04!";
    return "";
  }

  cout << "Please enter a valid date 30-11-2019 or 06-04!";
  return "";
}

string Validator::validateTime(string t)
{
  string ho, mi;
  int h1, m1;
  string tmp = t;

  if (t.length() == 5)
  {
    tmp.replace(2, 1, 1, ':');
    ho = t.substr(0, 2);
    mi = t.substr(3, 5);

    if (t == "     ")
    {
      return t;
    }

    if (event.isNumber(ho) && event.isNumber(mi))
    {
      h1 = stoi(ho);
      m1 = stoi(mi);
      if (h1 <= 24 && m1 <= 59)
      {
        return tmp;
      }
    }
  }
  cout << "Please enter a valid time 16:24!";
  return "";
}
int Validator::validatePriority(int p)
{
  if (p > 3)
  {
    return 0;
  }
  return p;
}
string Validator::validateEvent(string e)
{
  if (e.length() <= 40 || e.length() == 0)
  {
    return e;
  }
  cout << "Please enter a event: min 1 char and max 40 char";
  return "";
}