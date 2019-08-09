// HT17 DT060G Datateknik GR (B), Objektorienterad programmering i C++
// Lab 2 � Bank System
// 12-09-2017
// Helgi Poulsen
// Ver 1.0
//----------------------------------------------

//-------------------------------------------------------
// included headers
#include "Menu.h"
//-------------------------------------------------------

//------------------------------------------------------------------------------
// Defult constructor
//------------------------------------------------------------------------------
Menu::Menu() {
  menutext = "";
  enabled = true;
}

//------------------------------------------------------------------------------
// Constrcutor for initiating data member
//------------------------------------------------------------------------------
Menu::Menu(string x, bool option) {
  menutext = x;
  enabled = option;
}

//------------------------------------------------------------------------------
// Adding Items to the vector Vmain
// Job: to add all the additems into the vector Vmain.
// Dosent matter if bool is true or false
//------------------------------------------------------------------------------
void Menu::addItem(string menutext, bool enabled) {
  Vmain.push_back(Menu(menutext, enabled));
}

//------------------------------------------------------------------------------
// Turn on menu
// Job: To turn on all the menu items that are set to false in the vector
//------------------------------------------------------------------------------
void Menu::turnOnMenu() {
  // going through the vector and activating the menuitems
  for (auto &idx : Vmain)
    idx.setEnabled(true);
}

bool Menu::menuCheck(int x) { return Vmain[x].getEnabled(); }

//------------------------------------------------------------------------------
// Set functions
//------------------------------------------------------------------------------
void Menu::setEnabled(bool t) { enabled = t; }

//------------------------------------------------------------------------------
// Get functions
//------------------------------------------------------------------------------
bool Menu::getEnabled() const { return enabled; }

string Menu::getMenuText() const { return menutext; }

int Menu::getMenuOption() { return menuOption; };

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Printing menu items
// Job: To print all the menu items that have the bool set to true
// Other words. Printing all the enabled menuitems that are in the vector Vmain
//------------------------------------------------------------------------------
void Menu::printMenu() {
  // counter
  int i = 0;

  // going through the vector
  for (auto e : Vmain) {
    i++;

    if (e.getEnabled() == true) {
      // output 1. 2. etc and menutext from Vmain to screen
      cout << i << ". " << e.getMenuText() << endl;
    }
  }
}

int Menu::doMenuOption() {
  cout << endl << "Make your option:";
  int option;
  // checking if its a integer that is pressed, and removing the wrongfully
  // letter
  while (!(cin >> option)) {
    cin.clear();
    while (cin.get() != '\n')
      continue;

    // reporting that the user has used wrong input
    cout << "Invalid number!" << endl;
    cout << "Please enter a valid number from the list:";
  }
  // setting menuchoice to x
  ;
  menuOption = option;
  return menuOption;
  cout << "----------------------" << endl;
}