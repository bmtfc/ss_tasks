//
// Created by Mac on 05.01.2021.
//

#include "AnyType.h"

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

AnyType::AnyType(const AnyType &obj)
{
    data_type = obj.data_type;
    if (data_type == BOOL)
    { bool_data = obj.bool_data; }
    if (data_type == INT)
    { int_data = obj.int_data; }
    if (data_type == DOUBLE)
    { double_data = obj.double_data; }
    if (data_type == CHAR)
    { char_data = obj.char_data; }
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

bool AnyType::ToBool()
{
    if (data_type == BOOL)
    {
        return bool_data;
    } else
    {
        throw (AnyTypeExceptionBool());
    }
}


int AnyType::ToInt()
{
    if (data_type == INT)
    {
        return int_data;
    } else
    {
        throw (AnyTypeExceptionInt());
    }
}

double AnyType::ToDouble()
{
    if (data_type == DOUBLE)
    {
        return double_data;
    } else
    {
        throw (AnyTypeExceptionDouble());
    }
}

char AnyType::ToChar()
{
    if (data_type == CHAR)
    {
        return char_data;
    } else
    {
        throw (AnyTypeExceptionChar());
    }
}

void AnyType::Destroy()
{
    if (data_type == BOOL)
    { bool_data = false; }
    if (data_type == INT)
    { int_data = 0; }
    if (data_type == DOUBLE)
    { double_data = 0.0; }
    if (data_type == CHAR)
    { char_data = '\0'; }
}

void AnyType::SwapWith(AnyType &other)
{
    AnyType temp = *this;
    *this = other;
    other = temp;
}

const char *AnyType::GetType()
{
    return DATA_TYPES_NAMES[data_type].data();
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

