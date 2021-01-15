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
    printf("actual size : %d, capacity : %d \n\n",GetSize(list),GetCapacity(list));
    printf("Index of \"uitye\" : %d\n\n", StringListIndexOf(list,"uitye")+1);
    printf("Sorted list :\n");
    StringListSort(list);
    StringListPrint(list);
    StringListRemove(list,"ffgh");
    printf("List after deleting \"ffgh\"\n");
    StringListPrint(list);
    printf("actual size : %d, capacity : %d \n\n",GetSize(list),GetCapacity(list));
    StringListDestroy(&list);
    return 0;
}