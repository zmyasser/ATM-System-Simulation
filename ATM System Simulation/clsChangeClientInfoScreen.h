#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsChangeClientInfoScreen : protected clsScreen
{

private:

    enum enPersonalInfo { enPinCode = 1, enPhone = 2, enEmail = 3, enBackToATMMenu = 4 };

    static short _ReadClientChoice();
    
    static void _PerformChangePersonalOperationOption(enPersonalInfo PersonalInfo);
    
public:

    static void ShowChangePersonalInfoScreen();
   
};