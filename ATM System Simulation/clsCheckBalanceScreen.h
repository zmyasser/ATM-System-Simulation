#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrentClient.h"

class clsCheckBalanceScreen : protected clsScreen
{

private:

	static void _CheckClientBalance();
	
public:

	static void ShowCheckClientBalanceScreen();
	
};


