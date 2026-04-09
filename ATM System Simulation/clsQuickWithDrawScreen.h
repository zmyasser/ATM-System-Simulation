#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsCurrentClient.h"

class clsQuickWithDrawScreen : protected clsScreen
{

private:

    static short _ReadQuickWithDrawScreenOption();
    
    static short _getQuickWithDrawAmount(short QuickWithDrawOption);
   
    static void _PerformQuickWithdrawOption(short QuickWithDrawOption);
    

public:

    static void ShowQuickWithdrawScreen();
    
};