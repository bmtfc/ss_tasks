//
// Created by Mac on 05.01.2021.
//

#include "AnyTypeExceptions.h"

const char *AnyTypeException::what() const throw()
{
    return "Type Error\n";
}

const char *AnyTypeExceptionBool::what() const throw()
{
    return "Type should be \"Bool\"\n";
}

const char *AnyTypeExceptionInt::what() const throw()
{
    return "Type should be \"Int\"\n";
}

const char *AnyTypeExceptionDouble::what() const throw()
{
    return "Type should be \"Double\"\n";
}

const char *AnyTypeExceptionChar::what() const throw()
{
    return "Type should be \"Char\"\n";
}