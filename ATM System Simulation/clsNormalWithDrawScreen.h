#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrentClient.h"


class clsNormalWithDrawScreen : protected clsScreen
{

private:

    static void _PerformNormalWithdrawOption();

public:

    static void ShowNormalWithDrawScreen();
    
};
