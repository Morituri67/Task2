//
// Created by Artem on 04.08.2021.
//

#include "ListString.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>

static int StringCount;
static int ListCapacity;

int StringListSize(){
    return StringCount;
}

void SwapStrings(char** string1,char** string2){
    char* temp;
    temp=*string1;
    *string1=*string2;
    *string2=temp;

    /*char temp[strlen(*string1)+1];
    strcpy(temp,*string1);
    *//*list[string1]=(char*)realloc(list[string1], strlen(list[string2])+1);*//*
    strcpy(*string1,*string2);
    strcpy(*string2,temp);*/
}

void StringListInit(char ***list){
    ListCapacity= 8;
    (*list)= (char **) calloc(ListCapacity,sizeof(char*)) ;
    StringCount= 0;

}

void StringListAdd(char** list, char* buffer){
    if (StringCount<ListCapacity){
        list[StringCount]= (char*)malloc(strlen(buffer)+1);
        strcpy(list[StringCount],buffer);
        StringCount++;
    } else {
        ListCapacity*=2;
        list= (char**)realloc(list, sizeof(char*)*ListCapacity);
        list[StringCount]=(char*)malloc(strlen(buffer)+1);
        strcpy(list[StringCount],buffer);
        StringCount++;
    }

}

void DeleteString(char** list, int StringNumber){
    if (StringNumber!=StringCount-1){
        SwapStrings(&list[StringNumber],&list[StringCount-1]);
    }

    ListCapacity=StringCount;
    list= (char**)realloc(list, sizeof(char*)*ListCapacity);
    free(list[StringCount-1]);

    StringCount--;
}


int FindString(char** list, char* CompareString){
    for (int i = 0; i < StringCount; ++i) {
        if(!strcmp(list[i],CompareString)){
            return i;
        }
    }
    return -1;
}

void ShowList(char **list){
    std::cout<<"\n\t THE LIST IS ->\n";
    for (int i = 0; i < StringCount; ++i) {
        puts(list[i]);
    }
}

void StringListDestroy(char*** list){

    for (int i = 0; i < StringCount; ++i) {
        free((*list)[i]);
    }
    free((*list));
    StringCount=0;

}

void StringListRemoveDuplicates(char** list){
    for (int i = 0; i < StringCount; ++i) {
        for (int j = i+1; j < StringCount; ++j) {
            if (!strcmp(list[i],list[j])){
                DeleteString(list,j);
            }
        }
    }
}

void StringListReplaceInStrings(char** list, char* before, char* after){
    for (int i = 0; i < StringCount; ++i){
        if(!strcmp(list[i],before)){
            strcpy(list[i],after);
        }
    }
}

static int myCompare(const void* string1, const void* string2)
{

    return strcmp(*(const char**)string1, *(const char**)string2);
}

void StringListSort(char** list){
    qsort(list, StringCount, sizeof(const char*), myCompare);
}