#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
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
        if (library[i]) {
            printf("%c: ", 'A' + i - 1);
            print_list(library[i]);
        }
    }
}

struct song_node * find_element(struct song_node **library, char name[], char artist[]) {
    return find_node(library[letter(artist)], name, artist);
}

void print_letter(struct song_node **library, char l) {
    print_list(library[letter(&l)]);
}

struct song_node * find_element_artist(struct song_node **library, char artist[]) {
    return find_artist(library[letter(artist)], artist);
}

void print_artist(struct song_node ** library, char artist[]){
    struct song_node * musician = find_artist(library[letter(artist)],artist);
    printf("All songs by %s: ", artist);
    while (!strcasecmp(musician -> artist,artist)){
       printf("{ %s, %s }  ", musician->name, musician-> artist);
        if (!(musician->next)){
            break;
        }
       musician = musician->next;
    }
    printf("\n");
}
void shuffle(struct song_node ** library,int amount, int rand_seed){
    struct song_node * already_used = NULL;
    int counter [27];
    int total = 0;
    int i;
    for (int i = 0; i < 27; i++){
        total += length_list(library[i]);
        //printf("%d\n",total);
        counter[i] = total;
    }
    
    srand(rand_seed);
    for (int i = 0; i < amount; i++){
        int l = 0;
        l = rand() % total;
        int letter = 0;
        for (int i = 0; i < 27; i++){
            if (l < counter[i]){
                letter = i;
                break;
            }
        }
        struct song_node * correct_letter = library[letter];
        
        int h = counter[letter] - l;
        int c = 0;
       for (c = 1; c < h; c++){
            correct_letter = correct_letter->next;
        }
        if ((find_node(already_used,correct_letter->name,correct_letter->artist) != NULL)){
            i--;
             }
        else{
        print_node(correct_letter);
        already_used = insert_front(already_used,correct_letter->name,correct_letter->artist);
        }
           
    }
    
            }
struct song_node ** delete_song(struct song_node ** library, char song[], char artist[]){
    int a = letter(artist);
    library[a] = remove_node(library[a], song, artist);
    return library;
}

void clear_library(struct song_node **library) {
    int i;
    for (i = 0; i < LENGTH; i++) {
        library[i] = free_list(library[i]);
    }
}