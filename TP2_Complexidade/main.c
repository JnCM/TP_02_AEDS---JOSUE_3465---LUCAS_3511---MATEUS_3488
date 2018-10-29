#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Funcoes.h"

int main(){
    int Opcao = 1;
    while(Opcao != 0){
        int i, j, num=0, cont=0;
        int N, X, Menor_Dist;
        clock_t t_inicial, t_final;
        double Tempo_ms, Tempo_seg, Tempo_min, Tempo_hs;
        char Matricula1[5], Matricula2[5], Matricula3[5];
        printf("=======================================================================================================\n");
        printf("Digite qual opcao voce deseja:\n");
        printf("0 - Sair\n");
        printf("1 - Arquivo\n");
        printf("2 - Iterativo\n");
        printf("=======================================================================================================\n");
        scanf("%d", &Opcao);

        if(Opcao == 1){
            FILE *Arquivo;
            int **Matriz_Dist, *Vetor_Pos, *Melhor_Cam;
            char Nome_Arq[100];
            printf("=======================================================================================================\n");
            printf("Digite o nome do Arquivo com sua Extensao:\n");
            scanf("%s", Nome_Arq);
            Arquivo = fopen(Nome_Arq, "r");
            fscanf(Arquivo, "%s", Matricula1);
            fscanf(Arquivo, "%s", Matricula2);
            fscanf(Arquivo, "%s", Matricula3);
            fscanf(Arquivo, "%d", &N);

            Matriz_Dist = (int **)malloc(N*N*sizeof(int));
            for(i=1; i<=N; i++){
                Matriz_Dist[i] = (int *)malloc(N*sizeof(int));
            }
            Vetor_Pos = (int *)malloc((N-1)*sizeof(int));
            Melhor_Cam = (int *)malloc((N-1)*sizeof(int));

            for(i=1; i<=N; i++){
                for(j=1; j<=N; j++){
                    if(i==j){
                        Matriz_Dist[i][j] = 0;
                    }
                    else{
                        fscanf(Arquivo, "%d", &Matriz_Dist[i][j]);
                    }
                }
            }
            fclose(Arquivo);

            CalculaX(&X, Matricula1, Matricula2, Matricula3, N);

            PreencheVetor(Vetor_Pos, X, N);

            printf("=======================================================================================================\n");
            printf("=======================================================================================================\n");
            ImprimeMatricula(Matricula1, Matricula2, Matricula3);
            printf("=======================================================================================================\n");
            printf("=======================================================================================================\n");
            printf("Quantidade de cidades: %d\n", N);
            printf("=======================================================================================================\n");
            printf("=======================================================================================================\n");
            printf("Cidade Inicial: %d\n", X);
            printf("=======================================================================================================\n");
            t_inicial = clock();
            permuta(X, Vetor_Pos, 1, N-1, Matriz_Dist, Melhor_Cam, &Menor_Dist, &cont);
            t_final = clock();
            Tempo_ms = (t_final - t_inicial) * 1000.0 / CLOCKS_PER_SEC;
            CalculaTempo(Tempo_ms, &Tempo_seg, &Tempo_min, &Tempo_hs);
            printf("=======================================================================================================\n");
            printf("Matriz de Distancia:\n");
            printf("=======================================================================================================\n");
            ImprimeMatriz(Matriz_Dist, N);
            printf("=======================================================================================================\n");
            printf("A menor distancia foi: %d\n", Menor_Dist);
            printf("=======================================================================================================\n");
            printf("Sequencia de cidades percorridas: ");
            ImprimeCam(Melhor_Cam, X, N);
            printf("=======================================================================================================\n");
            ImprimeTempo(Tempo_ms, Tempo_seg, Tempo_min, Tempo_hs);
            printf("=======================================================================================================\n");
        }

        else if(Opcao == 2){
            int **Matriz_Dt, *Vetor_Ps, *Melhor_Cm;
            printf("=======================================================================================================\n");
            printf("Digite as Matriculas:\n");
            scanf("%s", Matricula1);
            scanf("%s", Matricula2);
            scanf("%s", Matricula3);
            printf("=======================================================================================================\n");
            printf("Digite a Quantidade de cidades:\n");
            scanf("%d", &N);
            while(N==1){
            	printf("Digite uma quantidade maior que 1:\n");
            	scanf("%d", &N);
			}
            printf("=======================================================================================================\n");

            Matriz_Dt = (int **)malloc(N*N*sizeof(int));
            for(i=1; i<=N; i++){
                Matriz_Dt[i] = (int *)malloc(N*sizeof(int));
            }
            Vetor_Ps = (int *)malloc((N-1)*sizeof(int));
            Melhor_Cm = (int *)malloc((N-1)*sizeof(int));

            for(i=1; i<=N; i++){
                for(j=1; j<=N; j++){
                    if(i==j){
                        Matriz_Dt[i][j] = 0;
                    }
                    else{
                        do{
                            num = rand()%100;
                        }while(num==0);
                        Matriz_Dt[i][j] = num;
                    }
                }
            }

            CalculaX(&X, Matricula1, Matricula2, Matricula3, N);

            PreencheVetor(Vetor_Ps, X, N);

            printf("=======================================================================================================\n");
            printf("=======================================================================================================\n");
            ImprimeMatricula(Matricula1, Matricula2, Matricula3);
            printf("=======================================================================================================\n");
            printf("=======================================================================================================\n");
            printf("Quantidade de cidades: %d\n", N);
            printf("=======================================================================================================\n");
            printf("=======================================================================================================\n");
            printf("Cidade Inicial: %d\n", X);
            printf("=======================================================================================================\n");
            t_inicial = clock();
            permuta(X, Vetor_Ps, 1, N-1, Matriz_Dt, Melhor_Cm, &Menor_Dist, &cont);
            t_final = clock();
            Tempo_ms = (t_final - t_inicial) * 1000.0 / CLOCKS_PER_SEC;
            CalculaTempo(Tempo_ms, &Tempo_seg, &Tempo_min, &Tempo_hs);
            printf("=======================================================================================================\n");
            printf("Matriz de Distancia:\n");
            printf("=======================================================================================================\n");
            ImprimeMatriz(Matriz_Dt, N);
            printf("=======================================================================================================\n");
            printf("A menor distancia foi: %d\n", Menor_Dist);
            printf("=======================================================================================================\n");
            printf("Sequencia de cidades percorridas: ");
            ImprimeCam(Melhor_Cm, X, N);
            printf("=======================================================================================================\n");
            ImprimeTempo(Tempo_ms, Tempo_seg, Tempo_min, Tempo_hs);
            printf("=======================================================================================================\n");
        }
    }

    return 0;
}
