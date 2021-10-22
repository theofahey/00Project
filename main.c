#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

int main() {
    struct song_node *list = NULL;
    list = insert_song(list, "D", "A");
    print_list(list);
    list = insert_song(list, "B", "A");
    list = insert_song(list, "C", "A");
    print_list(list);
    return 0;
}