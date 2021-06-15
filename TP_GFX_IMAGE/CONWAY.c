#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 
#include "GfxLib.h" 
#include "BmpLib.h"
#include "ESLib.h" 
#include "conway.h"

#define LargeurFenetre 800
#define HauteurFenetre 600
#define lignes_grilles 10
#define colonnes_grilles 10
#define CellSize 50
#define InBetween 1

void gestionEvenement(EvenementGfx evenement);

int **grille=NULL;

int main(int argc, char **argv)
{
	initialiseGfx(argc, argv);
	prepareFenetreGraphique("CONWAY", LargeurFenetre, HauteurFenetre);
	modePleinEcran();
	lanceBoucleEvenements();
	LibererMemoireGrille(grille);
	return 0;
}

void gestionEvenement(EvenementGfx evenement)
{
	switch (evenement)
	{

		case Initialisation:;
			InitialisationGrille(grille);
			demandeTemporisation(20);
			break;
		
		case Temporisation:
			rafraichisFenetre();
			break;
			
		case Affichage:
			
			effaceFenetre(0,0,0);
			couleurCourante(255,255,255);
			epaisseurDeTrait(3);
			ligne(0,hauteurFenetre()*0.12,largeurFenetre(),hauteurFenetre()*0.12);
			/*
			for ( int i = 0; i < largeurFenetre(); i++ ){
				for ( int j = 0; j < hauteurFenetre(); j++ ){
					
					couleurCourante(46,148,242);
					
					int LBCx = InBetween*(i+1) + CellSize*(i);
					int LBCy = InBetween*(j+1) + CellSize*(j+1);
					int RTCx = InBetween*(i+1) + CellSize*(i+1);
					int RTCy = InBetween*(j+1) + CellSize*(j);
					
					rectangle(RTCx, RTCy, LBCx, LBCy);
				}
			}
			*/
			break;
			
		case Clavier:
			printf("%c : ASCII %d\n", caractereClavier(), caractereClavier());

			switch (caractereClavier())
			{
				case 'Q': 
				case 'q':
					termineBoucleEvenements();
					break;
			}
			break;
			
		case ClavierSpecial:
			printf("ASCII %d\n", toucheClavier());
			break;

		case BoutonSouris:
			if (etatBoutonSouris() == GaucheAppuye)
			{
				printf("Bouton gauche appuye en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
			}
			else if (etatBoutonSouris() == GaucheRelache)
			{
				printf("Bouton gauche relache en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
			}
			break;
		
		case Souris:
			break;
		
		case Inactivite:
			break;
		
		case Redimensionnement: 
			printf("Largeur : %d\t", largeurFenetre());
			printf("Hauteur : %d\n", hauteurFenetre());
			break;
	}
}

void InitialisationGrille(int** grille)
{
	grille = (int**)malloc(lignes_grilles*sizeof(int*));
	for(int i=0;i<colonnes_grilles;i++)
	{
		grille[i]=(int*)malloc(colonnes_grilles*sizeof(int));
	}
	for(int i=0;i<lignes_grilles;i++)
	{
		for(int j=0;j<colonnes_grilles;j++)
		{
			grille[i][j]=0;
		}
	}
}

void LibererMemoireGrille(int** grille)
{
	for(int i=0;i<colonnes_grilles;i++)
	{
		free(grille[i]);
	}
	free(grille);
}
