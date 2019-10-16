#include "encyclopedie.h"

Encyclopedie creer_encyclopedie(){
    Encyclopedie nouvelle;
    nouvelle = (Encyclopedie)malloc(sizeof(Encyclopedie));
    return nouvelle;
};

Encyclopedie inserer(Encyclopedie e, long id, char *title , char *content){
    Article nouveau;
    nouveau = (Article)malloc(sizeof(Article));
    nouveau->title = (char)malloc(sizeof(char) * strlen(title));
};