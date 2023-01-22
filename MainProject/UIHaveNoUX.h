#ifndef UIHAVENOUX_H
#define UIHAVENOUX_H
#pragma once

#include <iomanip>
#include "HandleMiscellaneous.h"
#include "HandleMain.h"

void formLogin(string & strUsername, string & strPassword);
char chooseAdminOrEmployee();
void loginAdmin(string & strUsername, string & strPassword);
void loginEmployees(string & strUsername, string & strPassword, int iMaxLogin);
void showAnEmployeeInfoElement(color textColor, string strUsername, string strFullName, string strAddress, string strPhoneNumber, string strEmailAddress,
	string endType, char fillType = ' ');
char menuAdmin();
char menuEmployee();
char menuUpdateInfo();

#endif
