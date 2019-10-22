//#include "./liste_chainee/liste.h"
#include "./arbre_binaire/arbre.h"

int main(int argc, char const *argv[])
{
    ptEncyclopedie e = creer_encyclopedie();
    e = inserer(e, 100, "Test 100", "On aime les 100 sheh");   
    e = inserer(e, 200, "Test 200", "On aime les 200");
    e = inserer(e, 50, "Test 50", "On aime les 50 sheh");
    e = inserer(e, 25, "Test 25", "On aime les 25");
    e = inserer(e, 75, "Test 75", "On aime les 75 sheh");
    e = inserer(e, 87, "Test 87", "On aime les 87");
    e = inserer(e, 86, "Test 86", "On aime les 86 sheh");
    e = inserer(e, 93, "Test 93", "On aime les 93");
    e = inserer(e, 55, "Test 55", "On aime les 55 sheh");
    e = inserer(e, 52, "Test 52", "On aime les 52");
    e = inserer(e, 70, "Test 70", "On aime les 70 sheh");
    e = inserer(e, 60, "Test 60", "On aime les 60");
    e = inserer(e, 58, "Test 58", "On aime les 58 sheh");
    e = inserer(e, 65, "Test 65", "On aime les 65");
    
    Arbre first = e->premier;
    printf("\nAffichage de l'arbre : \n");
    affichage(first,e,0);
    
    e = supprimer(e,75);
    
    printf("\nAffichage de l'arbre : \n");
    affichage(first,e,0);
    
    char *contenuArticle;
    contenuArticle = rechercher_article(e,58);
    printf("Le contenu de l'article 58 est :\n%s\n",contenuArticle);
    
    ptEncyclopedie recherche;
    recherche = rechercher_article_plein_texte(e,"sheh");
    Arbre temp;
    temp = recherche->premier;
    printf("\nAffichage de l'arbre : \n");
    affichage(temp,recherche,0);
    printf("Test titre : %s\n",temp->article->titre);
    
    
    detruire_bibliotheque(e);
    detruire_bibliotheque(recherche);
    
    return 0;
}