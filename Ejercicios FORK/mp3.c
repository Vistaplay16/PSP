#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t pid1,pid2,pidhijoquetermina,pidHijo,pidPadre,pidHijo2,pidPadre2,pidhijoquetermina2;
  
  
  // Se crea un proceso hijo, la función fork() devuelve:
  // un valor negativo -> si se produce cualquier error
  // 0 -> si estamos en el proceso hijo
  // un valor positivo (pid del hijo) -> si estamos en el proceso padre

  pid1 = fork();
 

  if (pid1 == 0 )  //Nos encontramos en Proceso hijo Oscar
  {        
    pidHijo=getpid();
    pidPadre=getppid();
    printf("Soy el proceso Oscar %d\n", pidHijo);
    sleep(10);
    printf("Despierto \n");
    
  }
  else    //Nos encontramos en Proceso padre Manuel
  {  
    pid_t pidManuel;
    pidManuel=getpid();
   printf("Soy el proceso padre Manuel %d\n", pidManuel);  
   pidhijoquetermina=waitpid(pid1, NULL,0);        
   printf("Ha terminado el proceso %d \n", pidhijoquetermina);    
   pid2 = fork();

   if (pid2==0)
   { //Nos encontramos en el proceso Hijo Alfonso
    pidHijo2=getpid();
    pidPadre2=getppid();
    printf("Soy el proceso Alfonso \n");
    printf("ID proceso hijo %d  id proceso padre %d\n", pidHijo2, pidPadre2);
   }else{
    pidhijoquetermina2=waitpid(pid2, NULL,0);
    printf("Ha terminado el proceso %d \n", pidhijoquetermina2); 
   }
   
  }

   exit(0);
}
