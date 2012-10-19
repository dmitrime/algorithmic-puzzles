#define MAXIMO 2000000000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int humble[5843];
//int humble[100000];
//int combs[11*10];

int cmp_int(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

void preprocess()
{
	int i;
	int j;
	int k = 1;
	int m;
	int n;
	int valor = 1;
	int a1;
	int a2;
	int a3;
	
	//memset(humble, 0xEF, sizeof(humble));
	
	humble[0] = 0;
	/*for (i = 1; i < 5843; i++)
		humble[i] = MAXIMO + 1;*/
	
	//combs[k++] = 1;
	
/*	for (i = 0; i <= 10; i++)
	{
		if (i > 0)
			valor *= 2;
		anterior = valor;
		
		for (j = 0; j <= 9; j++)
		{
			if (j > 0)
				valor *= 5;
			
			combs[k++] = valor;
		}
		
		valor = anterior;
	}*/
	
	//i = j = k = m = n = 0;
	
	for (i = 0; /*valor <= MAXIMO/2*/; i++)
	{
		if (i > 0)
			valor *= 2;
		a1 = valor;
		
		for (j = 0; /*valor <= MAXIMO/3*/; j++)
		{
			if (j > 0)
				valor *= 3;
			a2 = valor;
			
			for (m = 0; /*valor <= MAXIMO/5*/; m++)
			{
				if (m > 0)
					valor *= 5;
				a3 = valor;
				
				/*if (valor > MAXIMO/5)
					break;*/
				
				for (n = 0; /*valor <= MAXIMO/7*/; n++)
				{
					if (n > 0)
						valor *= 7;
						
					humble[k++] = valor;
					
					if (valor > MAXIMO/7)
						break;
				}
				
				//humble[k++] = valor;
				valor = a3;

				if (valor > MAXIMO/5)
					break;
			}

			//humble[k++] = valor;
			valor = a2;
			
			if (valor > MAXIMO/3)
				break;
		} 
		
		//humble[k++] = valor;
		valor = a1;
		
		if (valor > MAXIMO/2)
			break;
	}
	
	qsort(humble, 5843, sizeof(int), cmp_int);
	
	/*for (i = 0; i < 11*10; i++)
	{
		printf("%3d %d\n", i, combs[i]);
	}*/

	/*for (i = 0; i < 5843; i++)
	{
		printf("%4d -- %10d\n", i, humble[i]);
	}
	
	printf("----------\n");*/
}

int main()
{
	int n;
	int i;
	char *sufstr[] = {"th", "st", "nd", "rd"};
	FILE *fp = fopen("out1.txt", "w");
	
	preprocess();
	
	for ( i = 1; i < 5843; i++)
	  fprintf(fp, "%d\n", humble[i]);
	
	scanf("%d", &n);
	
	while (n != 0)
	{
		if (n%100 >= 11 && n%100 <= 13)
			i = 0;
		else
		{
			switch (n%10)
			{
				case 1:
				case 2:
				case 3:
					i = n%10;
					break;
				default:
					i = 0;
			}
		}
		
		printf("The %d%s humble number is %d.\n", n, sufstr[i], humble[n]);
		
		scanf("%d", &n);
	}
	
	return 0;	
}
