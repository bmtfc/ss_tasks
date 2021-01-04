#include <iostream>
#include <string.h>
#include <stdlib.h>

#define MAX_COUNT_OF_DIGITS_IN_INT 128

void StringListInit(char ***list)
{
    char **t_list = (char **) malloc(1 * sizeof(char *));
    t_list[0] = (char *) malloc(MAX_COUNT_OF_DIGITS_IN_INT * sizeof(char));
    char buf[MAX_COUNT_OF_DIGITS_IN_INT];
    snprintf(buf, sizeof(buf), "%d", 0);
    t_list[0] = buf;
    *list = t_list;
}

void StringListAdd(char ***list, char *str)
{
    int list_size = atoi(*list[0]) + 1;
    char **temp;
    temp = *list;
    int n = strlen(str);
    temp = (char **) realloc(temp, (list_size + 1) * sizeof(*temp));
    temp[list_size] = (char *) malloc((n + 1) * sizeof(char));
    int i;
    for (i = 0; i < n; ++i)
    {
        temp[list_size][i] = str[i];
    }
    temp[list_size][i] = '\0';
    char buf[MAX_COUNT_OF_DIGITS_IN_INT];
    snprintf(buf, sizeof(buf), "%d", list_size);
    temp[0] = buf;
    *list = temp;
}

void PrintList(char ***list)
{
    int num_of_str = atoi(*list[0]) + 1;
    for (int i = 1; i < num_of_str; ++i)
    {
        printf("%s\n", (*list)[i]);
    }
}

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

int StringListSize(char **list)
{
    return (atoi(list[0]));
}

int StringListIndexOf(char **list, char *str)
{
    int list_size = atoi(list[0]) + 1;
    for (int i = 1; i < list_size; i++)
    {
        if (strcmp(list[i], str) == 0)
        {
            return (i);
        }
    }
    return (-1);
}

int main()
{

    char **list;
    StringListInit(&list);
    StringListAdd(&list, "ghgh");
    StringListAdd(&list, "ghgh");
    StringListAdd(&list, "hhgh");
    StringListAdd(&list, "ghgh");
    StringListAdd(&list, "ghgh");
    PrintList(&list);
    printf("size of the list : %d\n", StringListSize(list));
    printf("index of the hhgh in list : %d", StringListIndexOf(list, "hhgh"));
    StringListDestroy(&list);

    return 0;
}