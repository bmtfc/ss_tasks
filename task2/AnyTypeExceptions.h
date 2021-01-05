#ifndef TASK2_ANYTYPEEXCEPTIONS_H
#define TASK2_ANYTYPEEXCEPTIONS_H

#include <exception>

class AnyTypeException : public std::exception
{
public :
    const char *what() const throw();
};

class AnyTypeExceptionBool : public AnyTypeException
{
    const char *what() const throw();
};

class AnyTypeExceptionInt : public AnyTypeException
{
    const char *what() const throw();
};

class AnyTypeExceptionDouble : public AnyTypeException
{
    const char *what() const throw();
};

class AnyTypeExceptionChar : public AnyTypeException
{
    const char *what() const throw();
};


#endif //TASK2_ANYTYPEEXCEPTIONS_H
