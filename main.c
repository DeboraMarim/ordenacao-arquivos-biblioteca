/*AQUI VAO AS CHAMADAS DAS FUNÇOES*/


#include <stdio.h>
#include <stdlib.h>
#include "biblio.h"
#include <time.h>

int main()
{
    FILE* arq1;
    int op = 0;
    int tam = 0;
    int metodo = 0;
    int i =0;


    printf("\n informe o tamanho do vetor");
    printf("\n digite 1 para 500.000");
    printf("\n digite 2 para 750.000");
    printf("\n digite 3 para 1.000.000");
    scanf("%d", &op);
    printf("\n informe o metodo de ordenacao");
    printf("\n digite 1 para Insertion Sort");
    printf("\n digite 2 para Bubble Sort");
    printf("\n digite 3 para Selection Sort");
    printf("\n digite 4 para Shell Sort");
    scanf("%d", &metodo);

    if(op == 1)
        tam = 500000;

    if(op == 2)
        tam = 750000;

    if(op == 3)
        tam = 1000000;




    arq1 = fopen("arq1.txt", "w");

    if(arq1 == NULL){
            printf("\n ERRO AO ABRIR O ARQUIVO\n ");
    }

    preencheRandon(arq1, tam);

    fclose(arq1);

    int *vet;
    vet = (int *) malloc (tam * sizeof(int));

    arq1 = fopen("arq1.txt", "r");
    if(arq1 == NULL){
    printf("\n ERRO AO ABRIR O ARQUIVO\n ");
    }

    i=0;
    while((fscanf(arq1, "%d ", &vet[i])) != EOF) {
        i++;
    }
    fclose(arq1);
    i=0;

    exibeVet(vet, tam);



       clock_t inicio = clock();

    for( i = 0; i < 3000; i++)
        printf("\n%d ", i);
    double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
    printf("\nTEMPO = %.2f", tempo);



    if(metodo == 1)

        InsertionSort(vet, tam);

    if(metodo == 2 )
        BubbleSort(vet, tam);

    if(metodo == 3 )
        fSelect_Sort(vet, tam);

    if(metodo == 4 )
        shell_sort(vet, tam);





    arq1 = fopen("arq1.txt", "w");

    if(arq1 == NULL){
            printf("\n ERRO AO ABRIR O ARQUIVO\n ");
    }

    preencheoOrdenado(arq1, vet, tam);

    fclose(arq1);
 printf("\n FIM DO PROCESSO\n ");
return 0;
}



