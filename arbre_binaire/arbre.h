#include "../lecture_fichier/lecture.h"

typedef struct Node
{
    struct Node *feuilleGauche;
    struct Node *feuilleDroite;
    ptArticle article;
}Node, *Arbre;

ptEncyclopedie inserer(ptEncyclopedie e, long id, char *titre, char *contenu);
ptEncyclopedie supprimer(ptEncyclopedie e, long id);
//char* rechercher_article(ptEncyclopedie e, long id);
//ptEncyclopedie rechercher_article_plein_texte(encyclopedie e, char* word);
//void detruire_bibliotheque(ptEncyclopedie e);
void affichage(Arbre a,ptEncyclopedie e);