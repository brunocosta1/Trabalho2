#include "contref.h"
#include <stdio.h>
#include <stdlib.h>

void *malloc2(int tamanho){

    espaco *temp;
    char *ptr;
    int result;

    temp = (espaco*)calloc(sizeof(espaco) + tamanho, 1);
    if(temp == NULL)
        return NULL;
    else
        temp->contador = 1;

    ptr = (char*)temp;
    ptr += sizeof(espaco);
    temp->memoria_alocada = ptr;

    return (void*)ptr;
    
}

void atrib2(void *p1, void *p2){

    char *ptr1, *ptr2;
    espaco *temp1, *temp2;

    ptr1 = (char*)p1;
    ptr2 = (char*)p2;


    ptr1 -= (sizeof(espaco));
    ptr2 -= (sizeof(espaco));

    temp1 = (espaco*)ptr1;
    temp2 = (espaco*)ptr1;

    if(p2 != NULL)
        temp1->contador++; 
    else
        temp1->contador--;

    if(temp1->contador == 0)
        free(temp1);
    



}

int cont_ref(void *ptr){
    
    espaco *temp;
    char *cptr;
    int value;

    cptr = (char*)ptr;
    cptr -= (sizeof(espaco));
    temp = (espaco*)cptr;

    value = temp->contador;

    return value;

}
