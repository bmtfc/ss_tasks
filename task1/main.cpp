#include <iostream>
#include <string.h>
#include <stdlib.h>

#define MAX_COUNT_OF_DIGITS_IN_INT 128

/* Initializes list */
void StringListInit(char ***list)
{
    char **temp_list = (char **) malloc(1 * sizeof(char *));
    temp_list[0] = (char *) malloc(MAX_COUNT_OF_DIGITS_IN_INT * sizeof(char));
    char buf[MAX_COUNT_OF_DIGITS_IN_INT];
    snprintf(buf, sizeof(buf), "%d", 0);
    temp_list[0] = buf;
    *list = temp_list;
}

/* Inserts value at the end of the list. */
void StringListAdd(char ***list, char *str)
{
    int list_size = atoi(*list[0]) + 1;
    char **temp_list;
    temp_list = *list;
    int n = strlen(str);
    temp_list = (char **) realloc(temp_list, (list_size + 1) * sizeof(*temp_list));
    temp_list[list_size] = (char *) malloc((n + 1) * sizeof(char));
    int i;
    for (i = 0; i < n; ++i)
    {
        temp_list[list_size][i] = str[i];
    }
    temp_list[list_size][i] = '\0';
    char buf[MAX_COUNT_OF_DIGITS_IN_INT];
    snprintf(buf, sizeof(buf), "%d", list_size);
    temp_list[0] = buf;
    *list = temp_list;
}

/* Print list */
void PrintList(char ***list)
{
    int list_size = atoi(*list[0]) + 1;
    for (int i = 1; i < list_size; ++i)
    {
        printf("%s\n", (*list)[i]);
    }
}

/* Destroy list and set pointer to NULL. */
void StringListDestroy(char ***list)
{
    int list_size = atoi(*list[0]) + 1;
    for (int i = 1; i < list_size; ++i)
    {
        free((*list)[i]);
    }
    free(*list);
    *list = nullptr;
}

/* Returns the number of items in the list. */
int StringListSize(char ***list)
{
    return (atoi(*list[0]));
}

/* Returns the index position of the first occurrence of str in the list. */
int StringListIndexOf(char **list, char *str)
{
    int list_size = atoi((list)[0]) + 1;
    for (int i = 1; i < list_size; i++)
    {
        if (strcmp((list)[i], str) == 0)
        {
            return (i);
        }
    }
    return (-1);
}

/* Removes first occurrence of str in the list. */
void StringListRemove(char ***list, char *str)
{
    int list_size = atoi(*list[0]) + 1;
    char **temp_list = *list;
    t = (char **) realloc(temp_list, (list_size) * sizeof(*temp_list));

    for (int i = 0; i < list_size; ++i)
    {
        strcpy(temp_list[i], (*list)[i]);
    }

    int index_of_str_to_del = -1;

    for (int i = 1; i < list_size; i++)
    {
        if (strcmp(temp_list[i], str) == 0)
        {
            index_of_str_to_del = i;
        }
    }

    if (index_of_str_to_del < 0)
    {
        return;
    }

    list_size--;
    for (int i = index_of_str_to_del; i < list_size; ++i)
    {
        strcpy(temp_list[i], temp_list[i + 1]);
    }

    t = (char **) realloc(temp_list, (list_size - 1) * sizeof(*t));

    char buf[MAX_COUNT_OF_DIGITS_IN_INT];
    snprintf(buf, sizeof(buf), "%d", list_size - 1);
    temp_list[0] = buf;
    *list = temp_list;
}

int main()
{
    char **list;
    StringListInit(&list);
    StringListAdd(&list, "ahgh");
    StringListAdd(&list, "ghgh");
    StringListAdd(&list, "hhgh");
    StringListAdd(&list, "bhgh");
    StringListAdd(&list, "ghgh");
    PrintList(&list);
    printf("size of the list : %d\n", StringListSize(&list));
    printf("index of the hhgh in list : %d\n", StringListIndexOf(list, "hhgh"));
    StringListRemove(&list, "hhgh");
    PrintList(&list);
    StringListDestroy(&list);
    return 0;
}