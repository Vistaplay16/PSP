#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){
    //PRIMERO NACE EL PADRE MANOLO
    pid_t pidJuan;

    pidJuan=fork();

    //NACE EL HIJO DE MANOLO, JUAN

    if (pidJuan==0)
    {
        //ESTA ES LA ZONA DE JUAN
        pid_t pidDeJuan, pidDeManolo;
        pidDeJuan=getpid();

        if (pidDeJuan%2==0)
        {
            pidDeManolo=getppid();
            printf("Soy Juan %d y mi padre es Manolo %d \n" , pidDeJuan, pidDeManolo);
        }else
        {
            printf("Soy Juan %d \n", pidDeJuan);   
        }

        sleep(10);
    }else
    {
        //ESTA ES LA ZONA DE MANOLO
        pid_t pidIker;
        pidIker=fork();

        //NACE EL SEGUNDO HIJO DE MANOLO, IKER

        if (pidIker==0)
        {
            //ZONA DE IKER
            pid_t pidAna, pidDeIker,  pidDeManolo1;
            pidDeIker=getpid();
            if (pidDeIker%2==0)
            {
                pidDeManolo1=getppid();
                printf("Soy Iker %d y mi padre es Manolo %d  \n", pidDeIker, pidDeManolo1);
            }else
            {
                printf("Soy Iker %d \n", pidDeIker);   
            }

            sleep(5);

            pidAna=fork();
            //NACE ANA LA HIJA DE IKER

            if (pidAna==0)
            {               
                //ZONA DE ANA
                pid_t pidDeAna, pidDeManolo2;
                pidDeAna=getpid();

                if (pidDeAna%2==0)
                {
                    pidDeManolo2=getppid();
                    printf("Soy Ana %d y mi padre es Iker %d \n", pidDeAna, pidDeManolo2);
                }else
                {
                    printf("Soy Ana %d \n", pidDeAna);   
                }


            }else
            {
                //ZONA DE IKER
                wait(NULL);
            }
        }else
        {
            //ZONA DE MANOLO
            wait(NULL);
            wait(NULL);
        }
    }
}