#ifndef any_type_hpp
#define any_type_hpp

#include <iostream>
#include <sstream>
#include <type_traits>
#include <typeinfo>

class AnyType
{
    enum class DataType
    {
        Bool, Int, LongInt, Double, UnsignedLongInt,
        LongDouble, Char, UnsignedChar, UnsignedInt, Float,
        None
    } data_type;

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
    } value;

private /* methods */:
    void ValidateTypeOrRaise(DataType castDataType) const;

    template<typename Integral, std::enable_if_t<std::is_integral<Integral>::value, int> = 0>
    void SetValue(const Integral &v);

    template<typename Floating, std::enable_if_t<std::is_floating_point<Floating>::value, int> = 0>
    void SetValue(const Floating &v);

private /* static methods */:
    static const char *ToString(DataType dt);

public:
    AnyType();

    template<typename FundamentalType>
    AnyType(const FundamentalType &value);

    AnyType(const AnyType &other) = default;

    AnyType(AnyType &&other) = default;

    AnyType &operator=(const AnyType &other) = default;

    AnyType &operator=(AnyType &&other) = default;

    template<typename FundamentalType>
    AnyType &operator=(const FundamentalType &value);

    template<typename FundamentalType>
    AnyType &operator=(FundamentalType &&value);

    DataType GetDataType() const;

    void Clear();

    bool ToBool() const;

    char ToChar() const;

    unsigned char ToUnsignedChar() const;

    int ToInt() const;

    unsigned ToUnsignedInt() const;

    long int ToLongInt() const;

    unsigned long int ToUnsignedLongInt() const;

    float ToFloat() const;

    double ToDouble() const;

    long double ToLongDouble() const;
};

//
//  IMPLEMENTATION
//

void AnyType::ValidateTypeOrRaise(DataType castDataType) const
{
    if (data_type != castDataType)
    {
        std::ostringstream os;
        os << "Unable to cast from " << ToString(data_type);
        os << " to " << ToString(castDataType);
        throw std::runtime_error{os.str()};
    }
}

template<
        typename Integral,
        std::enable_if_t<std::is_integral<Integral>::value, int>
>
void AnyType::SetValue(const Integral &v)
{
    if (std::is_same_v<Integral, bool>)
    {
        data_type = DataType::Bool;
        value.m_bool = v;
    } else if (std::is_signed<Integral>::value)
    {
        if (std::is_same_v<Integral, char>)
        {
            data_type = DataType::Char;
            value.m_char = v;
        } else if (std::is_same_v<Integral, int>)
        {
            data_type = DataType::Int;
            value.m_int = v;
        } else if (std::is_same_v<Integral, long int>)
        {
            data_type = DataType::LongInt;
            value.m_lint = v;
        }
    } else if (std::is_unsigned<Integral>::value)
    {
        if (std::is_same_v<Integral, unsigned char>)
        {
            data_type = DataType::UnsignedChar;
            value.m_uchar = v;
        } else if (std::is_same_v<Integral, unsigned int>)
        {
            data_type = DataType::UnsignedInt;
            value.m_uint = v;
        } else if (std::is_same_v<Integral, unsigned long int>)
        {
            data_type = DataType::UnsignedLongInt;
            value.m_ulint = v;
        }
    }
}

template<
        typename Floating,
        std::enable_if_t<std::is_floating_point<Floating>::value, int>
>
void AnyType::SetValue(const Floating &v)
{
    if constexpr (std::is_same_v<Floating, float>)
    {
        data_type = DataType::Float;
        value.m_float = v;
    } else if constexpr (std::is_same_v<Floating, double>)
    {
        data_type = DataType::Double;
        value.m_double = v;
    } else if constexpr (std::is_same_v<Floating, long double>)
    {
        data_type = DataType::LongDouble;
        value.m_ldouble = v;
    }
}

#define DT_CASE(datatype)  \
case datatype:           \
  return #datatype;      \
  break;

const char *AnyType::ToString(DataType dt)
{
    switch (dt)
    {
        DT_CASE(DataType::Bool)
        DT_CASE(DataType::Int)
        DT_CASE(DataType::LongInt)
        DT_CASE(DataType::Double)
        DT_CASE(DataType::UnsignedLongInt)
        DT_CASE(DataType::LongDouble)
        DT_CASE(DataType::Char)
        DT_CASE(DataType::UnsignedChar)
        DT_CASE(DataType::UnsignedInt)
        DT_CASE(DataType::Float)
        DT_CASE(DataType::None)
        default:
            []()
            {}();
    }
}

AnyType::AnyType() : data_type{DataType::None}
{

}

template<typename FundamentalType>
AnyType::AnyType(const FundamentalType &value)
{
    SetValue(value);
}

template<typename FundamentalType>
AnyType &AnyType::operator=(const FundamentalType &value)
{
    SetValue(value);
    return *this;
}

template<typename FundamentalType>
AnyType &AnyType::operator=(FundamentalType &&value)
{
    SetValue(value);
    return *this;
}

AnyType::DataType AnyType::GetDataType() const
{
    return data_type;
}

void AnyType::Clear()
{
    data_type = DataType::None;
}

bool AnyType::ToBool() const
{
    ValidateTypeOrRaise(DataType::Bool);
    return value.m_bool;
}

char AnyType::ToChar() const
{
    ValidateTypeOrRaise(DataType::Char);
    return value.m_char;
}

unsigned char AnyType::ToUnsignedChar() const
{
    ValidateTypeOrRaise(DataType::UnsignedChar);
    return value.m_uchar;
}

int AnyType::ToInt() const
{
    ValidateTypeOrRaise(DataType::Int);
    return value.m_int;
}

unsigned AnyType::ToUnsignedInt() const
{
    ValidateTypeOrRaise(DataType::UnsignedInt);
    return value.m_uint;
}

long int AnyType::ToLongInt() const
{
    ValidateTypeOrRaise(DataType::LongInt);
    return value.m_lint;
}

unsigned long int AnyType::ToUnsignedLongInt() const
{
    ValidateTypeOrRaise(DataType::UnsignedLongInt);
    return value.m_ulint;
}

float AnyType::ToFloat() const
{
    ValidateTypeOrRaise(DataType::Float);
    return value.m_float;
}

double AnyType::ToDouble() const
{
    ValidateTypeOrRaise(DataType::Double);
    return value.m_double;
}

long double AnyType::ToLongDouble() const
{
    ValidateTypeOrRaise(DataType::LongDouble);
    return value.m_ldouble;
};

#endif /* any_type_hpp */