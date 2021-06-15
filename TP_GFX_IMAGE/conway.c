#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 
#include "GfxLib.h" 
#include "BmpLib.h"
#include "ESLib.h" 
#include "conway.h"

#define LargeurFenetre 1200
#define HauteurFenetre 1000

void gestionEvenement(EvenementGfx evenement);

int main(int argc, char **argv)
{
	initialiseGfx(argc, argv);
	prepareFenetreGraphique("CONWAY", LargeurFenetre, HauteurFenetre);
	modePleinEcran();
	lanceBoucleEvenements();
	LibererMemoireGrille();
	return 0;
}

void gestionEvenement(EvenementGfx evenement)
{
	switch (evenement)
	{
		case Initialisation:;
			InitialisationGrille();
			demandeTemporisation(20);
			break;
		
		case Temporisation:
			rafraichisFenetre();
			break;
			
		case Affichage:
			effaceFenetre(0,0,0);
			couleurCourante(255,255,255);
			epaisseurDeTrait(2);
			AffichageGrille();
			AffichageMatrice();
			epaisseurDeTrait(3);
			AffichageMenu();
			epaisseurDeTrait(2);
			AfficheBtnPlus(etatBtnPlus);
			epaisseurDeTrait(2);
			AfficheBtnMoins(etatBtnMoins);
			break;
			
		case Clavier:
			printf("%c : ASCII %d\n", caractereClavier(), caractereClavier());

			switch (caractereClavier())
			{
				case 'Q': 
				case 'q':
					termineBoucleEvenements();
					break;

				case 'F':
				case 'f':
					modePleinEcran();	
					break;
			}
			break;
			
		case ClavierSpecial:
			printf("ASCII %d\n", toucheClavier());
			break;

		case BoutonSouris:
			if (etatBoutonSouris() == GaucheAppuye)
			{
				if(ordonneeSouris()>hauteurFenetre()*0.12){
					SourisCase();
				}
				//Pour bouton Plus
				if(abscisseSouris()>=largeurFenetre()*0.8 && ordonneeSouris()<=hauteurFenetre()*0.12*0.9 && abscisseSouris()<=largeurFenetre()*0.9 && ordonneeSouris()>=hauteurFenetre()*0.12*0.1){
					BtnPlus(pt_lignes_grilles, pt_colonnes_grilles); 
					etatBtnPlus=1;
					printf("%d\n", lignes_grilles);
				}
				//Pour bouton Moins
				if(abscisseSouris()>=largeurFenetre()*0.68 && ordonneeSouris()<=hauteurFenetre()*0.12*0.9 && abscisseSouris()<=largeurFenetre()*0.78 && ordonneeSouris()>=hauteurFenetre()*0.12*0.1){
					BtnMoins(pt_lignes_grilles, pt_colonnes_grilles); 
					etatBtnMoins=1;
					printf("%d\n", lignes_grilles);
				}
			}
			else if (etatBoutonSouris() == GaucheRelache)
			{
				etatBtnMoins=0;
				etatBtnPlus=0;
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

void InitialisationGrille()
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

void LibererMemoireGrille(void)
{
	for(int i=0;i<colonnes_grilles;i++)
	{
		free(grille[i]);
	}
	free(grille);
}

void AffichageMenu(void)
{
	couleurCourante(0,255,0);
	ligne(0,hauteurFenetre()*0.12,largeurFenetre(),hauteurFenetre()*0.12);
	couleurCourante(0,0,0);
	rectangle(0,hauteurFenetre()*0.12,largeurFenetre(),0);
}

void AffichageGrille(void)
{
	couleurCourante(255,255,255);
	float ratio = ((float)largeurFenetre()/(float)lignes_grilles);
	for(int i=0;i<lignes_grilles+1;i++)
	{
		ligne(ratio*i,0,ratio*i,hauteurFenetre());
	}
	for(int j=0;j<colonnes_grilles+1;j++)
	{
		ligne(0,ratio*j,largeurFenetre(),ratio*j);
	}
}

void SourisCase(void)
{
	float ratio = ((float)largeurFenetre()/(float)lignes_grilles);
	float x = abscisseSouris();
	float y = ordonneeSouris();
	int ligneX=0;
	int colonneY=0;
	for(int i=0;i<lignes_grilles+1;i++)
	{
		if(ratio*i>x)
		{
			ligneX=i;
			break;
		}
	}
	for(int j=0;j<colonnes_grilles+1;j++)
	{
		if(ratio*j>y)
		{
			colonneY=j;
			break;
		}
	}
	grille[ligneX][colonneY]=1;
}

void AffichageMatrice(void)
{
	float ratio = ((float)largeurFenetre()/(float)lignes_grilles);
	for(int i=0;i<lignes_grilles;i++)
	{
		for(int j=0;j<colonnes_grilles;j++)
		{
			if(grille[i][j]==1)
			{
				couleurCourante(255,169,0);
				rectangle(i*ratio,j*ratio,i*ratio-ratio,j*ratio-ratio);
			}
		}
	}
}

void AfficheBtnPlus(int etatBtnPlus){
	if(etatBtnPlus==0){
		couleurCourante(0, 0, 0);
		rectangle(largeurFenetre()*0.8, hauteurFenetre()*0.12*0.9, largeurFenetre()*0.9, hauteurFenetre()*0.12*0.1);
		epaisseurDeTrait(3);
		couleurCourante(255, 255, 255);
		ligne(largeurFenetre()*0.85, hauteurFenetre()*0.12*0.7, largeurFenetre()*0.85, hauteurFenetre()*0.12*0.3);
		ligne(largeurFenetre()*0.83, hauteurFenetre()*0.12*0.5, largeurFenetre()*0.87, hauteurFenetre()*0.12*0.5);
		epaisseurDeTrait(2);
		ligne(largeurFenetre()*0.8, hauteurFenetre()*0.12*0.9, largeurFenetre()*0.9, hauteurFenetre()*0.12*0.9);
		ligne(largeurFenetre()*0.8, hauteurFenetre()*0.12*0.1, largeurFenetre()*0.9, hauteurFenetre()*0.12*0.1);
		ligne(largeurFenetre()*0.8, hauteurFenetre()*0.12*0.9, largeurFenetre()*0.8, hauteurFenetre()*0.12*0.1);
		ligne(largeurFenetre()*0.9, hauteurFenetre()*0.12*0.9, largeurFenetre()*0.9, hauteurFenetre()*0.12*0.1);
	}
	else if(etatBtnPlus==1){
		couleurCourante(255, 255, 255);
		rectangle(largeurFenetre()*0.8, hauteurFenetre()*0.12*0.9, largeurFenetre()*0.9, hauteurFenetre()*0.12*0.1);
		epaisseurDeTrait(3);
		couleurCourante(0, 0, 0);
		ligne(largeurFenetre()*0.85, hauteurFenetre()*0.12*0.7, largeurFenetre()*0.85, hauteurFenetre()*0.12*0.3);
		ligne(largeurFenetre()*0.83, hauteurFenetre()*0.12*0.5, largeurFenetre()*0.87, hauteurFenetre()*0.12*0.5);
	}
}

void BtnMoins(int *lignes, int *colonnes){
	if(*lignes<146){
		*lignes=*lignes+5;
		*colonnes=*colonnes+5;
	}
}

void AfficheBtnMoins(int etatBtnMoins){
	if(etatBtnMoins==0){
		couleurCourante(0, 0, 0);
		rectangle(largeurFenetre()*0.68, hauteurFenetre()*0.12*0.9, largeurFenetre()*0.78, hauteurFenetre()*0.12*0.1);
		epaisseurDeTrait(3);
		couleurCourante(255, 255, 255);
		ligne(largeurFenetre()*0.71, hauteurFenetre()*0.12*0.5, largeurFenetre()*0.75, hauteurFenetre()*0.12*0.5);
		epaisseurDeTrait(2);
		ligne(largeurFenetre()*0.68, hauteurFenetre()*0.12*0.9, largeurFenetre()*0.78, hauteurFenetre()*0.12*0.9);
		ligne(largeurFenetre()*0.68, hauteurFenetre()*0.12*0.1, largeurFenetre()*0.78, hauteurFenetre()*0.12*0.1);
		ligne(largeurFenetre()*0.68, hauteurFenetre()*0.12*0.9, largeurFenetre()*0.68, hauteurFenetre()*0.12*0.1);
		ligne(largeurFenetre()*0.78, hauteurFenetre()*0.12*0.9, largeurFenetre()*0.78, hauteurFenetre()*0.12*0.1);
	}
	else if(etatBtnMoins==1){
		couleurCourante(255, 255, 255);
		rectangle(largeurFenetre()*0.68, hauteurFenetre()*0.12*0.9, largeurFenetre()*0.78, hauteurFenetre()*0.12*0.1);
		epaisseurDeTrait(3);
		couleurCourante(0, 0, 0);
		ligne(largeurFenetre()*0.71, hauteurFenetre()*0.12*0.5, largeurFenetre()*0.75, hauteurFenetre()*0.12*0.5);
	}
}

void BtnPlus(int *lignes, int *colonnes){
	if(*lignes>6){
		*lignes=*lignes-5;
		*colonnes=*colonnes-5;
	}
}
