#include "encyclopedie.h"

Encyclopedie creer_encyclopedie(){
    Encyclopedie nouvelle;
    nouvelle = (Encyclopedie)malloc(sizeof(Encyclopedie));
    return nouvelle;
};

Encyclopedie inserer(Encyclopedie e, long id, char *title , char *content){
    Article nouveau;
    nouveau = (Article)malloc(sizeof(Article));
    nouveau->id - id;
    nouveau->title = (char)malloc(sizeof(char) * strlen(title));
    nouveau->title = title;
    nouveau->content = (char)malloc(sizeof(char) * strlen(content));
    nouveau->content = content;
    nouveau->next = e;
    e->next=nouveau;
};