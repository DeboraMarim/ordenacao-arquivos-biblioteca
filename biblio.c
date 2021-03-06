
/*AQUI VAO OS ESCOPOS DAS FUNÇOES*/

#include "biblio.h"

/************************INSERTION***************************************/

InsertionSort(int *p, int t){

   /*variaveis auxiliares*/
        int k, j, aux;
        int n = t;
    /* processo de ordenacao*/
        for (k = 1; k <= n - 1; k++){
            aux = p[k];
            j = k - 1;
                while (j >= 0 && aux < p[j]) {
                    p[j+1] = p[j];
                    j--;
                }
            p[j+1] = aux;
       }

    printf("\n \n Metodo Insertion concluido com sucesso \n ");
    exibeVet(p, t);

};
/****************************BUBBLE***********************************/

BubbleSort(int *p, int t){

/*variaveis auxiliares*/
    int contador;
    int TAM;
    TAM = t;
    int i;
    int aux;

/* processo de ordenacao*/

 for (contador = 1; contador < TAM; contador++) {
   for (i = 0; i < TAM - 1; i++) {
     if (p[i] > p[i + 1]) {
       aux = p[i];
       p[i] = p[i + 1];
       p[i + 1] = aux;
     }
   }
 }

    printf("\n \n Metodo Bubble concluido com sucesso \n ");
    exibeVet(p, t);

};

/****************************PREENCHE RANDOMICO***********************************/

 void preencheRandon(char *arquivo, int t){
       int i =0;


            while(i<t){
                fprintf(arquivo , "%d ", rand() % t);
                i++;
            }

}
/****************************EXIBE VETOR***********************************/
  void exibeVet(int *p, int t){
      printf("\n \n VETOR: \n ");
      int i=0;
      while(i<t){
            printf("%d  ", p[i]);
            i++;
        }
  }
/****************************PREENCHE ORDENADO***********************************/

 void preencheoOrdenado(char *arquivo, int *p, int t){
       int i =0;


            while(i<t){
                fprintf(arquivo , "%d ", p[i]);
                i++;
            }

}
/****************************PREENCHE ORDENADO***********************************/
void fSelect_Sort(int *p, int TAM){

    int vMenor;
    int vAux;
    int vTemp;
    int vTroca;

    for(vAux=0; vAux < TAM-1; vAux++) // Percorre todo o vetor até TAM-1, pois a ultima posição não precisa testar pois ja estara ordenada;
    {
        vMenor = vAux; // Menor valor recebe a posição que está passando;

        for (vTemp=vAux+1; vTemp < TAM; vTemp++) // Percorre o vetor da posição vAux+1 até o final;
        {
            if (p[vTemp] < p[vMenor]) // Testa se a posição que está passando é menor que o menor valor;
            {
                vMenor = vTemp; // vMenor recebe a posição do menor valor;
            }
        }

        if (vMenor != vAux) // Se a posição for diferente da que está passando, ocorre a troca;
        {
            vTroca   = p[vAux];
            p[vAux]   = p[vMenor];
            p[vMenor] = vTroca;
        }
    }
    printf("\n \n Metodo Selection concluido com sucesso \n ");
    exibeVet(p, TAM);

}

/****************************SHELL ORDENADO***********************************/


void shell_sort(int *p, int t)
{
 int i , j , value;
 int gap = 1;

 do {
  gap = 3*gap+1;
 } while(gap < t);

 do {
  gap /= 3;
  for(i = gap; i < t; i++) {
   value = p[i];
   j = i - gap;

   while (j >= 0 && value < p[j]) {
    p[j + gap] = p[j];
    j -= gap;
   }
   p[j + gap] = value;
  }
 }while(gap > 1);
}
