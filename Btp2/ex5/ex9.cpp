/*Ecrire un programme qui permet de générer le tableau tab à partir du fichier « prime.txt ». La valeur
de retour de cette fonction est le nombre de ses clients et de fournir un fichier texte «ristournes.txt»
contenant pour chaque client*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Déclaration
struct CLIENT
{
    int num;
    float MTP;
    float MGR;
};

typedef struct CLIENT CLIENT;

CLIENT tab[100][3]; // déclaration d'un tableau pour stocker les variables

int charge_client(CLIENT tab[][3])
{
    FILE *fichier;
    fichier = fopen("prime.txt", "r");

    if (fichier == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    char ligne[1000]; // déclaration d'une variable pour stocker chaque ligne
    int l = 0;

    while (fgets(ligne, sizeof(ligne), fichier) != NULL)
    {
        sscanf(ligne, "%d %f %f", &tab[l][0].num, &tab[l][1].MTP, &tab[l][2].MGR);
        l++;
    }

    fclose(fichier);

    // Nouveau tableau pour stocker les résultats sans doublons
    CLIENT result[100][3];
    int result_size = 0;

    for (int i = 0; i < l; i++)
    {
        // Vérifie si le numéro est déjà présent dans le tableau result
        int duplicate = 0;
        for (int j = 0; j < result_size; j++)
        {
            if (tab[i][0].num == result[j][0].num)
            {
                // Si trouvé, ajoute les valeurs à celles existantes
                result[j][1].MTP += tab[i][1].MTP;
                result[j][2].MGR += tab[i][2].MGR;
                duplicate = 1;
                break;
            }
        }

        // Si le numéro n'est pas déjà présent, ajoute-le au tableau result
        if (!duplicate)
        {
            result[result_size][0] = tab[i][0];
            result[result_size][1] = tab[i][1];
            result[result_size][2] = tab[i][2];
            result_size++;
        }
    }
	
	FILE *fichier1;
    fichier1 = fopen("ristournes.txt", "w");
    
    // Vérifier que le fichier a bien été ouvert
    if (fichier1 == NULL) {
        printf("Erreur");
        return 0;
    }
    
    // Écrire les résultats dans le fichier de sortie
    for (int i = 0; i < result_size; i++)
    {
        fprintf(fichier1, "%d   %.2f      %.2f\n", result[i][0].num, result[i][1].MTP, result[i][2].MGR);
    }

    return 0;
}

int main()
{
    charge_client(tab);

    return 0;
}

