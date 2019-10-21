#include "arbre.h"
#include <stdbool.h>

ptEncyclopedie inserer(ptEncyclopedie e, long id, char *titre, char *contenu){
    ptArticle nArticle;
    Arbre nFeuille,parcours;
    nArticle = malloc(sizeof(article));
    nArticle->id = id;
    nArticle->titre = malloc(sizeof(char) * strlen(titre));
    nArticle->titre = titre;
    nArticle->contenu = malloc(sizeof(char) * strlen(contenu));
    nArticle->contenu = contenu;
    
    nFeuille = malloc(sizeof(Node));
    nFeuille->article = nArticle;
    nFeuille->feuilleGauche = NULL;
    nFeuille->feuilleDroite = NULL;
    
    if(e->premier == NULL) {
    	printf("Premier insere\n");
    	e->premier = nFeuille;
    } else {
    	parcours = e->premier;
    	while(parcours != NULL) {
    		if(id < parcours->article->id) {
    			if(parcours->feuilleGauche != NULL) {
    				parcours = parcours->feuilleGauche;
    			} else {
    				parcours->feuilleGauche = nFeuille;
    				parcours = NULL;
    			}
    		} else {
    			if(parcours->feuilleDroite != NULL) {
    				parcours = parcours->feuilleDroite;
    			} else {
    				parcours->feuilleDroite = nFeuille;
    				parcours = NULL;
    			}
    		}
    	}
    }
    
    printf("Insertion reussie :\nID : %ld \nTitre : %s\nContenu : %s\n",id,titre,contenu);
    return e;
}

/*ptEncyclopedie supprimer(ptEncyclopedie e, long id){
	bool supprime;
	Arbre parcours, precedent;
	article art;
	
	if(e->premier != NULL) {
		supprime = false;
		parcours = e->premier;
		precedent = NULL;
		while(supprime==false && parcours!=NULL) {
			if(parcours->article->id==id) {			
				free(parcours->article);
				if(precedent==NULL) {
					e->premier = parcours->maillonSuivant;
				} else {
					precedent->maillonSuivant = maillon->maillonSuivant;
				}
				printf("Supprime : %s \n",maillon->article->titre);
				free(maillon);
				supprime = true;
			}
			precedent = maillon;
			maillon = maillon->maillonSuivant;		
		}
	}
	return e;
}

char* rechercher_article(ptEncyclopedie e, long id) {
	char* resultat = NULL;	
	ptMaillon maillon;
	maillon = e->premier;
	while(maillon!=NULL && resultat==NULL) {
		if(maillon->article->id==id) {
			
			resultat = maillon->article->contenu;
		}
		maillon = maillon->maillonSuivant;
	}
	
	return resultat;
}

encyclopedie rechercher_article_plein_texte(encyclopedie e, char* word){
	encyclopedie newEncyclopedie;
	newEncyclopedie = creer_encyclopedie();
	ptMaillon maillon;
	maillon = e.premier;
	while(maillon!=NULL){
		if(maillon->article->contenu){
		}
		maillon = maillon->maillonSuivant;
	}
	return newEncyclopedie;
}

void detruire_bibliotheque(ptEncyclopedie e) {
	ptMaillon maillon;
	maillon = e->premier;
	while(maillon!=NULL) {		
		e->premier = maillon->maillonSuivant;
		free(maillon);
		maillon = e->premier;
	}
	printf("L'encyclopedie a ete detruite\n");
}*/

void affichage(Arbre a,ptEncyclopedie e){
	if(a==e->premier) {
		printf("%ld %ld\n | /\n%ld\n",a->feuilleGauche->article->id,a->feuilleDroite->article->id,a->article->id);
	} else {
		if(a!=NULL) {
			printf("Oui");
			affichage(a->feuilleGauche,e);
			affichage(a->feuilleDroite,e);		
			printf("%ld %ld\n | /\n",a->feuilleGauche->article->id,a->feuilleDroite->article->id);
		} else {
			printf("     \n | /\n");
		}
	}
}