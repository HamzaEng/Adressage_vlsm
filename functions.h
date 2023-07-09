#ifndef _addressage_H_
#define _addressage_H_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// cette fonction permet d'obtenir l'adresse masque de sous-reseau à partir d'un prefixe donné
void netMask(int prefixe)
{
    int i;
    int s = 0;
    if (prefixe > 2 && prefixe <= 8)
    { // le cas de premier octet
        for (i = 7; i >= 0; i--)
        {
            if (i >= 8 - prefixe)
            {
                s = s + pow(2, i);
            }
        }
        printf("%d.0.0.0", s);
    }
    if (prefixe > 8 && prefixe <= 16)
    { // le cas de deuxieme octet
        for (i = 7; i >= 0; i--)
        {
            if (i >= 8 - prefixe + 8)
            {
                s = s + pow(2, i);
            }
        }
        printf("255.%d.0.0", s);
    }
    if (prefixe > 16 && prefixe <= 24)
    { // le cas de troisieme octet
        for (i = 7; i >= 0; i--)
        {
            if (i >= 8 - prefixe + 16)
            {
                s = s + pow(2, i);
            }
        }
        printf("255.255.%d.0", s);
    }
    if (prefixe > 24 && prefixe <= 30)
    { // le cas de quatrieme octet
        for (i = 7; i >= 0; i--)
        {
            if (i >= 8 - prefixe + 24)
            {
                s = s + pow(2, i);
            }
        }
        printf("255.255.255.%d", s);
    }
}
// la fonction brodcast permet d'obtenir l'adresse de diffusion
void brodcast(int ipAdd[], int prefixe)
{
    int i, index;
    int s = 0;
    int temp;
    if (prefixe >= 2 && prefixe <= 8)
    {
        index = 8 - prefixe;
        for (i = 0; i < index; i++)
        {
            s += pow(2, i);
        }
        temp = ipAdd[0] + s;
        printf("%d.255.255.255", temp);
    }
    else if (prefixe > 8 && prefixe <= 16)
    {
        index = 8 - prefixe + 8;
        for (i = 0; i < index; i++)
        {
            s += pow(2, i);
        }
        temp = ipAdd[1] + s;
        printf("%d.%d.255.255", ipAdd[0], temp);
    }
    else if (prefixe > 16 && prefixe <= 24)
    {
        index = 8 - prefixe + 16;
        for (i = 0; i < index; i++)
        {
            s += pow(2, i);
        }
        temp = ipAdd[2] + s;
        printf("%d.%d.%d.255", ipAdd[0], ipAdd[1], temp);
    }
    else if (prefixe > 24 && prefixe <= 30)
    {
        index = 8 - prefixe + 24;
        for (i = 0; i < index; i++)
        {
            s += pow(2, i);
        }
        temp = ipAdd[3] + s;
        printf("%d.%d.%d.%d", ipAdd[0], ipAdd[1], ipAdd[2], temp);
    }
    else
    {
        printf("s'il vous plait entrer une prefixe correcte");
    }
}

// fonction verfiier la suffisance de prefixe donné par utilisateur
int validePrefixe(int table[], int size, int prefixe)
{                    // table indique les besoins des sous-reseaux sousReseau[0], sousReseau[1] ...
    int besoin = 0;  // besoin indique le totale des besoins en @ip
    int taile, i, j; // taile indique la taille fourni par la prefixe donne
    for (i = 0; i < size; i++)
    {
        j = 0;
        do
        {
            if (table[i] <= pow(2, j))
            {
                break;
            }
            j++;
        } while (table[i] > pow(2, j));
        besoin += pow(2, j);
    }
    taile = pow(2, (32 - prefixe));
    return besoin <= taile ? 1 : -1;
}
// fonction pour trier le tableau en ordre DESC

void trierTableau(int table[], int size)
{
    int i, j, tmp;
    for (i = 0; i < size; i++)
    {
        for (j = i; j < size; j++)
        {
            if (table[i] < table[j])
            {
                tmp = table[i];
                table[i] = table[j];
                table[j] = tmp;
            }
        }
    }
}

// fonction getPrefixe permet d'obtenir le nombre des bits de la partier hote à partir de la taille de sous-réseau
int getPrefixe(int taille)
{
    int j = 0;
    
    do
    {
        if (taille <= pow(2, j))
        {
            break;
        }
        j++;
    } while (taille > pow(2, j));
    return j;
}

void affichage()
{
    printf("\n######################################################\n\n");
    printf("############ PROGRAMME D'ADDRESSAGE TCP/IPV4 #########\n");
    printf("\n######################################################\n\n");
}

#endif
