//
// Created by Mac on 15.01.2021.
//

#ifndef TASK1_STRINGLIST_H
#define TASK1_STRINGLIST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* Initializes list */
void StringListInit(char ***list);

/* Destroy list and set pointer to NULL. */
void StringListDestroy(char ***list);

/* Sets value of list i-th element   */
void StringListSet(char **list, size_t i, char *str);

/* Returns i-th element of the list */
void StringListGet(char **list, size_t i, char **out);

/* Inserts value at the end of the list. */
void StringListAdd(char ***list, char *str);

/* Removes all occurrences of str in the list. */
void StringListRemove(char **list, char *str);

/* Returns the number of items in the list. */
size_t StringListSize(char **list);

/* Returns the index position of the first occurrence of str in the list. */
size_t StringListIndexOf(char **list, char *str);

/* Sorts the list of strings in ascending order */
void StringListSort(char **list);

/* Prints the content of list */
void StringListPrint(char **list);


/* Writes num as sizeof(size_t) bytes into out starting from index */
void ToBytes(size_t num, char *out, size_t index);

/* Returns sizeof(size_t) bytes of arr starting from index as size_t */
size_t ToInt(char *arr, size_t index);

/* Stores list size in first sizeof(size_t) bytes of list[0] */
void SetSize(char **list, size_t size);

/* Stores list buffer size in second half of list[0]. */
void SetCapacity(char **list, size_t size);

/* Returns  number of elements in the list. */
size_t GetSize(char **list);

/* Returns buffer size of the list. */
size_t GetCapacity(char **list);

/* Reallocating list memory by capacity_scale if list size equals to list capacity. */
int ReallocList(char ***list, size_t capacity_scale = 2);

/* Swaps two elements of the list  */
void Swap(char **list, size_t index1, size_t index2);


#endif //TASK1_STRINGLIST_H
