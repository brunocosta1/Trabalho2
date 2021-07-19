#ifndef CONTREF_H
#define CONTREF_H

typedef struct{

    void *memoria_alocada;
    unsigned int tamanho;
    int contador;

}espaco;

void dump();
void *malloc2(unsigned int tamanho);
void atrib2(void *p1, void *p2);
void dec(void *ptr);
void acrec(void *ptr);
int cont_ref(void *p1);

#endif
