#pragma once
#include "iostream"
#include "clsScreen.h"
#include "clsCurrentClient.h"


class clsChangeClientPhoneScreen : protected clsScreen
{

private:

	static std::string _ReadNewPhone();
	
public:

	static void ShowChangeClientPhoneScreen();
	
};
