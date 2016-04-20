#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char string[100];
  char** temp = NULL;
  char** entrada_strings = NULL;
  int N = 0;
  int i;

  while (scanf("%s", string) != EOF){
    N++;

    temp = (char**)realloc(entrada_strings, N * sizeof(char*));

    if (temp != NULL) {
      entrada_strings = temp;
      entrada_strings[N-1] = malloc(strlen(string) + 1);
      strcpy(entrada_strings[N-1], string);
    }
    else {
      free (entrada_strings);
      puts ("Error (re)allocating memory");
      exit (1);
    }
  }

  for (i = 0; i < N; i++)
    printf ("%s \n",entrada_strings[i]);

  free(entrada_strings);

return 0;
}
