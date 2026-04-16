
#include <iostream>
#include "clsLoginApproved.h"
#include "clsLoginScreen.h"

int main()
{
    
    while (LoginApproved)
    {
        clsLoginScreen::ShowClientLoginScreen();
    }

    return 0;
}

