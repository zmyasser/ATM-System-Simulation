
#include <iostream>
#include "clsScreen.h"
#include "clsDate.h"
#include "clsCurrentClient.h"

void clsScreen::_DrawScreenHeader(const std::string& Title, const std::string& SubTitle)
{
    std::cout << "\t\t\t\t\t______________________________________";
    std::cout << "\n\n\t\t\t\t\t  " << Title;
    if (SubTitle != "")
    {
        std::cout << "\n\t\t\t\t\t  " << SubTitle;
    }
    std::cout << "\n\t\t\t\t\t______________________________________\n\n";

    std::cout << "\n\t\t\t\t\tClient: " << CurrentClient.getFullName() << "\n";
    std::cout << "\t\t\t\t\tDate: " << clsDate::DateToString(clsDate()) << "\n\n";
}