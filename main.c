#include <stdio.h>
#include <stdlib.h>

struct espaco{

    void *memoria_alocada;
    int contador;

};

void *malloc2(int tamanho);
void atrib2(void *p1, void *p2);

int main(){

    int *v = (int*)malloc2(sizeof(int)+1);

    *v = 4;

    printf("Teste\n");

    for(int i = 0; i < 10; i++)
        printf("%d\n", *(v-i));
    
    printf("\n");
    atrib2((int*) v, NULL);

    for(int i = 0; i < 10; i++)
        printf("%d\n", *(v-i));

    return 0;

}


void *malloc2(int tamanho){

    struct espaco *aux = (struct espaco*)malloc(sizeof(struct espaco));
    aux->memoria_alocada = malloc(tamanho);
    aux->contador = 19; //Número diferente apenas para teste

    return (aux->memoria_alocada);

}

void atrib2(void *p1, void *p2){

    int *aux;

    aux = (int*)p1;

    *(aux-6) = *(aux-6) - 1;

    p1 = p2;



}

