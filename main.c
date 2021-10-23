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
    insert_element(library, "Wonderwall","Oasis");
    insert_element(library, "Another Song", "Oasis");
    insert_element(library, "ATST", "Blink-182");
    insert_element(library, "Hey There Delilah", "Plain White T's");
    insert_element(library, "Mr.Brightside", "The Killers");
    insert_element(library, "Why is C", "So Difficult");
   // print_library(library);
   // print_letter(library,'W');
   //print_node(find_element_artist(library, "World"));
    //printf("This Works");
    //print_artist(library, "World");
    shuffle(library,4);
    return 0;
}
