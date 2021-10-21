#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

int main() {
    struct song_node *list = NULL;
    list = insert_front(list, "A", "some");
    print_list(list);
    list = remove_node(list, "a", "some");
    print_list(list);
    return 0;
}