#include "listaEncadeada.h"
#include<iostream>
using namespace std;

listaEncadeada::listaEncadeada(){
    this -> primeiro = nullptr;
    this -> ultimo = nullptr;
    this -> qtd = 0;
};

listaEncadeada::~listaEncadeada(){
    delete this -> primeiro;
    delete this -> ultimo;
};

bool listaEncadeada::anexar(int elemento){
    No* novo = new No (elemento, nullptr);
    if(this -> primeiro == nullptr){
        this -> primeiro = novo;
    } else {
        this -> ultimo -> proximo = novo;
    }

    this -> ultimo = novo;
    this -> qtd++;

    return true;
};

bool listaEncadeada::inserir(int elemento, int posicao){
    if(posicao < 0 || posicao > this -> qtd) return false;

    No* inserir = new No(elemento,nullptr);
    No* aux; 
    No* aux2;
    if(this -> primeiro == nullptr){
        this -> primeiro = inserir;
    } else {
        aux = this -> primeiro;
        aux2 = nullptr;
        for(int i = 0; i < posicao - 1; i++){
            aux = aux -> proximo;
        }
        aux2 = aux -> proximo;
        aux -> proximo = inserir;
        inserir -> proximo = aux2;
    }
    this -> qtd++;

    return true;
};

bool listaEncadeada::substituir(int posicao, int elemento){
    if(posicao < 0 || posicao > this -> qtd) return false;

    No* aux = this -> primeiro;


    for(int i = 0; i < posicao; i++){
        aux = aux -> proximo;
    }
    aux -> dado = elemento;

    return true;
};

int  listaEncadeada::removerPorElemento(int elemento){
 
    if(this-> qtd == 1){
        No* noRemover = this -> primeiro;
        this -> primeiro = nullptr;
        this -> ultimo = nullptr;
        delete noRemover;
        return 0;
    } // serve para um unico elemento
    else if(this -> primeiro -> dado == elemento){ // remover o primeiro   
        No* noRemover = this -> primeiro;
        this -> primeiro = this -> primeiro -> proximo;
        delete noRemover;
        this -> qtd--;
        return 0;    
    }
    else if(this -> ultimo -> dado == elemento){
        No* aux = this -> primeiro;

        for(int i = 0; i < this -> qtd - 2; i++){
            aux = aux -> proximo;   
        }
        this -> ultimo = aux;
        
        aux = aux -> proximo;

        this -> ultimo -> proximo = nullptr;

        delete aux;
        this -> qtd--;
        return this -> qtd; 
    } else {
        No* aux = this -> primeiro;
        int posicao = 1;

        while(aux -> proximo != nullptr){
            No* sucessor = aux -> proximo;

            if(sucessor -> dado == elemento){
                aux -> proximo = sucessor -> proximo;
                delete sucessor;
                this -> qtd--;
                return posicao;
            }
            aux = aux ->proximo;
            posicao++;
        }
        return -1;
    }
};
bool listaEncadeada::removerPorPosicao(int posicao, int &removido){
    if(posicao == 0){
        removido = this -> primeiro -> dado;
        No* removePos = this -> primeiro;
        this -> primeiro = this -> primeiro -> proximo;
        delete removePos;
        this -> qtd--;
    } else if(posicao == this -> qtd - 1){
        removido = this -> ultimo -> dado;
        No* aux = this -> primeiro;

        for(int i = 0; i < this -> qtd - 2; i++){
            aux = aux -> proximo;
        }
        this -> ultimo = aux;
        aux = aux -> proximo;
        this -> ultimo -> proximo = nullptr;

        delete aux;
    } else {
        No* aux = this -> primeiro;
        No* sucessor = aux -> proximo;
        
        for(int i = 0; i < posicao-1;i++){
            aux =  aux->proximo; 
            sucessor = sucessor->proximo;
        }
        removido = sucessor -> dado;
        aux->proximo = sucessor->proximo;
        delete sucessor;
    }
    return true;
};
int listaEncadeada::tamanho(){
    return this -> qtd;
};
int listaEncadeada::buscarPorElemento(int elemento){
    No* aux = this -> primeiro;
    int posicao;
    
        for(posicao = 0; posicao < this -> qtd; posicao++){
            if(aux -> dado == elemento){
                return posicao;
            }  
            aux = aux -> proximo;
        } 

    return -1;
};
int  listaEncadeada::buscarPorPosicao(int posicao){
    No* aux = this -> primeiro;
    if(posicao < 0 || posicao > this -> qtd) return -1;

    if(posicao == 0) return aux -> dado;

    for(int i = 0; i < posicao; i++){
        aux = aux -> proximo;
    }
    return aux -> dado;
};
void listaEncadeada::imprimir(){
    cout << "[";
    No* aux = this -> primeiro;

    while(aux != nullptr){
        cout << aux -> dado;
        if(aux -> proximo != nullptr) cout << ",";
        aux = aux -> proximo;
    }

    cout << "]" << endl;
};

int main (){
    int removido;
    listaEncadeada* list = new listaEncadeada();
    list->anexar(10);//0

    list->inserir(20,1);//1
    list->inserir(13,2);//2
    list->inserir(6,3);//3
    list->inserir(1,4);//4
    
    // list->substituir(0,15);
    
    //list->removerPorElemento(10);
    list->removerPorPosicao(4,removido);
    
    // cout << "Tamanho da lista: "   << list->tamanho() << endl;
    // cout << "Posicao do elemento: "<< list-> buscarPorElemento(10)<< endl;
    // cout << "Elemento da Posicao: "<<list->buscarPorPosicao(2)<< endl;
    
    list->imprimir();
}