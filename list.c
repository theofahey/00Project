#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void print_list(struct song_node *front) {
    printf("[ ");
    while (front) {
        printf("{Name: %s, Artist: %s} ", front -> name, front -> artist)
        front = front -> next;
    }
    printf("]\n");
}

struct song_node * insert_front(struct song_node *front, char name[], char artist[]) {
    struct song_node *n = malloc(sizeof(struct song_node));
    strncpy(n -> name, name, sizeof(struct song_node.name));
    strncpy(n -> artist, artist, sizeof(struct song_node.artist));
    return n;
}
