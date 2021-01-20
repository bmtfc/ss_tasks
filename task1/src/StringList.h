#ifndef TASK1_SRC_STRINGLIST_H
#define TASK1_SRC_STRINGLIST_H

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
char *StringListGet(char **list, size_t i);

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


#endif //TASK1_SRC_STRINGLIST_H
