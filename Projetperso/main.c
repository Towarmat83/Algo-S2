#include "mod.h"

int main()
{
int tab [20];
int tab1[20];
init(tab);
init(tab1);
tab=calc(tab, tab1);
calc(tab, tab1);
affichage(tab);
affichage(tab1);
}
