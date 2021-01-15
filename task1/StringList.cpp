//
// Created by Mac on 15.01.2021.
//

#include "StringList.h"

// dynamic array implementation
// first "char*" contains size and capacity (sizeof(size_t));

void StringListInit(char ***list)
{
    *list = (char **) malloc(sizeof(char *));
    if (*list == nullptr)
    {
        exit(-1);
    }

    (*list)[0] = (char *) malloc(sizeof(size_t) * 2);
    if (*list[0] == nullptr)
    {
        exit(-1);
    }

    Set_Size(*list, 1);
    Set_Capacity(*list, 1);
}

void StringListDestroy(char ***list)
{
    char **lst = *list;
    const auto size = Get_Size(lst);

    for (size_t i = 0; i < size; i++)
    {
        if (lst[i] != nullptr)
        { free((lst)[i]); }
    }

    free(lst);
    *list = nullptr;
}

void StringListAdd(char ***list, char *str)
{
    if (Try_To_Realloc(list) == -1)
    {
        exit(-1);
    }

    char **lst = *list;
    const auto LIST_SIZE = Get_Size(lst);
    lst[LIST_SIZE] = (char *) malloc((strlen(str) + 1) * sizeof(char));
    strcpy(lst[LIST_SIZE], str);

    Set_Size(lst, LIST_SIZE + 1);
}

void StringListSet(char **list, size_t i, char *str)
{
    const size_t actual_i = i + 1;
    if (list[actual_i] != nullptr)
    { free(list[actual_i]); }
    list[actual_i] = (char *) malloc((strlen(str) + 1) * sizeof(char));
    strcpy(list[actual_i], str);
}

void StringListGet(char **list, size_t i, char **out)
{
    const size_t actual_i = i + 1;
    *out = list[actual_i];
}

size_t StringListSize(char **list)
{
    return static_cast<size_t>(Get_Size(list) - 1);
}

size_t StringListIndexOf(char **list, char *str)
{
    for (size_t i = 1; i < Get_Size(list); i++)
    {
        if (strcmp(list[i], str) == 0)
        {
            return i - 1;
        }
    }
    return -1;
}

//@TODO : rewrite StringListRemove
void StringListRemove(char **list, char *str)
{
    const auto LIST_SIZE = Get_Size(list);
    size_t removed_count = 0;
    ssize_t insert_index = -1;

    for (size_t i = 1; i < LIST_SIZE; i++)
    {
        if (insert_index == -1 && strcmp(list[i], str) == 0)
        {
            insert_index = i;
        }

        if (insert_index != -1)
        {
            if (strcmp(list[i], str) == 0)
            {
                free(list[i]);
                list[i] = nullptr;
                removed_count++;
            } else
            {
                Swap(list, i, insert_index);
                insert_index++;
            }
        }
    }

    Set_Size(list, LIST_SIZE - removed_count);
}

void StringListSort(char **list)
{
    const auto LIST_SIZE = Get_Size(list);
    for (size_t i = 1; i < LIST_SIZE; i++)
    {
        for (size_t j = 2; j < LIST_SIZE; j++)
        {
            if (strcmp(list[j], list[j - 1]) < 0)
            {
                Swap(list, j, j - 1);
            }
        }
    }
}

void StringListPrint(char **list)
{
    for (size_t i = 1; i < Get_Size(list); i++)
    {
        printf("%s\n", list[i]);
    }
    printf("\n");
}


void ToBytes(size_t a, char *out, size_t index)
{
    out = out + index;
    for (int i = 0; i < sizeof(size_t); i++)
    {
        out[i] = static_cast<char>((a >> (i * 8)) & 0xFF);
    }
}

size_t ToInt(char *arr, size_t index)
{
    arr = arr + index;

    size_t result = 0;
    size_t bitmap = 0xFF;

    for (int i = 0; i < sizeof(size_t); i++)
    {
        result |= (arr[i] << (i * 8)) & bitmap;
        bitmap <<= 8;
    }
    return result;

}

void Set_Size(char **list, size_t size)
{
    ToBytes(size, list[0], 0);
}

void Set_Capacity(char **list, size_t size)
{
    ToBytes(size, list[0], sizeof(size_t));
}

size_t Get_Size(char **list)
{
    return ToInt(list[0], 0);
}

size_t Get_Capacity(char **list)
{
    return ToInt(list[0], sizeof(size_t));
}

int Try_To_Realloc(char ***list, size_t capacity_scale)
{
    char **lst = *list;
    const auto LIST_SIZE = Get_Size(lst);
    const auto LIST_CAPACITY = Get_Capacity(lst);

    if (LIST_SIZE == LIST_CAPACITY)
    {
        *list = (char **) realloc(lst, LIST_CAPACITY * sizeof(char *) * capacity_scale);
        Set_Capacity(*list, LIST_CAPACITY * capacity_scale);
    }

    if (*list == nullptr)
    {
        free(lst);
        return -1;
    }

    return 0;
}

void Swap(char **list, size_t index1, size_t index2)
{
    char *temp = list[index1];
    list[index1] = list[index2];
    list[index2] = temp;
}