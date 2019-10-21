//#include "./liste_chainee/liste.h"
#include "./arbre_binaire/arbre.h"

int main(int argc, char const *argv[])
{
    ptEncyclopedie e = creer_encyclopedie();    
    e = inserer(e, 10, "Test 10", "On aime les 10");
    e = inserer(e, 5, "Test 5", "On aime les 5");
    e = inserer(e, 15, "Test 15", "On aime les 15");
    e = inserer(e, 17, "Test 17", "On aime les 17");
    e = inserer(e, 13, "Test 13", "On aime les 13");
    
    Arbre first = e->premier;
    /*if(first != NULL) {
    	printf("\nTest de la racine :\nID : %ld\n",first->article->id);
    	printf("Titre : %s\n",first->article->titre);
    	printf("Contenu : %s\n",first->article->contenu);
    	printf("\nTest du gauche :\nID : %ld\n",first->feuilleGauche->article->id);
    	printf("Titre : %s\n",first->feuilleGauche->article->titre);
    	printf("Contenu : %s\n",first->feuilleGauche->article->contenu);
    	printf("\nTest du droit :\nID : %ld\n",first->feuilleDroite->article->id);
    	printf("Titre : %s\n",first->feuilleDroite->article->titre);
    	printf("Contenu : %s\n",first->feuilleDroite->article->contenu);
    };*/
    
    printf("\nAffichage de l'arbre : \n");
    affichage(first,e);
   
    /*e = inserer(e, 2000, "Test", "Test");
    printf("ok inserer 2\n");
    

    //affichage(e);
    //printf("ok affichage\n");

    //e = supprimer(e, 2000);
    //affichage(e);
    //printf("ok supp\n");

    e = lecture_fichier("test.dat");

    affichage(e);

    //printf("\n\nRECHERCHEEEEEEEEEEEEEEEEEEEEEE\n\n\n\nContenu de l'article 1000 : %s\n", rechercher_article(e, 6877038));
    detruire_bibliotheque(e);*/
    return 0;
}