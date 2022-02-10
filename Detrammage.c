#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define N 30

int main()
{
    char trame[]="{\"ax\":   12,\"ay\":   15,\"az\":   17,\"bx\":   20,\"by\":   21,\"bz\":   22,\"gx\":   33,\"gy\":   32,\"gz\":   31,\"T\":   20,\"P\":  300,\"H\":  100,\"F\":782758}";

  FILE* fichier =NULL; //déclaration et initialisation du pointeur

  //Ouverture du fichier
  fichier = fopen("test1.bin", "ab");
  if (fichier == NULL)
    {
      //On affiche un message d'erreur
      printf("Impossible d'ouvrir le fichier test.txt");
      return -1;
    }

  else
    {
    
    char ax[6]={'0'};
    char ay[6]={'0'};
    char az[6]={'0'};
    char bx[6]={'0'};
    char by[6]={'0'};
    char bz[6]={'0'};
    char gx[6]={'0'};
    char gy[6]={'0'};
    char gz[6]={'0'};
    char T[6]={'0'};
    char P[6]={'0'};
    char H[6]={'0'};
    char F[7]={'0'};
    
    char* aax = (char*)malloc(N*sizeof(char));
    char* aay = (char*)malloc(N*sizeof(char));
    char* aaz = (char*)malloc(N*sizeof(char));
    char* bbx = (char*)malloc(N*sizeof(char));
    char* bby = (char*)malloc(N*sizeof(char));
    char* bbz = (char*)malloc(N*sizeof(char));
    char* ggx = (char*)malloc(N*sizeof(char));
    char* ggy = (char*)malloc(N*sizeof(char));
    char* ggz = (char*)malloc(N*sizeof(char));
    char* temp =(char*)malloc(N*sizeof(char));
    char* pres =(char*)malloc(N*sizeof(char));
    char* hum =(char*)malloc(N*sizeof(char));
    char* force = (char*)malloc(N*sizeof(char));
    
    char* aax2 = (char*)malloc(N*sizeof(char));
    char* aay2 = (char*)malloc(N*sizeof(char));
    char* aaz2 = (char*)malloc(N*sizeof(char));
    char* bbx2 = (char*)malloc(N*sizeof(char));
    char* bby2 = (char*)malloc(N*sizeof(char));
    char* bbz2 = (char*)malloc(N*sizeof(char));
    char* ggx2 = (char*)malloc(N*sizeof(char));
    char* ggy2 = (char*)malloc(N*sizeof(char));
    char* ggz2 = (char*)malloc(N*sizeof(char));
    char* temp2 =(char*)malloc(N*sizeof(char));
    char* pres2 =(char*)malloc(N*sizeof(char));
    char* hum2 =(char*)malloc(N*sizeof(char));
    char* force2 = (char*)malloc(N*sizeof(char));

    aax = strstr(trame,":");
    aay = strstr(trame+14,":");
    aaz = strstr(trame+25,":");
    bbx = strstr(trame+36,":");
    bby = strstr(trame+47,":");
    bbz = strstr(trame+58,":");
    ggx = strstr(trame+69,":");
    ggy = strstr(trame+80,":");
    ggz = strstr(trame+91,":");
    temp = strstr(trame+100,":");
    pres = strstr(trame+110,":");
    hum = strstr(trame+120,":");
    force = strstr(trame+131,":");
    
    aax2 = strstr(trame,",");
    aay2 = strstr(trame+14,",");
    aaz2 = strstr(trame+25,",");
    bbx2 = strstr(trame+36,",");
    bby2 = strstr(trame+47,",");
    bbz2 = strstr(trame+58,",");
    ggx2 = strstr(trame+69,",");
    ggy2 = strstr(trame+80,",");
    ggz2 = strstr(trame+91,",");
    temp2 = strstr(trame+100,",");
    pres2 = strstr(trame+110,",");
    hum2 = strstr(trame+120,",");
    force2 = strstr(trame+131,"}");
    
    int ax_size = aax2-aax;
    int ay_size = aay2-aay;
    int az_size = aaz2-aaz;
    int bx_size = bbx2-bbx;
    int by_size = bby2-bby;
    int bz_size = bbz2-bbz;
    int gx_size = ggx2-ggx;
    int gy_size = ggy2-ggy;
    int gz_size = ggz2-ggz;
    int T_size = temp2-temp;
    int P_size = pres2-pres;
    int H_size = hum2-hum;
    int F_size = force2-force;
    
    strncpy(ax, aax+1, ax_size-1);
    printf(ax);
    printf("\n");

    strncpy(ay, aay+1, ay_size-1);
    printf(ay);
    printf("\n");

    strncpy(az, aaz+1, az_size-1);
    printf(az);
    printf("\n");
        
    strncpy(bx, bbx+1, bx_size-1);
    printf(bx);
    printf("\n");

    strncpy(by, bby+1, by_size-1);
    printf(by);
    printf("\n");

    strncpy(bz, bbz+1, bz_size-1);
    printf(bz);
    printf("\n");

    strncpy(gx, ggx+1, gx_size-1);
    printf(gx);
    printf("\n");

    strncpy(gy, ggy+1, gy_size-1);
    printf(gy);
    printf("\n");

    strncpy(gz, ggz+1, gz_size-1);
    printf(gz);
    printf("\n");

    strncpy(T, temp+1, T_size-1);
    printf(T);
    printf("\n");
    
    strncpy(P, pres+1, P_size-1);
    printf(P);
    printf("\n");
    
    
    strncpy(H, hum+1, H_size-1);
    printf(H);
    printf("\n");
    
    strncpy(F, force+1, F_size-1);
    printf(F);
    printf("\n");
    
    float position_ax = atof(ax);
    float position_ay = atof(ay);
    float position_az = atof(az);
    float position_bx = atof(bx);
    float position_by = atof(by);
    float position_bz = atof(bz);
    float position_gx = atof(gx);
    float position_gy = atof(gy);
    float position_gz = atof(gz);
    float temperature = atof(T);
    float pression = atof(P);
    float humidite = atof(H);
    float F_force = atof(F);

    fprintf(fichier,"\n");
    fprintf(fichier,"%.1f",position_ax);
    fprintf(fichier,";");
    fprintf(fichier,"%.1f",position_ay);
    fprintf(fichier,";");
    fprintf(fichier,"%.1f",position_az);
    fprintf(fichier,";");
    fprintf(fichier,"%.1f",position_bx);
    fprintf(fichier,";");
    fprintf(fichier,"%.1f",position_by);
    fprintf(fichier,";");
    fprintf(fichier,"%.1f",position_bz);
    fprintf(fichier,";");
    fprintf(fichier,"%.1f",position_gx);
    fprintf(fichier,";");
    fprintf(fichier,"%.1f",position_gy);
    fprintf(fichier,";");
    fprintf(fichier,"%.1f",position_gz);
    fprintf(fichier,";");
    fprintf(fichier,"%.1f",temperature);
    fprintf(fichier,";");
    fprintf(fichier,"%.1f",pression);
    fprintf(fichier,";");
    fprintf(fichier,"%.1f",humidite);
    fprintf(fichier,";");
    fprintf(fichier,"%.1f",F_force);
    fprintf(fichier,";");

    
    }


  
    return 0;
}
