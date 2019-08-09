#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory>
#include <string>
using namespace std;

#include "Application.h"

int main(int argc, char **argv)
{
  //Bash to remove empty lines in txt file
  system("sed -i '/^$/d' ~/Dropbox/Calendar/calendar");
  shared_ptr<Calendar> c(new Calendar());
  shared_ptr<Application> a(new Application());
  string x = "";
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
    if (i >= 1)
    {
      x += argv[i];
      x += " ";
    }
  }
  a->addEventDirectly(c, x);
  a->showEvents(c);

  return 0;
}
