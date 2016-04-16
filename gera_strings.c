/* 1)
*                          UNIVERSIDADE DE BRASILIA
*                                   1/2016
*                       Projeto e Analise de Algoritmos
*
*                      Douglas Shiro Yokoyama 13/0024902
*
*******************************************************************************
* Gerar Strings: <comando> gera_strings N ordem > entrada.txt
*
*   - strings podem ter 1(um) ou mais caracteres alfabéticos e espaço;
*   - MAX de caracteres por string = 100;
*   - Todos os caracteres sao minusculos;
*   - Apenas 1 (uma) string por linha;
*   - Ignorar linhas sem pelo menos 1(um) caracter alfabetico;
*   - N: numero de strings a ser gerada;
*   - ordem: norm   = strings em ordem crescente;
*            inver  = strings em ordem decrescente;
*            aleat  = strings em ordem aleatoria;
*/

#include <stdio.h>
#include <string.h>
#include <time.h>

//Gera strings aleatórias
char* Gera_strings();

//Compara Crescente
static int Compara_Norm(const void *a, const void *b);

//Compara Descresencte
static int Compara_Inver(const void *a, const void *b);

int main(int argc, char* argv[]){

  int N; //Numero de Strings a ser gerado

  srand(time(NULL));

  if (argc == 3){

    N = atoi(argv[1]);

    if(N < 0){

      printf("\nERRO: numero invalido de strings;\n");

    }else{

      if (strcmp(argv[2], "norm") == 0){



      }else if(strcmp(argv[2], "inver") == 0){



      }else if(strcmp(argv[2], "aleat") == 0){



      }else{

        printf("\nERRO: ordem nao reconhecida como valida;\n");

      }

    }
  }else{

    printf("ERRO: Argumentos invalidos;\nFormato dos argumentos: gera_strings N ordem > entrada.txt\n");

  }

  return 0;
}

char* Gera_strings(){

}

static int Compara_Norm(const void *a, const void *b){
  return strcmp (*(char **) a, *(char **) b);
}

static int Compara_Inver(const void *a, const void *b){
  return strcmp (*(char **) a, *(char **) b)*-1;
}
