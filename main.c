#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "library.h"

int main() {
    /*struct song_node *list = NULL;
    list = insert_node(list, "D", "A");
    print_list(list);
    list = insert_node(list, "B", "B");
    list = insert_node(list, "C", "A");
    print_list(list);
    print_node(find_artist(list,"A"));
    print_list(list);*/
    struct song_node **library = create_library();
    insert_element(library, "Hello", "World");
    insert_element(library, "Hi", "World");
    insert_element(library, "Hire", "War");
    print_library(library);
    print_letter(library,'W');
    print_node(find_element_artist(library, "War"));
    return 0;
}