#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h> 

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
        read(fd[0], buffer, sizeof(buffer)); // Lee el contenido del pipe
        close(fd[0]); // Cierra el descriptor de lectura después de leer

        // Usar strtok para dividir la cadena por comas
        char *token = strtok(buffer, ",");

        int i = 1;
        int suma = 0;
        while (token != NULL) {
            if (strcmp(token, "+") != 0) { // Comparar cadenas 
                printf("Número %d: %s\n", i, token); // Imprime cada número
                suma += atoi(token); // Convierte el token a entero y lo suma
            } else {
                printf("El carácter recibido es: %s\n", token);
            }
            token = strtok(NULL, ","); // Pasa al siguiente token
            i++;
        }
        printf("La suma es: %d\n", suma); // Imprime la suma final
    } else {
        // Proceso padre
        close(fd[0]); // Cierra el descriptor de lectura
        printf("El padre escribe en el PIPE\n");
        write(fd[1], "20,60,30,+", strlen("20,60,30,+") + 1); // Incluye el '\0'
        close(fd[1]); // Cierra el descriptor de escritura después de escribir
        wait(NULL);   // Espera a que el proceso hijo termine
    }

    return 0;
}
