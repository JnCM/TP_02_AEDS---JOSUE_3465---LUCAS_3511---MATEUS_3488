#include <stdio.h>
#include <stdlib.h>
#include "Funcoes.h"

void CalculaX(int *X, char *M1, char *M2, char *M3, int N){
    int Soma_dig1, Soma_dig2, Soma_dig3, Soma_Mat;
    Soma_dig1 = (((int)M1[0])-48)+(((int)M1[1])-48)+(((int)M1[2])-48)+(((int)M1[3])-48);
    Soma_dig2 = (((int)M2[0])-48)+(((int)M2[1])-48)+(((int)M2[2])-48)+(((int)M2[3])-48);
    Soma_dig3 = (((int)M3[0])-48)+(((int)M3[1])-48)+(((int)M3[2])-48)+(((int)M3[3])-48);
    Soma_Mat = Soma_dig1+Soma_dig2+Soma_dig3;
    *X = Soma_Mat%N;
    if(*X==0){
        *X = N;
    }
}

void PreencheVetor(int *Vetor, int X, int N){
    int i, aux = 0;
    for(i=1; i<=N-1; i++){
        if(i==X){
            aux = 1;
        }
        if(aux == 0){
            Vetor[i] = i;
        }
        else{
            Vetor[i] = i+1;
        }
    }
}

void troca(int *Vetor, int i, int j){
	int aux = Vetor[i];
	Vetor[i] = Vetor[j];
	Vetor[j] = aux;
}

void permuta(int X, int *Vetor, int inf, int sup, int N, int Matriz[N][N], int *Melhor_Cam, int *Menor_Dist, int *cont){
	if(inf == sup){
        int Distancia, i;
        Distancia = Matriz[X][Vetor[1]];
        Distancia += Matriz[Vetor[sup]][X];
        printf("%d ", X);
            for(i = 1; i <= sup; i++){
                printf("%d ", Vetor[i]);
                if(i != sup){
                    Distancia += Matriz[Vetor[i]][Vetor[i+1]];
                }
            }
        printf("%d - Distancia: %d\n", X, Distancia);
        printf("\n");
		if(*cont == 0){
          *Menor_Dist = Distancia;
          for(i=1; i<= sup; i++){
                Melhor_Cam[i] = Vetor[i];
          }
        *cont = 1;
		}
        else{
            if(Distancia < *Menor_Dist){
                *Menor_Dist = Distancia;
                for(i=1; i<= sup; i++){
                    Melhor_Cam[i] = Vetor[i];
                }
            }
        }
	}
	else{
        int i;
		for(i = inf; i <= sup; i++){
          troca(Vetor, inf, i);
          permuta(X, Vetor, inf+1, sup, N, Matriz, Melhor_Cam, Menor_Dist, cont);
          troca(Vetor, inf, i);
        }
	}
}

void CalculaTempo(double TempoMS, double *TempoSEG, double *TempoMIN, double *TempoHR){
    *TempoSEG = TempoMS/1000;
    *TempoMIN = *TempoSEG/60;
    *TempoHR = *TempoMIN/60;
}

void ImprimeMatricula(char *M1, char *M2, char *M3){
    printf("Matricula 1 -> %s\n", M1);
    printf("Matricula 2 -> %s\n", M2);
    printf("Matricula 3 -> %s\n", M3);
}

void ImprimeMatriz(int N, int Matriz[N][N]){
    int i, j;
    for(i=1; i<=N; i++){
        for(j=1; j<=N; j++){
            if(Matriz[i][j] <10){
                printf("0%d ", Matriz[i][j]);
            }
            else{
                printf("%d ", Matriz[i][j]);
            }
        }
        printf("\n");
    }
}

void ImprimeCam(int *VCam, int X, int N){
    int i;
    printf("%d ", X);
    for(i=1; i<=N-1; i++){
        printf("%d ", VCam[i]);
    }
    printf("%d\n", X);
}

void ImprimeTempo(double TempoMS, double TempoSEG, double TempoMIN, double TempoHR){
    printf("Tempo de execucao em milissegundos: %.2lf ms.\n", TempoMS);
    printf("Tempo de execucao em segundos: %.2lf s.\n", TempoSEG);
    printf("Tempo de execucao em minutos: %.2lf min.\n", TempoMIN);
    printf("Tempo de execucao em horas: %.2lf hrs.\n", TempoHR);
}
