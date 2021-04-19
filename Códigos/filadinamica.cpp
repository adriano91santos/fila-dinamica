#include <iostream>
#include "filadinamica.h"
#include <cstddef>
#include <new>

using namespace std;

    filadinamica::filadinamica() // construtor
    {
        primeiro = NULL;
        ultimo = NULL;
    }

    filadinamica::~filadinamica() // destrutor
    {
        No* temp;
        while (primeiro != NULL){
            temp = primeiro;
            primeiro = primeiro->proximo;
            delete temp;
        } 
        ultimo = NULL;
    }

    bool filadinamica::estavazio() // isempty
    {
        return (primeiro == NULL);
    }

    bool filadinamica::estacheio() // isfull
    {
        No* temp;
        try{
            temp = new No;
            delete temp;
            return false;

        } catch(bad_alloc exception){
            return true;
        }
    }

    void filadinamica::inserir(TipoItem item) // push
    {
        if (estacheio()){
            cout << "A fila esta cheia\n";
            cout << "Nao foi possivel inserir esse elemento\n";
        } else{
            No* NoNovo = new No;
            NoNovo->valor = item;
            NoNovo->proximo = NULL;
            if (primeiro == NULL){
                primeiro = NoNovo;
            } else{
                ultimo->proximo = NoNovo;
            }

            ultimo = NoNovo;
        }
    }

    TipoItem filadinamica::remover() // pop
    {
        if (estavazio()){
            cout << "A fila esta vazia\n";
            cout << "Nao tem elemento para ser removido\n";
            return 0;
        } else{
            No* temp = primeiro;
            TipoItem item = primeiro->valor;
            primeiro = primeiro->proximo;
            if (primeiro == NULL){
                ultimo = NULL;
            }
            delete temp;
            return item;
        }
    }

    void filadinamica::imprimir() // print
    {
        No* temp = primeiro;
        cout << "Fila = [ ";
        while (temp != NULL){
            cout << temp->valor << " ";
            temp = temp->proximo;
        }

        cout << "]\n";
    }
