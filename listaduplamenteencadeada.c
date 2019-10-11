#include <stdio.h>
#include <stdlib.h>
#include "no.h"

NO *inicio;
NO *fim;
int tam=0;

void addinicio (int elemento){

    NO *novo = malloc(sizeof(NO));
    novo->elemento=elemento;
    novo->prox = NULL;
    novo->ant = NULL;
    if(tam==0){
        inicio = novo;
        fim = novo;
    }else{
        novo->prox = inicio;
        inicio->ant = novo;
        inicio = novo;
    }
    tam++;
}

void addfim (int elemento){

    NO* novo = malloc(sizeof(NO));
    novo->elemento = elemento;
    novo->prox = NULL;
    novo->ant = NULL;

    if(tam==0){
        inicio=novo;
        fim=novo;
    }else{
    fim->prox = novo;
    novo->ant = fim;
    fim=novo;
    }
    tam++;
}

void addposicao (int posicao, int elemento){

    if(posicao>=0 && posicao<=tam){
    NO* novo = malloc(sizeof(NO));
    novo->elemento = elemento;
    novo->ant = NULL;
    novo->prox = NULL;

    if(posicao==0){
        addinicio(elemento);
    }else if (posicao==tam){
        addfim(elemento);
    }else{
        NO* aux = inicio;

        int i;
        for(i=0; i<posicao-1;i++){
            aux=aux->prox;
            }
        novo->prox = aux->prox;
        novo->ant = aux;
        aux->prox->ant = novo;
        aux->prox = novo;
        tam++;
        }

    }
}

void rminicio (){
    if(tam>0){
        NO* lixo = inicio;
        if(tam==1){
            inicio=NULL;
            fim=NULL;
        }
        else{
            inicio->prox->ant=NULL;
            inicio=inicio->prox;
        }
    free(lixo);
    tam--;
    }else
    printf("Nao tem nada para ser removido");
    }

void rmfim (){
    if (tam>0){
            NO* lixo = fim;
        if(tam==1){
            inicio=NULL;
            fim=NULL;
        }else{
            fim=fim->ant;
            fim->prox=NULL;
        }
        free(lixo);
        tam--;
    }else
    printf("Nao tem nada para ser removido");
}

void rmposicao (int posicao){
    if(posicao>0 && posicao<tam && tam>0){
        if (posicao==1)
            rminicio();
        else if (posicao==tam)
            rmfim();
        else{
            NO* aux = inicio;
            int i;
            for(i=0;i<posicao-1;i++){
                aux=aux->prox;
            }
            NO* lixo = aux->prox;
            aux->prox=aux->prox->prox;
            aux->prox->ant=aux;
            free(lixo);
            tam--;
            }
    }else
        printf("Nao tem nada para ser removido");

}



void imprimir () {
    NO* aux=inicio;
        for(aux = inicio;aux!=NULL;aux=aux->prox){
        printf("%d ",aux->elemento);
    }
    printf("\n");
}

int main () {

    addinicio(20);
    addinicio(10);
    addfim(40);
    addposicao(2,15);
    addposicao(4,100);
    addinicio(200);
    addinicio(150);
    addfim(69);
    addfim(89);
    printf("tam= %d\n", tam);
    imprimir();
    rmposicao(2);



    imprimir();


return 0;
}
