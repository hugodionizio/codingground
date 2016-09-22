/*
string s;

s.length();
strlen(s);
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//97 ao 122 usa só letras minúsculas
//65 ao 90 usa só letras maiúsculas
//48 ao 57 usa só numeros
#define COMECO_CHAR 97
#define FIM_CHAR 122
#define MAX_SENHA 20

void Forca_Bruta(char *str);
void Forca_Bruta_Inteligente(char *pass);
void Verifica_Senha(char *forca, char *pass);

int main() {
  char senha[MAX_SENHA] = "ciro";

  //Forca_Bruta_Inteligente(senha);
  Forca_Bruta(senha);

  return 0;
}
void Forca_Bruta(char *pass) {
  int i;
  char forca[MAX_SENHA];

  for (i = 0;i < MAX_SENHA; i++)
    forca[i] = '\0';

  printf("%s", pass);

  for (forca[0] = COMECO_CHAR; forca[0] <= FIM_CHAR; forca[0]++)//1 caractere
    for (forca[1] = COMECO_CHAR; forca[1] <= FIM_CHAR; forca[1]++)//2 caracteres
      for (forca[2] = COMECO_CHAR; forca[2] <= FIM_CHAR; forca[2]++)//3 caracteres
        for (forca[3] = COMECO_CHAR; forca[3] <= FIM_CHAR; forca[3]++)//4 caracteres
         // for (forca[4] = COMECO_CHAR; forca[4] <= FIM_CHAR; forca[4]++)//5 caracteres
            //for (forca[5] = COMECO_CHAR; forca[5] <= FIM_CHAR; forca[5]++)//6 caracteres
              //for (forca[6] = COMECO_CHAR; forca[6] <= FIM_CHAR; forca[6]++)//7 caracteres
               // for (forca[7] = COMECO_CHAR; forca[7] <= FIM_CHAR; forca[7]++)//8 caracteres
                 // for (forca[8] = COMECO_CHAR; forca[8] <= FIM_CHAR; forca[8]++)//9 caracteres
                    //for (forca[9] = COMECO_CHAR; forca[9] <= FIM_CHAR; forca[9]++)
                    {
                      if ( !strcmp(forca, pass) ) {
                        printf("\nSenha: %s", forca);
                        exit(1);
                       } else // retire o else e o printf abaixo para ter mais desempenho!
                       printf("\n%s", forca);
                    }
}
//Verifica e vai aumentando os digitos se não achar a senha...
void Forca_Bruta_Inteligente(char *pass) {
  int i, tam;
  char forca[MAX_SENHA];

  tam = strlen(pass);

  for (i = 0;i < MAX_SENHA; i++)
    forca[i] = '\0';

  printf("%s", pass);

  for (forca[0] = COMECO_CHAR; forca[0] <= FIM_CHAR; forca[0]++) {
    if (tam <= 1){
      if (tam == 1)
        Verifica_Senha( forca, pass);
    } else
    for (forca[1] = COMECO_CHAR; forca[1] <= FIM_CHAR; forca[1]++) {
      if (tam <= 2){
        if (tam == 2)
        Verifica_Senha( forca, pass);
      } else
      for (forca[2] = COMECO_CHAR; forca[2] <= FIM_CHAR; forca[2]++) {
        if (tam <= 3){
          if (tam == 3)
          Verifica_Senha( forca, pass);
        } else
        for (forca[3] = COMECO_CHAR; forca[3] <= FIM_CHAR; forca[3]++) {
          if (tam <= 4){
            if (tam == 4)
              Verifica_Senha( forca, pass);
          } else
          for (forca[4] = COMECO_CHAR; forca[4] <= FIM_CHAR; forca[4]++) {
            if (tam <= 5){
              if (tam == 5)
              Verifica_Senha( forca, pass);
            } else
            for (forca[5] = COMECO_CHAR; forca[5] <= FIM_CHAR; forca[5]++) {
              if (tam <= 6){
                if (tam == 6)
                Verifica_Senha( forca, pass);
              } else
              for (forca[6] = COMECO_CHAR; forca[6] <= FIM_CHAR; forca[6]++) {
                if (tam <= 7){
                  if (tam == 7)
                  Verifica_Senha( forca, pass);
                } else
                for (forca[7] = COMECO_CHAR; forca[7] <= FIM_CHAR; forca[7]++) {
                  if (tam <= 8){
                    if (tam == 8)
                    Verifica_Senha( forca, pass);
                  } else
                  for (forca[8] = COMECO_CHAR; forca[8] <= FIM_CHAR; forca[8]++) {
                    if (tam <= 9){
                      if (tam == 9)
                      Verifica_Senha( forca, pass);
                    } else {
                      printf("\nSenha muito grande! > 9");
                      exit(1);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

void Verifica_Senha(char *forca, char *pass) {

  if ( !strcmp(forca, pass) ) {
    printf("\nSenha: %s", forca);
    printf("\nSenha em ascii: ");
    {
      int i;
      for (i = 0; forca[i] != '\0'; i++)
        printf("%d:", forca[i]);
    }
    exit(1);
    } else// retire o else e o printf abaixo para ter mais desempenho!
      printf("\n%s", forca);
}
