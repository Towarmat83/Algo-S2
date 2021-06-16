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
	lignes2=fabs((1470-curseur)/400)*300;
	colonnes2=fabs((1470-curseur)/400)*300;
	switch (evenement)
	{
		case Initialisation:;
			InitialisationGrille();
			demandeTemporisation(20);
			break;
		
		case Temporisation:
			ModifierPositionCurseur();
			rafraichisFenetre();
			break;
			
		case Affichage:
			effaceFenetre(0,0,0);
			couleurCourante(124, 125, 124);
			epaisseurDeTrait(1);
			AffichageGrille(lignes2,colonnes2);
			AffichageMatrice(lignes2,colonnes2);
			epaisseurDeTrait(3);
			AffichageMenu();
			couleurCourante(255,255,255);
			SliderZoom(); 
			Curseur();
			AfficheBtnLecture();
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
				printf("\n%d",abscisseSouris());
				if(ordonneeSouris()>(hauteurFenetre()*0.12))
				{
					SourisCase(lignes2,colonnes2);
				}
				if(sqrt(pow(390-abscisseSouris(),2)+pow(66-ordonneeSouris(),2))<=45)
				{
					etat = 1-etat;
				}
			}
			if(etatBoutonSouris() == DroiteAppuye)
			{
				if(ordonneeSouris()>(hauteurFenetre()*0.12))
				{
					RetirerCase(lignes2,colonnes2);
				}
				if(sqrt(pow(390-abscisseSouris(),2)+pow(66-ordonneeSouris(),2))<=45)
				{
					etat = 1-etat;
				}
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
	grille = (int**)malloc((lignes_grilles+1)*sizeof(int*));
	for(int i=0;i<colonnes_grilles+1;i++)
	{
		grille[i]=(int*)malloc((colonnes_grilles+1)*sizeof(int));
	}
	for(int i=0;i<lignes_grilles+1;i++)
	{
		for(int j=0;j<colonnes_grilles+1;j++)
		{
			grille[i][j]=0;
		}
	}
	if(grille==NULL)
	{
		printf("\nImpossible d'allouer de la mémoire...");
		exit(EXIT_FAILURE);
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
	couleurCourante(0,255,0);
	ligne(largeurFenetre()-500,0,largeurFenetre()-500,hauteurFenetre()*0.12);
	ligne(460,0,460,hauteurFenetre()*0.12);
}

void AffichageGrille(float ligne2,float colonnes2)
{
	couleurCourante(124, 125, 124);
	float ratio = ((float)largeurFenetre()/(float)ligne2);
	for(int i=0;i<colonnes2+1;i++)
	{
		ligne(ratio*i,0,ratio*i,hauteurFenetre());
	}
	for(int j=0;j<colonnes2+1;j++)
	{
		ligne(0,ratio*j,largeurFenetre(),ratio*j);
	}
}

void SourisCase(float lignes2,float colonnes2)
{
	float ratio = ((float)largeurFenetre()/(float)lignes2);
	float x = abscisseSouris();
	float y = ordonneeSouris();
	int ligneX=0;
	int colonneY=0;
	for(int i=0;i<lignes2+2;i++)
	{
		if(ratio*i>x)
		{
			ligneX=i;
			break;
		}
	}
	for(int j=0;j<colonnes2+2;j++)
	{
		if(ratio*j>y)
		{
			colonneY=j;
			break;
		}
	}
	grille[ligneX][colonneY]=1;
	
}

void AffichageMatrice(float lignes2,float colonnes2)
{
	float ratio = ((float)largeurFenetre()/(float)lignes2);
	for(int i=0;i<lignes2+1;i++)
	{
		for(int j=0;j<colonnes2+1;j++)
		{
			if(grille[i][j]==1)
			{
				couleurCourante(255,169,0);
				rectangle(i*ratio,j*ratio,i*ratio-ratio,j*ratio-ratio);
			}
		}
	}
}

void SliderZoom() 
{
	couleurCourante(255,255,255);
	epaisseurDeTrait(4);
	ligne(largeurFenetre()-450,60,largeurFenetre()-50,60); //400 unités
	ligne(largeurFenetre()-450,40,largeurFenetre()-450,80);
	ligne(largeurFenetre()-50,40,largeurFenetre()-50,80);
	epaisseurDeTrait(1);
	afficheChaine("ZOOM", 40, largeurFenetre()-310, 85);
	afficheChaine("0",25,largeurFenetre()-458,90);
	afficheChaine("300",25,largeurFenetre()-75,90);
	couleurCourante(0,145,255);
	cercle(curseur,60,10);
}

void cercle(float centreX, float centreY, float rayon)
{
	const int Pas = 100;
	const double PasAngulaire = 2.*M_PI/Pas;
	int index;
	
	for (index = 0; index < Pas; ++index)
	{
		const double angle = 2.*M_PI*index/Pas; 
		triangle(centreX, centreY,
				 centreX+rayon*cos(angle), centreY+rayon*sin(angle),
				 centreX+rayon*cos(angle+PasAngulaire), centreY+rayon*sin(angle+PasAngulaire));
	}
	
}

void ModifierPositionCurseur(void)
{
	if (etatBoutonSouris() == GaucheAppuye || etatBoutonSouris() == DroiteAppuye)
	{
		if(abscisseSouris()>=largeurFenetre()-450 && abscisseSouris()<=largeurFenetre()-50)
		{
			if(ordonneeSouris()>=50 && ordonneeSouris()<=70)
			{
				float point = (4/3)*(abscisseSouris()-(largeurFenetre()-450));
				curseur = largeurFenetre()-450+point;
				printf("\n%f",curseur);
			}
		}
	}
}

void RetirerCase(float lignes2,float colonnes2)
{
	float ratio = ((float)largeurFenetre()/(float)lignes2);
	float x = abscisseSouris();
	float y = ordonneeSouris();
	int ligneX=0;
	int colonneY=0;
	for(int i=0;i<lignes2+2;i++)
	{
		if(ratio*i>x)
		{
			ligneX=i;
			break;
		}
	}
	for(int j=0;j<colonnes2+2;j++)
	{
		if(ratio*j>y)
		{
			colonneY=j;
			break;
		}
	}
	if(grille[ligneX][colonneY]==1)
	{
		grille[ligneX][colonneY]=0;
	}
}

void Curseur(void)
{
	couleurCourante(184,184,184);
	rectangle((largeurFenetre()*680/1920),(hauteurFenetre()*52/1080), (largeurFenetre()*1200/1920), (hauteurFenetre()*57/1080)); // Modifie le rectangle sur lequelle le curseur se déplace
	epaisseurDeTrait(5);
	ligne((largeurFenetre()*680/1920),(hauteurFenetre()*40/1080), (largeurFenetre()*680/1920), (hauteurFenetre()*70/1080)); // Limite à droite 
	ligne((largeurFenetre()*1200/1920),(hauteurFenetre()*40/1080), (largeurFenetre()*1200/1920), (hauteurFenetre()*70/1080)); // Limite à gauche
	couleurCourante(255,255,0);
	ligne((largeurFenetre()*784/1920),(hauteurFenetre()*45/1080), (largeurFenetre()*784/1920), (hauteurFenetre()*65/1080)); // *0,5
	ligne((largeurFenetre()*888/1920),(hauteurFenetre()*45/1080), (largeurFenetre()*888/1920), (hauteurFenetre()*65/1080)); // *1
	ligne((largeurFenetre()*992/1920),(hauteurFenetre()*45/1080), (largeurFenetre()*992/1920), (hauteurFenetre()*65/1080)); // *2
	ligne((largeurFenetre()*1096/1920),(hauteurFenetre()*45/1080), (largeurFenetre()*1096/1920), (hauteurFenetre()*65/1080)); // *4


	couleurCourante(255,0,0);
	cercle(boutonabscisse,(hauteurFenetre()*55/1080),10);
	
		
	// Affichage texte
	epaisseurDeTrait(2);
	couleurCourante(255,255,255);
	afficheChaine("x0.5", 20, (largeurFenetre()*660/1920), (hauteurFenetre()*80/1080)); // Coordonnées du premier caractère
	afficheChaine("x1", 20, (largeurFenetre()*775/1920), (hauteurFenetre()*75/1080)); 
	afficheChaine("x2", 20, (largeurFenetre()*877/1920), (hauteurFenetre()*75/1080));
	afficheChaine("x4", 20, (largeurFenetre()*979/1920), (hauteurFenetre()*75/1080));
	afficheChaine("x8", 20, (largeurFenetre()*1082/1920), (hauteurFenetre()*75/1080));
	afficheChaine("x16", 20, (largeurFenetre()*1185/1920), (hauteurFenetre()*80/1080));
	
	//Pour faire bouger le curseur en le superposant au rectangle
	if ((abscisseSouris()>=680 && abscisseSouris()<=1200) && (ordonneeSouris()>=50 && ordonneeSouris()<=60)) 
	{
		boutonabscisse=abscisseSouris();
		if (boutonabscisse >= largeurFenetre()*1200/1920){ // largeur max des bornes du curseur
			boutonabscisse = largeurFenetre()*1200/1920;
		}
		else if (boutonabscisse <= largeurFenetre()*680/1920){ // largeur min des bornes du curseur
			boutonabscisse = largeurFenetre()*680/1920;
		}
	}
}

void AfficheBtnLecture(void)
{
	couleurCourante(255,255,255); 
	cercle(390,66,45); // Cercle Pause
	couleurCourante(0,0,0);
	cercle(390,66,42); // Cercle intérieur noir
	couleurCourante(255,255,255);
	
	if(etat == 1){ // Bouton Pause
		rectangle(370,85,385,47); // rectangle gauche
		rectangle(395,85,410,47); // rectangle droit
	}
	else if(etat == 0){ // Bouton Reprendre 
		triangle(376,46,376,83,410,64);
	}
}