#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrentClient.h"
#include "clsLoginApproved.h"
#include "clsATM_MenuScreen.h"

class clsLoginScreen : clsScreen
{
private:
    static void _Login();

public:

    static void ShowClientLoginScreen();
    
};

