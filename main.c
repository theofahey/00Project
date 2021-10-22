#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

int main() {
    struct song_node *list = NULL;
    list = insert_node(list, "D", "A");
    print_list(list);
    list = insert_node(list, "B", "B");
    list = insert_node(list, "C", "A");
    list = remove_node(list, "D", "A");
    list = remove_node(list, "B", "B");
    list = remove_node(list, "D", "A");
    list = remove_node(list, "E", "F");
    print_list(list);
    print_list(find_artist(list,"C"));
    return 0;
}