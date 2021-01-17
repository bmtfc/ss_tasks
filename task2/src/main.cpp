#include <iostream>
#include "AnyType.h"

using namespace std;

int main()
{
    AnyType x(2);
    cout << "Creating AnyType variable with type \"int\" and value 2\n";
    cout << "X - value : " << x.ToInt() << ", type : " << x.GetType() << "\n\n";
    cout << "Trying to cast to \"double\"\n";
    try
    {
        x.ToDouble();
    }
    catch (const AnyTypeException &e)
    {
        cout << e.what() << '\n';
    }

    AnyType y(true);
    x.SwapWith(y);
    cout << "Creating AnyType variable with type \"bool\" and value true\n";
    cout << "Using \"swap\" method\n";
    cout << "X - value : " << boolalpha << x.ToBool() << ", type : " << x.GetType() << '\n';
    cout << "Y - value : " << y.ToInt() << ", type : " << y.GetType() << "\n\n";
    cout << "Using destroy method \n";
    x.Destroy();
    cout << "Type of variable after destroying : " << x.GetType() << '\n';

    return 0;
}
