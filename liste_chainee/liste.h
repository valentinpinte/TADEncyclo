#include "../lecture_fichier/lecture.h"

typedef struct Maillon
{
    struct Maillon *maillonSuivant;
    ptArticle article;
} maillon, *ptMaillon;


ptEncyclopedie supprimer(ptEncyclopedie e, long id);
char* rechercher_article(ptEncyclopedie e, long id);
ptEncyclopedie rechercher_article_plein_texte(ptEncyclopedie e, char* word);
void detruire_bibliotheque(ptEncyclopedie e);
void affichage(ptEncyclopedie e);
