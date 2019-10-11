#include <stdio.h>
#include <stdlib.h>

struct no{
    int elemento;
    struct no* prox;
    struct no* ant;
    };

    typedef struct no NO;
