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
        close(fd[1]); // Cierra el descriptor de escritura
        printf("El hijo se dispone a leer el PIPE\n");
        read(fd[0], buffer, sizeof(buffer));
        printf("\tMensaje leído del pipe: %s\n", buffer);
        close(fd[0]); // Cierra el descriptor de lectura después de leer
    } else {
        // Proceso padre
        time_t tiempo_actual;
        time(&tiempo_actual); 
        char *fecha ;
        fecha = ctime(&tiempo_actual) ;

        close(fd[0]); // Cierra el descriptor de lectura
        printf("El padre escribe en el PIPE...\n");
        write(fd[1], fecha,  strlen(fecha)+1);  
        close(fd[1]); // Cierra el descriptor de escritura después de escribir
        wait(NULL);   
    }

    return 0;
}
