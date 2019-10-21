#include "lecture.h"

ptEncyclopedie lecture_fichier(char *nomFichier)
{
    printf("Lecture fichier\n");
    FILE *f;

    ptEncyclopedie resultat;
    long id;
    char lectureActu[1000000];
    resultat = creer_encyclopedie();

    if (!(f = fopen(nomFichier, "r")))
    {
        printf("erreur d'ouverture du fichier %s.\n", nomFichier);
    }
    else
    {


        while (fgets(lectureActu,1000000,f))
        {
            
            

            int i2 = 1;
            char *actu = strtok(lectureActu, "|");

            char *contenue,*titre;

            while (i2 <= 3)
            {
                switch (i2)
                {
                case 1:
                    
                    id = atol(actu);
                    break;
                case 2:
                    titre = malloc(sizeof(char) * (strlen(actu)+1));
                    strcpy(titre, actu);

                    break;
                case 3:
                    contenue = malloc(sizeof(char) * (strlen(actu)+1));
                    strcpy(contenue, actu);
                    break;
                }
                i2++;
                actu = strtok(NULL, "|");
            }
            inserer(resultat, id, titre, contenue);
            
        }
    }

    

    return resultat;
}
