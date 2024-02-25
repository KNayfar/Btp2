#include <stdio.h>
#include <stdlib.h>

// Structure repr�sentant un �l�ment du tableau
struct Occurence_car {
    char c;
    int repetition;
};

// Fonction pour ins�rer un caract�re dans le tableau de structure
void insere_caractere(struct Occurence_car tableau[], int *n, char nouveau_caractere) {
    // V�rifier si le caract�re existe d�j� dans le tableau
    for (int i = 0; i < *n; i++) {
        if (tableau[i].c == nouveau_caractere) {
            // Le caract�re existe, augmenter le nombre de r�p�titions
            tableau[i].repetition++;
            return; // Sortir de la fonction car le travail est termin�
        }
    }

    // Le caract�re n'existe pas encore dans le tableau, l'ajouter
    tableau[*n].c = nouveau_caractere;
    tableau[*n].repetition = 1;
    (*n)++; // Augmenter la taille du tableau
}

int main() {
    // Exemple d'utilisation de la fonction
    struct Occurence_car tableau[256]; // Tableau de structures
    int n = 0; // Taille initiale du tableau

    // Appel de la fonction pour ins�rer des caract�res dans le tableau
    char nom_fichier[30];
    FILE *fp;
    char c;

    printf("Donner le nom du fichier : ");
    gets(nom_fichier);

    if (!(fp = fopen(nom_fichier, "r"))) {
        printf("Fichier inexistant\n");
        exit(0);
    }

    while ((c = fgetc(fp)) != EOF) {
        insere_caractere(tableau, &n, c);
    }

    // Afficher le contenu du tableau apr�s les insertions
    printf("Caractere\tRepetition\n");
    for (int i = 0; i < n; i++) {
        printf("%c\t\t%d\n", tableau[i].c, tableau[i].repetition);
    }

    fclose(fp);

    return 0;
}

