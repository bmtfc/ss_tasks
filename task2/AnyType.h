#ifndef TASK2_ANYTYPE_H
#define TASK2_ANYTYPE_H

#include <string>
#include "AnyTypeExceptions.h"

const int NUMBER_OF_DATA_TYPES = 4;
const std::string DATA_TYPES[NUMBER_OF_DATA_TYPES]{"bool", "int", "double", "char"};

class AnyType
{
private :
    union
    {
        bool bool_data;
        int int_data;
        double double_data;
        char char_data;
    };

    std::string data_type;

public:
    explicit AnyType(bool data);

    explicit AnyType(int data);

    explicit AnyType(double data);

    explicit AnyType(char data);


    void SetValue(bool data);

    void SetValue(int data);

    void SetValue(double data);

    void SetValue(char data);


    bool ToBool();

    int ToInt();

    double ToDouble();

    char ToChar();


    void Destroy();

    void SwapWith(AnyType &other);

    const char *GetType();

};


#endif //TASK2_ANYTYPE_H
