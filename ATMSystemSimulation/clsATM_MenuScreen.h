#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"



class clsATM_MenuScreen : protected clsScreen
{

private:

    enum enClientMainMenuScreenOptions { enQuickWithdraw = 1, enNormalWithDraw = 2, enDeposit = 3, enCheckBalance = 4, enChangePersonalInfo = 5, enExit = 6 };

    static short _ReadClientMenuOption();
   
    static void _ShowQuickWithDrawScreen();
   
    static void _ShowNormalWithDrawScreen();
   
    static void _ShowDepositScreen();
    
    static void _ShowCheckBalanceScreen();
    
    static void _ShowChangePersonalInfoScreen();
    
    static void _LogOut();
    
    static void _PerformClientMainMenuOption(enClientMainMenuScreenOptions MainMenuOption);
    

public:

    static void ShowClientMainMenu();
    
};

