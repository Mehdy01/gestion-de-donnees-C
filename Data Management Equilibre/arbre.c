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
    //arbre->employe = cree_employe();
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

int max(int a, int b){
    return (a > b)? a : b;
}
int height(Arbre* arbre){
    int h=0;
    if(arbre != NULL){
        int gauche_height = height(arbre->Gauche);
        int droit_height = height(arbre->Droit);
        int max_height = max(gauche_height, droit_height);
        h = max_height + 1;
    }

    return h;
}
int difference(Arbre* arbre){
    int gauche_height = height(arbre->Gauche);
    int droit_height = height(arbre->Droit);

    return gauche_height - droit_height;
}

// Droit rotate
Arbre* droitRotate(Arbre* arbre) {

    Arbre* x = arbre->Gauche;
    Arbre* y = x->Droit;

    x->Droit = arbre;
    if(arbre->Parent!=NULL) {
        if(arbre->Parent->Gauche == arbre){
            arbre->Parent->Gauche = x;
        }
        else{
            arbre->Parent->Droit = x;
        }
    }
    x->Parent = arbre->Parent;
    arbre->Gauche = y;
    if(y!=NULL){
        y->Parent = arbre;
    }
    arbre->Parent = x;
    return x;

}

// Gauche rotate
Arbre* gaucheRotate(Arbre* arbre) {
    Arbre* y = arbre->Droit;
    Arbre* x = y->Gauche;
    y->Gauche = arbre;
    if(arbre->Parent!=NULL){
        if(arbre->Parent->Gauche == arbre){
            arbre->Parent->Gauche = y;
        }
        else{
            arbre->Parent->Droit = y;
        }
    }
    y->Parent = arbre->Parent;
    arbre->Droit = x;
    if(x!=NULL){
        x->Parent = arbre;
    }
    arbre->Parent = y;
    return y;
}


Arbre* inserer_noeud(Arbre *arbre, int cle){
    if(arbre == NULL){
        arbre = cree_racine(cle);
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
    }
    else{
        printf("Il exist deja une noeud avec meme cle");
    }



    int balance = difference(arbre);

    // Cas => Droit Droit
    if(balance < -1 && cle > arbre->Droit->cle){
        return gaucheRotate(arbre);
    }
    // Cas => Gauche Gauche
    if(balance > 1 && cle < arbre->Gauche->cle){
        return droitRotate(arbre);
    }
    // Cas => Gauche Droit
    if(balance > 1 && cle > arbre->Gauche->cle){
        arbre->Gauche = gaucheRotate(arbre->Gauche);
        return droitRotate(arbre);
    }
    // Cas => Droit Gauche
    if(balance < -1 && cle < arbre->Droit->cle){
        arbre->Droit = droitRotate(arbre->Droit);
        return gaucheRotate(arbre);
    }
    return arbre;
}

Arbre* inserer_noeud_avec_fichier(Arbre* arbre, int cle, Employe* employe){

    if(arbre == NULL){
        arbre = cree_racine_avec_fichier(cle, employe);
    }
    if(arbre->cle<cle){
        if(arbre->Droit!=NULL){
            inserer_noeud_avec_fichier(arbre->Droit, cle, employe);
        }
        else{
            Arbre *arbre1 = cree_racine_avec_fichier(cle, employe);
            arbre1->Parent = arbre;
            arbre->Droit = arbre1;
        }
    }
    else if(arbre->cle>cle){
        if(arbre->Gauche!=NULL){
            inserer_noeud_avec_fichier(arbre->Gauche, cle, employe);
        }
        else{
            Arbre *arbre1 = cree_racine_avec_fichier(cle, employe);
            arbre1->Parent = arbre;
            arbre->Gauche = arbre1;
        }
    }
    else{
        printf("Il exist deja une noeud avec meme cle");
    }

    int balance = difference(arbre);

    // Cas => Droit Droit
    if(balance < -1 && cle > arbre->Droit->cle){
        return gaucheRotate(arbre);
    }
    // Cas => Gauche Gauche
    if(balance > 1 && cle < arbre->Gauche->cle){
        return droitRotate(arbre);
    }
    // Cas => Gauche Droit
    if(balance > 1 && cle > arbre->Gauche->cle){
        arbre->Gauche = gaucheRotate(arbre->Gauche);
        return droitRotate(arbre);
    }
    // Cas => Droit Gauche
    if(balance < -1 && cle < arbre->Droit->cle){
        arbre->Droit = droitRotate(arbre->Droit);
        return gaucheRotate(arbre);
    }
    return arbre;
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
Arbre* supprimer_noeud(Arbre* arbre, int cle){
    if(arbre == NULL){
        printf("Aucun element dans l'arbre a supprimer");
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

    int balance = difference(arbre);

    // Cas => Droit Droit
    if(balance < -1 && difference(arbre->Droit) <= 0){
        return gaucheRotate(arbre);
    }
    // Cas => Gauche Gauche
    if(balance > 1 && difference(arbre->Gauche) >= 0){
        return droitRotate(arbre);
    }
    // Cas => Gauche Droit
    if(balance > 1 && difference(arbre->Gauche) < 0){
        arbre->Gauche = gaucheRotate(arbre->Gauche);
        return droitRotate(arbre);
    }
    // Cas => Droit Gauche
    if(balance < -1 && difference(arbre->Droit) > 0){
        arbre->Droit = droitRotate(arbre->Droit);
        return gaucheRotate(arbre);
    }
    return arbre;
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

