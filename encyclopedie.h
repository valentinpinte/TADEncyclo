#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct article
{
    long id;
    char *title;
    char *content;
    struct article *next;
};

typedef struct article * Encyclopedie;

Encyclopedie creer_encyclopedie();
Encyclopedie inserer(Encyclopedie e, long index, char *title,char *content);