#include "StringList.h"


int main()
{
    char **list;
    StringListInit(&list);
    StringListAdd(&list,"abcd");
    StringListAdd(&list,"ffgh");
    StringListAdd(&list,"uitye");
    StringListAdd(&list,"ccvc");
    StringListPrint(list);
    printf("size : %d, capacity : %d \n",Get_Size(list),Get_Capacity(list));
    printf("Index of \"uitye\" : %d\n", StringListIndexOf(list,"uitye")+1);
    StringListSort(list);
    StringListPrint(list);
    StringListRemove(list,"ffgh");
    printf("List after deleting \"ffgh\"\n");
    StringListPrint(list);
    printf("size : %d, capacity : %d \n",Get_Size(list),Get_Capacity(list));


    return 0;
}