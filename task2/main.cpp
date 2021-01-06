#include <iostream>
#include "AnyType.h"

int main()
{
    AnyType X(7.98);
    AnyType Y(false);
    AnyType Z(X);
    Y = true;
    //X.SwapWith(Y);
    Z.SwapWith(Y);
    try
    {
        std::cout << std::boolalpha << X.ToBool() << '\n';
        std::cout << X.ToDouble();
    }
    catch (AnyTypeException &e)
    {
        std::cout << e.what();
    }
    X = 't';
    std::cout << Y.GetType() << '\n';
    try
    {
        std::cout << X.ToChar();
    }
    catch (AnyTypeException &e)
    {
        std::cout << e.what();
    }

    return 0;
}
