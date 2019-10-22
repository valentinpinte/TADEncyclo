#include "liste.h"

ptEncyclopedie inserer(ptEncyclopedie e, long id, char *titre, char *contenu)
{
	ptArticle nArticle;
	ptMaillon nMaillon;
	nArticle = (ptArticle)malloc(sizeof(article));
	nArticle->id = id;
	//nArticle->titre = malloc(sizeof(char) * strlen(titre));
	nArticle->titre = titre;
	//nArticle->contenu = malloc(sizeof(char) * strlen(contenu));
	nArticle->contenu = contenu;

	nMaillon = (ptMaillon)malloc(sizeof(maillon));
	nMaillon->article = nArticle;

	nMaillon->maillonSuivant = e->premier;
	e->premier = nMaillon;
	//printf(" TITRE INSERTION %s  ID %ld CONTENUE %s\n", ((ptMaillon)(e->premier))->article->titre, ((ptMaillon)(e->premier))->article->id, ((ptMaillon)(e->premier))->article->contenu);
	return e;
}

ptEncyclopedie supprimer(ptEncyclopedie e, long id)
{
	bool supprime;
	ptMaillon maillon, precedent;
	supprime = false;
	maillon = (ptMaillon)e->premier;
	//printf("ok %ld\n",maillon->article);
	//printf("id : %ld \n",maillon->article->id);
	precedent = NULL;
	while (supprime == false && maillon != NULL)
	{
		if (maillon->article->id == id)
		{
			
			if (precedent == NULL)
			{
				e->premier = maillon->maillonSuivant;
			}
			else
			{
				precedent->maillonSuivant = maillon->maillonSuivant;
			}
			free(maillon->article);
			free(maillon);
			supprime = true;
		}
		precedent = maillon;
		maillon = maillon->maillonSuivant;
	}
	return e;
}

char *rechercher_article(ptEncyclopedie e, long id)
{
	char *resultat = NULL;
	ptMaillon maillon;
	maillon = e->premier;
	while (maillon != NULL && resultat == NULL)
	{
		if (maillon->article->id == id)
		{

			resultat = maillon->article->contenu;
		}
		maillon = maillon->maillonSuivant;
	}

	return resultat;
}

void affichage(ptEncyclopedie e)
{

	printf("AFFICHAGE \n");

	if (e->premier == NULL)
	{
		printf("C NULL \n");
	}
	ptMaillon maillon;
	maillon = e->premier;

	while (maillon != NULL)
	{
		printf("\nid : %ld \ntitre : %s\ncontenue : %0.100s", maillon->article->id, maillon->article->titre, maillon->article->contenu);
		maillon = maillon->maillonSuivant;
	}
}

ptEncyclopedie rechercher_article_plein_texte(ptEncyclopedie e, char *word)
{
	ptEncyclopedie newEncyclopedie;
	newEncyclopedie = creer_encyclopedie();
	ptMaillon maillon;
	maillon = e->premier;
	while (maillon != NULL)
	{
		if (strstr(maillon->article->contenu, word) || strstr(maillon->article->titre, word))
		{
			long id = maillon->article->id;
			char *titre = malloc(sizeof(char) * (strlen(maillon->article->titre) + 1));
			strcpy(titre,maillon->article->titre);
			char *contenu = malloc(sizeof(char) * (strlen(maillon->article->contenu) + 1));
			strcpy(contenu,maillon->article->contenu);
			inserer(newEncyclopedie,id,titre,contenu);
		}
		maillon = maillon->maillonSuivant;
	}
	return newEncyclopedie;
}

ptEncyclopedie detruire_bibliotheque(ptEncyclopedie e)
{
	ptMaillon maillon;
	maillon = e->premier;
	while (maillon != NULL)
	{
		e->premier = maillon->maillonSuivant;
		free(maillon->article->titre);
		free(maillon->article->contenu);
		free(maillon->article);
		free(maillon);
		maillon = e->premier;
	}
	free(e);
	printf("\nL'encyclopedie a ete detruite\n");
	return e;
}