#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 
#include "GfxLib.h" 
#include "BmpLib.h"
#include "ESLib.h" 
#include "conway.h"

#define LargeurFenetre 1920
#define HauteurFenetre 1080

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
	abscisse = abscisseSouris();
	ordonnee = ordonneeSouris();
	if(temp==limitetemp)
	{
		temp=0;
	}
	else
	{
		temp++;
	}
	
	switch (evenement)
	{
		case Initialisation:;
			InitialisationGrille();
			InitialisationGrillet1();
			InitialiserVariablesGlobales();
			demandeTemporisation(24);
			break;
		
		case Temporisation:
			InitialiserLignesColonnesAffichage();
			ModifierPositionCurseur();
			if (etatBoutonSouris() == GaucheAppuye)
			{
				if(ordonnee>(hauteurFenetre()*0.12) && etat==0 && menu == 0)
				{
					SourisCase(lignes2,colonnes2);
				}
			}
			if(etatBoutonSouris() == DroiteAppuye)
			{
				if(ordonnee>(hauteurFenetre()*0.12) && etat==0 && menu == 0)
				{
					RetirerCase(lignes2,colonnes2);
				}
				
			}
			if(etat==1 && temp==limitetemp)
			{
				RemplirGrillet1();
				PassageTempsSuperieur();
			}
			rafraichisFenetre();
			break;
			
		case Affichage:
			effaceFenetre(0,0,0);
			couleurCourante(124, 125, 124);
			epaisseurDeTrait(1);
			AffichageGrille(lignes2,colonnes2);
			AffichageMatrice(lignes2,colonnes2);
			if(etat==1)
			{
				AffichageGrillet1(lignes2,colonnes2);
			}
			epaisseurDeTrait(3);
			AffichageMenu();
			couleurCourante(255,255,255);
			SliderZoom(); 
			AfficheBtnLecture();
			AfficheBtnReset();
			AfficheBtnLectureHover();
			AfficheBtnResetHover();
			AffichePointInterrogation();
			AffichePointInterrogationHover();
			AfficheBtnRadio(btnRad);
			break;
			
		case Clavier:
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
			break;

		case BoutonSouris:
			if(etatBoutonSouris() == DroiteAppuye || etatBoutonSouris() == GaucheAppuye)
			{
				if(sqrt(pow(largeurFenetre()/4.923-abscisse,2)+pow(hauteurFenetre()/16.364-ordonnee,2))<=largeurFenetre()/42.6666)
				{
					etat = 1-etat;
				}
				else if((abscisse>=(largeurFenetre()*30/1920)) && (ordonnee>=(hauteurFenetre()*12/1080)) && (abscisse<=(largeurFenetre()*180/1920)) && (ordonnee<=(hauteurFenetre()*120/1080)))
				{
					menu = 1-menu;
				}
				else if(sqrt(pow((largeurFenetre()*260/1920)-abscisse,2)+pow((hauteurFenetre()*66/1080)-ordonnee,2))<=45)
				{
					etat = 0;
					ResetGrille();
				}
				else if((abscisse>=largeurFenetre()*566/1920 && abscisse<=largeurFenetre()*686/1920) && (ordonnee>=hauteurFenetre()*20/1080 && ordonnee<=hauteurFenetre()*120/1080))
				{
					btnRad=1;
					limitetemp=16;
					temp=0;
				}
				else if((abscisse>=largeurFenetre()*736/1920 && abscisse<=largeurFenetre()*839/1920) && (ordonnee>=hauteurFenetre()*20/1080 && ordonnee<=hauteurFenetre()*120/1080))
				{
					btnRad=2;
					limitetemp=8;
					temp=0;
				}
				else if((abscisse>=largeurFenetre()*891/1920 && abscisse<=largeurFenetre()*1011/1920) && (ordonnee>=hauteurFenetre()*20/1080 && ordonnee<=hauteurFenetre()*120/1080))
				{
					btnRad=3;
					limitetemp=4;
					temp=0;
				}
				else if((abscisse>=largeurFenetre()*1047/1920 && abscisse<=largeurFenetre()*1158/1920) && (ordonnee>=hauteurFenetre()*20/1080 && ordonnee<=hauteurFenetre()*120/1080))
				{
					btnRad=4;
					limitetemp=2;
					temp=0;
				}
				else if((abscisse>=largeurFenetre()*1215/1920 && abscisse<=largeurFenetre()*1341/1920) && (ordonnee>=hauteurFenetre()*20/1080 && ordonnee<=hauteurFenetre()*120/1080))
				{
					btnRad=5;
					limitetemp=0;
					temp=0;
				}
			}
			break;
		
		case Souris:
			break;
		
		case Inactivite:
			break;
		
		case Redimensionnement: 
			break;
	}
}

void InitialiserLignesColonnesAffichage(void)
{
	lignes2=fabs(((largeurFenetre()*1470/1920)-curseur)/(largeurFenetre()*400/1920))*lignes_grilles;
	colonnes2=lignes2;
}

void InitialiserVariablesGlobales(void)
{
	curseur=largeurFenetre()*1550/1920;
	boutonabscisse=largeurFenetre()*992/1920;
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
	ligne(0,hauteurFenetre()*129.6/1080,largeurFenetre(),hauteurFenetre()*129.6/1080);
	couleurCourante(0,0,0);
	rectangle(0,hauteurFenetre()*129.6/1080,largeurFenetre(),0);
	couleurCourante(0,255,0);
	ligne(largeurFenetre()*1420/1920,0,largeurFenetre()*1420/1920,hauteurFenetre()*129.6/1080);
	ligne(largeurFenetre()*460/1920,0,largeurFenetre()*460/1920,hauteurFenetre()*129.6/1080);
	couleurCourante(155,255,0);
}

void AffichageGrille(float ligne2,float colonnes2)
{
	couleurCourante(42, 43, 43);
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
	float x = abscisse;
	float y = ordonnee;
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
	ligne(largeurFenetre()/1.3521+50,hauteurFenetre()/18,largeurFenetre()/1.0267,hauteurFenetre()/18); //400 unités
	ligne(largeurFenetre()/1.3521+50,hauteurFenetre()/27,largeurFenetre()/1.3521+50,hauteurFenetre()/13.5);
	ligne(largeurFenetre()/1.0267,hauteurFenetre()/13.5,largeurFenetre()/1.0267,hauteurFenetre()/27);
	epaisseurDeTrait(1);
	afficheChaine("0",largeurFenetre()/76.8,largeurFenetre()/1.3132,hauteurFenetre()/12);
	afficheChaine("300",largeurFenetre()/76.8,largeurFenetre()/1.0406,hauteurFenetre()/12);
	couleurCourante(0,145,255);
	cercle(curseur,hauteurFenetre()*60/1080,10);
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
		if(abscisse>=largeurFenetre()*1470/1920 && abscisse<=largeurFenetre()*1870/1920)
		{
			if(ordonnee>=hauteurFenetre()*10/1080 && ordonnee<=hauteurFenetre()*110/1080)
			{
				float point = (4/3)*(abscisse-(largeurFenetre()*1470/1920));
				curseur = (largeurFenetre()*1470/1920)+point;
			}
		}
	}
}

void RetirerCase(float lignes2,float colonnes2)
{
	float ratio = ((float)largeurFenetre()/(float)lignes2);
	float x = abscisse;
	float y = ordonnee;
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

void AfficheBtnLecture(void)
{
	couleurCourante(255,255,255); 
	cercle(largeurFenetre()*390/1920,hauteurFenetre()*66/1080,45); // Cercle Pause
	couleurCourante(0,0,0);
	cercle(largeurFenetre()*390/1920,hauteurFenetre()*66/1080,42); // Cercle intérieur noir
	couleurCourante(255,255,255);
	
	if(etat == 1){ // Bouton Pause
		rectangle(largeurFenetre()*370/1920,hauteurFenetre()*85/1080,largeurFenetre()*385/1920,hauteurFenetre()*47/1080); // rectangle gauche
		rectangle(largeurFenetre()*395/1920,hauteurFenetre()*85/1080,largeurFenetre()*410/1920,hauteurFenetre()*47/1080); // rectangle droit
	}
	else if(etat == 0){ // Bouton Reprendre 
		triangle(largeurFenetre()*376/1920,hauteurFenetre()*46/1080,largeurFenetre()*376/1920,hauteurFenetre()*83/1080,largeurFenetre()*410/1920,hauteurFenetre()*64/1080);
	}
}

void InitialisationGrillet1(void)
{
	grillet1 = (int**)malloc((lignes_grilles+1)*sizeof(int*));
	for(int i=0;i<colonnes_grilles+1;i++)
	{
		grillet1[i]=(int*)malloc((colonnes_grilles+1)*sizeof(int));
	}
	for(int i=0;i<lignes_grilles+1;i++)
	{
		for(int j=0;j<colonnes_grilles+1;j++)
		{
			grillet1[i][j]=0;
		}
	}
	if(grillet1==NULL)
	{
		printf("\nImpossible d'allouer de la mémoire...");
		exit(EXIT_FAILURE);
	}
}

void RemplirGrillet1(void)
{
	for(int i=0;i<lignes_grilles+1;i++)
	{
		for(int j=0;j<colonnes_grilles+1;j++)
		{
			int nombre_voisin_vivant=ScanCellules(i,j);
			ReglesConway(nombre_voisin_vivant,i,j);
		}
	}
}

int ScanCellules(int i,int j)
{
	int nbr=0;
	if(i==0)
	{
		if(j==0) // I==0 et j==0
		{
			if(grille[i][j+1]==1)
			{
				nbr++;
			}
			if(grille[i+1][j+1]==1)
			{
				nbr++;
			}
			if(grille[i+1][j]==1)
			{
				nbr++;
			}
		}
		if(j==colonnes_grilles) // i==0 et j==colonnes_grilles
		{
			if(grille[i][j-1]==1)
			{
				nbr++;
			}
			if(grille[i+1][j-1]==1)
			{
				nbr++;
			}
			if(grille[i+1][j]==1)
			{
				nbr++;
			}
		}
		else // uniquement i==0
		{
			if(grille[i][j+1]==1)
			{
				nbr++;
			}
			if(grille[i+1][j+1]==1)
			{
				nbr++;
			}
			if(grille[i+1][j]==1)
			{
				nbr++;
			}
			if(grille[i+1][j-1]==1)
			{
				nbr++;
			}
			if(grille[i][j-1]==1)
			{
				nbr++;
			}
		}
	}
	else if(j==0)
	{
		if(i==lignes_grilles) // si j==0 et i==lignes_grilles
		{
			if(grille[i-1][j]==1)
			{
				nbr++;
			}
			if(grille[i-1][j+1]==1)
			{
				nbr++;
			}
			if(grille[i][j+1]==1)
			{
				nbr++;
			}
		}
		else // uniquement si j==0
		{
			if(grille[i-1][j]==1)
			{
				nbr++;
			}
			if(grille[i-1][j+1]==1)
			{
				nbr++;
			}
			if(grille[i][j+1]==1)
			{
				nbr++;
			}
			if(grille[i+1][j+1]==1)
			{
				nbr++;
			}
			if(grille[i+1][j]==1)
			{
				nbr++;
			}
		}
	}
	else if(i==lignes_grilles)
	{
		if(j==colonnes_grilles) // si i==lignes_grilles et j==colonnes_grilles
		{
			if(grille[i-1][j]==1)
			{
				nbr++;
			}
			if(grille[i-1][j-1]==1)
			{
				nbr++;
			}
			if(grille[i][j-1]==1)
			{
				nbr++;
			}
		}
		else
		{
			if(grille[i][j-1]==1)
			{
				nbr++;
			}
			if(grille[i-1][j-1]==1)
			{
				nbr++;
			}
			if(grille[i-1][j]==1)
			{
				nbr++;
			}
			if(grille[i-1][j+1]==1)
			{
				nbr++;
			}
			if(grille[i][j+1]==1)
			{
				nbr++;
			}
		}
	}
	else if(j==colonnes_grilles) // uniquement si j==colonnes_grilles
	{
		if(grille[i-1][j]==1)
		{
			nbr++;
		}
		if(grille[i-1][j-1]==1)
		{
			nbr++;
		}
		if(grille[i][j-1]==1)
		{
			nbr++;
		}
		if(grille[i+1][j-1]==1)
		{
			nbr++;
		}
		if(grille[i+1][j]==1)
		{
			nbr++;
		}
	}
	else
	{
		if(grille[i-1][j-1]==1)
		{
			nbr++;
		}
		if(grille[i-1][j]==1)
		{
			nbr++;
		}
		if(grille[i-1][j+1]==1)
		{
			nbr++;
		}
		if(grille[i][j-1]==1)
		{
			nbr++;
		}
		if(grille[i+1][j-1]==1)
		{
			nbr++;
		}
		if(grille[i+1][j]==1)
		{
			nbr++;
		}
		if(grille[i+1][j+1]==1)
		{
			nbr++;
		}
		if(grille[i][j+1]==1)
		{
			nbr++;
		}
	}
	return nbr;
}

void ReglesConway(int nombre_voisin_vivant,int x,int y)
{
	if(grille[x][y]==1)
	{
		if(nombre_voisin_vivant>=2 && nombre_voisin_vivant<=3)
		{
			grillet1[x][y]=1;
		}
		else if(nombre_voisin_vivant<2 || nombre_voisin_vivant>3)
		{
			grillet1[x][y]=0;
		}
	}
	else if(grille[x][y]==0)
	{
		if(nombre_voisin_vivant==3)
		{
			grillet1[x][y]=1;
		}
		else if(nombre_voisin_vivant!=3)
		{
			grillet1[x][y]=0;
		}
	}
}

void AffichageGrillet1(float lignes2,float colonnes2)
{
	float ratio = ((float)largeurFenetre()/(float)lignes2);
	for(int i=0;i<lignes2+1;i++)
	{
		for(int j=0;j<colonnes2+1;j++)
		{
			if(grillet1[i][j]==1)
			{
				couleurCourante(0,145,255);
				rectangle(i*ratio,j*ratio,i*ratio-ratio,j*ratio-ratio);
			}
		}
	}
}

void PassageTempsSuperieur(void)
{
	for(int i=0;i<lignes_grilles+1;i++)
	{
		for(int j=0;j<colonnes_grilles+1;j++)
		{
			grille[i][j]=grillet1[i][j];
		}
	}
}
void AfficheBtnReset(void){
	couleurCourante(255,255,255); 
	cercle(largeurFenetre()*260/1920,hauteurFenetre()*66/1080,45); // Cercle Pause
	couleurCourante(0,0,0);
	cercle(largeurFenetre()*260/1920,hauteurFenetre()*66/1080,42); // Cercle intérieur noir
	couleurCourante(255,255,255); 
	cercle(largeurFenetre()*260/1920,hauteurFenetre()*66/1080,25); 
	couleurCourante(0,0,0);
	cercle(largeurFenetre()*260/1920,hauteurFenetre()*66/1080,22);
	couleurCourante(0,0,0);
	rectangle(largeurFenetre()*262/1920,hauteurFenetre()*90/1080,largeurFenetre()*288/1920,hauteurFenetre()*63/1080);
	couleurCourante(255,255,255);
	triangle(largeurFenetre()*260/1920,hauteurFenetre()*81.5/1080,largeurFenetre()*260/1920,hauteurFenetre()*95.5/1080,largeurFenetre()*270/1920,hauteurFenetre()*88.5/1080);
}

void AffichePointInterrogation(void)
{
	if(menu == 1){ // Menu activé
		couleurCourante(255,255,0);
		rectangle(largeurFenetre()*30/1920,hauteurFenetre()*10/1080,largeurFenetre()*180/1920,hauteurFenetre()*120/1080);
		couleurCourante(0,0,0);
		rectangle(largeurFenetre()*32/1920,hauteurFenetre()*12/1080,largeurFenetre()*178/1920,hauteurFenetre()*118/1080);
		// Affichage menu
		couleurCourante(255,0,0);
		rectangle(largeurFenetre()*94/1920,hauteurFenetre()*158/1080,largeurFenetre()*1826/1920,hauteurFenetre()*1056/1080);
		couleurCourante(0,0,0);
		rectangle(largeurFenetre()*96/1920,hauteurFenetre()*160/1080,largeurFenetre()*1824/1920,hauteurFenetre()*1054/1080);
		
		//flèches de gauche à droite
		couleurCourante(255,255,255);
		rectangle(largeurFenetre()*255/1920,hauteurFenetre()*200/1080,largeurFenetre()*265/1920,hauteurFenetre()*750/1080);
		triangle(largeurFenetre()*250/1920,hauteurFenetre()*200/1080,largeurFenetre()*270/1920,hauteurFenetre()*200/1080,largeurFenetre()*260/1920,hauteurFenetre()*170/1080);
		epaisseurDeTrait(10);
		ligne(largeurFenetre()*258/1920,hauteurFenetre()*749/1080,largeurFenetre()*350/1920,hauteurFenetre()*800/1080);
		rectangle(largeurFenetre()*349/1920,hauteurFenetre()*796/1080,largeurFenetre()*370/1920,hauteurFenetre()*805/1080);
		epaisseurDeTrait(2);
		
		rectangle(largeurFenetre()*385/1920,hauteurFenetre()*200/1080,largeurFenetre()*395/1920,hauteurFenetre()*600/1080);
		triangle(largeurFenetre()*380/1920,hauteurFenetre()*200/1080,largeurFenetre()*400/1920,hauteurFenetre()*200/1080,largeurFenetre()*390/1920,hauteurFenetre()*170/1080);
		epaisseurDeTrait(10);
		ligne(largeurFenetre()*388/1920,hauteurFenetre()*599/1080,largeurFenetre()*480/1920,hauteurFenetre()*650/1080);
		rectangle(largeurFenetre()*479/1920,hauteurFenetre()*646/1080,largeurFenetre()*490/1920,hauteurFenetre()*655/1080);
		epaisseurDeTrait(2);
		
		rectangle(largeurFenetre()*1660/1920,hauteurFenetre()*200/1080,largeurFenetre()*1670/1920,hauteurFenetre()*240/1080);
		triangle(largeurFenetre()*1655/1920,hauteurFenetre()*200/1080,largeurFenetre()*1675/1920,hauteurFenetre()*200/1080,largeurFenetre()*1665/1920,hauteurFenetre()*170/1080);
		epaisseurDeTrait(2);
		afficheChaine("Informations sur le menu",60,largeurFenetre()*556/1920,hauteurFenetre()*985/1080);
		afficheChaine("Bouton pour reset la grille",40,largeurFenetre()*390/1920,hauteurFenetre()*796/1080);
		afficheChaine("Bouton Marche/Pause",40,largeurFenetre()*510/1920,hauteurFenetre()*646/1080);
		afficheChaine("ZOOM", 40, largeurFenetre()*1610/1920, hauteurFenetre()*255/1080);
		couleurCourante(255,0,0);
		ligne(largeurFenetre()*550/1920,hauteurFenetre()*970/1080,largeurFenetre()*1380/1920,hauteurFenetre()*970/1080);
		ligne(largeurFenetre()*550/1920,hauteurFenetre()*970/1080,largeurFenetre()*550/1920,hauteurFenetre()*1054/1080);
		ligne(largeurFenetre()*1380/1920,hauteurFenetre()*970/1080,largeurFenetre()*1380/1920,hauteurFenetre()*1054/1080);
		// Point d'intérrogation
		couleurCourante(255,0,0);
	}
	else if(menu == 0){ // Menu désactivé
		couleurCourante(255,255,255);
		rectangle(largeurFenetre()*30/1920,hauteurFenetre()*10/1080,largeurFenetre()*180/1920,hauteurFenetre()*120/1080);
		couleurCourante(0,0,0);
		rectangle(largeurFenetre()*32/1920,hauteurFenetre()*12/1080,largeurFenetre()*178/1920,hauteurFenetre()*118/1080);
		// Point d'intérrogation
		couleurCourante(255,255,255);
	}
	rectangle(largeurFenetre()*95/1920,hauteurFenetre()*25/1080,largeurFenetre()*110/1920,hauteurFenetre()*35/1080); // Point du bas
	rectangle(largeurFenetre()*95/1920,hauteurFenetre()*45/1080,largeurFenetre()*110/1920,hauteurFenetre()*65/1080); // Corps
	rectangle(largeurFenetre()*110/1920,hauteurFenetre()*65/1080,largeurFenetre()*125/1920,hauteurFenetre()*75/1080); // Partie de droite
	rectangle(largeurFenetre()*125/1920,hauteurFenetre()*75/1080,largeurFenetre()*140/1920,hauteurFenetre()*95/1080); 
	rectangle(largeurFenetre()*85/1920,hauteurFenetre()*95/1080,largeurFenetre()*125/1920,hauteurFenetre()*105/1080); // Partie du haut
	rectangle(largeurFenetre()*70/1920,hauteurFenetre()*85/1080,largeurFenetre()*85/1920,hauteurFenetre()*95/1080); // Partie de droite
}

void ResetGrille(void)
{
	for(int i=0;i<lignes_grilles;i++)
	{
		for(int j=0;j<colonnes_grilles;j++)
		{
			grille[i][j]=0;
			grillet1[i][j]=0;
		}
	}
}

void AfficheBtnLectureHover(void)
{
	if(sqrt(pow(largeurFenetre()/4.923-abscisse,2)+pow(hauteurFenetre()/16.364-ordonnee,2))<=largeurFenetre()/42.6666)
	{
		couleurCourante(0,0,0); 
		cercle(largeurFenetre()*390/1920,hauteurFenetre()*66/1080,45); // Cercle Pause
		couleurCourante(255,255,255);
		cercle(largeurFenetre()*390/1920,hauteurFenetre()*66/1080,42); // Cercle intérieur noir
		couleurCourante(0,0,0);
		
		if(etat == 1){ // Bouton Pause
			rectangle(largeurFenetre()*370/1920,hauteurFenetre()*85/1080,largeurFenetre()*385/1920,hauteurFenetre()*47/1080); // rectangle gauche
			rectangle(largeurFenetre()*395/1920,hauteurFenetre()*85/1080,largeurFenetre()*410/1920,hauteurFenetre()*47/1080); // rectangle droit
		}
		else if(etat == 0){ // Bouton Reprendre 
			triangle(largeurFenetre()*376/1920,hauteurFenetre()*46/1080,largeurFenetre()*376/1920,hauteurFenetre()*83/1080,largeurFenetre()*410/1920,hauteurFenetre()*64/1080);
		}
	}
	
}

void AfficheBtnResetHover(void)
{
	if(sqrt(pow((largeurFenetre()*260/1920)-abscisse,2)+pow((hauteurFenetre()*66/1080)-ordonnee,2))<=45)
	{
		couleurCourante(0,0,0); 
		cercle(largeurFenetre()*260/1920,hauteurFenetre()*66/1080,45); // Cercle Pause
		couleurCourante(255,255,255);
		cercle(largeurFenetre()*260/1920,hauteurFenetre()*66/1080,42); // Cercle intérieur noir
		couleurCourante(0,0,0); 
		cercle(largeurFenetre()*260/1920,hauteurFenetre()*66/1080,25); 
		couleurCourante(255,255,255);
		cercle(largeurFenetre()*260/1920,hauteurFenetre()*66/1080,22);
		couleurCourante(255,255,255);
		rectangle(largeurFenetre()*262/1920,hauteurFenetre()*90/1080,largeurFenetre()*288/1920,hauteurFenetre()*63/1080);
		couleurCourante(0,0,0);
		triangle(largeurFenetre()*260/1920,hauteurFenetre()*81.5/1080,largeurFenetre()*260/1920,hauteurFenetre()*95.5/1080,largeurFenetre()*270/1920,hauteurFenetre()*88.5/1080);
	}
}

void AffichePointInterrogationHover(void)
{
	if((abscisse>=(largeurFenetre()*30/1920)) && (ordonnee>=(hauteurFenetre()*12/1080)) && (abscisse<=(largeurFenetre()*180/1920)) && (ordonnee<=(hauteurFenetre()*120/1080)))
	{
		if(menu == 0)
		{ // Menu désactivé
			couleurCourante(0,0,0);
			rectangle(largeurFenetre()*30/1920,hauteurFenetre()*10/1080,largeurFenetre()*180/1920,hauteurFenetre()*120/1080);
			couleurCourante(255,255,255);
			rectangle(largeurFenetre()*32/1920,hauteurFenetre()*12/1080,largeurFenetre()*178/1920,hauteurFenetre()*118/1080);
			// Point d'interrogation
			couleurCourante(0,0,0);
		}
		rectangle(largeurFenetre()*95/1920,hauteurFenetre()*25/1080,largeurFenetre()*110/1920,hauteurFenetre()*35/1080); // Point du bas
		rectangle(largeurFenetre()*95/1920,hauteurFenetre()*45/1080,largeurFenetre()*110/1920,hauteurFenetre()*65/1080); // Corps
		rectangle(largeurFenetre()*110/1920,hauteurFenetre()*65/1080,largeurFenetre()*125/1920,hauteurFenetre()*75/1080); // Partie de droite
		rectangle(largeurFenetre()*125/1920,hauteurFenetre()*75/1080,largeurFenetre()*140/1920,hauteurFenetre()*95/1080); 
		rectangle(largeurFenetre()*85/1920,hauteurFenetre()*95/1080,largeurFenetre()*125/1920,hauteurFenetre()*105/1080); // Partie du haut
		rectangle(largeurFenetre()*70/1920,hauteurFenetre()*85/1080,largeurFenetre()*85/1920,hauteurFenetre()*95/1080); // Partie de droite
	}
	
}

void AfficheBtnRadio(int btnRad){
	couleurCourante(255, 255, 255);
	cercle((largeurFenetre()*0.324), (hauteurFenetre()*0.03), 10);
	cercle((largeurFenetre()*0.408), (hauteurFenetre()*0.03), 10);
	cercle((largeurFenetre()*0.492), (hauteurFenetre()*0.03), 10);
	cercle((largeurFenetre()*0.576), (hauteurFenetre()*0.03), 10);
	cercle((largeurFenetre()*0.66), (hauteurFenetre()*0.03), 10);
	afficheChaine("x0.5", 50, largeurFenetre()*0.30, hauteurFenetre()*0.06);
	afficheChaine("x1", 50, largeurFenetre()*0.40, hauteurFenetre()*0.06);
	afficheChaine("x2", 50, largeurFenetre()*0.48, hauteurFenetre()*0.06);
	afficheChaine("x4", 50, largeurFenetre()*0.56, hauteurFenetre()*0.06);
	afficheChaine("x8", 50, largeurFenetre()*0.65, hauteurFenetre()*0.06);
	//
	couleurCourante(255,0,0);
	
	//
	couleurCourante(0, 0, 0);
	if(btnRad==1){
		couleurCourante(255, 0, 0);
		cercle((largeurFenetre()*0.324), (hauteurFenetre()*0.03), 10);
	}
	else if(btnRad==2){
		couleurCourante(255, 0, 0);
		cercle((largeurFenetre()*0.408), (hauteurFenetre()*0.03), 10);
	}
	else if(btnRad==3){
		couleurCourante(255, 0, 0);
		cercle((largeurFenetre()*0.492), (hauteurFenetre()*0.03), 10);
	}
	else if(btnRad==4){
		couleurCourante(255, 0, 0);
		cercle((largeurFenetre()*0.576), (hauteurFenetre()*0.03), 10);
	}
	else if(btnRad==5){
		couleurCourante(255, 0, 0);
		cercle((largeurFenetre()*0.66), (hauteurFenetre()*0.03), 10);
	}
}
