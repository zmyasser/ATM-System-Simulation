#include <iostream>
#include <iomanip>
#include "clsQuickWithDrawScreen.h"


short clsQuickWithDrawScreen::_ReadQuickWithDrawScreenOption()
{
    std::cout << std::setw(37) << std::left << "";
    short Choice = clsInputValidate<short>::ReadNumberBetween(1, 9, "Choose what you want to do [1] --> [9]: ");
    return Choice;
}

short clsQuickWithDrawScreen::_getQuickWithDrawAmount(short QuickWithDrawOption)
{
    switch (QuickWithDrawOption)
    {
    case 1:
        return  20;
    case 2:
        return 50;
    case 3:
        return 100;
    case 4:
        return 200;
    case 5:
        return 400;
    case 6:
        return 600;
    case 7:
        return 800;
    case 8:
        return 1000;
    default:
        return 0;

    }

}

void clsQuickWithDrawScreen::_PerformQuickWithdrawOption(short QuickWithDrawOption)
{
    if (QuickWithDrawOption == 9)//exit 
        return;

    short WithDrawBalance = _getQuickWithDrawAmount(QuickWithDrawOption);

    if (WithDrawBalance > CurrentClient.getAccountBalance())
    {
        std::cout << "\nThe amount exceeds your balance!\n";
        std::cout << "\n\nPress Any key to continue...";
        system("pause>0");        
        return;
    }

    CurrentClient.Withdraw(WithDrawBalance);
    std::cout << "\nOperation has been completed successfully!\n";
    std::cout << "Your new balance is: " << CurrentClient.getAccountBalance() << std::endl;


    printf("\nPress any key to go back to ATM Menu Screen...\n");
    system("pause>0");
}


void clsQuickWithDrawScreen::ShowQuickWithdrawScreen()
{

    system("cls");
    _DrawScreenHeader("\t Quick WithDraw Screen", "");

    std::cout << std::setw(37) << std::left << "" << "===========================================\n";
    std::cout << std::setw(37) << std::left << "" << "\t\tQuick Withdraw\n";
    std::cout << std::setw(37) << std::left << "" << "===========================================\n";
    std::cout << std::setw(37) << std::left << "" << "\t[1] 20\t\t[2] 50\n";
    std::cout << std::setw(37) << std::left << "" << "\t[3] 100\t\t[4] 200\n";
    std::cout << std::setw(37) << std::left << "" << "\t[5] 400\t\t[6] 600\n";
    std::cout << std::setw(37) << std::left << "" << "\t[7] 800\t\t[8] 1000\n";
    std::cout << std::setw(37) << std::left << "" << "\t[9] Exit\n";
    std::cout << std::setw(37) << std::left << "" << "===========================================\n";
    std::cout << std::setw(37) << std::left << "" << "Your Balance is " << CurrentClient.getAccountBalance() << "\n";

    _PerformQuickWithdrawOption(_ReadQuickWithDrawScreenOption());
}

