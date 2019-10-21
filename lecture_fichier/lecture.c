#include "lecture.h"

ptEncyclopedie lecture_fichier(char *nomFichier)
{
    printf("Lecture fichier\n");
    FILE *f;

    ptEncyclopedie resultat;
    long id;
    char lectureActu[1000000];
    char *titre, *titreTempo, *contenue;
    int i, retour;
    char poubelle;
    ptArticle articleActu;
    resultat = creer_encyclopedie();

    if (!(f = fopen(nomFichier, "r")))
    {
        printf("erreur d'ouverture du fichier %s.\n", nomFichier);
    }
    else
    {

        retour = fscanf(f, "%ld", &id);

        while (retour != EOF)
        {

            i = 0;

            retour = fscanf(f, "%c", &lectureActu[i]);
            while (lectureActu[i] != '\n' && lectureActu[i] != '\r')
            {
                i++;
                retour = fscanf(f, "%c", &lectureActu[i]);
            }
            lectureActu[i] = '\n';
            
            titreTempo = strchr(lectureActu, '|') +1;
            contenue = strchr(titreTempo, '|') + 1;

            char *x;
            x = strstr(titreTempo, "|") + 1;
            printf("\nx : %s\n", x);
            printf("\ntempo : %s\n", titreTempo);

            int nb = x - titreTempo;

            titre = malloc(sizeof(char) * (nb+1));
            strncpy(titre, titreTempo, nb-1);
            titre[nb+1] = 0;

            printf("nb %d\n", nb);

            printf("id : \n%ld\ntitre :\n%s\n",id,titre);
            printf("\ncontenue %s\n", contenue);
            inserer(resultat, id, titre, contenue);
            
            retour = fscanf(f, "%ld", &id);
            //free(titre);
        }
    }

    return resultat;
}
