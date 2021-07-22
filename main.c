#include <stdio.h>
#include <stdlib.h>
#include "contref.h"
#include <string.h>

int main(){

    //Exemplo slide

    /*int *v = malloc2(sizeof(int));*/

    /**v = 10;*/

    /*int *w = malloc2(sizeof(int));*/
    /*dump(); // 2 espaços alocados com 1 referência*/

    /**w = 20;*/

    /*atrib2(v, w);*/
    /*dump(); // 1 espaço alocado com duas referências */

    /*char *c = (char*)malloc2(sizeof(char));*/
    /**c = 'Z';*/
    /*dump(); //  2 espaços alocados, 1 com duas referências e 1 com uma*/

    /*atrib2(w, NULL);*/
    /*dump(); // 2 espaços alocados, os dois com uma referência*/


     /*Outro exemplo*/
    
    int *v = malloc2(sizeof(int) * 4);

    for(int i = 0; i < 4; i++)
        v[i] = 19+i;

    dump();

    for(int i = 0; i < 4; i++)
        printf("%d\n\n", v[i]);
    
    int *w = malloc2(sizeof(int) * 4);

    dump();

    atrib2(w, v);

    for(int i = 0; i < 4; i++)
        printf("%d\n\n", w[i]);

    dump();


    return 0;

}


