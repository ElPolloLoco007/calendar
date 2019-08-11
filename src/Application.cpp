#include "Application.h"

Application::Application()
{
  menu.addItem("Add Event", true);
  menu.addItem("Update/Delete Event", true);
  menu.addItem("Show Event List", true);
  menu.addItem("Exit", true);
}

void Application::showMenu() { return menu.printMenu(); }

void Application::help()
{
  cout << "Welcome to calendar terminal\n";
  cout << "To get to the menu simply type calendar --menu\n";
  cout << "To instant add Event: ./main general 12-08-2021 12-08 2 this is a event";
}

void Application::addEventDirectly(shared_ptr<Calendar> c, string type, string date, string time, string priority, string msg)
{
  shared_ptr<Event> e(new Event());
  string vType, vDate, vTime, vMsg;
  int vPriority;
  int iPriority;

  vType = v.validateType(type);
  while (vType == "")
  {
    cout << "\nType:";
    getline(cin, type);
    vType = v.validateType(type);
  }
  cout << vType;

  e->setType(vType);
  //------------------------------
  vDate = v.validateDate(date);
  while (vDate == "")
  {
    cout << "\nDate:";
    getline(cin, date);
    vDate = v.validateDate(date);
  }
  e->setDate(vDate);
  //------------------------------

  vTime = v.validateTime(time);
  while (vTime == "")
  {
    cout << "\nTime:";
    getline(cin, time);
    vTime = v.validateTime(time);
  }
  e->setTime(vTime);

  //------------------------------
  while (!e->isNumber(priority))
  {
    cin.clear();
    cin.ignore(999, '\n');
    cout << "Invalid data type! Please enter 'i' again";
    cout << "\nPriority:";
    cin >> priority;
  }
  iPriority = stoi(priority);

  vPriority = v.validatePriority(iPriority);
  e->setPriority(vPriority);

  //------------------------------

  vMsg = v.validateEvent(msg);
  while (vMsg == "")
  {
    cout << "\nEvent:";
    getline(cin, msg);
    vMsg = v.validateEvent(msg);
  }
  e->setEvent(vMsg);
  //------------------------------

  c->addCalendareventMsg(e);
  c->printSpecificeventMsg(e);
  cout << "\n";
}

void Application::addEvent(shared_ptr<Calendar> c)
{

  cin.ignore();
  shared_ptr<Event> e(new Event());
  string type, date, time, event;
  string vType = "";
  int priority;
  string vDate = "";
  string vTime = "";
  int vPriority = 0;
  string vMsg = "";
  //------------------------------
  cout << "Type:";
  getline(cin, type);
  if (type.length() > 0)
  {
    type[0] = toupper(type[0]);
  }

  vType = v.validateType(type);
  while (vType == "")
  {
    cout << "\nDate:";
    getline(cin, vType);
    vType = v.validateType(type);
  }
  vType[0] = toupper(vType[0]);
  e->setType(vType);

  //------------------------------
  cout << "Date:";
  getline(cin, date);
  vDate = v.validateDate(date);
  while (vDate == "")
  {
    cout << "\nDate:";
    getline(cin, date);
    vDate = v.validateDate(date);
  }
  e->setDate(vDate);
  //------------------------------

  cout << "Time:";
  getline(cin, time);
  vTime = v.validateTime(time);
  while (vTime == "")
  {
    cout << "\nTime:";
    getline(cin, date);
    vTime = v.validateTime(time);
  }
  e->setTime(vTime);
  //------------------------------

  cout << "Priority:";
  while (!(cin >> priority))
  {
    cin.clear();
    cin.ignore(999, '\n');
    cout << "Invalid data type! Please enter 'i' again";
  }
  vPriority = v.validatePriority(priority);
  e->setPriority(vPriority);
  cin.ignore();
  //------------------------------

  cout << "Event:";
  getline(cin, event);
  vMsg = v.validateEvent(event);
  while (vMsg == "")
  {
    cout << "\nEvent:";
    getline(cin, event);
    vMsg = v.validateEvent(event);
  }
  e->setEvent(vMsg);
  //------------------------------

  c->addCalendareventMsg(e);
  c->printSpecificeventMsg(e);
  cout << "\n";
}
void Application::updateDeleteEvent(shared_ptr<Calendar> &c)
{
  system("gedit ~/Dropbox/Calendar/calendar");
  clearScreen();
}
void Application::showEvents(shared_ptr<Calendar> c)
{
  shared_ptr<Event> e(new Event());
  c->readFromCalendar("calendar", e);
  c->printCalendar();
}
void Application::sortEvents(shared_ptr<Calendar> &c) {}

void Application::run(shared_ptr<Calendar> &c)
{

  bool again = true;
  do
  {
    cout << "**** Menu ****" << endl;
    menu.printMenu();
    cout << "--------------";
    menu.doMenuOption();

    switch (menu.getMenuOption())
    {
    case 1:
      addEvent(c);
      returnToMenu1();
      break;
    case 2:
      updateDeleteEvent(c);
      break;
    case 3:
      showEvents(c);
      returnToMenu();
      break;
    case 4:
      again = false;
    }
  } while (again);
}

void Application::returnToMenu()
{
  cout << "\nPress Enter to return to menu:";
  cin.get();
  cin.get();
  clearScreen();
}

void Application::returnToMenu1()
{
  cout << "\nPress Enter to return to menu:";
  cin.get();
  clearScreen();
}

void Application::clearScreen()
{
#ifdef WINDOWS
  std::system("cls");
#else
  // Assume POSIX
  std::system("clear");
#endif
}