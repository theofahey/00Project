#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

void print_list(struct song_node *front) {
    printf("[ ");
    while (front) {
        printf("{Name: %s, Artist: %s} ", front -> name, front -> artist);
        front = front -> next;
    }
    printf("]\n");
}

struct song_node * insert_front(struct song_node *front, char name[], char artist[]) {
    struct song_node *n = malloc(sizeof(struct song_node));
    strncpy(n -> name, name, sizeof(n -> name));
    strncpy(n -> artist, artist, sizeof(n -> artist));
    return n;
}

struct song_node * free_list(struct song_node *front) {
    while (front) {
        struct song_node *next = front -> next;
        free(front);
        front = next;
    }
    return front;
}

struct song_node * remove_node(struct song_node *front, char name[], char artist[]) {
    if (!front) {
        return NULL;
    }
    if (!(strcasecmp(front -> name, name) && strcasecmp(front -> artist, artist))) {
        return front -> next;
    }
    struct song_node *temp = front;
    while (front -> next) {
        if (!(strcasecmp(front -> next -> name, name) && strcasecmp(front -> next -> artist, artist))) {
            front -> next = front -> next -> next;
            break;
        }
        front = front -> next;
    }
    return temp;
}

int compare(struct song_node *a, struct song_node *b) {
    int c = strcasecmp(a -> artist, b -> artist);
    if (!c) {
        return c;
    }
    int d = strcasecmp(a -> name, b -> name);
    if (!d) {
        return d;
    }
    return 0;
}