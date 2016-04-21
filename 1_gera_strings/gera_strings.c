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
#include <stdlib.h>

//Gera strings aleatórias
char* GeraStrings();

//Compara Crescente
static int ComparaNorm(const void *a, const void *b);

//Compara Descresencte
static int ComparaInver(const void *a, const void *b);

int main(int argc, char* argv[]){

  int N; //Numero de Strings a ser gerado
  int i;
  char **Entrada_strings;
  char *string;

  srand(time(NULL));

  if (argc == 3){

    N = atoi(argv[1]);

    if(N < 0){

      printf("\nERRO: numero invalido de strings;\n");

    }else{

      Entrada_strings = (char**)calloc(N, sizeof(char*));

      for (i = 0; i < N; i++){
        string = GeraStrings();
        Entrada_strings[i] = string;
      }

      if (strcmp(argv[2], "norm") == 0){
        //Ordena Strings Oderm Noraml para o arquivo de entradas gerado
        qsort(Entrada_strings, N, sizeof(char*), ComparaNorm);

        for (i = 0; i < N; i++){
          printf("%s\n",Entrada_strings[i]);
          free(Entrada_strings[i]);
        }
        free(Entrada_strings);

      }else if(strcmp(argv[2], "inver") == 0){
        //Ordena Strings Ordem Inversa para o arquivo de entradas gerado
        qsort(Entrada_strings, N, sizeof(char*), ComparaInver);

        for (i = 0; i < N; i++){
          printf("%s\n", Entrada_strings[i]);
          free(Entrada_strings[i]);
        }
        free(Entrada_strings);

      }else if(strcmp(argv[2], "aleat") == 0){
        string = GeraStrings();

        for (i = 0; i < N; i++){
          printf("%s\n", Entrada_strings[i]);
          free(Entrada_strings[i]);
        }
        free(Entrada_strings);
        
      }else{

        printf("\nERRO: ordem nao reconhecida como valida;\n");

      }

    }
  }else{

    printf("\nERRO: Argumentos invalidos;\nFormato dos argumentos: gera_strings N ordem > entrada.txt\n");

  }

  return 0;
}

char* GeraStrings(){
  int Max_string = 10 + rand()%90; //tamanho maximo da string de 100 caracteres
  int i;
  char *string; //string a ser gerada

  string = (char*)calloc(Max_string+1, sizeof(char));

  for(i = 0; i < Max_string; i++){
    //gera caracteres aleatorios 97 = 'a' ~ 122 = 'z'
    string[i] = 97 + rand()%26;
  }
  string[i]= '\0';

return string;
}

static int ComparaNorm(const void *a, const void *b){
  return strcmp (*(char **) a, *(char **) b);
}

static int ComparaInver(const void *a, const void *b){
  return strcmp (*(char **) a, *(char **) b)*-1;
}
