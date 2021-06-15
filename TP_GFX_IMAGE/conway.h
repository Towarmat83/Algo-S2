#include <stdlib.h>
#ifndef CONWAY
#define CONWAY

int **grille=NULL;
int lignes_grilles=50;
int colonnes_grilles=50;
int *pt_lignes_grilles=&lignes_grilles;
int *pt_colonnes_grilles=&colonnes_grilles;

void InitialisationGrille(void); 
void LibererMemoireGrille(void);
void AffichageMenu(void);
void AffichageGrille(void);
void SourisCase(void);
void AffichageMatrice(void);

#endif