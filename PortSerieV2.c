///////////////////////////////////////////////////////////////////////////////////////////////// 
// EL HADDAD Noor // KAZEK Thibault
// Serveur TCP
// detramage
///////////////////////////////////////////////////////////////////////////////////////////////

// Librairies en C

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()
#include <stdlib.h>

#define N 30

int main()
{
  char* buf = (char*)malloc(N*sizeof(char));
  int serial_port;
  serial_port = open("/dev/ttyACM0", O_RDWR);



  // Recherche des erreurs

  if (serial_port < 0) 
  {
    printf("Error %i from open: %s\n", errno, strerror(errno));
  }
  else
  {
     printf("Le port est ouvert\n");
  }




struct termios tty;
if(tcgetattr(serial_port, &tty) != 0) 
{
    printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
}

tty.c_cflag &= ~CSTOPB; // Clear stop field, only one stop bit used in communication (most common)
tty.c_cflag &= ~PARENB; // Clear parity bit, disabling parity (most common)
tty.c_cflag &= ~CSIZE;
tty.c_cflag |= CS8;
tty.c_cflag &= ~CRTSCTS; // Disable RTS/CTS hardware flow control (most common)
tty.c_cflag |= CREAD | CLOCAL; // Turn on READ & ignore ctrl lines (CLOCAL = 1)
tty.c_lflag &= ~ICANON;
tty.c_lflag &= ~ECHO; // Disable echo
tty.c_lflag &= ~ECHOE; // Disable erasure
tty.c_lflag &= ~ECHONL; // Disable new-line echo
tty.c_lflag &= ~ISIG;
tty.c_iflag &= ~(IXON | IXOFF | IXANY);
tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL);
tty.c_oflag &= ~OPOST;
tty.c_oflag &= ~ONLCR;
tty.c_cc[VTIME] = 10;    // Wait for up to 1s (10 deciseconds), returning as soon as any data is received.
tty.c_cc[VMIN] = 0;


cfsetspeed(&tty, B9600);


if (tcsetattr(serial_port, TCSANOW, &tty) != 0)
  {
    printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
  }
 
 uint8_t i=0;

 char a=0;
 while (*buf !='{')
   {
     read(serial_port,&a,1);
     buf[0]=a;
     // printf("%s\n",buf);
   }

 for (i = 0;i<=140;i++)
   {
     read(serial_port,&a, 1);// 1 -> en byte est pas en bits
      buf[i+1]=a;
   }

   buf[140]='\0';
   printf("%s\n", buf);
   memset(buf, '\0', 140);
   close(serial_port);
   printf("Le port est fermé\n");


   
 return 0;
}
