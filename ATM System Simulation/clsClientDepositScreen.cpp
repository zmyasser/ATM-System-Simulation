#include "clsClientDepositScreen.h"

void clsClientDepositScreen::_PerformDepositOption()
{

    double DepositAmount = clsInputValidate<double>::ReadNumber("\nPlease, enter Deposit Amount: ");

    if (CurrentClient.Deposit(DepositAmount))
    {
        printf("\nOperation has been completed successfully!\n");
    }

    else
    {
        printf("\nSomething went wrong, please try again!");
    }

    std::cout << "Your new balance is: " << CurrentClient.getAccountBalance() << std::endl;

}

void clsClientDepositScreen::ShowClientDepositScreen()
{
    _DrawScreenHeader("\tClient Deposit Screen", "");
    _PerformDepositOption();

    printf("\nPress any key to go back to ATM Menu Screen...\n");
    system("pause>0");
}
