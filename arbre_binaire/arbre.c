#include "arbre.h"
#include <stdbool.h>

ptEncyclopedie inserer(ptEncyclopedie e, long id, char *titre, char *contenu) {
    ptArticle nArticle;
    Arbre nFeuille,parcours;
    nArticle = (ptArticle)malloc(sizeof(article));
    nArticle->id = id;
    //nArticle->titre = malloc(sizeof(char) * strlen(titre));
    nArticle->titre = titre;
    //nArticle->contenu = malloc(sizeof(char) * strlen(contenu));
    nArticle->contenu = contenu;
    
    nFeuille = (Arbre)malloc(sizeof(Node));
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

ptEncyclopedie supprimer(ptEncyclopedie e, long id) {
	bool supprime;
	Arbre pere, parcours, precedent, aEffacer, filsGauche;
	article art;
	
	if(e->premier != NULL) {
		supprime = false;
		parcours = e->premier;
		precedent = NULL;
		while(supprime==false && parcours!=NULL) {
			if(id < parcours->article->id) {
				precedent = parcours;
				parcours = parcours->feuilleGauche;
			} else if(id > parcours->article->id) {
				precedent = parcours;
				parcours = parcours->feuilleDroite;
			} else {
				pere = precedent;
				aEffacer = parcours;
				precedent = parcours;
				parcours = parcours->feuilleGauche;
				while(parcours->feuilleDroite!=NULL) {
					precedent = parcours;
					parcours = parcours->feuilleDroite;
				}
				pere->feuilleDroite = parcours;
				parcours->feuilleDroite = aEffacer->feuilleDroite;
				aEffacer->feuilleDroite = NULL;
				precedent->feuilleDroite = NULL;
				if(parcours->feuilleGauche!=NULL) {
					filsGauche = parcours->feuilleGauche;
					while(filsGauche->feuilleGauche!=NULL) {
						filsGauche = filsGauche->feuilleGauche;
					}
					filsGauche->feuilleGauche = aEffacer->feuilleGauche;
				} else {
					parcours->feuilleGauche = aEffacer->feuilleGauche;
				}
				aEffacer->feuilleGauche = NULL;
				//free(aEffacer->article->titre);
				//free(aEffacer->article->contenu);
				free(aEffacer->article);
				free(aEffacer);
				supprime = true;
			}
		}
		if(supprime==false) {
			printf("Erreur dans la suppression : l'article cible n'a pas ete trouve\n");
		}
	}
	return e;
}

char* rechercher_article(ptEncyclopedie e, long id) {
	char* resultat = NULL;	
	Arbre parcours;
	parcours = recherche_par_id(e->premier,id);
	if(parcours!=NULL) {
		resultat = parcours->article->contenu;
	}	
	return resultat;
}

Arbre recherche_par_id(Arbre a, long id) {
	if(a==NULL) {
		return NULL;
	} else {		
		if(id < a->article->id) {
			return recherche_par_id(a->feuilleGauche,id);
		} else if(id > a->article->id) {
			return recherche_par_id(a->feuilleDroite,id);
		} else {
			return a;
		}
	}
}

ptEncyclopedie rechercher_article_plein_texte(ptEncyclopedie e, char *word) {
	ptEncyclopedie nouv;
	nouv = creer_encyclopedie();	
	Arbre a;
	a = e->premier;
	nouv = parcours_pour_mot(a,word,nouv);
	return nouv;
}

ptEncyclopedie parcours_pour_mot(Arbre a,char *word,ptEncyclopedie nouv) {
	if(a!=NULL) {	
		if(strstr(a->article->contenu, word) || strstr(a->article->titre,word)) {
			long id = a->article->id;
			char *titre = malloc(sizeof(char) * (strlen(a->article->titre) + 1));
			strcpy(titre,a->article->titre);
			char *contenu = malloc(sizeof(char) * (strlen(a->article->contenu) + 1));
			strcpy(contenu,a->article->contenu);
			nouv = inserer(nouv,id,titre,contenu);
		}
		parcours_pour_mot(a->feuilleGauche,word,nouv);
		parcours_pour_mot(a->feuilleDroite,word,nouv);
	}
	return nouv;
}

void detruire_bibliotheque(ptEncyclopedie e) {
	Arbre a;
	a = e->premier;
	liberation_noeud(a);
	free(e);
	printf("L'encyclopedie a ete detruite\n");
}

void liberation_noeud(Arbre a) {
	if(a->feuilleGauche != NULL){
		liberation_noeud(a->feuilleGauche);
	}
	if(a->feuilleDroite != NULL){
		liberation_noeud(a->feuilleDroite);
	}
	
	
	if(a!=NULL) {
		free(a->article->titre);
		free(a->article->contenu);
		free(a->article);
		free(a);
	}
}

void affichage(Arbre a,ptEncyclopedie e,int i){
	if(a!=NULL) {
		affichage(a->feuilleGauche,e,i+1);
		affichage(a->feuilleDroite,e,i+1);		
		printf("   |  /\n(%d)%ld\n",i,a->article->id);
	}
}