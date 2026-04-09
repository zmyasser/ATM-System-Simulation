#include "clsNormalWithDrawScreen.h"

void clsNormalWithDrawScreen::_PerformNormalWithdrawOption()
{

    
    double WithDrawAmount = clsInputValidate<double>::ReadNumber("\nPlease, enter WithDraw Amount: ");

    if (WithDrawAmount > CurrentClient.getAccountBalance())
    {
        std::cout << "\nThe amount exceeds your balance!\n";
        return;
    }

    if (CurrentClient.Withdraw(WithDrawAmount))
    {
        printf("\nOperation has been completed successfully!\n");
    }

    else
    {
        printf("\nSomething went wrong, please try again!");
    }

    std::cout << "Your new balance is: " << CurrentClient.getAccountBalance() << std::endl;
}

void clsNormalWithDrawScreen::ShowNormalWithDrawScreen()
{

    _DrawScreenHeader("\tNormal WithDrawScreen", "");
    _PerformNormalWithdrawOption();

    printf("\nPress any key to go back to ATM Menu Screen...\n");
    system("pause>0");
}