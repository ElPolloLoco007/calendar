// HT17 DT060G Datateknik GR (B), Objektorienterad programmering i C++
// Lab 2 � Bank System
// 12-09-2017
// Helgi Poulsen
// Ver 1.0
//----------------------------------------------



#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <iomanip>
#include <string>		
#include <vector>
using namespace std;

//------------------------------------------------------------------------------
// Class Defenition
//------------------------------------------------------------------------------
class Menu
{
private:
	
	vector <Menu> Vmain;		
	string menutext;
	int menuOption;
	bool enabled;				
	

public:

	Menu();							//Default constructor
	Menu(string x, bool option);    //initiating data members

	//set function
	void setEnabled(bool t);

	//get functions
	string getMenuText() const;
	bool getEnabled() const;	
	
	bool menuCheck(int x);						   //Checking the menu switch
	void printMenu();							   //Printing menu
	void addItem(string menutext, bool enabled);   //adding Items to Vmain	
	void turnOnMenu();							   //Turning on menu items	
	int doMenuOption();
	int getMenuOption();

};

#endif
