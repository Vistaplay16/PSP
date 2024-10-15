#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h> 
#include <time.h> 

int main() {
    int fd[2]; 
    char buffer[100];
    pid_t pid;

    pipe(fd);

    pid = fork();

    if (pid == 0) {
        // Proceso hijo
        srand(time(NULL) ^ getpid());
        int numero_1= rand()% 50;
        int numero_2=rand() % 50;
        close(fd[0]); // Cierra el descriptor de lectura
        char mensaje[50];
        snprintf(mensaje, sizeof(mensaje), "%d,%d", numero_1, numero_2); // Formato: "numero_1,numero_2"
        
        printf("El hijo envía los números: %s\n", mensaje);
        write(fd[1], mensaje, strlen(mensaje) + 1);  
        close(fd[1]); // Cierra el descriptor de escritura después de leer
    } else {
        // Proceso padre
        close(fd[1]); // Cierra el descriptor de lectura
        printf("El padre escribe en el PIPE\n");
        read(fd[0], buffer,sizeof(buffer)); // Incluye el '\0'
        close(fd[0]); // Cierra el descriptor de escritura después de escribir
        wait(NULL);   // Espera a que el proceso hijo termine

        char *token = strtok(buffer, ",");
        int numero_1=atoi(token);
        printf("%d \n",numero_1);
        token = strtok(NULL, ",");
        int numero_2=atoi(token);
        printf("%d \n",numero_2);

        int suma, resta, division, multiplicacion;
        suma=numero_1+numero_2;
        resta=numero_1-numero_2;
        division=numero_1/numero_2;
        multiplicacion=numero_1*numero_2;
    

        printf("La suma de %d y %d es: %d \n", numero_1, numero_2, suma);
        printf("La resta de %d y %d es: %d \n", numero_1 ,numero_2, resta);
        printf("La division de %d entre %d es: %d \n", numero_1, numero_2, division);
        printf("La multiplicacion de %d por %d es: %d \n", numero_1, numero_2, multiplicacion);

    }

    return 0;
}
