#include "main.h"

int main(int argc, char *argv[]){
    int a = 10;
    char *str = NULL;

    printf("%c %.9s %d %d %i", 'A', str, 0, -2147483647, 10);
    printf("%u %.2f %x %#p %#p %% \n", 4294967295, 3.1, 42, &a, NULL);

    _printf("%c %.9s %d %d %i", 'A', str, 0, -2147483647, 10);
    _printf("%u %.2f %x %p %p %% \n", 4294967295, 3.1, 42, &a, NULL);
    
    return 0;
}