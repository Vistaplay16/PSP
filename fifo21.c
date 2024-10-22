#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

int main(void)
{
    int fp_write, fp_read;
    int num, factorial;
    char buffer[10];

    mkfifo("PIPE02", 0666); 
    srand(time(NULL));
    num = rand() % 10 + 1;  
    printf("Número aleatorio generado: %d\n", num);

    fp_write = open("PIPE02", O_WRONLY);
    write(fp_write, &num, sizeof(num));
    close(fp_write);

    printf("Número aleatorio enviado. Esperando el resultado...\n");

    fp_read = open("PIPE02", O_RDONLY);
    read(fp_read, &factorial, sizeof(factorial));
    printf("El factorial de %d es: %d\n", num, factorial);
    close(fp_read);

    return 0;

}