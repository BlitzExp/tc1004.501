#include <stdio.h>
#include <unistd.h>

int main() {
    int a = 5;

    int pid = fork();
    if (pid == 0) {
        printf("Soy el proceso hijo a = %d, pid = %d\n", a, pid);
        execl("./hola", "hola", "uwu", "unu", (char*) NULL);
        printf("Esto no deberia imprimirse");
        return 0;
    }

    printf("Soy el proceso padre, a = %d, pid = %d\n", a, pid);
    sleep(20);
    return 0;
}