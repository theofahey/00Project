#include <stdio.h>
#include "list.h"
#define LENGTH 27

struct song_node ** create_library();
int letter(char string[]);
void insert_element(struct song_node **library, char name[], char artist[]);
void print_library(struct song_node **library);
void print_letter(struct song_node **library, char letter);
struct song_node * find_element(struct song_node **library, char name[], char artist[]);