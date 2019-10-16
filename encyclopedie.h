#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct maillon
{
    long id;
    char *title;
    char *content;
    struct maillon *next;
};

typedef struct maillon *Encyclopedie, *Article ;

Encyclopedie creer_encyclopedie();
Encyclopedie inserer(Encyclopedie e, long index, char *title,char *content);