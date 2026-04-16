#pragma once
#include "iostream"
#include "clsScreen.h"
#include "clsCurrentClient.h"

class clsChangeClientEmailScreen : protected clsScreen
{

private:

	static std::string _ReadNewEmail();
	
public:

	static void ShowChangeClientEmailScreen();
};
