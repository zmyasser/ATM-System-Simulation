#include "clsCheckBalanceScreen.h"

void clsCheckBalanceScreen::_CheckClientBalance()
{
	std::cout << "_______________________________________________________\n";
	std::cout << "-------------------------------------------------------\n";

	std::cout << "\nYour Balance is: " << CurrentClient.getAccountBalance() << std::endl;

	std::cout << "_______________________________________________________\n";
	std::cout << "-------------------------------------------------------\n";
}

void clsCheckBalanceScreen::ShowCheckClientBalanceScreen()
{
	_DrawScreenHeader("\t Client Balance Screen", "");
	_CheckClientBalance();

	printf("\nPress any key to go back to ATM Menu Screen...\n");
	system("pause>0");
}
