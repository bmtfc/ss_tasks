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
    Z = X;
    try
    {
        std::cout << std::boolalpha << X.ToBool() << '\n';
        std::cout << X.ToDouble();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
    X = 't';
    std::cout << Y.GetType() << '\n';
    try
    {
        std::cout << Z.ToChar();
    }
    catch (AnyTypeException &e)
    {
        std::cout << e.what();
    }

    return 0;
}
