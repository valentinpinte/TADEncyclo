#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Article
{
    long id;
    char *titre;
    char *contenu;
} article, *ptArticle;

typedef struct Encyclopedie
{
    void *premier;
} encyclopedie, *ptEncyclopedie;

ptEncyclopedie creer_encyclopedie();
ptEncyclopedie inserer(ptEncyclopedie e, long id, char *titre, char *content);

//typedef struct maillon
//{} Maillon, *ptMaillon;

