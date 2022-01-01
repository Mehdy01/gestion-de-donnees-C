#include "employe.h"

#ifndef DATA_MANAGEMENT_EQUILIBRE_ARBRE_H
#define DATA_MANAGEMENT_EQUILIBRE_ARBRE_H

typedef struct Arbre {
    int cle;
    Employe* employe;
    struct Arbre *Gauche;
    struct Arbre *Droit;
    struct Arbre *Parent;
}Arbre;

Arbre* declarer_noeud();
Arbre* cree_racine(int);
Arbre* inserer_noeud(Arbre*, int);
Arbre* inserer_noeud_avec_fichier(Arbre*, int, Employe*);
Arbre* supprimer_noeud(Arbre*, int);
Arbre* rechercher_noeud(Arbre*, int);
void modifier_une_noeud(Arbre*);
void afficher_une_noeud(Arbre*);
void afficher_noeuds(Arbre*);
int compter_noeuds(Arbre*);
Arbre* clear_noueds();

#endif //DATA_MANAGEMENT_EQUILIBRE_ARBRE_H
