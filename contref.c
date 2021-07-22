#include "contref.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int primeira_alocacao = 1;
espaco *endereco_primeira_alocacao;

void dec(void *ptr){

    char *ptr1;
    espaco *temp;

    ptr1 = (char*)ptr;
    ptr1 -= sizeof(espaco);
    temp = (espaco*)ptr1;

    temp->contador--;


}

void acrec(void *ptr){

    char *ptr1;
    espaco *temp;

    ptr1 = (char*)ptr;
    ptr1 -= sizeof(espaco);
    temp = (espaco*)ptr1;

    temp->contador++;

}


void *malloc2(unsigned int tamanho){

    espaco *temp;
    char *ptr;


    temp = calloc(sizeof(espaco) + tamanho, 1);
    
    if(temp == NULL)
        return NULL;
    else
        temp->contador = 1;

    ptr = (char*)temp;
    ptr += sizeof(espaco);

    temp->memoria_alocada = ptr;
    temp->tamanho = tamanho;
    temp->prox = NULL;
    temp->ant = NULL;

    if(primeira_alocacao == 1){

        primeira_alocacao = 0;
        endereco_primeira_alocacao = temp;

    }else{

        espaco *aux = endereco_primeira_alocacao;

        while(aux->prox != NULL)
            aux = aux->prox;

        primeira_alocacao++;

        aux->prox = temp;
        aux->prox->ant = aux; 
    }

    return (void*)ptr;
    
}

void atrib2(void *p1, void *p2){

    char *ptr1, *ptr2;
    espaco *temp1, *temp2;

    int tamanho = 0;

    char *aux1;
    

    ptr1 = (char*)p1;
    ptr1 -= (sizeof(espaco));
    temp1 = (espaco*)ptr1;



    if(p2 != NULL){

        ptr2 = (char*)p2;
        ptr2 -= (sizeof(espaco));
        temp2 = (espaco*)ptr2;

        dec(p1);

        memcpy(p1, p2, temp1->tamanho);

        acrec(p2);

    }else{

        p1 = NULL;
        temp1->contador--;
    }

    if(temp1->contador == 0){
        
        if(temp1->prox == NULL && temp1->ant != NULL){ //Verificando se é o último

            espaco *aux = temp1->ant;
            temp1->ant = NULL;
            aux->prox = NULL;

        }else{

            temp1->ant->prox = temp1->prox;
            temp1->prox->ant = temp1->ant;

        }

        free(temp1);
        primeira_alocacao--;

    }
    
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

void dump(){

    espaco *aux = endereco_primeira_alocacao;


    while(aux != NULL){

        printf("\nEndereço: %x\n", *(unsigned int*)&aux->memoria_alocada);
        printf("Conteúdo: %d\n", *(int*)aux->memoria_alocada);
        printf("Tamanho: %d\n", aux->tamanho);
        printf("Número de referencias: %d\n", aux->contador);

        aux = aux->prox;

    }

}
