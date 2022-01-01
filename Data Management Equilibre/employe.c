#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employe.h"

Employe* cree_employe(){
    Employe *employe = (Employe *)malloc(sizeof(Employe));
    employe->nom = (char*) malloc(50*sizeof(char));
    employe->prenom = (char*) malloc(50*sizeof(char));
    printf("\n--------------------------- Saisir Employe ---------------------------\n");
    printf("Donnez le nom d'employe : ");
    scanf("%s", employe->nom);
    printf("Donnez le prenom d'employe : ");
    scanf("%s", employe->prenom);
    printf("Donnez la date d'engagement d'employe avec cette format (1975-01-15)=>(annee-mois-jour) : ");
    scanf("%d-%d-%d", &employe->date_engagement.annee, &employe->date_engagement.mois, &employe->date_engagement.jour);
    printf("Donnez le salaire d'employe : ");
    scanf("%f", &employe->salaire);
    printf("\n----------------------------------------------------------------------\n");
    return employe;
}

void affiche_employe(Employe* employe){
    printf("\n--------------------------- Affiche Employe ---------------------------\n");
    printf("Employe : %s %s\n",employe->nom, employe->prenom);
    printf("Salaire : %.2f\n", employe->salaire);
    printf("Date engagement : %d/%d/%d\n",employe->date_engagement.jour, employe->date_engagement.mois, employe->date_engagement.annee);
    printf("\n-----------------------------------------------------------------------\n");
}

char* votre_choix(char* attribute){
    char *choix = (char*)malloc(5*sizeof(char));
    printf("Vous voulez modifier le %s de l'employe ? Oui ou Non : ", attribute);
    scanf("%s", choix);
    return choix;
}
void modifier_employe(Employe* employe){
    printf("\n--------------------------- Modifier Employe ---------------------------\n");
    if(strcmp(votre_choix("nom"),"Oui")==0) {
        printf("Donnez le nom d'employe : ");
        scanf("%s", employe->nom);
    }
    if(strcmp(votre_choix("prenom"),"Oui")==0) {
        printf("Donnez le prenom d'employe : ");
        scanf("%s", employe->prenom);
    }
    if(strcmp(votre_choix("date d'engagement"),"Oui")==0) {
        printf("Donnez la date d'engagement d'employe avec cette format (1975-01-15)=>(annee-mois-jour) : ");
        scanf("%d-%d-%d", &employe->date_engagement.annee, &employe->date_engagement.mois,
              &employe->date_engagement.jour);
    }
    if(strcmp(votre_choix("salaire"),"Oui")==0) {
        printf("Donnez le salaire d'employe : ");
        scanf("%f", &employe->salaire);
    }
    printf("\n----------------------------------------------------------------------\n");
}
