#ifndef TASK2_ANYTYPE_H
#define TASK2_ANYTYPE_H

#include <string>
#include "AnyTypeExceptions.h"

const int NUMBER_OF_DATA_TYPES = 8 + 1;
const std::string DATA_TYPES_NAMES[NUMBER_OF_DATA_TYPES]{"bool", "int", "unsigned int", "long int", "float",
                                                         "double", "long double", "char", "none"};

class AnyType
{
private :
    union
    {
        bool bool_data;
        int int_data;
        unsigned int unsigned_int_data;
        long int long_int_data;
        float float_data;
        double double_data;
        long double long_double_data;
        char char_data;
    };

    enum DATA_TYPES
    {
        BOOL, INT, UNSIGNED_INT, LONG_INT, FLOAT, DOUBLE, LONG_DOUBLE, CHAR, NONE
    } data_type;

public:
    explicit AnyType(bool data);

    explicit AnyType(int data);

    explicit AnyType(unsigned int data);

    explicit AnyType(long int data);

    explicit AnyType(float data);

    explicit AnyType(double data);

    explicit AnyType(long double data);

    explicit AnyType(char data);

    AnyType(const AnyType &obj);


    void SetValue(bool data);

    void SetValue(int data);

    void SetValue(unsigned int data);

    void SetValue(long int data);

    void SetValue(float data);

    void SetValue(double data);

    void SetValue(long double data);

    void SetValue(char data);


    bool ToBool();

    int ToInt();

    unsigned int ToUnsignedInt();

    long int ToLongInt();

    float ToFloat();

    double ToDouble();

    long double ToLongDouble();

    char ToChar();


    void Destroy();

    void SwapWith(AnyType &other);

    const char *GetType();


    AnyType &operator=(bool data);

    AnyType &operator=(int data);

    AnyType &operator=(unsigned int data);

    AnyType &operator=(long int data);

    AnyType &operator=(float data);

    AnyType &operator=(double data);

    AnyType &operator=(long double data);

    AnyType &operator=(char data);
};


#endif //TASK2_ANYTYPE_H