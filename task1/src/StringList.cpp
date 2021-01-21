#include "StringList.h"

/* PRIVATE METHODS */

void ToBytes(size_t a, char *out, size_t index);

size_t ToInt(char *arr, size_t index);

void SetSize(char **list, size_t size);

void SetCapacity(char **list, size_t size);

size_t GetSize(char **list);

size_t GetCapacity(char **list);

int ReallocList(char ***list, size_t capacity_scale = 2);

void Swap(char **list, size_t index1, size_t index2);


void StringListInit(char ***list)
{
    *list = (char **) malloc(sizeof(char *));
    if (*list == nullptr)
    {
        printf("Unable to allocate the memory\n");
        return;
    }

    (*list)[0] = (char *) malloc(sizeof(size_t) * 2);
    if (*list[0] == nullptr)
    {
        printf("Unable to allocate the memory\n");
        return;
    }
    SetSize(*list, 1);
    SetCapacity(*list, 1);
}

void StringListDestroy(char ***list)
{
    char **temp_list = *list;
    const size_t size = GetSize(temp_list);

    for (size_t i = 0; i < size; i++)
    {
        if (temp_list[i] != nullptr)
        {
            free((temp_list)[i]);
        }
    }

    free(temp_list);
    *list = nullptr;
}

void StringListAdd(char ***list, char *str)
{
    if (ReallocList(list) == -1)
    {
        printf("Unable to increase list size\n");
        return;
    }

    char **temp_list = *list;
    const size_t list_size = GetSize(temp_list);
    temp_list[list_size] = (char *) malloc((strlen(str) + 1) * sizeof(char));
    strcpy(temp_list[list_size], str);
    SetSize(temp_list, list_size + 1);
}

void StringListSet(char **list, size_t i, char *str)
{
    const size_t str_index = i;
    if (list[str_index] != nullptr)
    {
        free(list[str_index]);
    }
    list[str_index] = (char *) malloc((strlen(str) + 1) * sizeof(char));
    strcpy(list[str_index], str);
}

char *StringListGet(char **list, size_t i)
{
    return list[i];
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
            return i;
        }
    }
    return -1;
}

void StringListRemove(char **list, char *str)
{
    const size_t list_size = GetSize(list);
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
            }
            else
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
    const size_t list_size = GetSize(list);
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

void ToBytes(size_t a, char *out, size_t index)
{
    out = out + index;
    *reinterpret_cast<size_t *>(out) = a;
}

size_t ToInt(char *arr, size_t index)
{
    return *reinterpret_cast<size_t *>(arr + index);
}

int ReallocList(char ***list, size_t capacity_scale)
{
    char **temp_list = *list;
    const size_t list_size = GetSize(temp_list);
    const size_t list_capacity = GetCapacity(temp_list);

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