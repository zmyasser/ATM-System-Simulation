#pragma once
#include "iostream"
#include "clsScreen.h"
#include "clsCurrentClient.h"

class clsChangeClientPinCodeScreen : protected clsScreen
{

private:

	static std::string _ReadNewPinCode();
	
public:
	
	static void ShowChangeClientPinCodeScreen();
	
};
