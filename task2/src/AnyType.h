#ifndef TASK2_ANYTYPE_H
#define TASK2_ANYTYPE_H

#include <string>
#include "AnyTypeExceptions.h"
#include <iostream>

/*Class, that contains variable of types BOOL, INT, UNSIGNED_INT, LONG_INT, FLOAT, DOUBLE, LONG_DOUBLE, CHAR */
class AnyType
{
public:
    // Constructors
    explicit AnyType(bool data);

    explicit AnyType(int data);

    explicit AnyType(unsigned int data);

    explicit AnyType(long int data);

    explicit AnyType(float data);

    explicit AnyType(double data);

    explicit AnyType(long double data);

    explicit AnyType(char data);

    //Copy constructor
    AnyType(const AnyType &obj) = default;

    //Setters
    void SetValue(bool data);

    void SetValue(int data);

    void SetValue(unsigned int data);

    void SetValue(long int data);

    void SetValue(float data);

    void SetValue(double data);

    void SetValue(long double data);

    void SetValue(char data);


    // return data, throw AnyTypeException in case of wrong type
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

    //return name of the type of variable in class
    const char *GetType();

    AnyType &operator=(bool data);

    AnyType &operator=(int data);

    AnyType &operator=(unsigned int data);

    AnyType &operator=(long int data);

    AnyType &operator=(float data);

    AnyType &operator=(double data);

    AnyType &operator=(long double data);

    AnyType &operator=(char data);


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

    void CheckData(DATA_TYPES expected);

};


#endif //TASK2_ANYTYPE_H
