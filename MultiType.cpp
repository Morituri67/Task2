
#include "MultiType.h"
#include "WrongType.h"

MultiType::MultiType()
{

}
MultiType::MultiType(const MultiType & rhs)
{
    m_type = rhs.m_type;
    m_data = rhs.m_data;
}

MultiType::MultiType(MultiType&& rhs)
{
    this->m_data = std::move(rhs.m_data);
    this->m_type = std::move(rhs.m_type);
    rhs.m_type = EnumTypes::UNDEFINED;
}


MultiType::MultiType(bool bool_type): m_type(EnumTypes::BOOL)
{
    m_data.bool_value = bool_type;
}

MultiType::MultiType(char signed_char_type): m_type(EnumTypes::CHAR)
{
    m_data.char_value = signed_char_type;
}


MultiType::MultiType(int int_type): m_type(EnumTypes::INT)
{
    m_data.int_value = int_type;
}

MultiType::MultiType(unsigned int unsigned_int_type): m_type(EnumTypes::UNSIGNED_INT)
{
    m_data.unsigned_int_value = unsigned_int_type;
}


MultiType::MultiType(float float_type): m_type(EnumTypes::FLOAT)
{
    m_data.float_value = float_type;
}

MultiType::MultiType(double double_type): m_type(EnumTypes::DOUBLE)
{
    m_data.double_value = double_type;
}


MultiType& MultiType::operator=(const MultiType & rhs){
    if (this != &rhs)
    {
        MultiType copy(rhs);
        Swap(copy, *this);
    }
    return *this;
}

MultiType& MultiType::operator=(MultiType && rhs)
                {
    if (this != &rhs)
    {
        this->m_data = std::move(rhs.m_data);
        this->m_type = std::move(rhs.m_type);

        rhs.m_type = EnumTypes::UNDEFINED;
    }
    return *this;
}

void MultiType::Swap(MultiType & lhs, MultiType & rhs){
    std::swap(lhs.m_data, rhs.m_data);
    std::swap(lhs.m_type, rhs.m_type);
}

const char * MultiType::GetTypeName() const
{
    switch (m_type)
    {
        case EnumTypes::BOOL:
            return "bool";
        case EnumTypes::CHAR:
            return "char";
        case EnumTypes::INT:
            return "int";
        case EnumTypes::UNSIGNED_INT:
            return "unsigned int";
        case EnumTypes::FLOAT:
            return "float";
        case EnumTypes::DOUBLE:
            return "double";
        default:
            return "type undefined";
    }
}


int MultiType::ToInt() const{
    if (m_type != EnumTypes::INT)
        throw BadType();
    else
        return m_data.int_value;
}

unsigned int MultiType::ToUnsignedInt() const{
    if (m_type != EnumTypes::UNSIGNED_INT)
        throw BadType();
    else
        return m_data.unsigned_int_value;
}

float MultiType::ToFloat() const{
    if (m_type != EnumTypes::FLOAT)
        throw BadType();
    else
        return m_data.float_value;
}

double MultiType::ToDouble() const{
    if (m_type != EnumTypes::DOUBLE)
        throw BadType();
    else
        return m_data.double_value;
}

bool MultiType::ToBool() const{
    if (m_type != EnumTypes::BOOL)
        throw BadType();
    else
        return m_data.bool_value;
}

char MultiType::ToChar() const{
    if (m_type != EnumTypes::CHAR)
        throw BadType();
    else
        return m_data.char_value;
}
std::ostream & operator<<(std::ostream & out, const MultiType & obj){
    out << obj.GetTypeName() << " -> ";

    switch (obj.get_Type())
    {
        case EnumTypes::INT:
            return out << obj.m_data.int_value;
        case EnumTypes::UNSIGNED_INT:
            return out << obj.m_data.unsigned_int_value;
        case EnumTypes::FLOAT:
            return out << obj.m_data.float_value;
        case EnumTypes::DOUBLE:
            return out << obj.m_data.double_value;
        case EnumTypes::BOOL:
            return out << obj.m_data.bool_value;
        case EnumTypes::CHAR:
            return out << obj.m_data.char_value;
        default:
            return out << "can't represent data";
    }
}

