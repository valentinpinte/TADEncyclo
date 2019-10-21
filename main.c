#include "./liste_chainee/liste.h"

int main(int argc, char const *argv[])
{
    ptEncyclopedie e = creer_encyclopedie();
    /*
    e = inserer(e, 1000, "testtt", "coucou");
   

    e = inserer(e, 2000, "Test", "Test");
    printf("ok inserer 2\n");
    */

    //affichage(e);
    //printf("ok affichage\n");

    //e = supprimer(e, 2000);
    //affichage(e);
    //printf("ok supp\n");

    e = lecture_fichier("test.dat");

    affichage(e);

    //printf("\n\nRECHERCHEEEEEEEEEEEEEEEEEEEEEE\n\n\n\nContenu de l'article 1000 : %s\n", rechercher_article(e, 6877038));
    detruire_bibliotheque(e);
    return 0;
}
