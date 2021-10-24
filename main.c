#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "library.h"

int main() {
    struct song_node *list = NULL;
    printf("LINKED LIST TESTS\n");
    
    printf("\nTesting insert_front:\n");
    list = insert_front(list, "Thunderstruck", "AC/DC");
    printf("Inserted 'Thunderstruck' by 'AC/DC'\n");

    printf("\nTesting print_list:\n");
    print_list(list);

    printf("\nTesting print_node:\n");
    print_node(list);

    printf("\nTesting insert_node:\n");
    list = insert_node(list, "Street Spirit (Fade Out)", "Radiohead");
    printf("Inserted 'Street Spirit (Fade Out)' by 'Radiohead'\n");
    list = insert_node(list, "Even Flow", "Pearl Jam");
    printf("Inserted 'Even Flow' by 'Pearl Jam'\n");
    list = insert_node(list, "Time", "Pink Floyd");
    printf("Inserted 'Time' by 'Pink Floyd'\n");
    list = insert_node(list, "Alive", "Pearl Jam");
    printf("Inserted 'Alive' by 'Pearl Jam'\n");
    list = insert_node(list, "Paranoid Android", "Radiohead");
    printf("Inserted 'Paranoid Android' by 'Radiohead'\n");
    list = insert_node(list, "Yellow Ledbetter", "Pearl Jam");
    printf("Inserted 'Yellow Ledbetter' by 'Pearl Jam'\n");
    print_list(list);

    printf("\nTesting length_list\n");
    printf("Length: %d\n", length_list(list));

    printf("\nTesting compare:\n");
    struct song_node *e1 = list;
    struct song_node *e2 = list -> next -> next -> next;
    printf("Comparing '%s' by '%s' to '%s' by '%s': %d\n", e1 -> name, e1 -> artist, e2 -> name, e2 -> artist, compare(e1,e2));
    e1 = list -> next -> next;
    e2 = list -> next;
    printf("Comparing '%s' by '%s' to '%s' by '%s': %d\n", e1 -> name, e1 -> artist, e2 -> name, e2 -> artist, compare(e1,e2));
    e1 = list -> next;
    e2 = list -> next;
    printf("Comparing '%s' by '%s' to '%s' by '%s': %d\n", e1 -> name, e1 -> artist, e2 -> name, e2 -> artist, compare(e1,e2));
    
    printf("\nTesting find_node:\n");
    e1 = find_node(list, "Alive", "Pearl Jam");
    e2 = find_node(list, "None", "None");
    printf("Finding node '%s' by '%s': %p (Address) ", "Alive", "Pearl Jam", e1);
    print_node(e1);
    printf("Finding node '%s' by '%s': %p (Address) ", "None", "None", e2);
    print_node(e2);
    printf("\n");

    printf("\nTesting find_artist:\n");
    e1 = find_artist(list, "Pearl Jam");
    e2 = find_artist(list, "AC/DC");
    printf("Finding artist 'Pearl Jam'. Their first song is: ");
    print_node(e1);
    printf("Finding artist 'AC/DC'. Their first song is: ");
    print_node(e2);

    printf("\nTesting random_node:\n");
    srand(time(NULL));
    print_node(random_node(list, rand()));
    print_node(random_node(list, rand()));
    print_node(random_node(list, rand()));
    print_node(random_node(list, rand()));
    print_node(random_node(list, rand()));

    printf("\nTesting remove_node\n");
    printf("Removing 'Alive' by 'Pearl Jam'\n");
    list = remove_node(list, "Alive", "Pearl Jam");
    printf("Removing 'Paranoid Android' by 'Radiohead'\n");
    list = remove_node(list, "Paranoid Android", "Radiohead");
    print_list(list);

    printf("\nTesting free_list\n");
    list = free_list(list);
    print_list(list);

    printf("\n\n");
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
    printf("Song found!: %s, %s  at location %p \n", (find_element(library, "Hello", "World") -> name),(find_element(library, "Hello", "World") -> artist),(find_element(library, "Hello", "World") ));
    printf("Looking for \"Goodbye Moon\":\n");
    if ((find_element(library, "Goodbye", "Moon"))  == NULL){
        printf("Song Not Found! \n");
    }
    printf("Testing Find Artist: \n");
    printf("Looking for World\n");;
    printf("Artist Found! \n");
    print_list(find_element_artist(library, "World"));
    printf("Testing Remove Node: \n");
    printf("Removing Another Song - Oasis\n");
    delete_song(library, "Another Song", "Oasis");
    print_library(library);
    printf("Testing Shuffle: \n");
    shuffle(library,4,rand());
    printf("Shuffling Again: \n");
    shuffle(library,4,rand());
    printf("Adding Songs to Empty Library: \n");
    clear_library(library);
    insert_element(library, "Thunderstruck", "AC/DC");
    insert_element(library, "alive", "Pearl Jam");
    insert_element(library, "even flow", "Pearl Jam");
    print_library(library);
    printf("Testing Print Artist\n");
    print_artist(library, "Pearl Jam");
    return 0;
    
}
