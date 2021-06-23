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
			if(etatZoom==1 && ordonneeSouris()>=hauteurFenetre()*129.6/1080 && (etatBoutonSouris() == GaucheAppuye))
			{
				clicBasX=abscisseSouris();
				clicBasY=ordonneeSouris();
			}
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
			rafraichisFenetre();
			break;
			
		case Affichage:
			if(etatZoom==1 && ordonneeSouris()>=hauteurFenetre()*129.6/1080)
			{
				afficherRectangleZoom();
			}
			if(etat==1 && temp==limitetemp)
			{
				RemplirGrillet1();
				PassageTempsSuperieur();
			}
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
			AfficheFlecheDroite();
			AfficheFlecheGauche();
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
			}
			break;
			
		case ClavierSpecial:
			break;

		case BoutonSouris:

			if(etatBoutonSouris() == DroiteAppuye || etatBoutonSouris() == GaucheAppuye)

			{

			//éléments cliquable du menu 1

				if(page==0){

				if(sqrt(pow(largeurFenetre()/4.923-abscisse,2)+pow(hauteurFenetre()/16.364-ordonnee,2))<=largeurFenetre()/42.6666)

				{

					reset=0;

					etat = 1-etat;

				}

				else if((abscisse>=largeurFenetre()*1468/1920 && abscisse<=largeurFenetre()*1647/1920) && (ordonnee>=hauteurFenetre()*8/1080 && ordonnee<=hauteurFenetre()*122/1080))

				{

					boutonGrille=1-boutonGrille;

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

					LoupeOnOff = 1 - LoupeOnOff;

				}

				if(abscisse>=largeurFenetre()*1468/1920 && ordonnee>=hauteurFenetre()*8/1080 && abscisse<=largeurFenetre()*1647/1920 && ordonnee<=hauteurFenetre()*122/1080){

					GrilleOnOff = 1 - GrilleOnOff;

				}

				

			if (etatBoutonSouris() == GaucheAppuye)

			{

				if(abscisse>=largeurFenetre()*1693/1920 && abscisse<=largeurFenetre()*1872/1920)

				{

					if(ordonnee>=hauteurFenetre()*8/1080 && ordonnee<=hauteurFenetre()*122/1080)

					{

						etatZoom=1-etatZoom;
						if(etatZoom==0)
						{
							lignes2=lignes_grilles;
							colonnes2=colonnes_grilles;
						}

					}

				}

			}

			if(etatBoutonSouris()==GaucheAppuye && ordonneeSouris()>=hauteurFenetre()*129.6/1080)

			{

				clicHautX=abscisseSouris();

				clicHautY=ordonneeSouris();

			}

			if(etatBoutonSouris()==GaucheAppuye)

			{

				if(reset==1)

				{

					for(int i=0;i<longueurtabNOT;i++)

					{

						if(abscisse>=tabNOT[i].rectXinit*ratio && abscisse<=tabNOT[i].rectXfin*ratio)

						{

							if(ordonnee>=tabNOT[i].rectYinit*ratio && ordonnee<=tabNOT[i].rectYfin*ratio)

							{

								tabNOT[i].blocage=1-tabNOT[i].blocage;

								if(tabNOT[i].blocage==0)

								{

									for(int x=0;x<7;x++)

									{

										grille[tabNOT[i].blocageX[x]][tabNOT[i].blocageY[x]]=0;

									}

									

								}

								else if(tabNOT[i].blocage==1)

								{

									for(int x=0;x<7;x++)

									{

										grille[tabNOT[i].blocageX[x]][tabNOT[i].blocageY[x]]=1;

									}

									

								}



							}

						}

					}



					for(int i=0;i<longueurtabAND;i++)

					{

						if(abscisse>=tabAND[i].rectXinit*ratio && abscisse<=(tabAND[i].rectXinit-20+(tabAND[i].rectXfin-tabAND[i].rectXinit)/2)*ratio)

						{

							if(ordonnee>=tabAND[i].rectYinit*ratio && ordonnee<=tabAND[i].rectYfin*ratio)

							{

								tabAND[i].blocage1=1-tabAND[i].blocage1;

								if(tabAND[i].blocage1==0)

								{

									for(int x=0;x<7;x++)

									{

										grille[tabAND[i].blocage1X[x]][tabAND[i].blocage1Y[x]]=0;

									}

									

								}

								else if(tabAND[i].blocage1==1)

								{

									for(int x=0;x<7;x++)

									{

										grille[tabAND[i].blocage1X[x]][tabAND[i].blocage1Y[x]]=1;

									}

									

								}



							}

						}

						if(abscisse>=(tabAND[i].rectXinit-20+(tabAND[i].rectXfin-tabAND[i].rectXinit)/2)*ratio && abscisse<=tabAND[i].rectXfin*ratio)

						{

							if(ordonnee>=tabAND[i].rectYinit*ratio && ordonnee<=tabAND[i].rectYfin*ratio)

							{

								tabAND[i].blocage2=1-tabAND[i].blocage2;

								if(tabAND[i].blocage2==0)

								{

									for(int x=0;x<7;x++)

									{

										grille[tabAND[i].blocage2X[x]][tabAND[i].blocage2Y[x]]=0;

									}

									

								}

								else if(tabAND[i].blocage2==1)

								{

									for(int x=0;x<7;x++)

									{

										grille[tabAND[i].blocage2X[x]][tabAND[i].blocage2Y[x]]=1;

									}

									

								}



							}

						}

					}



					for(int i=0;i<longueurtabOR;i++)

					{

						if(abscisse>=tabOR[i].rectXinit*ratio && abscisse<=(tabOR[i].rectXinit+(tabOR[i].rectXfin-tabOR[i].rectXinit)/2)*ratio)

						{

							if(ordonnee>=tabOR[i].rectYinit*ratio && ordonnee<=tabOR[i].rectYfin*ratio)

							{

								tabOR[i].blocage1=1-tabOR[i].blocage1;

								if(tabOR[i].blocage1==0)

								{

									for(int x=0;x<7;x++)

									{

										grille[tabOR[i].blocage1X[x]][tabOR[i].blocage1Y[x]]=0;

									}

									

								}

								else if(tabOR[i].blocage1==1)

								{

									for(int x=0;x<7;x++)

									{

										grille[tabOR[i].blocage1X[x]][tabOR[i].blocage1Y[x]]=1;

									}

									

								}



							}

						}

						if(abscisse>=(tabOR[i].rectXinit+(tabOR[i].rectXfin-tabOR[i].rectXinit)/2)*ratio && abscisse<=tabOR[i].rectXfin*ratio)

						{

							if(ordonnee>=tabOR[i].rectYinit*ratio && ordonnee<=tabOR[i].rectYfin*ratio)



							{

								tabOR[i].blocage2=1-tabOR[i].blocage2;

								if(tabOR[i].blocage2==0)

								{

									for(int x=0;x<7;x++)

									{

										grille[tabOR[i].blocage2X[x]][tabOR[i].blocage2Y[x]]=0;

									}

									

								}

								else if(tabOR[i].blocage2==1)

								{

									for(int x=0;x<7;x++)

									{

										grille[tabOR[i].blocage2X[x]][tabOR[i].blocage2Y[x]]=1;

									}

									

								}



							}

						}

					}

				}

				

			}

		if(abscisse>=largeurFenetre()*1902/1920 && ordonnee<=hauteurFenetre()*120/1080 && abscisse<=largeurFenetre()*1911/1920 && ordonnee>=hauteurFenetre()*10/1080){

			page=1;

		}

		else if(abscisse>=largeurFenetre()*9/1920 && ordonnee<=hauteurFenetre()*120/1080 && abscisse<=largeurFenetre()*18/1920 && ordonnee>=hauteurFenetre()*10/1080){

			page=1;

		}

				}

		//éléments cliquable du menu 2

			else if(page==1){

				if(abscisse>=largeurFenetre()*1902/1920 && ordonnee<=hauteurFenetre()*120/1080 && abscisse<=largeurFenetre()*1911/1920 && ordonnee>=hauteurFenetre()*10/1080){

					page=0;

				}

				else if(abscisse>=largeurFenetre()*9/1920 && ordonnee<=hauteurFenetre()*120/1080 && abscisse<=largeurFenetre()*18/1920 && ordonnee>=hauteurFenetre()*10/1080){

					page=0;

				}

				if(abscisse>=largeurFenetre()*30/1920 && ordonnee<=hauteurFenetre()*120/1080 && abscisse<=largeurFenetre()*205/1920 && ordonnee>=hauteurFenetre()*10/1080){

					NotOnOff = 1 - NotOnOff;

					AndOnOff = 0;

					OrOnOff = 0;

				}

				else if(abscisse>=largeurFenetre()*251/1920 && ordonnee<=hauteurFenetre()*120/1080 && abscisse<=largeurFenetre()*424/1920 && ordonnee>=hauteurFenetre()*10/1080){

					AndOnOff = 1 - AndOnOff;

					NotOnOff = 0;

					OrOnOff = 0;

				}

				else if(abscisse>=largeurFenetre()*470/1920 && ordonnee<=hauteurFenetre()*120/1080 && abscisse<=largeurFenetre()*643/1920 && ordonnee>=hauteurFenetre()*10/1080){

					OrOnOff = 1 - OrOnOff;

					NotOnOff = 0;

					AndOnOff = 0;

				}

				

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
	ratio = ((float)largeurFenetre()/(float)lignes2);
}

void InitialiserVariablesGlobales(void)
{
	curseur=largeurFenetre()*1550/1920;
}

void InitialisationTableaux(void)
{
	longueurtabNOT=0;
	longueurtabOR=0;
	longueurtabAND=0;
	tabNOT = malloc((lignes_grilles+1)*sizeof(DONNEESNOT));
	for(int i=0;i<lignes_grilles+1;i++)
	{
		tabNOT[i].X=0;
		tabNOT[i].Y=0;
		tabNOT[i].rectXinit=0;
		tabNOT[i].rectYinit=0;
		tabNOT[i].rectXfin=0;
		tabNOT[i].rectYfin=0;
		tabNOT[i].blocage=0;
		for(int j=0;j<7;j++)
		{
			tabNOT[j].blocageX=(int*)malloc(sizeof(int)*6);
			tabNOT[j].blocageY=(int*)malloc(sizeof(int)*6);
		}
	}
	if(tabNOT==NULL)
	{
		printf("\nImpossible d'allouer de la mémoire...");
		exit(EXIT_FAILURE);
	}

	tabAND = malloc((lignes_grilles+1)*sizeof(DONNEESAND));
	for(int i=0;i<lignes_grilles+1;i++)
	{
		tabAND[i].X=0;
		tabAND[i].Y=0;
		tabAND[i].rectXinit=0;
		tabAND[i].rectYinit=0;
		tabAND[i].rectXfin=0;
		tabAND[i].rectYfin=0;
		tabAND[i].blocage1=0;
		tabAND[i].blocage2=0;
		for(int j=0;j<7;j++)
		{
			tabAND[j].blocage1X=(int*)malloc(sizeof(int)*6);
			tabAND[j].blocage1Y=(int*)malloc(sizeof(int)*6);
			tabAND[j].blocage2X=(int*)malloc(sizeof(int)*6);
			tabAND[j].blocage2Y=(int*)malloc(sizeof(int)*6);
		}
	}
	if(tabAND==NULL)
	{
		printf("\nImpossible d'allouer de la mémoire...");
		exit(EXIT_FAILURE);
	}

	tabOR = malloc((lignes_grilles+1)*sizeof(DONNEESOR));
	for(int i=0;i<lignes_grilles+1;i++)
	{
		tabOR[i].X=0;
		tabOR[i].Y=0;
		tabOR[i].rectXinit=0;
		tabOR[i].rectYinit=0;
		tabOR[i].rectXfin=0;
		tabOR[i].rectYfin=0;
		tabOR[i].blocage1=0;
		tabOR[i].blocage2=0;
		for(int j=0;j<7;j++)
		{
			tabOR[j].blocage1X=(int*)malloc(sizeof(int)*6);
			tabOR[j].blocage1Y=(int*)malloc(sizeof(int)*6);
			tabOR[j].blocage2X=(int*)malloc(sizeof(int)*6);
			tabOR[j].blocage2Y=(int*)malloc(sizeof(int)*6);
		}
	}

	if(tabOR==NULL)
	{
		printf("\nImpossible d'allouer de la mémoire...");
		exit(EXIT_FAILURE);
	}
}

void InitialisationGrille(void)
{
	InitialisationTableaux();
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

	// Début Gosper Glider Gun
	int initX = 300;
	int initY = 300;
	//LogicGateNOT(initX,initY,1);
	//LogicGateNOT(initX+100,initY+100,1);
	//LogicGateNOT(initX,initY+30,1);
	//GosperGliderGunDroite(initX,initY);
	//GosperGliderGunGauche(initX+49,initY+26);
	//LogicGateNOT(initX-100,initY-100,1);
	//LogicGateOR(initX,initY,1,1);
	//LogicGateOR(initX+100,initY-150,0,1);
	//LogicGateAND(initX-200,initY-100,1,0);
	//LogicGateAND(initX,initY,1,1);

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

	//affichage du menu 1
	if (page == 0)
	{
		couleurCourante(0,255,0);
		ligne(0,hauteurFenetre()*129.6/1080,largeurFenetre(),hauteurFenetre()*129.6/1080);
		couleurCourante(0,0,0);
		rectangle(0,hauteurFenetre()*129.6/1080,largeurFenetre(),0);
		couleurCourante(0,255,0);
		ligne(largeurFenetre()*1420/1920,0,largeurFenetre()*1420/1920,hauteurFenetre()*129.6/1080);
		ligne(largeurFenetre()*460/1920,0,largeurFenetre()*460/1920,hauteurFenetre()*129.6/1080);
		couleurCourante(155,255,0);
		AffichageBoutonGrille();
		AfficheBtnLecture();
		AfficheBtnReset();
		AfficheBtnLectureHover();
		AfficheBtnResetHover();
		AffichePointInterrogation();
		AffichePointInterrogationHover();
		AfficheBtnRadio(btnRad);
		AfficheBtnZoom();
	}
	//affichage du menu 2
	else if (page == 1)
	{
		couleurCourante(0,255,0);
		ligne(0,hauteurFenetre()*129.6/1080,largeurFenetre(),hauteurFenetre()*129.6/1080);
		couleurCourante(0,0,0);
		rectangle(0,hauteurFenetre()*129.6/1080,largeurFenetre(),0);
		couleurCourante(255,255,255);	
		afficheChaine("Menu 2", 30, largeurFenetre()*0.5, hauteurFenetre()*0.06);
		AfficheLogicGateNOT();
		AfficheLogicGateAND();
		AfficheLogicGateOR();
	}
}

void AffichageGrille(float ligne2,float colonnes2)
{
	if(boutonGrille==0)
	{
		couleurCourante(42, 43, 43);
		for(int i=0;i<lignes2;i++)
		{
			ligne(ratio*(i),0,ratio*(i),hauteurFenetre());
		}
		for(int j=0;j<colonnes2;j++)
		{
			ligne(0,ratio*(j),largeurFenetre(),ratio*(j));
		}
	}
	
	if(longueurtabNOT>0)
	{
		couleurCourante(255, 0, 0);
		for(int i=0;i<longueurtabNOT;i++)
		{
			ligne(tabNOT[i].rectXinit*ratio,tabNOT[i].rectYinit*ratio,tabNOT[i].rectXinit*ratio,tabNOT[i].rectYfin*ratio);
			ligne(tabNOT[i].rectXfin*ratio,tabNOT[i].rectYinit*ratio,tabNOT[i].rectXfin*ratio,tabNOT[i].rectYfin*ratio);
			ligne(tabNOT[i].rectXinit*ratio,tabNOT[i].rectYinit*ratio,tabNOT[i].rectXfin*ratio,tabNOT[i].rectYinit*ratio);
			ligne(tabNOT[i].rectXinit*ratio,tabNOT[i].rectYfin*ratio,tabNOT[i].rectXfin*ratio,tabNOT[i].rectYfin*ratio);
			epaisseurDeTrait(3);
			afficheChaine("NOT",10,tabNOT[i].rectXfin*ratio-50,tabNOT[i].rectYfin*ratio-25);
			afficheChaine("INPUT",10,tabNOT[i].rectXinit*ratio-70,tabNOT[i].rectYinit*ratio+120);
			afficheChaine("OUTPUT",10,tabNOT[i].rectXfin*ratio+10,tabNOT[i].rectYfin*ratio-150);
			epaisseurDeTrait(1);
		}
	}
	if(longueurtabAND>0)
	{
		couleurCourante(255, 0, 0);
		for(int i=0;i<longueurtabAND;i++)
		{
			ligne(tabAND[i].rectXinit*ratio,tabAND[i].rectYinit*ratio,tabAND[i].rectXinit*ratio,tabAND[i].rectYfin*ratio);
			ligne(tabAND[i].rectXfin*ratio,tabAND[i].rectYinit*ratio,tabAND[i].rectXfin*ratio,tabAND[i].rectYfin*ratio);
			ligne(tabAND[i].rectXinit*ratio,tabAND[i].rectYinit*ratio,tabAND[i].rectXfin*ratio,tabAND[i].rectYinit*ratio);
			ligne(tabAND[i].rectXinit*ratio,tabAND[i].rectYfin*ratio,tabAND[i].rectXfin*ratio,tabAND[i].rectYfin*ratio);
			epaisseurDeTrait(3);
			afficheChaine("AND",20,tabAND[i].rectXfin*ratio-50,tabAND[i].rectYfin*ratio-25);
			afficheChaine("INPUT A",20,tabAND[i].rectXinit*ratio+90,tabAND[i].rectYinit*ratio+490);
			afficheChaine("INPUT B",20,tabAND[i].rectXinit*ratio+420,tabAND[i].rectYinit*ratio+490);
			afficheChaine("OUTPUT",20,tabAND[i].rectXfin*ratio-300,tabAND[i].rectYfin*ratio-460);
			epaisseurDeTrait(1);
		}
	}
	if(longueurtabOR>0)
	{
		couleurCourante(255, 0, 0);
		for(int i=0;i<longueurtabOR;i++)
		{
			ligne(tabOR[i].rectXinit*ratio,tabOR[i].rectYinit*ratio,tabOR[i].rectXinit*ratio,tabOR[i].rectYfin*ratio);
			ligne(tabOR[i].rectXfin*ratio,tabOR[i].rectYinit*ratio,tabOR[i].rectXfin*ratio,tabOR[i].rectYfin*ratio);
			ligne(tabOR[i].rectXinit*ratio,tabOR[i].rectYinit*ratio,tabOR[i].rectXfin*ratio,tabOR[i].rectYinit*ratio);
			ligne(tabOR[i].rectXinit*ratio,tabOR[i].rectYfin*ratio,tabOR[i].rectXfin*ratio,tabOR[i].rectYfin*ratio);
			epaisseurDeTrait(3);
			afficheChaine("OR",20,tabOR[i].rectXfin*ratio-50,tabOR[i].rectYfin*ratio-25);
			afficheChaine("INPUT A",20,tabOR[i].rectXinit*ratio+90,tabOR[i].rectYinit*ratio+190);
			afficheChaine("INPUT B",20,tabOR[i].rectXinit*ratio+420,tabOR[i].rectYinit*ratio+190);
			afficheChaine("OUTPUT",20,tabOR[i].rectXfin*ratio+10,tabOR[i].rectYfin*ratio-150);
			epaisseurDeTrait(1);
		}
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
		if(ratio*(i)>x)
		{
			ligneX=i;
			break;
		}
	}
	for(int j=1;j<colonnes2;j++)
	{
		if(ratio*(j)>y)
		{
			colonneY=j;
			break;
		}
	}
	grille[ligneX][colonneY]=1;
}

void AffichageMatrice(float lignes2,float colonnes2)
{
	if(compteurZoom==1)
	{
		for(int i=0;i<lignes2+1;i++)
		{
			for(int j=0;j<colonnes2+1;j++)
			{
				if(grille[i][j]==1)
				{
					couleurCourante(255,169,0);
					rectangle((i)*ratio,(j)*ratio,(i)*ratio-ratio,(j)*ratio-ratio);
				}
			}
		}
	}
	else if(compteurZoom==0)
	{
		for(int i=0;i<lignes2+1;i++)
		{
			for(int j=0;j<colonnes2+1;j++)
			{
				if(grille[i][j]==1)
				{
					couleurCourante(255,169,0);
					rectangle((i)*ratio,(j)*ratio,(i)*ratio-ratio,(j)*ratio-ratio);
				}
			}
		}
	}	
	
	
	if(longueurtabNOT>0)
	{
		for(int i=0;i<longueurtabNOT;i++)
		{
			for(int x=0;x<7;x++)
			{
				if(tabNOT[i].blocage==1)
				{
					couleurCourante(0,255,0);
					rectangle(tabNOT[i].blocageX[x]*ratio,tabNOT[i].blocageY[x]*ratio,tabNOT[i].blocageX[x]*ratio-ratio,tabNOT[i].blocageY[x]*ratio-ratio);
				}
			}
		}
	}
	if(longueurtabAND>0)
	{
		for(int i=0;i<longueurtabAND;i++)
		{
			for(int x=0;x<7;x++)
			{
				if(tabAND[i].blocage1==1)
				{
					couleurCourante(0,255,0);
					rectangle(tabAND[i].blocage1X[x]*ratio,tabAND[i].blocage1Y[x]*ratio,tabAND[i].blocage1X[x]*ratio-ratio,tabAND[i].blocage1Y[x]*ratio-ratio);
				}
				if(tabAND[i].blocage2==1)
				{
					couleurCourante(0,255,0);
					rectangle(tabAND[i].blocage2X[x]*ratio,tabAND[i].blocage2Y[x]*ratio,tabAND[i].blocage2X[x]*ratio-ratio,tabAND[i].blocage2Y[x]*ratio-ratio);
				}
				
			}
		}
	}
	if(longueurtabOR>0)
	{
		for(int i=0;i<longueurtabOR;i++)
		{
			for(int x=0;x<7;x++)
			{
				if(tabOR[i].blocage1==1)
				{
					couleurCourante(0,255,0);
					rectangle(tabOR[i].blocage1X[x]*ratio,tabOR[i].blocage1Y[x]*ratio,tabOR[i].blocage1X[x]*ratio-ratio,tabOR[i].blocage1Y[x]*ratio-ratio);
				}
				if(tabOR[i].blocage2==1)
				{
					couleurCourante(0,255,0);
					rectangle(tabOR[i].blocage2X[x]*ratio,tabOR[i].blocage2Y[x]*ratio,tabOR[i].blocage2X[x]*ratio-ratio,tabOR[i].blocage2Y[x]*ratio-ratio);
				}
				
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

void AfficheBtnZoom(void)
{
    couleurCourante(255,255,255);
    rectangle(largeurFenetre()*1693/1920,hauteurFenetre()*8/1080,largeurFenetre()*1872/1920,hauteurFenetre()*122/1080);
    couleurCourante(0,0,0);
    rectangle(largeurFenetre()*1695/1920,hauteurFenetre()*10/1080,largeurFenetre()*1870/1920,hauteurFenetre()*120/1080);
    couleurCourante(255,255,255);
    epaisseurDeTrait(5);
    ligne(largeurFenetre()*1740/1920,hauteurFenetre()*30/1080,largeurFenetre()*1775/1920,hauteurFenetre()*57/1080);
    cercle(largeurFenetre()*1795/1920,hauteurFenetre()*70/1080,20);
    couleurCourante(0,0,0);
    cercle(largeurFenetre()*1795/1920,hauteurFenetre()*70/1080,16);
    couleurCourante(255,255,255);
    cercle(largeurFenetre()*1795/1920,hauteurFenetre()*70/1080,12);
    couleurCourante(0,0,0);
    cercle(largeurFenetre()*1795/1920,hauteurFenetre()*70/1080,10);
    couleurCourante(100,255,255);
    epaisseurDeTrait(3);
    afficheChaine("+",25,largeurFenetre()*1785/1920,hauteurFenetre()*60/1080);
    if(etatZoom==1)
    {
    	couleurCourante(0,0,0);
	    rectangle(largeurFenetre()*1693/1920,hauteurFenetre()*8/1080,largeurFenetre()*1872/1920,hauteurFenetre()*122/1080);
	    couleurCourante(255,255,255);
	    rectangle(largeurFenetre()*1695/1920,hauteurFenetre()*10/1080,largeurFenetre()*1870/1920,hauteurFenetre()*120/1080);
	    couleurCourante(0,0,0);
	    epaisseurDeTrait(5);
	    ligne(largeurFenetre()*1740/1920,hauteurFenetre()*30/1080,largeurFenetre()*1775/1920,hauteurFenetre()*57/1080);
	    cercle(largeurFenetre()*1795/1920,hauteurFenetre()*70/1080,20);
	    couleurCourante(255,255,255);
	    cercle(largeurFenetre()*1795/1920,hauteurFenetre()*70/1080,16);
	    couleurCourante(0,0,0);
	    cercle(largeurFenetre()*1795/1920,hauteurFenetre()*70/1080,12);
	    couleurCourante(255,255,255);
	    cercle(largeurFenetre()*1795/1920,hauteurFenetre()*70/1080,10);
	    couleurCourante(100,255,255);
	    epaisseurDeTrait(3);
	    afficheChaine("+",25,largeurFenetre()*1785/1920,hauteurFenetre()*60/1080);
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
		if(ratio*(i)>x)
		{
			ligneX=i;
			break;
		}
	}
	for(int j=0;j<colonnes2+2;j++)
	{
		if(ratio*(j)>y)
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
	for(int i=0;i<lignes_grilles;i++)
	{
		for(int j=0;j<colonnes_grilles;j++)
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
				rectangle((i)*ratio,(j)*ratio,(i)*ratio-ratio,(j)*ratio-ratio);
			}
		}
	}
	if(longueurtabNOT>0)
	{
		for(int i=0;i<longueurtabNOT;i++)
		{
			for(int x=0;x<7;x++)
			{
				if(tabNOT[i].blocage==1)
				{
					couleurCourante(0,255,0);
					rectangle(tabNOT[i].blocageX[x]*ratio,tabNOT[i].blocageY[x]*ratio,tabNOT[i].blocageX[x]*ratio-ratio,tabNOT[i].blocageY[x]*ratio-ratio);
				}
			}
		}
	}
	if(longueurtabAND>0)
	{
		for(int i=0;i<longueurtabAND;i++)
		{
			for(int x=0;x<7;x++)
			{
				if(tabAND[i].blocage1==1)
				{
					couleurCourante(0,255,0);
					rectangle(tabAND[i].blocage1X[x]*ratio,tabAND[i].blocage1Y[x]*ratio,tabAND[i].blocage1X[x]*ratio-ratio,tabAND[i].blocage1Y[x]*ratio-ratio);
				}
				if(tabAND[i].blocage2==1)
				{
					couleurCourante(0,255,0);
					rectangle(tabAND[i].blocage2X[x]*ratio,tabAND[i].blocage2Y[x]*ratio,tabAND[i].blocage2X[x]*ratio-ratio,tabAND[i].blocage2Y[x]*ratio-ratio);
				}
				
			}
		}
	}
	if(longueurtabOR>0)
	{
		for(int i=0;i<longueurtabOR;i++)
		{
			for(int x=0;x<7;x++)
			{
				if(tabOR[i].blocage1==1)
				{
					couleurCourante(0,255,0);
					rectangle(tabOR[i].blocage1X[x]*ratio,tabOR[i].blocage1Y[x]*ratio,tabOR[i].blocage1X[x]*ratio-ratio,tabOR[i].blocage1Y[x]*ratio-ratio);
				}
				if(tabOR[i].blocage2==1)
				{
					couleurCourante(0,255,0);
					rectangle(tabOR[i].blocage2X[x]*ratio,tabOR[i].blocage2Y[x]*ratio,tabOR[i].blocage2X[x]*ratio-ratio,tabOR[i].blocage2Y[x]*ratio-ratio);
				}
				
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
		// Point d'interrogation
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
	reset=1;
	InitialisationGrille();
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

void GosperGliderGunDroite(int initX, int initY)
{
	grille[initX][initY]=1;
	grille[initX+1][initY]=1;
	grille[initX+1][initY-1]=1;
	grille[initX][initY-1]=1;
	grille[initX+10][initY]=1;
	grille[initX+10][initY-1]=1;
	grille[initX+10][initY-2]=1;
	grille[initX+11][initY-3]=1;
	grille[initX+12][initY-4]=1;
	grille[initX+13][initY-4]=1;
	grille[initX+15][initY-3]=1;
	grille[initX+16][initY-2]=1;
	grille[initX+16][initY-1]=1;
	grille[initX+16][initY]=1;
	grille[initX+17][initY-1]=1;
	grille[initX+16][initY-2]=1;
	grille[initX+15][initY+1]=1;
	grille[initX+13][initY+2]=1;
	grille[initX+12][initY+2]=1;
	grille[initX+11][initY+1]=1;
	grille[initX+14][initY-1]=1;
	grille[initX+20][initY]=1;
	grille[initX+21][initY]=1;
	grille[initX+20][initY+1]=1;
	grille[initX+21][initY+1]=1;
	grille[initX+20][initY+2]=1;
	grille[initX+21][initY+2]=1;
	grille[initX+22][initY-1]=1;
	grille[initX+22][initY+3]=1;
	grille[initX+24][initY-1]=1;
	grille[initX+24][initY+3]=1;
	grille[initX+24][initY+4]=1;
	grille[initX+24][initY-2]=1;
	grille[initX+34][initY+1]=1;
	grille[initX+35][initY+1]=1;
	grille[initX+34][initY+2]=1;
	grille[initX+35][initY+2]=1;
}

void GosperGliderGunGauche(int initX, int initY)
{
	grille[initX][initY]=1;
	grille[initX+1][initY]=1;
	grille[initX][initY-1]=1;
	grille[initX+1][initY-1]=1;
	grille[initX+11][initY+1]=1;
	grille[initX+11][initY+2]=1;
	grille[initX+11][initY-3]=1;
	grille[initX+11][initY-4]=1;
	grille[initX+13][initY+1]=1;
	grille[initX+13][initY-3]=1;
	grille[initX+14][initY]=1;
	grille[initX+14][initY-1]=1;
	grille[initX+14][initY-2]=1;
	grille[initX+15][initY]=1;
	grille[initX+15][initY-1]=1;
	grille[initX+15][initY-2]=1;
	grille[initX+18][initY-3]=1;
	grille[initX+19][initY-3]=1;
	grille[initX+19][initY-2]=1;
	grille[initX+19][initY-4]=1;
	grille[initX+20][initY-1]=1;
	grille[initX+20][initY-5]=1;
	grille[initX+21][initY-3]=1;
	grille[initX+22][initY]=1;
	grille[initX+23][initY]=1;
	grille[initX+22][initY-6]=1;
	grille[initX+23][initY-6]=1;
	grille[initX+24][initY-1]=1;
	grille[initX+24][initY-5]=1;
	grille[initX+25][initY-2]=1;
	grille[initX+25][initY-3]=1;
	grille[initX+25][initY-4]=1;
	grille[initX+34][initY-2]=1;
	grille[initX+35][initY-2]=1;
	grille[initX+34][initY-3]=1;
	grille[initX+35][initY-3]=1;
}

void LogicGateNOT(int initX,int initY,int blocage)
{
	tabNOT[longueurtabNOT].X=initX;
	tabNOT[longueurtabNOT].Y=initY;
	tabNOT[longueurtabNOT].rectXinit=initX-4;
	tabNOT[longueurtabNOT].rectYinit=initY-20;
	tabNOT[longueurtabNOT].rectXfin=initX+80;
	tabNOT[longueurtabNOT].rectYfin=initY+7;
	tabNOT[longueurtabNOT].blocage=blocage;
	tabNOT[longueurtabNOT].blocageX[0]=initX+23;
	tabNOT[longueurtabNOT].blocageX[1]=initX+24;
	tabNOT[longueurtabNOT].blocageX[2]=initX+23;
	tabNOT[longueurtabNOT].blocageX[3]=initX+24;
	tabNOT[longueurtabNOT].blocageX[4]=initX+25;
	tabNOT[longueurtabNOT].blocageX[5]=initX+26;
	tabNOT[longueurtabNOT].blocageX[6]=initX+26;
	tabNOT[longueurtabNOT].blocageY[0]=initY-6;
	tabNOT[longueurtabNOT].blocageY[1]=initY-6;
	tabNOT[longueurtabNOT].blocageY[2]=initY-7;
	tabNOT[longueurtabNOT].blocageY[3]=initY-8;
	tabNOT[longueurtabNOT].blocageY[4]=initY-8;
	tabNOT[longueurtabNOT].blocageY[5]=initY-8;
	tabNOT[longueurtabNOT].blocageY[6]=initY-9;
	longueurtabNOT++;
	GosperGliderGunDroite(initX, initY);
	GosperGliderGunGauche(initX+40,initY-11);
	if(blocage==1)
	{
		grille[initX+23][initY-6]=1;
		grille[initX+24][initY-6]=1;
		grille[initX+23][initY-7]=1;
		grille[initX+24][initY-8]=1;
		grille[initX+25][initY-8]=1;
		grille[initX+26][initY-8]=1;
		grille[initX+26][initY-9]=1;
	}
}

void LogicGateAND(int initX,int initY,int blocage1,int blocage2)
{
	tabAND[longueurtabAND].X=initX-52;
	tabAND[longueurtabAND].Y=initY;
	tabAND[longueurtabAND].rectXinit=initX-55;
	tabAND[longueurtabAND].rectYinit=initY-67;
	tabAND[longueurtabAND].rectXfin=initX+80;
	tabAND[longueurtabAND].rectYfin=initY+7;
	tabAND[longueurtabAND].blocage1=blocage1;
	tabAND[longueurtabAND].blocage2=blocage2;
	tabAND[longueurtabAND].blocage1X[0]=initX-29;
	tabAND[longueurtabAND].blocage1X[1]=initX-28;
	tabAND[longueurtabAND].blocage1X[2]=initX-29;
	tabAND[longueurtabAND].blocage1X[3]=initX-28;
	tabAND[longueurtabAND].blocage1X[4]=initX-27;
	tabAND[longueurtabAND].blocage1X[5]=initX-26;
	tabAND[longueurtabAND].blocage1X[6]=initX-26;
	tabAND[longueurtabAND].blocage1Y[0]=initY-6;
	tabAND[longueurtabAND].blocage1Y[1]=initY-6;
	tabAND[longueurtabAND].blocage1Y[2]=initY-7;
	tabAND[longueurtabAND].blocage1Y[3]=initY-8;
	tabAND[longueurtabAND].blocage1Y[4]=initY-8;
	tabAND[longueurtabAND].blocage1Y[5]=initY-8;
	tabAND[longueurtabAND].blocage1Y[6]=initY-9;
	tabAND[longueurtabAND].blocage2X[0]=initX+23;
	tabAND[longueurtabAND].blocage2X[1]=initX+24;
	tabAND[longueurtabAND].blocage2X[2]=initX+23;
	tabAND[longueurtabAND].blocage2X[3]=initX+24;
	tabAND[longueurtabAND].blocage2X[4]=initX+25;
	tabAND[longueurtabAND].blocage2X[5]=initX+26;
	tabAND[longueurtabAND].blocage2X[6]=initX+26;
	tabAND[longueurtabAND].blocage2Y[0]=initY-6;
	tabAND[longueurtabAND].blocage2Y[1]=initY-6;
	tabAND[longueurtabAND].blocage2Y[2]=initY-7;
	tabAND[longueurtabAND].blocage2Y[3]=initY-8;
	tabAND[longueurtabAND].blocage2Y[4]=initY-8;
	tabAND[longueurtabAND].blocage2Y[5]=initY-8;
	tabAND[longueurtabAND].blocage2Y[6]=initY-9;
	grille[initX+10][initY-60]=1;
	grille[initX+10][initY-61]=1;
	grille[initX+9][initY-60]=1;
	grille[initX+8][initY-61]=1;
	grille[initX+8][initY-62]=1;
	grille[initX+8][initY-63]=1;
	grille[initX+7][initY-63]=1;
	longueurtabAND++;
	GosperGliderGunDroite(initX, initY);
	GosperGliderGunGauche(initX+40,initY-11);
	if(blocage2==1)
	{
		grille[initX+23][initY-6]=1;
		grille[initX+24][initY-6]=1;
		grille[initX+23][initY-7]=1;
		grille[initX+24][initY-8]=1;
		grille[initX+25][initY-8]=1;
		grille[initX+26][initY-8]=1;
		grille[initX+26][initY-9]=1;
	}
	GosperGliderGunDroite(initX-52,initY);
	if(blocage1==1)
	{
		grille[initX-29][initY-6]=1;
		grille[initX-28][initY-6]=1;
		grille[initX-29][initY-7]=1;
		grille[initX-28][initY-8]=1;
		grille[initX-27][initY-8]=1;
		grille[initX-26][initY-8]=1;
		grille[initX-26][initY-9]=1;
	}
}

void LogicGateOR(int initX,int initY,int blocage1,int blocage2)
{
	tabOR[longueurtabOR].X=initX-82;
	tabOR[longueurtabOR].Y=initY;
	tabOR[longueurtabOR].rectXinit=initX-85;
	tabOR[longueurtabOR].rectYinit=initY-20;
	tabOR[longueurtabOR].rectXfin=initX+80;
	tabOR[longueurtabOR].rectYfin=initY+7;
	tabOR[longueurtabOR].blocage1=blocage1;
	tabOR[longueurtabOR].blocage2=blocage2;
	tabOR[longueurtabOR].blocage1X[0]=initX-59;
	tabOR[longueurtabOR].blocage1X[1]=initX-58;
	tabOR[longueurtabOR].blocage1X[2]=initX-59;
	tabOR[longueurtabOR].blocage1X[3]=initX-58;
	tabOR[longueurtabOR].blocage1X[4]=initX-57;
	tabOR[longueurtabOR].blocage1X[5]=initX-56;
	tabOR[longueurtabOR].blocage1X[6]=initX-56;
	tabOR[longueurtabOR].blocage1Y[0]=initY-6;
	tabOR[longueurtabOR].blocage1Y[1]=initY-6;
	tabOR[longueurtabOR].blocage1Y[2]=initY-7;
	tabOR[longueurtabOR].blocage1Y[3]=initY-8;
	tabOR[longueurtabOR].blocage1Y[4]=initY-8;
	tabOR[longueurtabOR].blocage1Y[5]=initY-8;
	tabOR[longueurtabOR].blocage1Y[6]=initY-9;
	tabOR[longueurtabOR].blocage2X[0]=initX+23;
	tabOR[longueurtabOR].blocage2X[1]=initX+24;
	tabOR[longueurtabOR].blocage2X[2]=initX+23;
	tabOR[longueurtabOR].blocage2X[3]=initX+24;
	tabOR[longueurtabOR].blocage2X[4]=initX+25;
	tabOR[longueurtabOR].blocage2X[5]=initX+26;
	tabOR[longueurtabOR].blocage2X[6]=initX+26;
	tabOR[longueurtabOR].blocage2Y[0]=initY-6;
	tabOR[longueurtabOR].blocage2Y[1]=initY-6;
	tabOR[longueurtabOR].blocage2Y[2]=initY-7;
	tabOR[longueurtabOR].blocage2Y[3]=initY-8;
	tabOR[longueurtabOR].blocage2Y[4]=initY-8;
	tabOR[longueurtabOR].blocage2Y[5]=initY-8;
	tabOR[longueurtabOR].blocage2Y[6]=initY-9;
	longueurtabOR++;
	GosperGliderGunDroite(initX, initY);
	GosperGliderGunGauche(initX+40,initY-11);
	if(blocage2==1)
	{
		grille[initX+23][initY-6]=1;
		grille[initX+24][initY-6]=1;
		grille[initX+23][initY-7]=1;
		grille[initX+24][initY-8]=1;
		grille[initX+25][initY-8]=1;
		grille[initX+26][initY-8]=1;
		grille[initX+26][initY-9]=1;
	}
	GosperGliderGunDroite(initX-82, initY);
	//GosperGliderGunGauche(initX-42,initY-11);
	if(blocage1==1)
	{
		grille[initX-59][initY-6]=1;
		grille[initX-58][initY-6]=1;
		grille[initX-59][initY-7]=1;
		grille[initX-58][initY-8]=1;
		grille[initX-57][initY-8]=1;
		grille[initX-56][initY-8]=1;
		grille[initX-56][initY-9]=1;
	}
}

void afficherRectangleZoom(void)
{
	couleurCourante(0, 184, 15);
	if(etatBoutonSouris()==GaucheAppuye)
	{
		compteurZoom=0;
		rectangle(clicBasX,clicBasY,clicHautX,clicHautY);
	}
	if(etatBoutonSouris()==GaucheRelache && compteurZoom==0)
	{
		lignes2=abs(clicHautX-clicBasX)/ratio;
		colonnes2=lignes2;
		compteurZoom=1;
	}
	

}

void AffichageBoutonGrille(void)
{
    couleurCourante(255,255,255);
    rectangle(largeurFenetre()*1468/1920,hauteurFenetre()*8/1080,largeurFenetre()*1647/1920,hauteurFenetre()*122/1080);
    couleurCourante(0,0,0);
    rectangle(largeurFenetre()*1470/1920,hauteurFenetre()*10/1080,largeurFenetre()*1645/1920,hauteurFenetre()*120/1080);
    couleurCourante(200,200,200);
    rectangle(largeurFenetre()*1488/1920,hauteurFenetre()*23/1080,largeurFenetre()*1627/1920,hauteurFenetre()*105/1080);
	couleurCourante(0,0,0);
    rectangle(largeurFenetre()*1490/1920,hauteurFenetre()*25/1080,largeurFenetre()*1625/1920,hauteurFenetre()*102/1080);
    couleurCourante(130,130,130);
    epaisseurDeTrait(5);
    ligne(largeurFenetre()*1500/1920,hauteurFenetre()*25/1080,largeurFenetre()*1500/1920,hauteurFenetre()*102/1080);
	ligne(largeurFenetre()*1520/1920,hauteurFenetre()*25/1080,largeurFenetre()*1520/1920,hauteurFenetre()*102/1080);
    ligne(largeurFenetre()*1540/1920,hauteurFenetre()*25/1080,largeurFenetre()*1540/1920,hauteurFenetre()*102/1080);
    ligne(largeurFenetre()*1560/1920,hauteurFenetre()*25/1080,largeurFenetre()*1560/1920,hauteurFenetre()*102/1080);
    ligne(largeurFenetre()*1580/1920,hauteurFenetre()*25/1080,largeurFenetre()*1580/1920,hauteurFenetre()*102/1080);
    ligne(largeurFenetre()*1600/1920,hauteurFenetre()*25/1080,largeurFenetre()*1600/1920,hauteurFenetre()*102/1080);
    ligne(largeurFenetre()*1620/1920,hauteurFenetre()*25/1080,largeurFenetre()*1620/1920,hauteurFenetre()*102/1080);
    ligne(largeurFenetre()*1491/1920,hauteurFenetre()*35/1080,largeurFenetre()*1624/1920,hauteurFenetre()*35/1080);
    ligne(largeurFenetre()*1491/1920,hauteurFenetre()*55/1080,largeurFenetre()*1624/1920,hauteurFenetre()*55/1080);
    ligne(largeurFenetre()*1491/1920,hauteurFenetre()*75/1080,largeurFenetre()*1624/1920,hauteurFenetre()*75/1080);
    ligne(largeurFenetre()*1491/1920,hauteurFenetre()*95/1080,largeurFenetre()*1624/1920,hauteurFenetre()*95/1080);
}

void AfficheFlecheDroite(void){
	epaisseurDeTrait(5);
	couleurCourante(255,255,255);
	triangle(largeurFenetre()*1911/1920,hauteurFenetre()*65/1080,largeurFenetre()*1902/1920,hauteurFenetre()*50/1080,largeurFenetre()*1902/1920,hauteurFenetre()*80/1080);
}

void AfficheFlecheGauche(void){
	epaisseurDeTrait(5);
	couleurCourante(255,255,255);
	triangle(largeurFenetre()*9/1920,hauteurFenetre()*65/1080,largeurFenetre()*18/1920,hauteurFenetre()*50/1080,largeurFenetre()*18/1920,hauteurFenetre()*80/1080);
}

void AfficheLogicGateNOT(void){

    if (NotOnOff == 0)

    {

        couleurCourante(255,255,255);

        rectangle(largeurFenetre()*30/1920, hauteurFenetre()*10/1080, largeurFenetre()*205/1920, hauteurFenetre()*120/1080);

        couleurCourante(0,0,0);

        rectangle(largeurFenetre()*32/1920, hauteurFenetre()*12/1080, largeurFenetre()*203/1920, hauteurFenetre()*118/1080);

        couleurCourante(255,255,255);

        epaisseurDeTrait(3);

        afficheChaine("NOT", 50, largeurFenetre()*65/1920, hauteurFenetre()*45/1080);    

    }

    else if (NotOnOff == 1)

    {

        couleurCourante(0,0,0);

        rectangle(largeurFenetre()*30/1920, hauteurFenetre()*10/1080, largeurFenetre()*205/1920, hauteurFenetre()*120/1080);

        couleurCourante(255,255,255);

        rectangle(largeurFenetre()*32/1920, hauteurFenetre()*12/1080, largeurFenetre()*203/1920, hauteurFenetre()*118/1080);

        couleurCourante(0,0,0);

        epaisseurDeTrait(3);

        afficheChaine("NOT", 50, largeurFenetre()*65/1920, hauteurFenetre()*45/1080);    

    }

}



void AfficheLogicGateAND(void){

    if ( AndOnOff == 0)

    {

        couleurCourante(255,255,255);

        rectangle(largeurFenetre()*251/1920, hauteurFenetre()*10/1080, largeurFenetre()*424/1920, hauteurFenetre()*120/1080);

        couleurCourante(0,0,0);

        rectangle(largeurFenetre()*253/1920, hauteurFenetre()*12/1080, largeurFenetre()*422/1920, hauteurFenetre()*118/1080);

        couleurCourante(255,255,255);

        epaisseurDeTrait(3);

        afficheChaine("AND", 50, largeurFenetre()*285/1920, hauteurFenetre()*45/1080);    

    }

    else if ( AndOnOff == 1)

    {

        couleurCourante(0,0,0);

        rectangle(largeurFenetre()*251/1920, hauteurFenetre()*10/1080, largeurFenetre()*424/1920, hauteurFenetre()*120/1080);

        couleurCourante(255,255,255);

        rectangle(largeurFenetre()*253/1920, hauteurFenetre()*12/1080, largeurFenetre()*422/1920, hauteurFenetre()*118/1080);

        couleurCourante(0,0,0);

        epaisseurDeTrait(3);

        afficheChaine("AND", 50, largeurFenetre()*285/1920, hauteurFenetre()*45/1080);    

    }

}



void AfficheLogicGateOR(void){

    if ( OrOnOff == 0)

    {

        couleurCourante(255,255,255);

        rectangle(largeurFenetre()*470/1920, hauteurFenetre()*10/1080, largeurFenetre()*643/1920, hauteurFenetre()*120/1080);

        couleurCourante(0,0,0);

        rectangle(largeurFenetre()*472/1920, hauteurFenetre()*12/1080, largeurFenetre()*641/1920, hauteurFenetre()*118/1080);

        couleurCourante(255,255,255);

        epaisseurDeTrait(3);

        afficheChaine("OR", 50, largeurFenetre()*515/1920, hauteurFenetre()*45/1080);    

    }

    else if ( OrOnOff == 1)

    {

        couleurCourante(0,0,0);

        rectangle(largeurFenetre()*470/1920, hauteurFenetre()*10/1080, largeurFenetre()*643/1920, hauteurFenetre()*120/1080);

        couleurCourante(255,255,255);

        rectangle(largeurFenetre()*472/1920, hauteurFenetre()*12/1080, largeurFenetre()*641/1920, hauteurFenetre()*118/1080);

        couleurCourante(0,0,0);

        epaisseurDeTrait(3);

        afficheChaine("OR", 50, largeurFenetre()*515/1920, hauteurFenetre()*45/1080);    

    }

}