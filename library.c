#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "library.h"

struct song_node ** create_library() {
    struct song_node **n = calloc(LENGTH, sizeof(struct song_node *));
    return n;
}

int letter(char string[]) {
    if (!isalpha(string[0])) {
        return 0;
    }
    return (tolower(string[0]) - 'a' + 1);
}

void insert_element(struct song_node **library, char name[], char artist[]) {
    int l = letter(artist);
    library[l] = insert_node(library[l], name, artist);   
}

void print_library(struct song_node **library) {
    int i;
    for (i = 0; i < LENGTH; i++) {
        print_list(library[i]);
    }
}

struct song_node * find_element(struct song_node **library, char name[], char artist[]) {
    return find_node(library[letter(artist)], name, artist);
}

void print_letter(struct song_node **library, char l) {
    print_list(library[letter(&l)]);
}