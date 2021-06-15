#include "mod.h"
void init(int tab[])
{
	int x;
	for (x=0;x<20;x++)
	{
		tab[x]=0;
	}
	tab[0]=1;

}

void affichage(int tab[])
{

	printf("Voici la suite de Conway : ");
	int x;
	for (x=0;x<20;x++)
	{
		printf("%d ", tab[x]);
	}
	printf("\n");

}

int calc(int tab[], int tab1[])
{

	int a;
	int b;
	int c;
	int d;
	a=0;
	b=tab[a];
	c=0;
	d=0;
	
		
		while(tab[a]!=0)
		{
		b=tab[a];
		c=0;
		while (b==tab[a] && b!=0)
		{
			c++;
			a++;
		}
		tab1[d]=c;
		d++;
		tab1[d]=b;
		d++;
		}
		tab=tab1;
		d=0;
		a=0;
		while(tab[a]!=0)
		{
		b=tab[a];
		c=0;
		while (b==tab[a] && b!=0)
		{
			c++;
			a++;
		}
		tab1[d]=c;
		d++;
		tab1[d]=b;
		d++;
		}
		tab=tab1;
		d=0;
		a=0;
		
		

}
