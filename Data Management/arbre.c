#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"

Arbre* declarer_noeud(){
    Arbre *arbre = (Arbre*)malloc(sizeof(Arbre));
    return arbre;
}

Arbre* cree_racine(int cle){
    Arbre *arbre = declarer_noeud();
    arbre->cle = cle;
    arbre->employe = cree_employe();
    arbre->Parent = arbre->Droit = arbre->Gauche = NULL;
    return arbre;
}


Arbre* cree_racine_avec_fichier(int cle, Employe* employe){
    Arbre *arbre = declarer_noeud();
    arbre->cle = cle;
    arbre->employe = employe;
    arbre->Parent = arbre->Droit = arbre->Gauche = NULL;
    return arbre;
}
void inserer_noeud(Arbre *arbre, int cle){

    if(arbre == NULL){
        arbre = cree_racine(cle);
        return;
    }
    if(arbre->cle<cle){
        if(arbre->Droit!=NULL){
            inserer_noeud(arbre->Droit, cle);
        }
        else{
            Arbre *arbre1 = cree_racine(cle);
            arbre1->Parent = arbre;
            arbre->Droit = arbre1;
        }
        return;
    }
    else if(arbre->cle>cle){
        if(arbre->Gauche!=NULL){
            inserer_noeud(arbre->Gauche, cle);
        }
        else{
            Arbre *arbre1 = cree_racine(cle);
            arbre1->Parent = arbre;
            arbre->Gauche = arbre1;
        }
        return;
    }
    else{
        printf("Il exist deja une noeud avec meme cle");
        return;
    }
}

void inserer_noeud_avec_fichier(Arbre *arbre, int cle, Employe* employe){

    if(arbre == NULL){
        arbre = cree_racine_avec_fichier(cle, employe);
        return;
    }
    if(arbre->cle<cle){
        if(arbre->Droit!=NULL){
            inserer_noeud_avec_fichier(arbre->Droit, cle, employe);
        }
        else{
            Arbre *arbre1 = declarer_noeud();
            arbre1 = cree_racine_avec_fichier(cle, employe);
            arbre1->Parent = arbre;
            arbre->Droit = arbre1;
        }
        return;
    }
    else if(arbre->cle>cle){
        if(arbre->Gauche!=NULL){
            inserer_noeud_avec_fichier(arbre->Gauche, cle, employe);
        }
        else{
            Arbre *arbre1 = declarer_noeud();
            arbre1 = cree_racine_avec_fichier(cle, employe);
            arbre1->Parent = arbre;
            arbre->Gauche = arbre1;
        }
        return;
    }
    else{
        printf("Il exist deja une noeud avec meme cle");
        return;
    }
}

Arbre* rechercher_noeud(Arbre *arbre, int cle){
    if(arbre==NULL || arbre->cle==cle){
        return arbre;
    }

    if(arbre->cle < cle){
        return rechercher_noeud(arbre->Droit, cle);
    }

    return rechercher_noeud(arbre->Gauche, cle);
}

Arbre* MinValeurNoeud(Arbre* arbre){
    Arbre *current = arbre;
    while (current && current->Gauche != NULL){
        current = current->Gauche;
    }
    return current;
}
void supprimer_noeud(Arbre *arbre, int cle){
    if(arbre == NULL){
        printf("Aucun element dans l'arbre a supprimer");
        return;
    }

    if(arbre->cle<cle) {
        supprimer_noeud(arbre->Droit, cle);
    }
    else if(arbre->cle>cle){
        supprimer_noeud(arbre->Gauche, cle);
    }

    else {
        if(arbre->Gauche == NULL && arbre->Droit==NULL) {
            if(arbre->Parent != NULL){
                Arbre* parent = arbre->Parent;
                if(parent->Gauche == arbre){
                    parent->Gauche = NULL;
                }
                else{
                    parent->Droit = NULL;
                }
            }
            free(arbre);
        }
        else if(arbre->Gauche == NULL || arbre->Droit==NULL){
            if(arbre->Gauche == NULL){
                Arbre* parent = arbre->Parent;
                arbre->Droit->Parent = parent;
                if(parent->Gauche == arbre){
                    parent->Gauche = arbre->Droit;
                }
                else{
                    parent->Droit = arbre->Droit;
                }
            }
            else{
                Arbre* parent = arbre->Parent;
                arbre->Gauche->Parent = parent;
                if(parent->Gauche == arbre){
                    parent->Gauche = arbre->Gauche;
                }
                else{
                    parent->Droit = arbre->Gauche;
                }
            }
            free(arbre);
        }
        else{
            Arbre* MinNoeud = MinValeurNoeud(arbre->Droit);
            arbre->cle= MinNoeud->cle;
            arbre->employe = MinNoeud->employe;
            supprimer_noeud(arbre->Droit, MinNoeud->cle);
        }
    }
}
void modifier_une_noeud(Arbre *noeud){
    if(noeud!=NULL){
        printf("\n++++++++++++++++++++++++++++ Modifier Noeud ++++++++++++++++++++++++++++\n");
        modifier_employe(noeud->employe);
        printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

    }
}
void afficher_une_noeud(Arbre *noeud){
    if(noeud!=NULL){
        printf("\n++++++++++++++++++++++++++++ Affiche Noeud ++++++++++++++++++++++++++++\n");
        printf("\nCle : %d ", noeud->cle);
        affiche_employe(noeud->employe);
        printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

    }
}
void afficher_noeuds(Arbre *arbre){
    if(arbre!=NULL){
        afficher_une_noeud(arbre);
        afficher_noeuds(arbre->Gauche);
        afficher_noeuds(arbre->Droit);
    }
}
int compter_noeuds(Arbre *arbre){
    if(arbre==NULL){
        return 0;
    }

    return 1+ compter_noeuds(arbre->Gauche)+ compter_noeuds(arbre->Droit);
}

Arbre* clear_noueds(){
    return NULL;
}

