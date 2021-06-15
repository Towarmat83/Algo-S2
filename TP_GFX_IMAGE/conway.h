#include <stdlib.h>
#ifndef CONWAY
#define CONWAY

int **grille=NULL;
int lignes_grilles=150;
int colonnes_grilles=150;
int *pt_lignes_grilles=&lignes_grilles;
int *pt_colonnes_grilles=&colonnes_grilles;
int etatBtnPlus=0;
int etatBtnMoins=0;

void InitialisationGrille(void); 
void LibererMemoireGrille(void);
void AffichageMenu(void);
void AffichageGrille(void);
void SourisCase(void);
void AffichageMatrice(void);
void BtnPlus(int *lignes, int *colonnes);
void AfficheBtnPlus(int etatBtnPlus);
void BtnMoins(int *lignes, int *colonnes);
void AfficheBtnMoins(int etatBtnMoins);

#endif
