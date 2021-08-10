//
// Created by Artem on 10.08.2021.
//

#ifndef TASK_2_WRONGTYPE_H
#define TASK_2_WRONGTYPE_H
#include <iostream>

class BadType : public std::exception
        {
        public:
            virtual const char* what() const throw() { return "Bad types!"; }
        };
#endif //TASK_2_WRONGTYPE_H
