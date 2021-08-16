//
// Created by Artem on 08.08.2021.
//

#ifndef TASK_2_MULTITYPE_H
#define TASK_2_MULTITYPE_H
#include <iostream>
#include "WrongType.h"

enum class EnumTypes {
    UNDEFINED = -1,
    INT = 0,
    UNSIGNED_INT = 1,
    FLOAT = 2,
    DOUBLE = 3,
    BOOL = 4,
    CHAR = 5,
    };

union Data{
    int i;
    unsigned int u;
    float f;
    double d;
    bool b;
    char c;
};

class BadType;

class MultiType
        {
        public:
            MultiType();
            MultiType(const MultiType& Obj);
            MultiType(MultiType&& rvalue);

            MultiType(int value);
            MultiType(unsigned int value);
            MultiType(float value);
            MultiType(double value);
            MultiType(bool value);
            MultiType(char value);



            MultiType& operator=(const MultiType& rvalue);
            MultiType& operator=(MultiType&& rvalue);
            friend std::ostream& operator<<(std::ostream& out, const MultiType& obj);

            void Swap(MultiType& lvalue, MultiType& rvalue);

            int ToInt() const;
            unsigned int ToUnsignedInt() const;
            float ToFloat() const;
            double ToDouble() const;
            bool ToBool() const;
            char ToChar() const;
            EnumTypes get_Type() const { return m_type; }

        private:
            EnumTypes m_type;
            Data m_data;
};
#endif //TASK_2_MULTITYPE_H
