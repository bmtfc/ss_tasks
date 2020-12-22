#include <iostream>
#include <string.h>
#include <stdlib.h>

// init
// delete
//add
//remove
// number of items
// first match of string

// snprintf() and atoi()

void StringListInit(char ***list) {
    char **t_list = (char **) malloc(1 * sizeof(char *));
    t_list[0] = (char *) malloc(128 * sizeof(char));
    char buf[128];
    snprintf(buf, sizeof(buf), "%d", 0);
    t_list[0] = buf;
    *list = t_list;
}

void StringListAdd(char ***list, char *str) {
    int a = atoi(*list[0]) + 1;
    char **temp;
    temp = *list;
    int n = strlen(str);
    temp = (char **) realloc(temp, (a + 1) * sizeof(*temp));
    temp[a] = (char *) malloc((n + 1) * sizeof(char));
    int i;
    for (i = 0; i < n; ++i) {
        temp[a][i] = str[i];
    }
    temp[a][i] = '\0';
    char buf[128];
    snprintf(buf, sizeof(buf), "%d", a);
    temp[0] = buf;
    *list = temp;
}

void PrintList(char ***list) {
    int num_of_str = atoi(*list[0]) + 1;
    for (int i = 1; i < num_of_str; ++i)
        printf("%s\n", (*list)[i]);
}

void StringListDestroy(char ***list) {
    int a = atoi(*list[0]) + 1;
    for (int i = 1; i < a; ++i) {
        free((*list)[i]);
    }
    free(*list);
    *list = nullptr;
}

int main() {

    char **list;
    StringListInit(&list);
    StringListAdd(&list, "ghgh");
    StringListAdd(&list, "ghgh");
    StringListAdd(&list, "ghgh");
    StringListAdd(&list, "ghgh");
    StringListAdd(&list, "ghgh");
    PrintList(&list);
    StringListDestroy(&list);

    return 0;
}