#include "clsChangeClientEmailScreen.h"

std::string clsChangeClientEmailScreen::_ReadNewEmail()
{
	std::string NewEmail;

	printf("Enter a new Email: ");
	std::cin >> NewEmail;

	return NewEmail;
}

void clsChangeClientEmailScreen::ShowChangeClientEmailScreen()
{

	_DrawScreenHeader("Change Client Email Screen", "");

	std::string NewEmail = _ReadNewEmail();

	if (CurrentClient.ChangeClientEmail(NewEmail))
	{
		printf("\nYour Email has been UpDated Successfully");
	}

	else
	{
		printf("\nSomething went wrong, please try again!");
	}

	printf("\n\nPress any key to go back to change client info screen...\n");
	system("pause>0");
}