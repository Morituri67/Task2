#include "MultiType.h"
#include <iostream>


int main()
{
    MultiType obj1 = 67.3;
    MultiType obj2 = 6;
    MultiType obj3 = 'c';
    MultiType obj4 = 'a';

    std::cout<< obj1<< std::endl;
    std::cout<< obj2<< std::endl;
    std::cout<< obj3<< std::endl;

    try
    {
        obj2 = obj1.ToInt();
        std::cout << obj2;
        obj3 = obj4.ToChar();
        std::cout << obj3<<std::endl;
    }
    catch(BadType& bt)
    {
        std::cout << bt.what() << std::endl;
    }

    obj2.Swap(obj2, obj1);
    std::cout << obj2<<std::endl;

    return 0;
}
