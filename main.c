#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "library.h"

int main() {
    struct song_node **library = create_library();
    printf("Test Print Letter: \n");
    print_letter(library,'W');
    printf("Test Print Library: \n");
    print_library(library);
    insert_element(library, "Hello", "World");
    insert_element(library, "Hi", "World");
    insert_element(library, "Hire", "War");
    insert_element(library, "Wonderwall","Oasis");
    insert_element(library, "Another Song", "Oasis");
    insert_element(library, "ATST", "Blink-182");
    insert_element(library, "Hey There Delilah", "Plain White T's");
    insert_element(library, "Mr.Brightside", "The Killers");
    insert_element(library, "Why is C", "So Difficult");
    printf("Test Print Letter With Elements: \n");
    print_letter(library,'w');
    printf("Test Print Library with Elements\n");
    print_library(library);
    printf("Testing find: \n");
    printf("Looking for \"Hello World\":\n");
    printf("Song found!: %s, %s \n", (find_element(library, "Hello", "World") -> name),(find_element(library, "Hello", "World") -> artist) );
    printf("Looking for \"Goodbye Moon\":\n");
    if ((find_element(library, "Goodbye", "Moon"))  == NULL){
        printf("Song Not Found! \n");
    }
    printf("Testing Find Artist: \n");
    printf("Looking for Oasis\n");;
    printf("Artist Found! \n");
    print_artist(library, "Oasis");
    return 0;
    
}
