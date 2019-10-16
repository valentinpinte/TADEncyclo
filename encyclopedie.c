#include "encyclopedie.h"

Encyclopedie creer_encyclopedie(){
    Encyclopedie nouvelle;
    nouvelle = (Encyclopedie)malloc(sizeof(struct article));
    return nouvelle;
};

Encyclopedie inserer(Encyclopedie e, long id, char *title , char *content){
    Encyclopedie nouveau = 
};