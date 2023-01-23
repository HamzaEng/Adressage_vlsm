#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"

int main()
{
    int ip[4], masque, nbrReseaux, Prefixe;
    int pas; // c'est le pas pour determiner les @reseaux
    int tmp, j, i;
    affichage();
    printf("Donner une addresse ip: ");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
    printf("Donner le masque de reseau: /");
debut:
    scanf("%d", &masque);
    printf("Donner le nombre des reseaux Lans && Wans: ");
    scanf("%d", &nbrReseaux);
    int sousReseau[nbrReseaux];
    printf("saisi la taille de chaque reseau: \n");
    for (i = 0; i < nbrReseaux; i++)
    { // recuperation de l'adresse ip à partir de l'utilisateur
        printf("sousReseau[%d]: ", i + 1);
        scanf("%d", &sousReseau[i]);
    }
    if (validePrefixe(sousReseau, nbrReseaux, masque) == 1)
    { // le cas ou le masque est suffisante
        // trier les sous reseaux
        trierTableau(sousReseau, nbrReseaux);
        for (i = 0; i < nbrReseaux; i++)
        {
            j = getPrefixe(sousReseau[i]);
            Prefixe = 32 - j;
            printf("size: %d =>\t %d.%d.%d.%d \t\t", sousReseau[i], ip[0], ip[1], ip[2], ip[3]);
            brodcast(ip, Prefixe);
            printf("\t\t");
            netMask(Prefixe);
            printf(" /%d\n", Prefixe);
            if (Prefixe >= 2 && Prefixe <= 8)
            { // cas d'octet 1
                pas = pow(2, 32) / pow(2, j);
                ip[0] = ip[0] + pas;
            }
            if (Prefixe > 8 && Prefixe <= 16)
            { // cas d'octet 2
                pas = pow(2, j) / pow(2, 16);
                ip[1] = ip[1] + pas;
                if (ip[1] > 255)
                {
                    ip[0] = ip[0] + (ip[1] - 255);
                    ip[1] = 0;
                }
            }
            if (Prefixe > 16 && Prefixe <= 24)
            { // cas d'octet 3
                pas = pow(2, j) / pow(2, 8);
                ip[2] = ip[2] + pas;
                if (ip[2] > 255)
                {
                    ip[1] = ip[1] + (ip[2] - 255);
                    ip[2] = 0;
                }
            }
            if (Prefixe > 24 && Prefixe <= 30)
            { // cas d'octet 4
                pas = pow(2, j);
                ip[3] = ip[3] + pas;
                if (ip[3] > 255)
                {
                    ip[2] = ip[2] + (ip[3] - 255);
                    ip[3] = 0;
                }
            }
        }
    } // le cas ou le masque n'est pas suffisante
    else
    {
        printf("Erreur!! ce masque est insuffisant");
        printf("\n s'il vous plait entrer une masque suffisante : ");
        goto debut;
    }

    return 0;
}