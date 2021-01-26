#include <stdio.h>
#include <stdlib.h>
#include <locale.h>    
#include <sys/time.h>   
#define TAM 250



void shuffle(int *vet, size_t n);


void bubblesort (int vet[], int n);
void insertionsort (int vet[], int n);
void selectionsort (int vet[], int n);

int choose_pivot(int i, int j);
void swap(int *x, int *y);

int main () {
    setlocale (LC_ALL, "Portuguese");

    struct timeval end, now;
    int vet[TAM], o, i, aux[TAM];
    double timebubble = 0, timeinsertion = 0, timeselection = 0, timeheap = 0, timemerge = 0, timequick = 0;

        printf ("     CÓDIGO APS ORDENAÇÃO DE DADOS    \n\n\n");

        do{
            printf ("\nEscolha uma opcao\n");
            printf ("\n1 - Gerar numeros\n");
            printf ("2 - Ordenacao Bubblesort:\n");
            printf ("3 - Ordenacao Insertionsort:\n");
            printf ("4 - Ordenacao Selectionsort:\n");
            printf ("5 - Mostrar tempo de todas ordenacoes\n");
            printf ("9 - Sair\n\n");
            scanf ("%d", &o);

                switch (o){

                    case 1:
                        system ("cls");
                        srand (time(NULL));
                        for (i = 0; i < TAM; i++){
                            vet[i] = i;
                        }
                        shuffle (vet, TAM);
                        for (i = 0; i < TAM; i++) {
                            printf ("%d ", vet[i]);
                        }
                        break;
                    case 2:
                        system ("cls");
                        gettimeofday (&now, NULL);
                        bubblesort (vet, TAM);
                        gettimeofday (&end, NULL);
                        timebubble = (double)(end.tv_usec - now.tv_usec)/1000000 + (double)(end.tv_sec - now.tv_sec);
                        for (i = 0; i < TAM; i++) {
                            printf ("%d ", vet[i]);
                        }         
                        printf ("\n\n%f ms para ordenar %d nÃºmeros com o Bubblesort\n\n", timebubble, TAM);
                        break;
                    case 3:
                        system ("cls");
                        gettimeofday (&now, NULL);
                        insertionsort (vet, TAM);
                        gettimeofday (&end, NULL);
                        timeinsertion = (double)(end.tv_usec - now.tv_usec)/1000000 + (double)(end.tv_sec - now.tv_sec);
                        for (i = 0; i < TAM; i++) {
                            printf ("%d ", vet[i]);
                        }         
                        printf ("\n\n%f ms de %d nÃºmeros com o Insertionsort\n\n", timeinsertion, TAM);
                        break;
                    case 4:                       /*Execute mais de uma vez para ordenar todos os numeros*/
                        system ("cls");
                        gettimeofday (&now, NULL);
                        selectionsort (vet, TAM);
                        gettimeofday (&end, NULL);
                        timeselection = (double)(end.tv_usec - now.tv_usec)/1000000 + (double)(end.tv_sec - now.tv_sec);
                        for (i = 0; i < TAM; i++){
                            printf ("%d ", vet[i]);
                        }         
                        printf ("\n\n%f ms de %d nÃºmeros com o Selectionsort\n\n", timeselection, TAM);
                        break;
                    case 5:
                        system ("cls");
                        printf ("Tempo do Bubblesort:  ms\n", timebubble);
                        printf ("Tempo do Insertionsort:   ms\n", timeinsertion);
                        printf ("Tempo do Selectionsort:   ms\n", timeselection);
                }
        } while (o != 9);
}

void shuffle(int *vet, size_t n) {
   if (n > 1) {
       size_t i;
       for (i = 0; i < TAM; i++) {
         size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
         int t = vet[j];
         vet[j] = vet[i];
         vet[i] = t;
       }
   }
}

void bubblesort (int vet[], int n) {
    int i, j, aux;
            for (i = 0; i < n; i++) {
                for (j = 0; j < n - 1; j++) {
                    if (vet[j] > vet[j + 1]) {
                        aux = vet[j];
                        vet[j]= vet[j + 1];
                        vet[j + 1] = aux;
                    }
                }
            }
}

void insertionsort (int vet[], int n) {
	int i, j, aux;
	for (i = 1; i < n; i++) {
		aux = vet[i];
		for (j = i - 1; (j >= 0) && (aux < vet[j]); j--) {
			vet[j + 1] = vet[j];
        }
		vet[j + 1] = aux;
		}
}

void selectionsort (int vet[], int n) {
    int i, j, menor, aux;

        for (i = 0; i < n - 1; i++) {
            menor = i;
                for (j = i + 1; j < n; j++) {
                        if (vet[j] < vet[aux]) {
                            aux = j;
                        }
                }
                    if (i != aux) {
                        aux = vet[i];
                        vet[i] = vet[aux];
                        vet[aux] = aux;
                    }
        }
}

int centro (int i, int j) {
    return ((i + j) / 2);
}

void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
