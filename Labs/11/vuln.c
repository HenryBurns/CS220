#include <stdio.h>

int foo(){
    char buf[64];
    printf("buffer address = %p\n", buf);
    puts("Enter text: ");
    gets(buf);
    printf("Contents of buf are: %s\n", buf);
    return 9;
}

int main(){
    printf("Addr of main: %p\n", &main);
    return foo();
}
