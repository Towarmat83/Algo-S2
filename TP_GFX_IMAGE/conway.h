#include <stdlib.h>
#ifndef CONWAY
#define CONWAY

int **grille=NULL;
<<<<<<< HEAD
int lignes_grilles=300; // MAX=300
int colonnes_grilles=300; // MAX=300
float curseur=1670;
float lignes2=10;
float colonnes2=10;
float boutonabscisse=680;
int etat = 0;
=======
int lignes_grilles=150;
int colonnes_grilles=150;
int *pt_lignes_grilles=&lignes_grilles;
int *pt_colonnes_grilles=&colonnes_grilles;
int etatBtnPlus=0;
int etatBtnMoins=0;
>>>>>>> fc3b4f4ec6159da9204d74ffa3204a40acc5d1ef

void cercle(float centreX, float centreY, float rayon);
void InitialisationGrille(void); 
void LibererMemoireGrille(void);
void AffichageMenu(void);
<<<<<<< HEAD
void AffichageMatrice(float lignes2,float colonnes2);
void SourisCase(float lignes2,float colonnes2);
void AffichageGrille(float ligne2,float colonnes2);
void SliderZoom(void);
void ModifierPositionCurseur(void);
void RetirerCase(float lignes2,float colonnes2);
void Curseur(void);
void AfficheBtnLecture(void);
=======
void AffichageGrille(void);
void SourisCase(void);
void AffichageMatrice(void);
void BtnPlus(int *lignes, int *colonnes);
void AfficheBtnPlus(int etatBtnPlus);
void BtnMoins(int *lignes, int *colonnes);
void AfficheBtnMoins(int etatBtnMoins);
>>>>>>> fc3b4f4ec6159da9204d74ffa3204a40acc5d1ef

#endif
