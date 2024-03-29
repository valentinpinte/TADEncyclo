#include "liste.h"
#include <stdbool.h>

ptEncyclopedie inserer(ptEncyclopedie e, long id, char *titre, char *contenu){
    ptArticle nArticle;
    ptMaillon nMaillon;
    nArticle = malloc(sizeof(article));
    nArticle->id = id;
    nArticle->titre = malloc(sizeof(char) * strlen(titre));
    nArticle->titre = titre;
   	nArticle->contenu = malloc(sizeof(char) * strlen(contenu));
    nArticle->contenu = contenu;
    
    nMaillon = malloc(sizeof(maillon));
    nMaillon->article = nArticle;

    nMaillon->maillonSuivant = e->premier;
    e->premier = nMaillon;
    printf(" TITRE INSERTION %s  ID %ld CONTENUE %s\n",((ptMaillon)(e->premier))->article->titre,((ptMaillon)(e->premier))->article->id,((ptMaillon)(e->premier))->article->contenu);
    return e;
}

/*encyclopedie inserer(ptEncyclopedie e, long id, char *titre, char *contenu){
    ptArticle nArticle;
    ptMaillon nMaillon;
    nArticle = malloc(sizeof(article));
    nArticle->id = id;
    nArticle->titre = malloc(sizeof(char) * strlen(titre));
    nArticle->titre = titre;
    nArticle->contenu = malloc(sizeof(char) * strlen(contenu));
    nArticle->contenu = contenu;
    
    nMaillon = malloc(sizeof(maillon));
    nMaillon->article = nArticle;

    nMaillon->maillonSuivant = e->premier;
    e->premier = nMaillon;
    printf("%s \n",((ptMaillon)(e->premier))->article->titre);
    return *e;
    
}*/

ptEncyclopedie supprimer(ptEncyclopedie e, long id){
	bool supprime;
	ptMaillon maillon, precedent;
	article art;
	supprime = false;
	maillon = (ptMaillon)e->premier;
	//printf("ok %ld\n",maillon->article);
	//printf("id : %ld \n",maillon->article->id);
	precedent = NULL;
	while(supprime==false && maillon!=NULL) {
		if(maillon->article->id==id) {			
			free(maillon->article);
			if(precedent==NULL) {
				e->premier = maillon->maillonSuivant;
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

void affichage(ptEncyclopedie e){
	
	printf("AFFICHAGE \n");	

	if(e->premier == NULL){
		printf("C NULL \n");	
	}
	ptMaillon maillon;
	maillon = e->premier;
	
	while(maillon!=NULL) {
		printf("\nid : %ld \ntitre : %s\ncontenue : %s",maillon->article->id,maillon->article->titre,maillon->article->contenu);
		maillon = maillon->maillonSuivant;
	}
}

/*encyclopedie rechercher_article_plein_texte(encyclopedie e, char* word){
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
}*/

void detruire_bibliotheque(ptEncyclopedie e) {
	ptMaillon maillon;
	maillon = e->premier;
	while(maillon!=NULL) {		
		e->premier = maillon->maillonSuivant;
		free(maillon);
		maillon = e->premier;
	}
	printf("L'encyclopedie a ete detruite\n");
}