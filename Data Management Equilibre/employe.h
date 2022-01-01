#ifndef DATA_MANAGEMENT_EQUILIBRE_EMPLOYE_H
#define DATA_MANAGEMENT_EQUILIBRE_EMPLOYE_H
typedef struct Employe{
    char* nom;
    char* prenom;
    struct
    {
        int annee;
        int mois;
        int jour;
    }date_engagement;
    float salaire;
}Employe;

Employe* cree_employe();
void affiche_employe(Employe*);
void modifier_employe(Employe*);
#endif //DATA_MANAGEMENT_EQUILIBRE_EMPLOYE_H
