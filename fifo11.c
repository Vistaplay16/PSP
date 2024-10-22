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
    int p, num, factorial;
    char buffer[10];

    // Crear los FIFOs (pipes con nombre)
    mkfifo("FIFO1", 0666);  
    mkfifo("FIFO2", 0666);  

   
    srand(time(NULL));
    num = rand() % 10 + 1;  
    printf("Número aleatorio generado: %d\n", num);


    fp_write = open("FIFO1", O_WRONLY);
    write(fp_write, &num, sizeof(num));
    close(fp_write);
    
    printf("Número aleatorio enviado. Esperando el resultado...\n");

    fp_read = open("FIFO2", O_RDONLY);
    read(fp_read, &factorial, sizeof(factorial));
    printf("El factorial de %d es: %d\n", num, factorial);
    close(fp_read);

    return 0;
}
