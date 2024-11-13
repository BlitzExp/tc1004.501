#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void no_me_matas(int signum) {
    printf("\nRecibi la senal %d\n", signum);
    printf("No me puedes matar\n");
}

int condicion;
void termina_ciclo(int signum) {
    printf("Cambiando el valor de la condicion\n");
    condicion = 20;
}

int main() {
    signal(2, no_me_matas);
    signal(10, termina_ciclo);

    condicion = 1;
    while(condicion == 1) {
        printf("Trabajando\n");
        sleep(2);
    }
    
    printf("Terminando\n");
    return 0;
}