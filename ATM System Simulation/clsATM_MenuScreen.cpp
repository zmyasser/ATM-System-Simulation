
#pragma once
#include "clsATM_MenuScreen.h"
#include "clsQuickWithDrawScreen.h"
#include "clsNormalWithDrawScreen.h"
#include "clsClientDepositScreen.h"
#include "clsCheckBalanceScreen.h"
#include "clsChangeClientInfoScreen.h"


 short clsATM_MenuScreen::_ReadClientMenuOption()
 {
     std::cout << std::setw(37) << std::left << "";
     short Choice = clsInputValidate<short>::ReadNumberBetween(1, 6, "Choose what you want to do [1] --> [6]:");
     return Choice;
 }

 void clsATM_MenuScreen::_ShowQuickWithDrawScreen()
 {
     clsQuickWithDrawScreen::ShowQuickWithdrawScreen();
 }

 void clsATM_MenuScreen::_ShowNormalWithDrawScreen()
 {
     clsNormalWithDrawScreen::ShowNormalWithDrawScreen();
 }

 void clsATM_MenuScreen::_ShowDepositScreen()
 {
     clsClientDepositScreen::ShowClientDepositScreen();
 }

 void clsATM_MenuScreen::_ShowCheckBalanceScreen()
 {
     clsCheckBalanceScreen::ShowCheckClientBalanceScreen();
 }

 void clsATM_MenuScreen::_ShowChangePersonalInfoScreen()
 {
     clsChangeClientInfoScreen::ShowChangePersonalInfoScreen();
 }

 void clsATM_MenuScreen::_LogOut()
 {
     CurrentClient = clsBankClient::Find("", "");
 }


 void clsATM_MenuScreen::_PerformClientMainMenuOption(enClientMainMenuScreenOptions MainMenuOption)
 {
     switch (MainMenuOption)
     {
     case enClientMainMenuScreenOptions::enQuickWithdraw:
     {
         system("cls");
         _ShowQuickWithDrawScreen();
         break;
     }
     case enClientMainMenuScreenOptions::enNormalWithDraw:
         system("cls");
         _ShowNormalWithDrawScreen();
         break;

     case enClientMainMenuScreenOptions::enDeposit:
         system("cls");
         _ShowDepositScreen();
         break;

     case enClientMainMenuScreenOptions::enCheckBalance:
         system("cls");
         _ShowCheckBalanceScreen();
         break;

     case enClientMainMenuScreenOptions::enChangePersonalInfo:
         system("cls");
         _ShowChangePersonalInfoScreen();
         break;

     }
 }

 void clsATM_MenuScreen::ShowClientMainMenu()
 {

     while (true)
     {
         system("cls");
         _DrawScreenHeader("\tATM Main Menu Screen", "");

         std::cout << std::setw(37) << std::left << "" << "===========================================\n";
         std::cout << std::setw(37) << std::left << "" << "\t\tATM Main Menu Screen\n";
         std::cout << std::setw(37) << std::left << "" << "===========================================\n";
         std::cout << std::setw(37) << std::left << "" << "\t[1] Quick Withdraw.\n";
         std::cout << std::setw(37) << std::left << "" << "\t[2] Normal Withdraw.\n";
         std::cout << std::setw(37) << std::left << "" << "\t[3] Deposit\n";
         std::cout << std::setw(37) << std::left << "" << "\t[4] Check Balance.\n";
         std::cout << std::setw(37) << std::left << "" << "\t[5] Change Personal Info\n";
         std::cout << std::setw(37) << std::left << "" << "\t[6] Logout.\n";
         std::cout << std::setw(37) << std::left << "" << "===========================================\n";

         enClientMainMenuScreenOptions option = (enClientMainMenuScreenOptions)_ReadClientMenuOption();

         if (option == enExit)
         {
             _LogOut();
             break;
         }

         _PerformClientMainMenuOption(option);
     }
 }




