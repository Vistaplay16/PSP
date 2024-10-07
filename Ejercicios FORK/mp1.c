
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
   /*Zona declaración variables*/
   pid_t pid_hijo, pidH,pidHijo,pidPadre;
    
   pid_hijo= fork();

   if (pid_hijo==0) {
      //Zona del hijo
      pidHijo=getpid();
      pidPadre=getppid();
      printf("El nombre del alumno es victor \n");
      printf("ID proceso hijo %d  id proceso padre %d\n", pidHijo, pidPadre);

      sleep(5);
   }else{
      //Zona del padre
      pidH = wait(NULL);
      printf("Ha terminado el proceso %d \n", pidH);    
   }
   
 exit(0);
}
