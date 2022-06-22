 /*******************\
*  Created by Xorka   *
 \*******************/

#include <windows.h>
#include <iostream>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void asii_logo()
{
    std::cout << "	 .o88b.  .d8b.  db       .o88b. db    db db       .d8b.  d888888b  .d88b.  d8888b.	" << "\n";
    std::cout << "	d8P  Y8 d8' `8b 88      d8P  Y8 88    88 88      d8' `8b `~~88~~' .8P  Y8. 88  `8D	" << "\n";
    std::cout << "	8P      88ooo88 88      8P      88    88 88      88ooo88    88    88    88 88oobY'	" << "\n";
    std::cout << "	8b      88~~~88 88      8b      88    88 88      88~~~88    88    88    88 88`8b	" << "\n";
    std::cout << "	Y8b  d8 88   88 88booo. Y8b  d8 88b  d88 88booo. 88   88    88    `8b  d8' 88 `88.	" << "\n";
    std::cout << "	 `Y88P' YP   YP Y88888P  `Y88P' ~Y8888P' Y88888P YP   YP    YP     `Y88P'  88   YD	" << "\n" << "\n";
}

float number()
{
    int res = 0;
    for (;;)
    {
        char c = std::cin.get();
        if (c >= '0' && c <= '9')
            res = res * 10 + c - '0';
        else
        {
            std::cin.putback(c);
            return res;
        }
    }
}

float expr();

float skobki()
{
    char c = std::cin.get();
    if (c == '(')
    {
        float x = expr();
        std::cin.get();
        return x;
    }
    else
    {
        std::cin.putback(c);
        return number();
    }
}

float factor()
{
    float x = skobki();
    for (;;)
    {
        char c = std::cin.get();
        switch (c)
        {
        case '*':
            x *= skobki();
            break;
        case '/':
            x /= skobki();
            break;
        default:
            std::cin.putback(c);
            return x;
        }
    }
}

float expr()
{
    float x = factor();
    for (;;)
    {
        char c = std::cin.get();
        switch (c)
        {
        case '+':
            x += factor();
            break;
        case '-':
            x -= factor();
            break;
        default:
            std::cin.putback(c);
            return x;
        }
    }
}


int main()
{
    SetConsoleTextAttribute(hConsole, 9);
    asii_logo();

    SetConsoleTextAttribute(hConsole, 3);
    std::cout << "  Enter expression => ";
    float res = expr();
    std::cout << "  Expression answer =>  " << res << std::endl;
}