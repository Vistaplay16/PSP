
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    //Declaracion de variables
    pid_t pidHijo1;

    pidHijo1= fork();

    if (pidHijo1==0)
    {
        //Zona del hijo 1
        pid_t pidHijo, pidPadre, pidHijo2;
        pidHijo=getpid();
        pidPadre=getppid();
        printf("Me llamo Alberto \n");
        printf("Soy el hijo %d y mi padre es %d \n", pidHijo,pidPadre);
        sleep(10);

        pidHijo2=fork();
        if (pidHijo2==0){
            //Zona del hijo 2
            pid_t pidHijo_2, pidPadre2;
            pidHijo_2=getpid();
            pidPadre2=getppid();
            printf("Me llamo Victor \n");
            printf("Soy el hijo %d y mi padre es %d \n", pidHijo_2,pidPadre2);
            sleep(10);
        }else
        {
            //Zona del hijo 1
            pid_t pidHijoTer1;
            pidHijoTer1=waitpid(pidHijo2, NULL, 0);
            printf("Soy Alberto y mi hijo Victor %d ha terminado \n",pidHijoTer1);
            
        }

    }else
    {
        //Zona del padre
        pid_t pidHijoTer, pidPaco;
        pidPaco=getpid();
        printf("Me llamo Paco %d y mi hijo es Alberto %d \n", pidPaco, pidHijo1);
        pidHijoTer=waitpid(pidHijo1, NULL, 0);
        printf("Mi hijo Alberto %d ha terminado \n",pidHijoTer);
    }

}