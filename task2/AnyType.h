#ifndef TASK2_ANYTYPE_H
#define TASK2_ANYTYPE_H

#include <string>
#include "AnyTypeExceptions.h"

const int NUMBER_OF_DATA_TYPES = 4;
const std::string DATA_TYPES_NAMES[NUMBER_OF_DATA_TYPES]{"bool", "int", "double", "char"};
enum DATA_TYPES
{
    BOOL = 0, INT = 1, DOUBLE = 2, CHAR = 3
};

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

    DATA_TYPES data_type;

public:
    explicit AnyType(bool data);

    explicit AnyType(int data);

    explicit AnyType(double data);

    explicit AnyType(char data);

    AnyType(const AnyType &obj);


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

    AnyType &operator=(bool data);

    AnyType &operator=(int data);

    AnyType &operator=(double data);

    AnyType &operator=(char data);

};


#endif //TASK2_ANYTYPE_H
