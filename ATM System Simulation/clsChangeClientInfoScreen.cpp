#include "clsChangeClientInfoScreen.h"
#include "clsChangeClientPinCodeScreen.h"
#include "clsChangeClientPhoneScreen.h"
#include "clsChangeClientEmailScreen.h"

short clsChangeClientInfoScreen::_ReadClientChoice()
{
    std::cout << std::setw(37) << std::left << "";
    short Choice = clsInputValidate<short>::ReadNumberBetween(1, 4, "Choose what you want to do [1] --> [4]: ");
    return Choice;
}

void clsChangeClientInfoScreen::_PerformChangePersonalOperationOption(enPersonalInfo PersonalInfo)
{

    switch (PersonalInfo)
    {
    case enPersonalInfo::enPinCode:
    {
        system("cls");
        clsChangeClientPinCodeScreen::ShowChangeClientPinCodeScreen();
        break;
    }

    case enPersonalInfo::enPhone:
    {
        system("cls");
        clsChangeClientPhoneScreen::ShowChangeClientPhoneScreen();
        break;
    }

    case enPersonalInfo::enEmail:
    {
        system("cls");
        clsChangeClientEmailScreen::ShowChangeClientEmailScreen();
        break;
    }

    }
}




void clsChangeClientInfoScreen::ShowChangePersonalInfoScreen()
{
    while (true)
    {
        system("cls");
        _DrawScreenHeader("\t Change Personal Info Screen", "");

        std::cout << std::setw(37) << std::left << "" << "===========================================\n";
        std::cout << std::setw(37) << std::left << "" << "\t\tPersonal Info\n";
        std::cout << std::setw(37) << std::left << "" << "===========================================\n";

        std::cout << std::setw(37) << std::left << "" << "[1] Change Your PinCode.\n";
        std::cout << std::setw(37) << std::left << "" << "[2] Change Your Phone.\n";
        std::cout << std::setw(37) << std::left << "" << "[3] Change Your Email.\n";
        std::cout << std::setw(37) << std::left << "" << "[4] Go Back To ATM Main Menu.\n";

        std::cout << std::setw(37) << std::left << "" << "===========================================\n";

        enPersonalInfo option = (enPersonalInfo)_ReadClientChoice();

        if (option == enBackToATMMenu)
        {
            break;
        }

        _PerformChangePersonalOperationOption(option);
  
    }
}