#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory>
#include <string>
using namespace std;

#include "Application.h"
#include "Event.h"

int main(int argc, char **argv)
{
  Event e;
  e.getTimeNow();
  //Bash to remove empty lines in txt file
  system("sed -i '/^$/d' ~/Dropbox/Calendar/calendar");
  shared_ptr<Calendar> c(new Calendar());
  shared_ptr<Application> a(new Application());

  string type = "General";
  string x = "";
  string date = e.getToday();
  string time = "     ";
  string msg = "";
  string priority = "0";

  for (int i = 0; i < argc; i++)
  {
    if (strcmp(argv[i], "--menu") == 0)
    {
      a->run(c);
    }
    else if (strcmp(argv[i], "--help") == 0)
    {
      a->help();
    }
    if (i == 1)
    {

      string tmp = argv[i];
      if (tmp.length() > 1)
      {
        tmp[0] = toupper(tmp[0]);
      }
      if (tmp == "General" || tmp == "Event" || tmp == "Meeting")
      {
        type = tmp;
      }
      else if (tmp.length() == 10)
      {
        date = tmp;
      }
      else if (tmp.length() == 5 && tmp != "Event")
      {
        time = tmp;
      }
      else if (tmp.length() == 1)
      {
        priority = tmp;
      }
      else
      {
        msg += tmp;
        msg += " ";
      }
    }
    if (i == 2)
    {
      string tmp = argv[i];
      cout << tmp + "\n";
      if (tmp.length() == 10)
      {
        date = tmp;
      }
      else if (tmp.length() == 5)
      {
        time = tmp;
      }
      else if (tmp.length() == 1)
      {
        priority = tmp;
      }
      else
      {
        msg += tmp;
        msg += " ";
      }
    }
    if (i == 3)
    {
      string tmp = argv[i];
      cout << tmp + "\n";
      if (tmp.length() == 5)
      {
        time = tmp;
      }
      else if (tmp.length() == 1)
      {
        priority = tmp;
      }
      else
      {
        msg += tmp;
        msg += " ";
      }
    }

    if (i == 4)
    {
      string tmp = argv[i];
      if (tmp.length() == 1)
      {
        priority = tmp;
      }
      else
      {
        msg += tmp;
        msg += " ";
      }
    }
    if (i > 4)
    {
      string tmp = argv[i];
      msg += tmp;
      msg += " ";
    }
  }
  if (argc > 2)
  {
    a->addEventDirectly(c, type, date, time, priority, msg);
  }

  a->showEvents(c);

  return 0;
}
