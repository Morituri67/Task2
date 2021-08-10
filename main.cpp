#include "ListString.h"
#include <iostream>
#include <string.h>

int main() {
    char **list;
    std::cout<<"\n\t Enter 5 strings\n";
    StringListInit(&list);
    char buffer[30];

        gets(buffer);
        StringListAdd(list,buffer);

        gets(buffer);
        StringListAdd(list,buffer);

        gets(buffer);
        StringListAdd(list,buffer);

        gets(buffer);
        StringListAdd(list,buffer);

        gets(buffer);
        StringListAdd(list,buffer);



    std::cout<<"\n There are "<<StringListSize()<<" strings in list";
    ShowList(list);

    StringListSort(list);
    StringListRemoveDuplicates(list);
    StringListReplaceInStrings(list,"1","hello");


    ShowList(list);
    std::cout<<"\n There are "<<StringListSize()<<" strings in list";

    StringListDestroy(&list);
    return 0;
}


