#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h> 
#include <time.h> 
#include <ctype.h>
char calcular_letra_dni(int numero) {
    const char letras[] = "TRWAGMYFPDXBNJZSQVHLCKE"; // Letras correspondientes
    return letras[numero % 23]; // Devuelve la letra correspondiente
}



int factorial(int n) {
    int fact = 1;  // Inicializamos fact en 1, ya que multiplicaremos
    for (int i = 1; i <= n; i++) {
        fact *= i;  // Multiplicamos fact por cada número de 1 a n
    }
    return fact;  // Retornamos el resultado
}

int validar_numero(const char *cadena) {
    // Comprobar longitud de la cadena
    if (strlen(cadena) != 8) {
        return 0;  // Retorna 0 si no tiene exactamente 8 caracteres
    }

    for (int i = 0; cadena[i] != '\0'; i++) {
        // Si encontramos un espacio o un carácter no numérico
        if (isspace(cadena[i]) || !isdigit(cadena[i])) {
            return 0;  // Retorna 0 si no es válido
        }
    }
    return 1;  // Retorna 1 si es un número válido sin espacios
}

int main() {
    int fd1[2]; // Pipe para padre -> hijo
    int fd2[2]; // Pipe para hijo -> padre
    char buffer[100];
    pid_t pid;

    pipe(fd1);
    pipe(fd2);

    pid = fork();

    if (pid == 0) {
        // ZONA HIJO
        char entrada[100];
        int numero = 0;

        while (1) {
            printf("Introduce un número de exactamente 8 dígitos: ");
            fgets(entrada, sizeof(entrada), stdin);  // Lee la entrada del usuario

            // Eliminar el salto de línea final si existe
            entrada[strcspn(entrada, "\n")] = '\0';

            // Validar si la entrada es un número válido
            if (validar_numero(entrada)) {
                numero = atoi(entrada);  // Convertir la entrada a entero
                break;  // Salir del bucle si la entrada es válida
            } else {
                printf("Error: Por favor, introduce un número de exactamente 8 dígitos sin espacios.\n");
            }
        }

        char str_num[20];
        sprintf(str_num, "%d", numero); 
        close(fd1[0]);
        write(fd1[1], str_num, sizeof(str_num));
        close(fd1[1]);


        close(fd2[1]);
        read(fd2[0], buffer, sizeof(buffer));
        close(fd2[0]);
        printf("Soy el hijo. \nLa letra del DNI es: %s \n ", buffer);


    } else {
        // ZONA PADRE
        close(fd1[1]);
        read(fd1[0], buffer, sizeof(buffer));
        close(fd1[0]);
        printf("Soy el padre. \nEl número que ha mandado el hijo es: \n%s \n", buffer);
        
        // Convertir el número a entero
        int numero_dni = atoi(buffer);
        
        // Calcular la letra del DNI
        char letra_dni = calcular_letra_dni(numero_dni);
        char letra_buffer[2]; // Buffer para la letra (más un carácter nulo)
        letra_buffer[0] = letra_dni; // Asignar la letra
        letra_buffer[1] = '\0'; // Asegúrate de que sea una cadena

        close(fd2[0]);
        write(fd2[1], letra_buffer, sizeof(letra_buffer));
        close(fd2[1]);
        wait(NULL); // Espera a que el hijo termine
    }

    return 0;
}
