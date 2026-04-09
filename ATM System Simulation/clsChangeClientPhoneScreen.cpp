#include "clsChangeClientPhoneScreen.h"

std::string clsChangeClientPhoneScreen::_ReadNewPhone()
{
	std::string NewPhone;
	std::string ConfirmPhone;

	printf("Enter a new Phone Number: ");
	std::cin >> NewPhone;

	printf("Confirm your Phone Number: ");
	std::cin >> ConfirmPhone;

	while (NewPhone != ConfirmPhone)
	{
		printf("\nWrong PinCode, please try again\n");

		printf("Enter a new Phone Number: ");
		std::cin >> NewPhone;

		printf("Confirm your Phone Number: ");
		std::cin >> ConfirmPhone;
	}

	return NewPhone;
}

void clsChangeClientPhoneScreen::ShowChangeClientPhoneScreen()
{

	_DrawScreenHeader("Change Client Phone Screen", "");


	std::string NewPhone = _ReadNewPhone();

	if (CurrentClient.ChangeClientPhone(NewPhone))
	{
		printf("\nYour Phone has been UpDated Successfully!");
	}

	else
	{
		printf("\nSomething went wrong, please try again!");
	}


	printf("\n\nPress any key to go back to change client info screen...\n");
	system("pause>0");
}
