#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Compara na ordem crescente
static int compareNorm (const void * a, const void * b);

//Compara na ordem decrescente
static int compareInver (const void * a, const void * b);

//Gera uma string aleatoria
char* gerarString();

int main (int argc, char* argv[]){

    srand(time(NULL));

    if (argc == 3) {
        int num_strings = atoi(argv[1]);

        if (num_strings < 0) {

            printf("Número de strings inválido\n");

        }else{

            if (strcmp(argv[2], "norm") == 0) {

                char** allStrings = (char**)calloc(num_strings, sizeof(char*));

                for (int i = 0; i < num_strings; i++) {

                    char* string = gerarString();

                    allStrings[i] = string;

                }

                //ordena
                qsort(allStrings, num_strings, sizeof(char*), compareNorm);

                for (int i = 0; i < num_strings; i++) {
                    printf("%s\n", allStrings[i]);
                    free(allStrings[i]);
                }

                free(allStrings);

            }else if (strcmp(argv[2], "inver") == 0){

                char** allStrings = (char**)calloc(num_strings, sizeof(char*));

                for (int i = 0; i < num_strings; i++) {

                    char* string = gerarString();

                    allStrings[i] = string;

                }

                //ordena invertido
                qsort(allStrings, num_strings, sizeof(char*), compareInver);

                for (int i = 0; i < num_strings; i++) {
                    printf("%s\n", allStrings[i]);
                    free(allStrings[i]);
                }

                free(allStrings);

            }else if (strcmp(argv[2], "aleat") == 0){

                for (int i = 0; i < num_strings; i++) {

                    char* string = gerarString();

                    printf("%s\n", string);

                    free(string);
                }

            }else{
                printf("Ordem inválida\n");
            }

        }

    }else{

        printf("Erro nos argumentos\n");

    }

    return 0;
}

static int compareNorm (const void * a, const void * b){

    return strcmp (*(char **) a, *(char **) b);

}

static int compareInver (const void * a, const void * b){

    return (strcmp (*(char **) a, *(char **) b))*(-1);

}

char* gerarString(){

    int tamanhoString = 1+ rand()%100;
    char* string = (char*)calloc(tamanhoString+1, sizeof(char));

    for (int i = 0; i < tamanhoString; i++) {
        string[i] = 97 + rand()%26; //97 a 122 -> 'a' à 'z'
        string[i+1] = '\0';
    }

    return string;
}
