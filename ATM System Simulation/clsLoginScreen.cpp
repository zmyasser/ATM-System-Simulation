#include <iostream>
#include "clsLoginScreen.h"

void clsLoginScreen::_Login()
{
    bool LoginFailed = false;
    std::string AccountNumber, PinCode;
    short counter = 3;

    do
    {
        system("cls");
        _DrawScreenHeader("\t  Client Login Screen.", "");

        if (LoginFailed)
        {
            std::cout << "\nInvalid Account Number/PinCode!\n";

            counter--;
            if (counter == 0)
            {
                std::cout << "\nSystem Locked, Try again later\n";
                CurrentClient = clsBankClient::Find("", "");
                LoginApproved = false;
                break;
            }

            std::cout << "You have " << counter << " attempts left!\n";
        }

        std::cout << "\nEnter Account Number: ";
        std::cin >> AccountNumber;

        std::cout << "Enter Pin: ";
        std::cin >> PinCode;

        CurrentClient = clsBankClient::Find(AccountNumber, PinCode);
        LoginFailed = CurrentClient.isEmpty();
        LoginApproved = !LoginFailed;

    } while (LoginFailed);

    if (LoginApproved)
    {
        CurrentClient.RegisterClientLoginInFile();
        clsATM_MenuScreen::ShowClientMainMenu();
    }
}


void clsLoginScreen::ShowClientLoginScreen()
{
    _Login();
}