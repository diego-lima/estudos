#include <stdio.h>
#include <stdlib.h>

void mcpy(char *dest, char *src){
    // Copia string
    while (*src != '\0'){
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
}

void mcat(char *dest, char *src){
    // Concatena string
    while (*dest != 0){
        dest++;
    }
    while (*src != 0){
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
}

int main(){
    char *dest;
    dest = (char*) malloc(80*sizeof(char));
    mcpy(dest, "oilar");
    printf("dest: %s\n", dest);
    mcat(dest, "hielo");
    printf("dest: %s\n", dest);

    return 0;
}