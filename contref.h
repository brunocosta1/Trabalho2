#ifndef CONTREF_H
#define CONTREF_H

typedef struct{

    void *memoria_alocada;
    int contador;

}espaco;

void *malloc2(int tamanho);
void atrib2(void *p1, void *p2);
int cont_ref(void *p1);

#endif
