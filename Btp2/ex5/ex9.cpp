/*Ecrire un programme qui permet de g�n�rer le tableau tab � partir du fichier � prime.txt �. La valeur
de retour de cette fonction est le nombre de ses clients et de fournir un fichier texte �ristournes.txt�
contenant pour chaque client*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// D�claration
struct CLIENT
{
    int num;
    float MTP;
    float MGR;
};

typedef struct CLIENT CLIENT;

CLIENT tab[100][3]; // d�claration d'un tableau pour stocker les variables

int charge_client(CLIENT tab[][3])
{
    FILE *fichier;
    fichier = fopen("prime.txt", "r");

    if (fichier == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    char ligne[1000]; // d�claration d'une variable pour stocker chaque ligne
    int l = 0;

    while (fgets(ligne, sizeof(ligne), fichier) != NULL)
    {
        sscanf(ligne, "%d %f %f", &tab[l][0].num, &tab[l][1].MTP, &tab[l][2].MGR);
        l++;
    }

    fclose(fichier);

    // Nouveau tableau pour stocker les r�sultats sans doublons
    CLIENT result[100][3];
    int result_size = 0;

    for (int i = 0; i < l; i++)
    {
        // V�rifie si le num�ro est d�j� pr�sent dans le tableau result
        int duplicate = 0;
        for (int j = 0; j < result_size; j++)
        {
            if (tab[i][0].num == result[j][0].num)
            {
                // Si trouv�, ajoute les valeurs � celles existantes
                result[j][1].MTP += tab[i][1].MTP;
                result[j][2].MGR += tab[i][2].MGR;
                duplicate = 1;
                break;
            }
        }

        // Si le num�ro n'est pas d�j� pr�sent, ajoute-le au tableau result
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
    
    // V�rifier que le fichier a bien �t� ouvert
    if (fichier1 == NULL) {
        printf("Erreur");
        return 0;
    }
    
    // �crire les r�sultats dans le fichier de sortie
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

