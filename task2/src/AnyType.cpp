//
// Created by Mac on 05.01.2021.
//

#include "AnyType.h"

const int NUMBER_OF_DATA_TYPES = 9;
const char *DATA_TYPES_NAMES[NUMBER_OF_DATA_TYPES]{"bool", "int", "unsigned int", "long int", "float",
                                                   "double", "long double", "char", "none"};

AnyType::AnyType(bool data)
{
    bool_data = data;
    data_type = BOOL;
}

AnyType::AnyType(int data)
{
    int_data = data;
    data_type = INT;
}


AnyType::AnyType(double data)
{
    double_data = data;
    data_type = DOUBLE;
}

AnyType::AnyType(char data)
{
    char_data = data;
    data_type = CHAR;
}

AnyType::AnyType(unsigned int data)
{
    unsigned_int_data = data;
    data_type = UNSIGNED_INT;
}

AnyType::AnyType(long int data)
{
    long_int_data = data;
    data_type = LONG_INT;
}

AnyType::AnyType(float data)
{
    float_data = data;
    data_type = FLOAT;
}

AnyType::AnyType(long double data)
{
    long_double_data = data;
    data_type = LONG_DOUBLE;
}


void AnyType::SetValue(bool data)
{
    bool_data = data;
    data_type = BOOL;
}

void AnyType::SetValue(int data)
{
    int_data = data;
    data_type = INT;
}

void AnyType::SetValue(double data)
{
    double_data = data;
    data_type = DOUBLE;
}

void AnyType::SetValue(char data)
{
    char_data = data;
    data_type = CHAR;
}

void AnyType::SetValue(unsigned int data)
{
    unsigned_int_data = data;
    data_type = UNSIGNED_INT;
}

void AnyType::SetValue(long int data)
{
    long_int_data = data;
    data_type = LONG_INT;
}

void AnyType::SetValue(float data)
{
    float_data = data;
    data_type = FLOAT;
}

void AnyType::SetValue(long double data)
{
    long_double_data = data;
    data_type = LONG_DOUBLE;
}

bool AnyType::ToBool()
{
    CheckData(BOOL);
    return bool_data;
}


int AnyType::ToInt()
{
    CheckData(INT);
    return int_data;
}

double AnyType::ToDouble()
{
    CheckData(DOUBLE);
    return double_data;
}

char AnyType::ToChar()
{
    CheckData(CHAR);
    return char_data;
}


unsigned int AnyType::ToUnsignedInt()
{
    CheckData(UNSIGNED_INT);
    return unsigned_int_data;
}

long int AnyType::ToLongInt()
{
    CheckData(LONG_INT);
    return long_int_data;
}

float AnyType::ToFloat()
{
    CheckData(FLOAT);
    return float_data;
}

long double AnyType::ToLongDouble()
{
    CheckData(LONG_DOUBLE);
    return long_double_data;
}

void AnyType::Destroy()
{
    data_type = NONE;
}

void AnyType::SwapWith(AnyType &other)
{
    AnyType temp = *this;
    *this = other;
    other = temp;
}

const char *AnyType::GetType()
{
    return DATA_TYPES_NAMES[data_type];
}

AnyType &AnyType::operator=(const bool data)
{
    bool_data = data;
    data_type = BOOL;
    return *this;
}

AnyType &AnyType::operator=(const int data)
{
    int_data = data;
    data_type = INT;
    return *this;
}

AnyType &AnyType::operator=(const double data)
{
    double_data = data;
    data_type = DOUBLE;
    return *this;
}

AnyType &AnyType::operator=(const char data)
{
    char_data = data;
    data_type = CHAR;
    return *this;
}

AnyType &AnyType::operator=(unsigned int data)
{
    unsigned_int_data = data;
    data_type = UNSIGNED_INT;
    return *this;
}

AnyType &AnyType::operator=(long int data)
{
    long_int_data = data;
    data_type = LONG_INT;
    return *this;
}

AnyType &AnyType::operator=(float data)
{
    float_data = data;
    data_type = FLOAT;
    return *this;
}

AnyType &AnyType::operator=(long double data)
{
    long_double_data = data;
    data_type = LONG_DOUBLE;
    return *this;
}


void AnyType::CheckData(AnyType::DATA_TYPES expected)
{
    if (data_type == NONE)
    {
        throw AnyTypeException();
    }
    switch (expected)
    {
        case BOOL:
        {
            if (data_type != BOOL)
            {
                throw AnyTypeExceptionBool();
            }
            break;
        }
        case INT:
        {
            if (data_type != INT)
            {
                throw AnyTypeExceptionInt();
            }
            break;
        }
        case UNSIGNED_INT:
        {
            if (data_type != UNSIGNED_INT)
            {
                throw AnyTypeExceptionUnsignedInt();
            }
            break;
        }
        case LONG_INT:
        {
            if (data_type != LONG_INT)
            {
                throw AnyTypeExceptionLongInt();
            }
            break;

        }
        case FLOAT:
        {
            if (data_type != FLOAT)
            {
                throw AnyTypeExceptionFloat();
            }
            break;
        }
        case DOUBLE:
        {
            if (data_type != DOUBLE)
            {
                throw AnyTypeExceptionDouble();
            }
            break;
        }
        case LONG_DOUBLE:
        {
            if (data_type != LONG_DOUBLE)
            {
                throw AnyTypeExceptionLongDouble();
            }
            break;
        }
        case CHAR:
        {
            if (data_type != CHAR)
            {
                throw AnyTypeExceptionChar();
            }
            break;

        }
        default:
        {
            throw AnyTypeException();
        }
    }
}


