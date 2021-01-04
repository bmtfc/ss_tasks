#include <iostream>
#include <string.h>
#include <stdlib.h>

#define MAX_COUNT_OF_DIGITS_IN_INT 128

void StringListInit(char ***list)
{
    char **temp_list = (char **) malloc(1 * sizeof(char *));
    temp_list[0] = (char *) malloc(MAX_COUNT_OF_DIGITS_IN_INT * sizeof(char));
    char buf[MAX_COUNT_OF_DIGITS_IN_INT];
    snprintf(buf, sizeof(buf), "%d", 0);
    temp_list[0] = buf;
    *list = temp_list;
}

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

void PrintList(char ***list)
{
    int list_size = atoi(*list[0]) + 1;
    for (int i = 1; i < list_size; ++i)
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

int StringListSize(char ***list)
{
    return (atoi(*list[0]));
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

void StringListRemove(char ***list, char *str)
{
    int index_of_str_to_delete = -1;

    char **temp_list, **temp_list_all;
    temp_list = *list;
    temp_list_all = *list;

    int list_size = atoi(temp_list[0]) + 1;

    temp_list = (char **) realloc(temp_list, (list_size - 1) * sizeof(char *));

    for (int i = 1; i < list_size; i++)
    {
        if (strcmp(temp_list[i], str) == 0)
        {
            index_of_str_to_delete = i;
        }
    }

    list_size--;
    int k = 1;
    for (int i = 1; i < list_size - 1; ++i)
    {
        if (i == index_of_str_to_delete)
        {
            k++;
        }
        strcpy(temp_list[i], temp_list_all[k]);
        k++;
    }


    char buf[MAX_COUNT_OF_DIGITS_IN_INT];
    snprintf(buf, sizeof(buf), "%d", list_size - 1);
    temp_list[0] = buf;
    *list = temp_list;
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
    printf("size of the list : %d\n", StringListSize(&list));
    printf("index of the hhgh in list : %d\n", StringListIndexOf(list, "hhgh"));
    StringListRemove(&list, "hhgh");;
    PrintList(&list);
    StringListDestroy(&list);

    return 0;
}