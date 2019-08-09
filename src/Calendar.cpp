#include "Calendar.h"

void Calendar::writeToCalendar(string tfile, shared_ptr<Event> pEvent)
{

  string homepath = getenv("HOME");
  ofstream out;
  out.open(homepath + "/Dropbox/Calendar/" + tfile, std::ios_base::app);
  out << pEvent->getDate() << "?" << pEvent->getTime() << "?"
      << pEvent->getPriority() << "?" << pEvent->getEvent() << "\n";
  out.close();
}

void Calendar::readFromCalendar(string tfile, shared_ptr<Event> pEvent)
{
  pEvent->getTimeNow();
  string homepath = getenv("HOME");
  ifstream in(homepath + "/Dropbox/Calendar/" + tfile);
  if (in.is_open(), ios::in)
  {
    for (std::string line; std::getline(in, line);)
    {
      if (line.length() > 19)
      {
        std::string delimiter = "?";
        int counter = 0;
        size_t pos = 0;
        std::string token;
        while ((pos = line.find(delimiter)) != string::npos)
        {
          token = line.substr(0, pos);
          if (counter == 0)
          {
            pEvent->setDate(token);
          }
          if (counter == 1)
          {
            pEvent->setTime(token);
          }
          if (counter == 2)
          {
            pEvent->setPriority(stoi(token));
          }
          line.erase(0, pos + delimiter.length());
          counter++;
        }
        pEvent->setEvent(line);
        if (pEvent->getToday() == pEvent->getDate())
        {
          vTodayEvents.push_back(Event(pEvent->getDate(), pEvent->getTime(),
                                       pEvent->getPriority(),
                                       pEvent->getEvent()));
        }
        if (pEvent->dateDifference(pEvent->getToday(), pEvent->getDate()) > 0)
        {
          vEvents.push_back(Event(pEvent->getDate(), pEvent->getTime(),
                                  pEvent->getPriority(), pEvent->getEvent()));
        }
      }
      else
      {
        cout << "Error with event:" << line << "\n";
      }
    }

    in.close();
  }
  else
  {
    cout << "Unable to open file: " + tfile << "\n";
  }
}

void Calendar::sortByDate(vector<Event> e)
{
  sort(e.begin(), e.end(), [](Event a, Event b) -> bool {
    if (a.getDate().substr(6, 4) < b.getDate().substr(6, 4))
      return true;
    if (a.getDate().substr(6, 4) == b.getDate().substr(6, 4) &&
        a.getDate().substr(3, 2) < b.getDate().substr(3, 2))
      return true;
    if (a.getDate().substr(6, 4) == b.getDate().substr(6, 4) &&
        a.getDate().substr(3, 2) == b.getDate().substr(3, 2) &&
        a.getDate().substr(0, 2) < b.getDate().substr(0, 2))
      return true;
    if (a.getDate().substr(6, 4) == b.getDate().substr(6, 4) &&
        a.getDate().substr(3, 2) == b.getDate().substr(3, 2) &&
        a.getDate().substr(0, 2) == b.getDate().substr(0, 2) &&
        a.getPriority() < b.getPriority())
      return true;

    return false;
  });
}
void Calendar::printCalendar()
{

  sortByDate(vTodayEvents);
  sortByDate(vEvents);

  system("date");
  line();

  cout << left << setw(15) << "Date" << setw(9) << "Time" << setw(10)
       << "Priority" << setw(6) << "Event\n";
  line();
  cout << "TODAY\n";
  for (auto i : vTodayEvents)
  {
    if (i.getPriority() == 1)
    {
      cout << "\033[31m" << left << setw(15) << i.getDate() << setw(9)
           << i.getTime() << setw(10) << i.getPriority() << setw(6)
           << i.getEvent() << "\033[0m\n";
    }
    if (i.getPriority() == 2)
    {
      cout << "\033[33m" << left << setw(15) << i.getDate() << setw(9)
           << i.getTime() << setw(10) << i.getPriority() << setw(6)
           << i.getEvent() << "\033[0m\n";
    }
    if (i.getPriority() == 3)
    {
      cout << "\033[32m" << left << setw(15) << i.getDate() << setw(9)
           << i.getTime() << setw(10) << i.getPriority() << setw(6)
           << i.getEvent() << "\033[0m\n";
    }
    if (i.getPriority() == 0)
    {
      cout << "\033[36m" << left << setw(15) << i.getDate() << setw(9)
           << i.getTime() << setw(10) << i.getPriority() << setw(6)
           << i.getEvent() << "\033[0m\n";
    }
  }
  line();

  for (auto i : vEvents)
  {
    if (i.getPriority() == 1)
    {
      cout << "\033[31m" << left << setw(15) << i.getDate() << setw(9)
           << i.getTime() << setw(10) << i.getPriority() << setw(6)
           << i.getEvent() << "\033[0m\n";
    }
    if (i.getPriority() == 2)
    {
      cout << "\033[33m" << left << setw(15) << i.getDate() << setw(9)
           << i.getTime() << setw(10) << i.getPriority() << setw(6)
           << i.getEvent() << "\033[0m\n";
    }
    if (i.getPriority() == 3)
    {
      cout << "\033[32m" << left << setw(15) << i.getDate() << setw(9)
           << i.getTime() << setw(10) << i.getPriority() << setw(6)
           << i.getEvent() << "\033[0m\n";
    }
    if (i.getPriority() == 0)
    {
      cout << "\033[36m" << left << setw(15) << i.getDate() << setw(9)
           << i.getTime() << setw(10) << i.getPriority() << setw(6)
           << i.getEvent() << "\033[0m\n";
    }
  }
  line();
  vEvents.clear();
  vTodayEvents.clear();
}

void Calendar::printSpecificeventMsg(shared_ptr<Event> e)
{
  cout << "\nEvent added\n";
  line();
  cout << left << setw(15) << "Date" << setw(9) << "Time" << setw(10)
       << "Priority" << setw(6) << "Event\n";
  line();

  if (e->getPriority() == 1)
  {
    cout << "\033[31m" << left << setw(15) << e->getDate() << setw(9)
         << e->getTime() << setw(10) << e->getPriority() << setw(6)
         << e->getEvent() << "\033[0m\n";
  }
  if (e->getPriority() == 2)
  {
    cout << "\033[33m" << left << setw(15) << e->getDate() << setw(9)
         << e->getTime() << setw(10) << e->getPriority() << setw(6)
         << e->getEvent() << "\033[0m\n";
  }
  if (e->getPriority() == 3)
  {
    cout << "\033[32m" << left << setw(15) << e->getDate() << setw(9)
         << e->getTime() << setw(10) << e->getPriority() << setw(6)
         << e->getEvent() << "\033[0m\n";
  }
  if (e->getPriority() == 0)
  {
    cout << "\033[36m" << left << setw(15) << e->getDate() << setw(9)
         << e->getTime() << setw(10) << e->getPriority() << setw(6)
         << e->getEvent() << "\033[0m\n";
  }

  line();
}
void Calendar::line()
{
  for (int i = 1; i < 35; i++)
    cout << "--";
  cout << "\n";
}

void Calendar::addCalendareventMsg(shared_ptr<Event> e)
{

  writeToCalendar("calendar", e);
}