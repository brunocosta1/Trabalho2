#include <stdio.h>
#include <stdlib.h>
#include "contref.h"


int main(){

    int *v, *w;

    v = malloc2(sizeof(int) * 4);
    w = (int*)malloc(sizeof(int) * 4);

    for(int i = 0; i < 4; i++){

        v[i] = i;
        w[i] = i + 10 ;
    }


    printf("Teste\n");

    for(int i = 0; i < 4; i++){
        printf("%d\n", w[i]);
    }

    
    printf("\nNumero de referencias antes: %d\n\n", cont_ref(v));
    /*w = v;*/
    atrib2(w, v);
    /*dec(v);*/

    for(int i = 0; i < 4; i++)
        printf("%d\n", w[i]);

    printf("Numero de referencias depois: %d\n", cont_ref(v));
    
    printf("\n%d\n", *w);

    return 0;

}


