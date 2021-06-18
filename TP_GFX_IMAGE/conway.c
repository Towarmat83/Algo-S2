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
			ModifierPositionCurseur();
			InitialiserLignesColonnesAffichage();
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
			AfficheBtnLecture();
			AfficheBtnReset();
			AfficheBtnLectureHover();
			AfficheBtnResetHover();
			AffichePointInterrogation();
			AffichePointInterrogationHover();
			AfficheBtnRadio(btnRad);
			AfficheBtnZoom();
			break;
			
		case Clavier:
			switch (caractereClavier())
			{
				case 'T': 
				case 't':
					termineBoucleEvenements();
					break;

				case 'F':
				case 'f':
					modePleinEcran();	
					break;
				case 'd':
					deplacementX-=2;
					break;
				case 'q':
					deplacementX+=2;
					break;
				case 'z':
					deplacementY-=2;
					break;
				case 's':
					deplacementY+=2;
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
				if((abscisse>=largeurFenetre()/16-10 && abscisse<=largeurFenetre()/16*1.75+10) && (ordonnee>=hauteurFenetre()/32*14-10 && ordonnee<=hauteurFenetre()/32*18+10))
				{
					boutong++;
					boutond=1;
					if(boutong>2)
					{
					boutong=1;
					}
					pagemenu--;
				}
				if((abscisse>=largeurFenetre()/16*14.25-10 && abscisse<=largeurFenetre()/16*15+10) && (ordonnee>=hauteurFenetre()/32*14-10 && ordonnee<=hauteurFenetre()/32*18+10))
				{
					boutond++;
					boutong=1;
					if(boutond>2)
					{
					boutond=1;
					}
					pagemenu++;
				}
				if (pagemenu<1)
				{
					pagemenu=3;
				}
				if (pagemenu>3)
				{
					pagemenu=1;
				}
				if(abscisse>=largeurFenetre()*1693/1920 && ordonnee>=hauteurFenetre()*8/1080 && abscisse<=largeurFenetre()*1872/1920 && ordonnee<=hauteurFenetre()*122/1080){
					Dezoom(&lignes_grilles, &colonnes_grilles);
					etatBtnZ=2;
				}
				if(abscisse>=largeurFenetre()*1468/1920 && ordonnee>=hauteurFenetre()*8/1080 && abscisse<=largeurFenetre()*1647/1920 && ordonnee<=hauteurFenetre()*122/1080){
					Zoom(&lignes_grilles, &colonnes_grilles);
					etatBtnZ=1;
				}
				if(etatBoutonSouris() == DroiteRelache || etatBoutonSouris() == GaucheRelache){
					etatBtnZ=0;
				}
			}
			if(etatBoutonSouris() == DroiteRelache || etatBoutonSouris() == GaucheRelache){
				etatBtnZ=0;
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
	ratio = ((float)largeurFenetre()/(float)lignes2);
}

void InitialiserVariablesGlobales(void)
{
	curseur=largeurFenetre()*1550/1920;
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
	for(int j=0;j<colonnes_grilles+1;j++)
	{
		grille[0][j]=2;
	}
	for(int j=0;j<colonnes_grilles+1;j++)
	{
		grille[lignes_grilles][j]=2;
	}
	for(int i=0;i<lignes_grilles+1;i++)
	{
		grille[i][0]=2;
	}
	for(int i=0;i<lignes_grilles+1;i++)
	{
		grille[i][colonnes_grilles]=2;
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
	for(int i=0;i<colonnes2+1;i++)
	{
		ligne(ratio*(i),0,ratio*(i),hauteurFenetre());
	}
	for(int j=0;j<colonnes2+1;j++)
	{
		ligne(0,ratio*(j),largeurFenetre(),ratio*(j));
	}
}

void SourisCase(float lignes2,float colonnes2)
{
	float x = abscisse;
	float y = ordonnee;
	int ligneX=0;
	int colonneY=0;
	for(int i=1;i<lignes2-1;i++)
	{
		if(ratio*(i+deplacementX)>x)
		{
			ligneX=i;
			break;
		}
	}
	for(int j=1;j<colonnes2;j++)
	{
		if(ratio*(j+deplacementY)>y)
		{
			colonneY=j;
			break;
		}
	}
	grille[ligneX][colonneY]=1;
	
}

void AffichageMatrice(float lignes2,float colonnes2)
{
	for(int i=0;i<lignes2+1;i++)
	{
		for(int j=0;j<colonnes2+1;j++)
		{
			if(grille[i][j]==1)
			{
				couleurCourante(255,169,0);
				rectangle((i+deplacementX)*ratio,(j+deplacementY)*ratio,(i+deplacementX)*ratio-ratio,(j+deplacementY)*ratio-ratio);
			}
		}
	}
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
		if(abscisse>=largeurFenetre()*1468/1920 && abscisse<=largeurFenetre()*1647/1920)
		{
			if(ordonnee>=hauteurFenetre()*8/1080 && ordonnee<=hauteurFenetre()*122/1080)
			{
				if(lignes2>5)
				{
					lignes2-=2;
					colonnes2-=2;
				}
			}
		}
		else if(abscisse>=largeurFenetre()*1693/1920 && abscisse<=largeurFenetre()*1872/1920)
		{
			if(ordonnee>=hauteurFenetre()*8/1080 && ordonnee<=hauteurFenetre()*122/1080)
			{
				if(lignes2<lignes_grilles)
				{
					lignes2+=2;
					colonnes2+=2;
				}
			}
		}

	}
}
void AfficheBtnZoom(void)
{
    couleurCourante(255,255,255);
    rectangle(largeurFenetre()*1468/1920,hauteurFenetre()*8/1080,largeurFenetre()*1647/1920,hauteurFenetre()*122/1080);
    couleurCourante(0,0,0);
    rectangle(largeurFenetre()*1470/1920,hauteurFenetre()*10/1080,largeurFenetre()*1645/1920,hauteurFenetre()*120/1080);
    couleurCourante(255,255,255);
    rectangle(largeurFenetre()*1693/1920,hauteurFenetre()*8/1080,largeurFenetre()*1872/1920,hauteurFenetre()*122/1080);
    couleurCourante(0,0,0);
    rectangle(largeurFenetre()*1695/1920,hauteurFenetre()*10/1080,largeurFenetre()*1870/1920,hauteurFenetre()*120/1080);
    couleurCourante(255,255,255);
    epaisseurDeTrait(5);
    afficheChaine("+",60,largeurFenetre()*1535/1920,hauteurFenetre()*40/1080);
    afficheChaine("-",60,largeurFenetre()*1760/1920,hauteurFenetre()*40/1080);
    if(etatBtnZ==1){

    couleurCourante(0 ,0 ,0);

    rectangle(largeurFenetre()*1468/1920,hauteurFenetre()*8/1080,largeurFenetre()*1647/1920,hauteurFenetre()*122/1080);

    couleurCourante(255,255,255);
    
    rectangle(largeurFenetre()*1470/1920,hauteurFenetre()*10/1080,largeurFenetre()*1645/1920,hauteurFenetre()*120/1080);

    couleurCourante(0 ,0 ,0);

    epaisseurDeTrait(5);

    afficheChaine("+",60,largeurFenetre()*1535/1920,hauteurFenetre()*40/1080);
    }
    else if(etatBtnZ==2){

    couleurCourante(0 ,0 ,0);

    rectangle(largeurFenetre()*1693/1920,hauteurFenetre()*8/1080,largeurFenetre()*1872/1920,hauteurFenetre()*122/1080);

    couleurCourante(255,255,255);

    rectangle(largeurFenetre()*1695/1920,hauteurFenetre()*10/1080,largeurFenetre()*1870/1920,hauteurFenetre()*120/1080);

    couleurCourante(0 ,0 ,0);

    epaisseurDeTrait(5);

    afficheChaine("-",60,largeurFenetre()*1760/1920,hauteurFenetre()*40/1080);
    }

}

void RetirerCase(float lignes2,float colonnes2)
{
	float x = abscisse;
	float y = ordonnee;
	int ligneX=0;
	int colonneY=0;
	for(int i=0;i<lignes2+2;i++)
	{
		if(ratio*(i+deplacementX)>x)
		{
			ligneX=i;
			break;
		}
	}
	for(int j=0;j<colonnes2+2;j++)
	{
		if(ratio*(j+deplacementY)>y)
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
				rectangle((i+deplacementX)*ratio,(j+deplacementY)*ratio,(i+deplacementX)*ratio-ratio,(j+deplacementY)*ratio-ratio);
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
			couleurCourante(255,0,0);
			ligne(largeurFenetre()*550/1920,hauteurFenetre()*970/1080,largeurFenetre()*1380/1920,hauteurFenetre()*970/1080);
			ligne(largeurFenetre()*550/1920,hauteurFenetre()*970/1080,largeurFenetre()*550/1920,hauteurFenetre()*1054/1080);
			ligne(largeurFenetre()*1380/1920,hauteurFenetre()*970/1080,largeurFenetre()*1380/1920,hauteurFenetre()*1054/1080);
			couleurCourante(255,255,255);
			afficheChaine("Informations sur le menu",60,largeurFenetre()*556/1920,hauteurFenetre()*985/1080);
			epaisseurDeTrait(2);
		if(pagemenu==1)
		{
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
			afficheChaine("Bouton pour reset la grille",40,largeurFenetre()*390/1920,hauteurFenetre()*796/1080);
			afficheChaine("Bouton Marche/Pause",40,largeurFenetre()*510/1920,hauteurFenetre()*646/1080);
			afficheChaine("ZOOM", 40, largeurFenetre()*1610/1920, hauteurFenetre()*255/1080);
			triangle(largeurFenetre()*0.32,hauteurFenetre()*200/1080,largeurFenetre()*0.34,hauteurFenetre()*200/1080,largeurFenetre()*0.33,hauteurFenetre()*170/1080);
			rectangle(largeurFenetre()*0.326,hauteurFenetre()*200/1080,largeurFenetre()*0.334,hauteurFenetre()*240/1080);
			epaisseurDeTrait(10);
			ligne(largeurFenetre()*0.33,hauteurFenetre()*170/1080,largeurFenetre()*0.41,hauteurFenetre()*170/1080);
			triangle(largeurFenetre()*0.40,hauteurFenetre()*200/1080,largeurFenetre()*0.42,hauteurFenetre()*200/1080,largeurFenetre()*0.41,hauteurFenetre()*170/1080);
			rectangle(largeurFenetre()*0.406,hauteurFenetre()*200/1080,largeurFenetre()*0.414,hauteurFenetre()*340/1080);
			epaisseurDeTrait(10);
			ligne(largeurFenetre()*0.41,hauteurFenetre()*170/1080,largeurFenetre()*0.49,hauteurFenetre()*170/1080);
			triangle(largeurFenetre()*0.48,hauteurFenetre()*200/1080,largeurFenetre()*0.50,hauteurFenetre()*200/1080,largeurFenetre()*0.49,hauteurFenetre()*170/1080);
			rectangle(largeurFenetre()*0.486,hauteurFenetre()*200/1080,largeurFenetre()*0.494,hauteurFenetre()*440/1080);
			triangle(largeurFenetre()*0.56,hauteurFenetre()*200/1080,largeurFenetre()*0.58,hauteurFenetre()*200/1080,largeurFenetre()*0.57,hauteurFenetre()*170/1080);
			rectangle(largeurFenetre()*0.566,hauteurFenetre()*200/1080,largeurFenetre()*0.574,hauteurFenetre()*340/1080);
			epaisseurDeTrait(10);
			ligne(largeurFenetre()*0.57,hauteurFenetre()*170/1080,largeurFenetre()*0.49,hauteurFenetre()*170/1080);
			triangle(largeurFenetre()*0.65,hauteurFenetre()*200/1080,largeurFenetre()*0.67,hauteurFenetre()*200/1080,largeurFenetre()*0.66,hauteurFenetre()*170/1080);
			rectangle(largeurFenetre()*0.656,hauteurFenetre()*200/1080,largeurFenetre()*0.664,hauteurFenetre()*240/1080);
			epaisseurDeTrait(10);
			ligne(largeurFenetre()*0.66,hauteurFenetre()*170/1080,largeurFenetre()*0.57,hauteurFenetre()*170/1080);
			epaisseurDeTrait(2);
			afficheChaine("Changer la temporisation",40,largeurFenetre()*0.49,hauteurFenetre()*440/1080);
			// Point d'intérrogation
		}
		if (pagemenu==2)
		{
			afficheChaine("Pour ajouter des cellules vivantes",40,largeurFenetre()*390/1920,hauteurFenetre()*796/1080);
			rectangle(largeurFenetre()*258/1920,hauteurFenetre()*840/1080,largeurFenetre()*350/1920,hauteurFenetre()*750/1080);
			couleurCourante(0,0,0);
			rectangle(largeurFenetre()*258/1920+5,hauteurFenetre()*840/1080-5,largeurFenetre()*304/1920,hauteurFenetre()*820/1080);
			ligne(largeurFenetre()*258/1920,hauteurFenetre()*820/1080,largeurFenetre()*350/1920,hauteurFenetre()*820/1080);
			ligne(largeurFenetre()*304/1920,hauteurFenetre()*840/1080,largeurFenetre()*304/1920,hauteurFenetre()*820/1080);
			couleurCourante(255,255,255);
			afficheChaine("Pour tuer les cellules",40,largeurFenetre()*390/1920,hauteurFenetre()*646/1080);
			rectangle(largeurFenetre()*258/1920,hauteurFenetre()*690/1080,largeurFenetre()*350/1920,hauteurFenetre()*600/1080);
			couleurCourante(0,0,0);
			rectangle(largeurFenetre()*304/1920,hauteurFenetre()*690/1080-5,largeurFenetre()*350/1920-5,hauteurFenetre()*670/1080);
			ligne(largeurFenetre()*258/1920,hauteurFenetre()*670/1080,largeurFenetre()*350/1920,hauteurFenetre()*670/1080);
			ligne(largeurFenetre()*304/1920,hauteurFenetre()*690/1080,largeurFenetre()*304/1920,hauteurFenetre()*670/1080);
			couleurCourante(255,255,255);
		}
		if (pagemenu==3)
		{
			afficheChaine("Credit",60,largeurFenetre()*556/1920,hauteurFenetre()*885/1080);
			afficheChaine("Francois Caliendo",60,largeurFenetre()*556/1920,hauteurFenetre()*785/1080);
			afficheChaine("Remi Hoarau",60,largeurFenetre()*556/1920,hauteurFenetre()*685/1080);
			afficheChaine("Julien Hugues",60,largeurFenetre()*556/1920,hauteurFenetre()*585/1080);
			afficheChaine("Leo Villeneuve",60,largeurFenetre()*556/1920,hauteurFenetre()*485/1080);
		}
		boutongauche(boutong);
		boutondroite(boutond);
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

void boutongauche(int boutong)
{
	if (boutong==1)
	{
		couleurCourante(100,100,100);
		rectangle(largeurFenetre()/16-10,hauteurFenetre()/32*14-10,largeurFenetre()/16*1.75+10,hauteurFenetre()/32*18+10);
		couleurCourante(200,200,200);
		rectangle(largeurFenetre()/16,hauteurFenetre()/32*14,largeurFenetre()/16*1.75,hauteurFenetre()/32*18);
		couleurCourante(0,0,0);
		triangle(largeurFenetre()/16+15,hauteurFenetre()/32*16, largeurFenetre()/16+55,hauteurFenetre()/32*17, largeurFenetre()/16+55,hauteurFenetre()/32*15);
		couleurCourante(200,200,200);
		triangle(largeurFenetre()/16+35,hauteurFenetre()/32*16, largeurFenetre()/16+65,hauteurFenetre()/32*17, largeurFenetre()/16+65,hauteurFenetre()/32*15);
	}
	if (boutong==2)
	{
		couleurCourante(255,255,255);
		rectangle(largeurFenetre()/16-10,hauteurFenetre()/32*14-10,largeurFenetre()/16*1.75+10,hauteurFenetre()/32*18+10);
		couleurCourante(109,7,26);
		rectangle(largeurFenetre()/16,hauteurFenetre()/32*14,largeurFenetre()/16*1.75,hauteurFenetre()/32*18);
		couleurCourante(255,255,255);
		triangle(largeurFenetre()/16+15,hauteurFenetre()/32*16, largeurFenetre()/16+55,hauteurFenetre()/32*17, largeurFenetre()/16+55,hauteurFenetre()/32*15);
		couleurCourante(109,7,26);
		triangle(largeurFenetre()/16+35,hauteurFenetre()/32*16, largeurFenetre()/16+65,hauteurFenetre()/32*17, largeurFenetre()/16+65,hauteurFenetre()/32*15);
	}
}



void boutondroite(int boutond)
{	
	if (boutond==1)
	{
		couleurCourante(100,100,100);
		rectangle(largeurFenetre()/16*14.25-10,hauteurFenetre()/32*14-10,largeurFenetre()/16*15+10,hauteurFenetre()/32*18+10);
		couleurCourante(200,200,200);
		rectangle(largeurFenetre()/16*14.25,hauteurFenetre()/32*14,largeurFenetre()/16*15,hauteurFenetre()/32*18);
		couleurCourante(1,1,1);
		triangle(largeurFenetre()/16*15-15,hauteurFenetre()/32*16, largeurFenetre()/16*15-55,hauteurFenetre()/32*17, largeurFenetre()/16*15-55,hauteurFenetre()/32*15);
		couleurCourante(200,200,200);
		triangle(largeurFenetre()/16*15-35,hauteurFenetre()/32*16, largeurFenetre()/16*15-65,hauteurFenetre()/32*17, largeurFenetre()/16*15-65,hauteurFenetre()/32*15);
	}
	if (boutond==2)
	{
		couleurCourante(255,255,255);
		rectangle(largeurFenetre()/16*14.25-10,hauteurFenetre()/32*14-10,largeurFenetre()/16*15+10,hauteurFenetre()/32*18+10);
		couleurCourante(109,7,26);
		rectangle(largeurFenetre()/16*14.25,hauteurFenetre()/32*14,largeurFenetre()/16*15,hauteurFenetre()/32*18);
		couleurCourante(255,255,255);
		triangle(largeurFenetre()/16*15-15,hauteurFenetre()/32*16, largeurFenetre()/16*15-55,hauteurFenetre()/32*17, largeurFenetre()/16*15-55,hauteurFenetre()/32*15);
		couleurCourante(109,7,26);
		triangle(largeurFenetre()/16*15-35,hauteurFenetre()/32*16, largeurFenetre()/16*15-65,hauteurFenetre()/32*17, largeurFenetre()/16*15-65,hauteurFenetre()/32*15);
	}
}

void Dezoom(int *lignes, int *colonnes){
	if(*lignes<=491){
		*lignes=*lignes+10;
		*colonnes=*colonnes+10;
	}
}

void Zoom(int *lignes, int *colonnes){
	if(*lignes>=11){
		*lignes=*lignes-10;
		*colonnes=*colonnes-10;
	}
}