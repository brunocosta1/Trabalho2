#ifndef CONTREF_H
#define CONTREF_H

typedef struct espaco espaco;

struct espaco {

    void *memoria_alocada;
    unsigned int tamanho;
    int contador;

    struct espaco *prox;

};


//Funções principais

void *malloc2(unsigned int tamanho);
void atrib2(void *p1, void *p2);
void dump();

//Funções auxiliares

void dec(void *ptr);
void acrec(void *ptr);
int cont_ref(void *p1);

#endif
