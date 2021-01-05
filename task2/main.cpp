#include <iostream>

/*
•	The class should contain all type of constructors +
•	The class should contain all type of assignment operators +-
•	The class should contain a method to destroy contained object
•	The class should contain a method to swap two objects
•	The class should contain a method returns the type of the contained value
•	The function/method that extracts a value should provide type-safe access.
    If the requested type does not match to stored type exception should be thrown
 */

class AnyTypeException : public std::exception
{
public :
    const char *what() const throw()
    {
        return "Type Error\n";
    }
};

class AnyTypeExceptionInt : public AnyTypeException
{
    const char *what() const throw()
    {
        return "Type should be \"Int\"\n";
    }
};

const std::string DATA_TYPES[4]{"bool", "int", "double", "char"};

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
    explicit AnyType(bool data)
    {
        bool_data = data;
        data_type = DATA_TYPES[0];
    }

    explicit AnyType(int data)
    {
        int_data = data;
        data_type = DATA_TYPES[1];
    }


    explicit AnyType(double data)
    {
        double_data = data;
        data_type = DATA_TYPES[2];
    }

    explicit AnyType(char data)
    {
        char_data = data;
        data_type = DATA_TYPES[3];
    }


    void SetBool(bool data)
    {
        bool_data = data;
        data_type = DATA_TYPES[0];
    }

    void SetInt(int data)
    {
        int_data = data;
        data_type = DATA_TYPES[1];
    }

    void SetDouble(double data)
    {
        double_data = data;
        data_type = DATA_TYPES[2];
    }

    void SetChar(char data)
    {
        char_data = data;
        data_type = DATA_TYPES[3];
    }

    bool ToBool()
    {
        if (data_type == DATA_TYPES[0])
        {
            return bool_data;
        } else
        {
            throw (AnyTypeExceptionInt());
        }
    }


    int ToInt()
    {
        if (data_type == DATA_TYPES[1])
        {
            return int_data;
        } else
        {
            throw (AnyTypeExceptionInt());
        }
    }

    double ToDouble()
    {
        if (data_type == DATA_TYPES[2])
        {
            return double_data;
        } else
        {
            throw (AnyTypeException());
        }
    }

    char ToChar()
    {
        if (data_type == DATA_TYPES[3])
        {
            return char_data;
        } else
        {
            throw (AnyTypeException());
        }
    }

    void Destroy()
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


};

int main()
{
    AnyType X(7.98);
    AnyType Y(true);
    X = Y;
    try
    {
        std::cout << X.ToInt();
    }
    catch (AnyTypeException &e)
    {
        std::cout << e.what();
    }


    return 0;
}
