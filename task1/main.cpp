#include <iostream>
#include <string.h>
#include <stdlib.h>

// init
// delete
//add
//remove
// number of items
// first match of string

// snprintf() and atio()

void StringListInit(char ***list) {
    char **t_list = (char **) malloc(1 * sizeof(char *));
    char buf[128];
    snprintf(buf, sizeof(buf), "%d", 0);
    t_list[0] = buf;
    *list = t_list;
}

int main() {

    char **list;
    StringListInit(&list);


    return 0;
}