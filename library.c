#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

struct song_node ** create_library() {
    struct song_node **n = calloc(27, sizeof(struct song_node *));
    return n;
}