
#include "MultiType.h"


MultiType::MultiType()
{

}
MultiType::MultiType(const MultiType & rvalue)
{
    m_type = rvalue.m_type;
    m_data = rvalue.m_data;
}

MultiType::MultiType(MultiType&& rvalue)
{
    this->m_data = std::move(rvalue.m_data);
    this->m_type = std::move(rvalue.m_type);
    rvalue.m_type = EnumTypes::UNDEFINED;
}

MultiType::MultiType(int int_type): m_type(EnumTypes::INT)
{
    m_data.i = int_type;
}

MultiType::MultiType(unsigned int unsigned_int_type): m_type(EnumTypes::UNSIGNED_INT)
{
    m_data.u = unsigned_int_type;
}


MultiType::MultiType(float float_type): m_type(EnumTypes::FLOAT)
{
    m_data.f = float_type;
}

MultiType::MultiType(double double_type): m_type(EnumTypes::DOUBLE)
{
    m_data.d = double_type;
}

MultiType::MultiType(bool bool_type): m_type(EnumTypes::BOOL)
{
    m_data.b = bool_type;
}

MultiType::MultiType(char signed_char_type): m_type(EnumTypes::CHAR)
{
    m_data.c = signed_char_type;
}

MultiType& MultiType::operator=(const MultiType & rvalue){
    if (this != &rvalue)
    {
        MultiType copy(rvalue);
        Swap(copy, *this);
    }
    return *this;
}

MultiType& MultiType::operator=(MultiType && rvalue)
                {
    if (this != &rvalue)
    {
        this->m_data = std::move(rvalue.m_data);
        this->m_type = std::move(rvalue.m_type);

        rvalue.m_type = EnumTypes::UNDEFINED;
    }
    return *this;
}

void MultiType::Swap(MultiType & lvalue, MultiType & rvalue){
    std::swap(lvalue.m_data, rvalue.m_data);
    std::swap(lvalue.m_type, rvalue.m_type);
}

int MultiType::ToInt() const{
    if (m_type != EnumTypes::INT)
        throw BadType();
    else
        return m_data.i;
}

unsigned int MultiType::ToUnsignedInt() const{
    if (m_type != EnumTypes::UNSIGNED_INT)
        throw BadType();
    else
        return m_data.u;
}

float MultiType::ToFloat() const{
    if (m_type != EnumTypes::FLOAT)
        throw BadType();
    else
        return m_data.f;
}

double MultiType::ToDouble() const{
    if (m_type != EnumTypes::DOUBLE)
        throw BadType();
    else
        return m_data.d;
}

bool MultiType::ToBool() const{
    if (m_type != EnumTypes::BOOL)
        throw BadType();
    else
        return m_data.b;
}

char MultiType::ToChar() const{
    if (m_type != EnumTypes::CHAR)
        throw BadType();
    else
        return m_data.c;
}
std::ostream & operator<<(std::ostream & out, const MultiType & obj){

    switch (obj.get_Type())
    {
        case EnumTypes::INT:
            return out<< "\n INT-> " << obj.m_data.i;
        case EnumTypes::UNSIGNED_INT:
            return out<< "\n UNSIGNED INT-> " << obj.m_data.u;
        case EnumTypes::FLOAT:
            return out<< "\n -> FLOAT" << obj.m_data.f;
        case EnumTypes::DOUBLE:
            return out<< "\n -> DOUBLE" << obj.m_data.d;
        case EnumTypes::BOOL:
            return out<< "\n -> BOOL" << obj.m_data.b;
        case EnumTypes::CHAR:
            return out<< "\n -> CHAR" << obj.m_data.c;
        default:
            return out << "can't represent data";
    }
}

