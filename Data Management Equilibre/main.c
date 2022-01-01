#include <stdio.h>
#include "arbre.c"

Arbre* ajouter_avec_fichier(Arbre* arbre);
Arbre* ajouter_noeud(Arbre* arbre);
void rechercher(Arbre* arbre);
void modifier_noeud(Arbre* arbre);
void display_noeuds(Arbre* arbre);
void compter(Arbre* arbre);
Arbre* supprimer(Arbre* arbre);


void main()
{
    Arbre *arbre;
    int choix;

    printf("\n\t-----------------------OPERATIONS-----------------------\n");
    printf("\t1 - Ajouter les donnees a partir d un fichier texte\n");
    printf("\t2 - Ajouter une noeud\n");
    printf("\t3 - Rechercher une noeud\n");
    printf("\t4 - Modifier une noeud\n");
    printf("\t5 - Afficher les noeuds\n");
    printf("\t6 - Compter les noeuds\n");
    printf("\t7 - Supprimer un noeud\n");
    printf("\t8 - Detruire les noeuds\n");
    printf("\t9 - Exit\n");
    printf("\t--------------------------------------------------------");

    int cle;
    printf("\n++++++++++++++++++++++++++++ Creer Racine Noeud ++++++++++++++++++++++++++++\n");
    printf("\nEntrez la cle de votre racine : ");
    scanf("%d", &cle);
    arbre = cree_racine(cle);
    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    while(1)
    {
        printf("\n\n------------------------------------------------------------------------------------------\n\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);
        printf("\n\n------------------------------------------------------------------------------------------\n\n");
        switch (choix)
        {
            case 1:
                arbre = ajouter_avec_fichier(arbre);
                break;
            case 2:
                arbre = ajouter_noeud(arbre);
                break;
            case 3:
                rechercher(arbre);
                break;
            case 4:
                modifier_noeud(arbre);
                break;
            case 5:
                display_noeuds(arbre);
                break;
            case 6:
                compter(arbre);
                break;
            case 7:
                arbre = supprimer(arbre);
                break;
            case 8:
                arbre = clear_noueds();
                break;
            case 9:
                exit(0);
            default :
                printf("Mauvais choix, veuillez saisir le bon choix");
                break;
        }
    }
}
Arbre* ajouter_avec_fichier(Arbre* arbre){
    int cle;
    char *nom;
    char *prenom;
    int annee, mois, jour;
    float salaire;

    char nom_fichier[50];

    printf("Donnez le chemin de fichier : ");
    scanf("%s", nom_fichier);
    FILE * f = fopen(nom_fichier,"r");
    if (!f) printf("Erreur a l'ouverture de %s\n", nom_fichier);
    else
    {
        nom = (char*) malloc(50*sizeof(char));
        prenom = (char*) malloc(50*sizeof(char));
        while (!feof(f))
        {
            fscanf(f, "%d %s %s %d-%d-%d %f", &cle, nom, prenom, &annee, &mois, &jour, &salaire);
            //printf("%d %s %s %d-%d-%d %f\n", cle, nom, prenom, annee, mois, jour, salaire);
            Employe *employe = (Employe *)malloc(sizeof(Employe));
            employe->nom = nom;
            employe->prenom = prenom;
            employe->salaire = salaire;
            employe->date_engagement.annee = annee; employe->date_engagement.mois = mois; employe->date_engagement.jour = jour;
            arbre = inserer_noeud_avec_fichier(arbre, cle, employe);
        }
        fclose(f);
    }
    return arbre;
}
Arbre* ajouter_noeud(Arbre* arbre){
    int cle;
    printf("\nEntrez la cle de votre element : ");
    scanf("%d", &cle);
    arbre = inserer_noeud(arbre, cle);
    return arbre;
}

void rechercher(Arbre* arbre){
    int cle;
    printf("\nEntrez la cle de votre element : ");
    scanf("%d", &cle);
    Arbre *noeud = rechercher_noeud(arbre, cle);
    if(noeud==NULL){
        printf("L'element avec cette cle n'exist pas");
    }
    else{
        afficher_une_noeud(noeud);
    }
}

void modifier_noeud(Arbre* arbre){
    int cle;
    printf("\nEntrez la cle de la noeud a modifier : ");
    scanf("%d", &cle);
    Arbre *noeud = rechercher_noeud(arbre, cle);
    if(noeud==NULL){
        printf("L'element avec cette cle n'exist pas");
    }
    else{
        modifier_une_noeud(noeud);
    }
}

void display_noeuds(Arbre* arbre){
    afficher_noeuds(arbre);
}

void compter(Arbre* arbre){
    printf("Le nombre des noeuds est %d", compter_noeuds(arbre));
}

Arbre* supprimer(Arbre* arbre){
    int cle;
    printf("\nEntrez la cle de votre element : ");
    scanf("%d", &cle);
    arbre = supprimer_noeud(arbre, cle);
    return arbre;
}