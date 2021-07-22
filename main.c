#include <stdio.h>
#include <stdlib.h>
#include "contref.h"


int main(){


    int *v, *w;

    v = malloc2(sizeof *v * 4);
    w = malloc2(sizeof *w * 4);




    for(int i = 0; i < 4; i++){
        v[i] = i;
        w[i] = i + 10 ;
    }


    printf("Teste\n");

    dump();

    for(int i = 0; i < 4; i++){
        printf("%d\n", w[i]);
    }

    
    printf("\nNumero de referencias antes: %d\n\n", cont_ref(v));

    atrib2(w, v);



    for(int i = 0; i < 4; i++)
        printf("%d\n", w[i]);

    printf("Numero de referencias depois: %d\n\n", cont_ref(v));

    dump();
    
    return 0;

}


