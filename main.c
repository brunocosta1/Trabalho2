#include <stdio.h>
#include <stdlib.h>
#include "contref.h"

int main(){

    int *v = (int*)malloc2(sizeof(int));


    printf("%ld\n\n", sizeof(espaco));

    *v = 4;

    char *ptr;

    ptr = (char*)v;

    printf("Teste\n");

    for(int i = 0; i < 10; i++)
        printf("%d\n", *(ptr-i));
    
    printf("\n");
    atrib2((int*) v, NULL);

    for(int i = 0; i < 10; i++)
        printf("%d\n", *(ptr-i));

    printf("Numero de referencias: %d\n", cont_ref(v));
    

    return 0;

}


