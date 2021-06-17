#include <stdlib.h>
#ifndef CONWAY
#define CONWAY

int **grille=NULL;
int lignes_grilles=300; // MAX=300
int colonnes_grilles=300; // MAX=300
float curseur;
float lignes2=10;
float colonnes2=10;
float boutonabscisse;
int etat = 0;
int **grillet1=NULL;
int menu = 0;

void cercle(float centreX, float centreY, float rayon);
void InitialisationGrille(void); 
void LibererMemoireGrille(void);
void AffichageMenu(void);
void AffichageMatrice(float lignes2,float colonnes2);
void SourisCase(float lignes2,float colonnes2);
void AffichageGrille(float ligne2,float colonnes2);
void SliderZoom(void);
void ModifierPositionCurseur(void);
void RetirerCase(float lignes2,float colonnes2);
void AfficheBtnLecture(void);
void InitialisationGrillet1(void);
void RemplirGrillet1(void);
int ScanCellules(int i,int j);
void ReglesConway(int nombre_voisin_vivant,int x,int y);
void AffichageGrillet1(float lignes2,float colonnes2);
void PassageTempsSuperieur(void);
void AfficheBtnReset(void);
void InitialiserVariablesGlobales(void);
void InitialiserLignesColonnesAffichage(void);
void AffichePointInterrogation(void);

#endif
