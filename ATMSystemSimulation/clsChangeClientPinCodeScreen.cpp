#include "clsChangeClientPinCodeScreen.h"

std::string clsChangeClientPinCodeScreen::_ReadNewPinCode()
{
	std::string NewPinCode;
	std::string ConfirmPinCode;

	printf("Enter a new PinCode: ");
	std::cin >> NewPinCode;

	printf("Confirm your PinCode: ");
	std::cin >> ConfirmPinCode;

	while (NewPinCode != ConfirmPinCode)
	{
		printf("\nWrong PinCode, please try again\n");

		printf("Enter a new PinCode: ");
		std::cin >> NewPinCode;

		printf("Confirm your PinCode: ");
		std::cin >> ConfirmPinCode;
	}

	return NewPinCode;
}

void clsChangeClientPinCodeScreen::ShowChangeClientPinCodeScreen()
{

	_DrawScreenHeader("Change Client PinCode Screen", "");

	std::string NewPin = _ReadNewPinCode();

	if (CurrentClient.ChangeClientPinCode(NewPin))
	{
		printf("\nYour PinCode has been UpDated Successfully!");
	}

	else
	{
		printf("\nSomething went wrong, please try again!");
	}


	printf("\n\nPress any key to go back to change client info screen...\n");
	system("pause>0");
}