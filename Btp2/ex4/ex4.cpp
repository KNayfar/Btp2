#include <string.h>
#include <stdio.h>

int main() {
	int i;//déclaration de i (compteur parcourant la chaîne)
    int j = 0;//déclaration de j (compteur pour sauvegarder la position de l'espace à chaque fois)
    int k = 0;//déclaration de k (compteur parcourant les cases du tableau T)
    
	//déclaration du tableu ou je vais sauvegarder les mots de la chaine source
	char T[50][100];
    
	//déclaration et scan de la chaine source
	char ch[100];
    printf("Entrez une chaine : ");
    //scanf("%99[^\n]", ch);//j'ai utilisez %99[^\n] pour lire toute la ligne jusqu'au retour à la ligne
	gets(ch);
	//initialisation de j à 0
    j = 0;

    //décomposition de la chaîne source
    for (i = 0; i <= strlen(ch); i++) {
        if (ch[i] == ' ' || ch[i] == '\0') {
            strncpy(T[k], ch + j, i - j);
            T[k][i - j] = '\0';
            k++;
            j = i + 1;
        }
    }

    //déclaration et initialisation à 0 d'un tableau V pour stocker le nombre d'occurrences de chaque mot
    int V[50];
    for (i = 0; i < k; i++) {
        V[i] = 0;
    }

    //compter les occurrences de chaque mot
    for (i = 0; i < k; i++) {
        if (T[i][0] != '\0') {
            for (j = i + 1; j < k; j++) {
                if (strcmp(T[i], T[j]) == 0) {
                    V[i]++;
                    T[j][0] = '\0';
                }
            }
        }
    }

    //afficher les mots et leurs occurrences
    for (i = 0; i < k; i++) {
        if ((T[i][0] != '\0') && (V[i] != 0)) {
            printf("%s est repete %d fois.\n", T[i], V[i]+1);
        }
    }

}
