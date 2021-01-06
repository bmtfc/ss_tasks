//
// Created by Mac on 05.01.2021.
//

#include "AnyType.h"

AnyType::AnyType(bool data)
{
    bool_data = data;
    data_type = DATA_TYPES[0];
}

AnyType::AnyType(int data)
{
    int_data = data;
    data_type = DATA_TYPES[1];
}


AnyType::AnyType(double data)
{
    double_data = data;
    data_type = DATA_TYPES[2];
}

AnyType::AnyType(char data)
{
    char_data = data;
    data_type = DATA_TYPES[3];
}

AnyType::AnyType(const AnyType &obj)
{
    data_type = obj.data_type;
    if (data_type == DATA_TYPES[0])
    { bool_data = obj.bool_data; }
    if (data_type == DATA_TYPES[1])
    { int_data = obj.int_data; }
    if (data_type == DATA_TYPES[2])
    { double_data = obj.double_data; }
    if (data_type == DATA_TYPES[3])
    { char_data = obj.char_data; }
}


void AnyType::SetValue(bool data)
{
    bool_data = data;
    data_type = DATA_TYPES[0];
}

void AnyType::SetValue(int data)
{
    int_data = data;
    data_type = DATA_TYPES[1];
}

void AnyType::SetValue(double data)
{
    double_data = data;
    data_type = DATA_TYPES[2];
}

void AnyType::SetValue(char data)
{
    char_data = data;
    data_type = DATA_TYPES[3];
}

bool AnyType::ToBool()
{
    if (data_type == DATA_TYPES[0])
    {
        return bool_data;
    } else
    {
        throw (AnyTypeExceptionBool());
    }
}


int AnyType::ToInt()
{
    if (data_type == DATA_TYPES[1])
    {
        return int_data;
    } else
    {
        throw (AnyTypeExceptionInt());
    }
}

double AnyType::ToDouble()
{
    if (data_type == DATA_TYPES[2])
    {
        return double_data;
    } else
    {
        throw (AnyTypeExceptionDouble());
    }
}

char AnyType::ToChar()
{
    if (data_type == DATA_TYPES[3])
    {
        return char_data;
    } else
    {
        throw (AnyTypeExceptionChar());
    }
}

void AnyType::Destroy()
{
    if (data_type == DATA_TYPES[0])
    { bool_data = false; }
    if (data_type == DATA_TYPES[1])
    { int_data = 0; }
    if (data_type == DATA_TYPES[2])
    { double_data = 0.0; }
    if (data_type == DATA_TYPES[3])
    { char_data = '\0'; }
    data_type.clear();
}

void AnyType::SwapWith(AnyType &other)
{
    AnyType temp = *this;
    *this = other;
    other = temp;
}

const char *AnyType::GetType()
{
    return data_type.data();
}

AnyType &AnyType::operator=(const bool data)
{
    bool_data = data;
    data_type = DATA_TYPES[0];
    return *this;
}

AnyType &AnyType::operator=(const int data)
{
    int_data = data;
    data_type = DATA_TYPES[1];
    return *this;
}

AnyType &AnyType::operator=(const double data)
{
    double_data = data;
    data_type = DATA_TYPES[2];
    return *this;
}

AnyType &AnyType::operator=(const char data)
{
    char_data = data;
    data_type = DATA_TYPES[3];
    return *this;
}

