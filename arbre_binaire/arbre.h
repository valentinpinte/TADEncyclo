#include "../lecture_fichier/lecture.h"

typedef struct Node
{
    struct Node *feuilleGauche;
    struct Node *feuilleDroite;
    ptArticle article;
}Node, *Arbre;

ptEncyclopedie inserer(ptEncyclopedie e, long id, char *titre, char *contenu);
ptEncyclopedie supprimer(ptEncyclopedie e, long id);
char* rechercher_article(ptEncyclopedie e, long id);
Arbre recherche_par_id(Arbre a, long id);
ptEncyclopedie rechercher_article_plein_texte(ptEncyclopedie e, char *word);
ptEncyclopedie parcours_pour_mot(Arbre a,char *word,ptEncyclopedie nouv);
void detruire_bibliotheque(ptEncyclopedie e);
void liberation_noeud(Arbre a);
void affichage(Arbre a,ptEncyclopedie e,int i);