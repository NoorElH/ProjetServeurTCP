#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>


#define N 30


int main()
{
  char trame[]= "{\"temperature\":23.1,\"pressure\":1016.5,\"ax\": 1234,\"ay\":-6789,\"az\": 2345,\"gx\":-2345,\"gy\":12345,\"gz\":-12345,\"mx\":23456,\"my\":-23456,\"mz\": 3456}\n";

  FILE* fichier =NULL; //déclaration et initialisation du pointeur

  //Ouverture du fichier
  fichier = fopen("test.txt", "a");
  if (fichier == NULL)
    {
      //On affiche un message d'erreur
      printf("Impossible d'ouvrir le fichier test.txt");
      return -1;
    }

  else
    {
  
  char t[5]={'0'};
  char p[7]={'0'};
  char ax[6]={'0'};
  char ay[6]={'0'};
  char az[6]={'0'};
  char gx[6]={'0'};
  char gy[6]={'0'};
  char gz[6]={'0'};
  char mx[6]={'0'};
  char my[6]={'0'};
  char mz[6]={'0'};
  
  char* temp = (char*)malloc(N*sizeof(char));
  char* pres = (char*)malloc(N*sizeof(char));
  char* aax = (char*)malloc(N*sizeof(char));
  char* aay = (char*)malloc(N*sizeof(char));
  char* aaz = (char*)malloc(N*sizeof(char));
  char* ggx = (char*)malloc(N*sizeof(char));
  char* ggy = (char*)malloc(N*sizeof(char));
  char* ggz = (char*)malloc(N*sizeof(char));
  char* mmx = (char*)malloc(N*sizeof(char));
  char* mmy = (char*)malloc(N*sizeof(char));
  char* mmz = (char*)malloc(N*sizeof(char));
  

  temp = strstr(trame,":");
  pres = strstr(trame+22,":");
  aax = strstr(trame+38,":");
  aay = strstr(trame+50,":");
  aaz = strstr(trame+61,":");
  ggx = strstr(trame+72,":");
  ggy = strstr(trame+83,":");
  ggz = strstr(trame+94,":");
  mmx = strstr(trame+106,":");
  mmy = strstr(trame+117,":");
  mmz = strstr(trame+129,":");

  // int testv2;
  char* temp2 = (char*)malloc(N*sizeof(char));
  temp2= strstr(trame,",");
  while (temp2)
  {
     strncpy(t,temp+1, 4);
     printf(t);
     printf("\n");
  }
    
  
  
  /* strncpy(t,temp+1, 4);
  printf(t);
  printf("\n");*/


  strncpy(p, pres+1, 6);
  printf(p);
  printf("\n");

  strncpy(ax, aax+1, 5);
  printf(ax);
  printf("\n");

  strncpy(ay, aay+1, 5);
  printf(ay);
  printf("\n");

  strncpy(az, aaz+1, 5);
  printf(az);
  printf("\n");

  strncpy(gx, ggx+1, 5);
  printf(gx);
  printf("\n");

  strncpy(gy, ggy+1, 5);
  printf(gy);
  printf("\n");

  strncpy(gz, ggz+1, 5);
  printf(gz);
  printf("\n");

  strncpy(mx, mmx+1, 5);
  printf(mx);
  printf("\n");

  strncpy(my, mmy+1, 5);
  printf(my);
  printf("\n");

  strncpy(mz, mmz+1, 5);
  printf(mz);
  printf("\n");

  float multiplieur = 2.7;
  
  float temperature = atof(t);
  temperature = temperature * multiplieur;
  printf("%.1f",temperature);
  printf("\n");
  fprintf(fichier,"%.1f",temperature);

  fprintf(fichier,";");

  float pression = atof(p);
  pression = pression * multiplieur;
  printf("%.1f",pression);
  printf("\n");
  fprintf(fichier,"%.1f",pression);

  
    }
  fclose(fichier); //On ferme le fichier qui a été ouvert

  
  return 0;
}

