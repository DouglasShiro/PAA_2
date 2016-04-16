/* 6)
*                          UNIVERSIDADE DE BRASILIA
*                                   1/2016
*                       Projeto e Analise de Algoritmos
*
*                      Douglas Shiro Yokoyama 13/0024902
*
*******************************************************************************
* Agoritmo Insertion sort:
*   <comando> Insertion_sort < entrada.txt > saida.txt
*   <Complexidade> # melhor: O(n) # medio: O(n²) # pior: O(n²)
*
*******************************************************************************
* 6.1) conta_inversão: numero de inversoes que o vetor contem
*   - inversao: se i > j e A[i] < A[j]
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
 int T, contT = 0, N, i, j, temp;
 int a[10000];
 int contSwap = 0;

	do{
			scanf("%d", &T); //Numero de vezes que o algoritmo sera rodado
	}while((T < 0) || (T >= 5));

 while(contT != T){
   scanf("%d", &N); //Numero de elementos a serem organizados
	 for(i = 0; i < N; i++){
      scanf("%d", &a[i]);
   }

	 for(i = 1; i < N; i++){
		 	temp = a[i];
			j = i - 1;
			while((j >= 0) && (temp < a[j])){
					a[j+1] = a[j];
					j = j - 1;
					contSwap++;
			}
			a[j+1] = temp;
	 }

    printf("%d\n", contSwap);
  	contSwap = 0;
  	contT++;
 }

 return 0;
}
