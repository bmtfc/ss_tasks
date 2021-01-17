#include "StringList.h"

// TODO : create menu with while(true) and switch case
// TODO : UNIT TESTS !!!

int main()
{
    char **list;
    StringListInit(&list);
    StringListAdd(&list, "abcd");
    StringListAdd(&list, "ffgh");
    StringListAdd(&list, "uitye");
    StringListAdd(&list, "ccvc");
    StringListPrint(list);
    printf("Index of \"uitye\" : %d\n\n", StringListIndexOf(list, "uitye") + 1);
    printf("Sorted list :\n");
    StringListSort(list);
    StringListPrint(list);
    StringListRemove(list, "ffgh");
    printf("List after deleting \"ffgh\"\n");
    StringListPrint(list);
    StringListDestroy(&list);
    return 0;
}