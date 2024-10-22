#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int calcular_factorial(int n) {
    int factorial = 1;
    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }
    return factorial;
}

int main(void)
{
    int fp_read, fp_write;
    int num, factorial;

    // Abrir FIFO1 para leer el número aleatorio
    fp_read = open("FIFO1", O_RDONLY);
    read(fp_read, &num, sizeof(num));
    close(fp_read);

    printf("Número recibido: %d\n", num);

    // Calcular el factorial del número
    factorial = calcular_factorial(num);
    printf("Factorial calculado: %d\n", factorial);

    // Enviar el factorial a FIFO2
    fp_write = open("FIFO2", O_WRONLY);
    write(fp_write, &factorial, sizeof(factorial));
    close(fp_write);

    return 0;
}
