//
// Created by Artem on 04.08.2021.
//

#ifndef TASK_1_LISTSTRING_H
#define TASK_1_LISTSTRING_H

int StringListSize();

void SwapStrings(char** list,int string1,int string2);

void StringListInit(char ***list);

void StringListAdd(char** list, char* buffer);

void DeleteString(char** list, int StringNumber);

int FindString(char** list, char* CompareString);

void ShowList(char **list);

void StringListDestroy(char*** list);

void StringListRemoveDuplicates(char** list);

void StringListReplaceInStrings(char** list, char* before, char* after);

static int myCompare(const void* string1, const void* string2);

void StringListSort(char** list);
#endif //TASK_1_LISTSTRING_H
