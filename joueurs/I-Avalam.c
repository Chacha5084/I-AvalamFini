/********* Moteur de tournoi : I-Avalam ***************/

#include <stdio.h>
#include <stdlib.h>
#include "avalam.h"
#include "moteur.h"

T_ListeCoups liste;

int isoles2(octet pos1, octet pos2, T_ListeCoups coups);
int isoles3(octet pos1, octet pos2, octet pos3, T_ListeCoups coups);

void choisirCoup(T_Position currentPosition, T_ListeCoups listeCoups)
{

	int choix;
	int trait = currentPosition.trait;
	int i, o = 0, d = 0;
	printf("Ma couleur : %s\n", COLNAME(currentPosition.trait));

	// ouverture
	// SI JAUNE
	if (trait = JAU)
	{
		for (i = 0; i < listeCoups.nb; i++)
		{
			if (listeCoups.coups[i].origine == 28 && listeCoups.coups[i].destination == 21)
			{
				o = 28;
				d = 21;
			}
		}
		if (o != 0 && d != 0)
		{
			for (i = 0; i < listeCoups.nb; i++)
			{
				if (listeCoups.coups[i].origine == 12 && listeCoups.coups[i].destination == 7)
				{
					o = 12;
					d = 7;
				}
			}
		}
	}
	// SI ROUGE
	else
	{
		for (i = 0; i < listeCoups.nb; i++)
		{
			if (listeCoups.coups[i].origine == 26 && listeCoups.coups[i].destination == 19)
			{
				o = 26;
				d = 19;
			}
			else if (listeCoups.coups[i].origine == 27 && listeCoups.coups[i].destination == 19)
			{
				o = 27;
				d = 19;
			}
		}
	}

	// contre
	// SI JAUNE
	if (trait = JAU)
	{
		if (currentPosition.cols[26].couleur == VIDE && currentPosition.cols[19].couleur == JAU && currentPosition.cols[19].nb == 2)
		{
			o = 17;
			d = 18;
		}
		if (currentPosition.cols[21].couleur == VIDE && currentPosition.cols[28].couleur == JAU && currentPosition.cols[28].nb == 2)
		{
			o = 30;
			d = 29;
		}
	}
	// SI ROUGE
	if (trait = ROU)
	{
		if ((currentPosition.cols[47].couleur == VIDE && currentPosition.cols[45].couleur == ROU && currentPosition.cols[45].nb == 2) && (currentPosition.cols[44].couleur == VIDE && currentPosition.cols[43].couleur == JAU && currentPosition.cols[43].nb == 3))
		{
			o = 45;
			d = 41;
		}
		else if (currentPosition.cols[47].couleur == VIDE && currentPosition.cols[45].couleur == ROU && currentPosition.cols[45].nb == 2)
		{
			o = 46;
			d = 44;
		}

		if ((currentPosition.cols[0].couleur == VIDE && currentPosition.cols[2].couleur == ROU && currentPosition.cols[2].nb == 2) && (currentPosition.cols[3].couleur == VIDE && currentPosition.cols[4].couleur == JAU && currentPosition.cols[4].nb == 3))
		{
			o = 2;
			d = 6;
		}
		else if (currentPosition.cols[0].couleur == VIDE && currentPosition.cols[2].couleur == ROU && currentPosition.cols[2].nb == 2)
		{
			o = 1;
			d = 3;
		}
	}
	// ------------------------------------------------------------------------------------------------------------
	// int i, o, d;
	// printf("Ma couleur : %s\n", COLNAME(currentPosition.trait));
	// for(i=0;i<listeCoups.nb; i++) {
	// 	o = listeCoups.coups[i].origine;
	// 	d = listeCoups.coups[i].destination;
	// 	printf("Coup %d : ", i);
	// 	printf("%d (%d - %s) ->", o, currentPosition.cols[o].nb, COLNAME(currentPosition.cols[o].couleur));
	// 	printf("%d (%d - %s) \n", d, currentPosition.cols[d].nb, COLNAME(currentPosition.cols[d].couleur));
	// }

	// printf("Votre choix ? ");
	// scanf("%d", &choix);
	// printf("Vous avez choisi %d\n", choix);
	// ecrireIndexCoup(choix);
	//  -------------------------------------------------------------------------------------------------------------
}

int isoles2(octet pos1, octet pos2, T_ListeCoups coups)
{
	for (int i = 0; i < coups.nb; i++)
	{
		if ((coups.coups[i].origine == pos1 && coups.coups[i].destination != pos2) || (coups.coups[i].origine == pos2 && coups.coups[i].destination != pos1))
			return 0;
	}
	return 1;
}

int isoles3(octet pos1, octet pos2, octet pos3, T_ListeCoups coups)
{
	int check12;
	int check13;
	int check21;
	int check23;
	int check31;
	int check32;
	for (int i = 0; i < coups.nb; i++)
	{
		check12 = coups.coups[i].origine == pos1 && coups.coups[i].destination != pos2;
		check13 = coups.coups[i].origine == pos1 && coups.coups[i].destination != pos3;
		check21 = coups.coups[i].origine == pos2 && coups.coups[i].destination != pos1;
		check23 = coups.coups[i].origine == pos2 && coups.coups[i].destination != pos3;
		check31 = coups.coups[i].origine == pos3 && coups.coups[i].destination != pos1;
		check32 = coups.coups[i].origine == pos3 && coups.coups[i].destination != pos2;

		if (check12 || check13 || check21 || check23 || check31 || check32)
			return 0;
	}
	return 1;
}