//
//
// inspiration : 
//

#include "stdio.h"
#include "stdlib.h"
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char** argv){
  
	int Sock1;
        int x;
	// Pour paramétrer la socket que nous allons créer, nous allons déclarer une structure de type sockaddr_in
	struct sockaddr_in serveurAddr;

	int Sock2;
	struct sockaddr_in newAddr;
	
    	//Le type sokclen_t sert à stocker la taille d'une structure de type sockaddr_in
	socklen_t addr_size;
	char test[142];
	char confirm[8];
	char test2[24];

    	// On crée un socket avec pour paramètres :
        // AF_INET , SOCK_STREAM et 0 (Ce sont les paramètres pour le protocole TCP/IP)
        x=0;
	while (x < 100)
	  {
	
	Sock1 = socket(AF_INET, SOCK_STREAM, 0);
	printf("La socket a été créé avec succès.\n");
	
	if ((Sock1) == -1) {
	    perror("socket");
	    exit(1);
	  }
	
	// On crée une zone mémoire, identifiée par son adresse et sa taille, avec une valeur précise.
	memset(&serveurAddr, '\0', sizeof(serveurAddr));


        serveurAddr.sin_addr.s_addr = inet_addr ("161.3.82.189");//On définit l'adresse IP du serveur 
	serveurAddr.sin_family = AF_INET; // Toujours égale à AF_INET puisque TCP/IP
	serveurAddr.sin_port = htons(16069); // On définit le port de notre socket

	// Pour éviter les erreurs types Adress already in use nous avons utiliser "SO_REUSEADRESS"
	setsockopt(Sock1, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof (int));
		   
    // Bind permet d'associer les informations ci-dessus à la socket 
	if ((bind(Sock1, (struct sockaddr*)&serveurAddr, sizeof(serveurAddr))) == -1) {
	    perror("bind");
	    exit(1);
	  }
       
	
    // Listen permet de mettre la socket en état d'écoute , listen (La socket, le nombre maximal de connexions en attente)

	
	if ((listen(Sock1, 5)) == -1) {
	    perror("listen");
	    exit(1);
	  }
	 printf("En écoute\n");    
      

	
    // La fonction accept crée une nouvelle socket qui n'est pas en état d'écoute.
       

		if ((Sock2 = accept(Sock1, (struct sockaddr*)&newAddr, &addr_size)) == -1) {
	    perror("accept");
	    exit(1);
	  }
	
	recv(Sock2, confirm, 1024, 0);
	printf("Caractère recu : %s\n", confirm);
        
	
    // La fonction strcpy permet de copier le contenu d'une chaîne de caractères dans une autre.
        strcpy(test, "{\"ax\":   12,\"ay\":   15,\"az\":   17,\"bx\":   20,\"by\":   21,\"bz\":   22,\"gx\":   33,\"gy\":   32,\"gz\":   31,\"T\":   20,\"P\":  300,\"H\":  100,\"F\":782758}");
	strcpy(test2, "Caractère non reconnu");
  	if ((strcmp(confirm, "?") == 0)  && (send(Sock2, test, strlen(test), 0)) == -1 ) { // strlen renvoie la longueur de la chaine transmise
	  perror("send");
	  close(Sock2);
	  exit(0);
	}
	else if ((strcmp(confirm, "?") != 0)  && (send(Sock2, test2, strlen(test2), 0)) == -1 ) { // strlen renvoie la longueur de la chaine transmise
	  perror("send");
	  close(Sock2);
	  exit(0);
	}
	printf("Fermeture de la socket\n");
	shutdown(Sock1,2);
	close(Sock1);
	shutdown(Sock2,2);
	close(Sock2);
	x++;
	  }
	return 0;
}
