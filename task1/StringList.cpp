//
// Created by Mac on 15.01.2021.
//

#include "StringList.h"

// dynamic array implementation
// first "char*" contains size and capacity (sizeof(size_t) both);

/* PRIVATE METHODS */

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

    SetSize(*list, 1);
    SetCapacity(*list, 1);
}

void StringListDestroy(char ***list)
{
    char **temp_list = *list;
    const auto size = GetSize(temp_list);

    for (size_t i = 0; i < size; i++)
    {
        if (temp_list[i] != nullptr)
        { free((temp_list)[i]); }
    }

    free(temp_list);
    *list = nullptr;
}

void StringListAdd(char ***list, char *str)
{
    if (ReallocList(list) == -1)
    {
        exit(-1);
    }

    char **temp_list = *list;
    const auto list_size = GetSize(temp_list);
    temp_list[list_size] = (char *) malloc((strlen(str) + 1) * sizeof(char));
    strcpy(temp_list[list_size], str);

    SetSize(temp_list, list_size + 1);
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
    return static_cast<size_t>(GetSize(list) - 1);
}

size_t StringListIndexOf(char **list, char *str)
{
    for (size_t i = 1; i < GetSize(list); i++)
    {
        if (strcmp(list[i], str) == 0)
        {
            return i - 1;
        }
    }
    return -1;
}

//@TODO : сopied, rewrite StringListRemove
void StringListRemove(char **list, char *str)
{
    const auto list_size = GetSize(list);
    size_t removed_count = 0;
    ssize_t insert_index = -1;

    for (size_t i = 1; i < list_size; i++)
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

    SetSize(list, list_size - removed_count);
}

void StringListSort(char **list)
{
    const auto list_size = GetSize(list);
    for (size_t i = 1; i < list_size; i++)
    {
        for (size_t j = 2; j < list_size; j++)
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
    for (size_t i = 1; i < GetSize(list); i++)
    {
        printf("%s\n", list[i]);
    }
    printf("\n");
}

//@TODO: copied => figure out and rewrite (?)
//----------------------------------------------------------------------------------------------------------------------

void ToBytes(size_t a, char *out, size_t index)
{
    out = out + index;
    /*
    for (int i = 0; i < sizeof(size_t); i++)
    {
        out[i] = static_cast<char>((a >> (i * 8)) & 0xFF);
    }
    */
    *reinterpret_cast<size_t*>(out) = a;

}

size_t ToInt(char *arr, size_t index)
{
    /*
    arr = arr + index;

    size_t result = 0;
    size_t bitmap = 0xFF;

    for (int i = 0; i < sizeof(size_t); i++)
    {
        result |= (arr[i] << (i * 8)) & bitmap;
        bitmap <<= 8;
    }
    return result;
    */
    return *reinterpret_cast<size_t*>(arr + index);
}

void SetSize(char **list, size_t size)
{
    ToBytes(size, list[0], 0);
}

void SetCapacity(char **list, size_t size)
{
    ToBytes(size, list[0], sizeof(size_t));
}

size_t GetSize(char **list)
{
    return ToInt(list[0], 0);
}

size_t GetCapacity(char **list)
{
    return ToInt(list[0], sizeof(size_t));
}

//----------------------------------------------------------------------------------------------------------------------

int ReallocList(char ***list, size_t capacity_scale)
{
    char **temp_list = *list;
    const auto list_size = GetSize(temp_list);
    const auto list_capacity = GetCapacity(temp_list);

    if (list_size == list_capacity)
    {
        *list = (char **) realloc(temp_list, list_capacity * sizeof(char *) * capacity_scale);
        SetCapacity(*list, list_capacity * capacity_scale);
    }

    if (*list == nullptr)
    {
        free(temp_list);
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