#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrentClient.h"


class clsClientDepositScreen : protected clsScreen
{

private:

    static void _PerformDepositOption();
    
public:

    static void ShowClientDepositScreen();
  
};
