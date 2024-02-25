#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct client {
    int code;
    char nom[30];
    float solde;
};
typedef struct client CLIENT;

void remplir_fiche(CLIENT *c, char *s) {
    printf("donner le code : ");
    fflush(stdin);
    scanf("%d", &c->code);
    printf("donner le nom : ");
    fflush(stdin);
    fgets(c->nom, 30, stdin);
    printf("donner le solde : ");
    fflush(stdin);
    scanf("%f", &c->solde);
}

void afficher_client(CLIENT C) {
    printf("%d%s%f \n", C.code, C.nom, C.solde);
}

void afficher_tab(CLIENT t[], int n) {
    for (int i = 0; i < n; i++) {
        afficher_client(t[i]);
    }
}

int remplir_tab(CLIENT t[], FILE *fp) {
    char s[100];
    int i;
    for (i = 0; fgets(s, 100, fp); i++) {
        printf("client n°%d : \n", i);
        remplir_fiche(&t[i], s);
    }
    return i;
}

float recherchedicho(CLIENT t[], int n, int code) {
    int d, f, m;
    for (d = 0, f = n - 1, m = ((int)((d + f) / 2)); f >= d; m = ((d + f) / 2)) {
        if (t[m].code == code)
            return t[m].solde;
        else
            if (t[m].code < code) {
                d = m + 1;
            }
            else {
                f = m - 1;
            }
    }
    return -1;
}

int main(int argc, char *argv[]) {
    CLIENT *t;
    int code, n;
    float solde;
    FILE *fp;
    
    if (argc != 2) {
        printf("Usage: %s <nom_fichier>\n", argv[0]);
        return 1;
    }

    // ouvrir le fichier en lecture
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }

    // allocation dynamique du tableau
    t = (CLIENT *)malloc(10 * sizeof(CLIENT));
    if (t == NULL) {
        printf("Allocation de mémoire échouée");
        exit(1);
    }

    n = remplir_tab(t, fp);
    fclose(fp);

    // demander le code à rechercher
    printf("Entrez le code à rechercher : ");
    scanf("%d", &code);

    solde = recherchedicho(t, n, code);
    printf("%f\n", solde);

    afficher_tab(t, n);

    // libérer la mémoire allouée
    free(t);

    return 0;
}

