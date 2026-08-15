#include <iostream>
#include "LoginScreen.h"

using namespace std;


int main()
{
 
    while (true)
    {
        if (!LoginScreen::ShowLoginScreen())
        {
            break;
        }

    }


    return 0;
}

