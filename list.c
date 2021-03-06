#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

void print_list(struct song_node *front) {
    printf("[ ");
    while (front) {
        printf("{Name: %s, Artist: %s} ", front -> name, front -> artist);
        front = front -> next;
    }
    printf("]\n");
}
void print_node(struct song_node *element) {
    if (element) {
        printf("{Name: %s, Artist: %s}\n", element -> name, element -> artist);
    }
}
struct song_node * insert_front(struct song_node *front, char name[], char artist[]) {
    struct song_node *n = malloc(sizeof(struct song_node));
    strncpy(n -> name, name, sizeof(n -> name));
    strncpy(n -> artist, artist, sizeof(n -> artist));
    n -> next = front;
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
    if (!(strcasecmp(front -> name, name) || strcasecmp(front -> artist, artist))) {
        struct song_node *temp = front -> next;
        free(front);
        return temp;
    }
    struct song_node *temp = front;
    while (front -> next) {
        if (!(strcasecmp(front -> next -> name, name) || strcasecmp(front -> next -> artist, artist))) {
            free(front -> next);
            front -> next = front -> next -> next;
            break;
        }
        front = front -> next;
    }
    return temp;
}
struct song_node * find_node(struct song_node *front, char name[], char artist[]) {
	while (front) {
	    if (!(strcasecmp(front -> name, name)) && !(strcasecmp(front -> artist,artist))) {
		    return front;
	    }
	    front = front -> next;
    }
	return NULL;
}
int compare(struct song_node *a, struct song_node *b) {
    int c = strcasecmp(a -> artist, b -> artist);
    if (c) {
        return c;
    }
    int d = strcasecmp(a -> name, b -> name);
    if (d) {
        return d;
    }
    return 0;
}

struct song_node * insert_node(struct song_node *front, char name[], char artist[]) {
    struct song_node *n = NULL;
    n = insert_front(n, name, artist);
    struct song_node *temp = front;
    if (!front) {
        return n;
    }
    if (compare(n, front) < 0) {
        n -> next = front;
        return n;
    }
    while (front -> next) {
        if (compare(front, n) < 0 && compare(n, front -> next) < 0) {
            n -> next = front -> next;
            front -> next = n;
            return temp;
        }
        front = front -> next;
    }
    front -> next = n;
    return temp;
}

struct song_node * find_artist(struct song_node *front, char artist[]) {
    while (front) {
        if (!strcasecmp(front -> artist, artist)) {
            return front;
        }
        front = front -> next;
    }
    return NULL;
}

int length_list(struct song_node *front) {
    int i = 0;
    while (front) {
        i++;
        front = front -> next;
    }
    return i;
}
struct song_node * random_node(struct song_node *front, int seed) {
    int l = length_list(front);
    srand(seed);
    l = rand() % l;
    while (l) {
        front = front -> next;
        l--;
    }
    return front;
}
