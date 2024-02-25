#include <stdio.h>
#include <string.h>

// Declaration
struct Adresse {
    char Nom_rue[30];
    int Cpostal;
    char Ville[30];
};
typedef struct Adresse ADRESSE;

struct Date {
    int Jour, Mois, Annee;
};
typedef struct Date DATE;

struct Fiche {
    char Nom[30];
    char Prenom[30];
    ADRESSE adr;
    long Telephone;
    DATE d_naissance;
};
typedef struct Fiche FICHE;

void Lire_adresse(ADRESSE *A) {
    printf("Nom rue:\n");fflush(stdin);
    printf("Code postal:\n");fflush(stdin);
    printf("Nom ville:\n");fflush(stdin);
    scanf("%30s %d %30s", (A->Nom_rue), &(A->Cpostal), (A->Ville));
}

void Lire_date(DATE *D) {
    printf("Enter day month year: ");fflush(stdin);
    scanf("%d %d %d", &(D->Jour), &(D->Mois), &(D->Annee));
}

void lireFiche(FICHE *P) {
    printf("Enter name and surname: ");fflush(stdin);
    scanf("%30s %30s", (P->Nom), (P->Prenom));
    Lire_adresse(&(P->adr));
    printf("Enter telephone: ");fflush(stdin);
    scanf("%ld", &(P->Telephone));
    Lire_date(&(P->d_naissance));
}

void Affiche_adresse(ADRESSE A) {
    printf("Nom rue: %30s \n Code postal: %d\n Ville: %30s \n", (A.Nom_rue), (A.Cpostal), (A.Ville));fflush(stdin);
}

void Affiche_date(DATE D) {
    printf("Date: %d/%d/%d \n", (D.Jour), (D.Mois), (D.Annee));fflush(stdin);
}

void affichePers(FICHE P) {
    printf("Name: %30s \n Surname: %30s\n", (P.Nom), (P.Prenom));fflush(stdin);
    Affiche_adresse(P.adr);
    printf("Telephone: %ld \n", (P.Telephone));fflush(stdin);
    Affiche_date(P.d_naissance);
}

int remplirTab(FICHE t_pers[]) {
    int i, nb;
    printf("Enter number of employees: ");fflush(stdin);
    scanf("%d", &nb);

    for (i = 0; i < nb; i++)
        lireFiche(&(t_pers[i]));

    return (nb);
}

int rechercheNom(char *nom_pers, FICHE t_pers[], int nb_pers) {
    int i;
    for (i = 0; i < nb_pers; i++)
        if (!(strcmp(t_pers[i].Nom, nom_pers)))
            return (i);

    return (-1);
}

int rechercheTel(long tel, FICHE t_pers[], int nb_pers) {
    int i;
    for (i = 0; i < nb_pers; i++)
        if ((t_pers[i].Telephone) == tel)
            return (i);

    return (-1);
}

void affiche_tab_Pers(FICHE t_pers[], int nb) {
    int i;
    for (i = 0; i < nb; i++)
        affichePers(t_pers[i]);
}

int main() {
    FICHE t_pers[100];
    char nom_pers[30];
    int nb_pers, ind;
    long tel;

    nb_pers = remplirTab(t_pers);

    printf("Enter name to search: ");fflush(stdin);
    scanf("%s", nom_pers);
    ind = rechercheNom(nom_pers, t_pers, nb_pers);

    if (ind == -1){
    	printf("%s: not found", nom_pers);fflush(stdin);
	}
    else
        affichePers(t_pers[ind]);

    printf("Enter telephone to search: ");fflush(stdin);
    scanf("%ld", &tel);
    ind = rechercheTel(tel, t_pers, nb_pers);

    if (ind == -1){
    	printf("%s: not found", nom_pers);fflush(stdin);
	}
    else
        affichePers(t_pers[ind]);

    printf("Personnel table:\n");fflush(stdin);
    affiche_tab_Pers(t_pers, nb_pers);

    return 0;
}

