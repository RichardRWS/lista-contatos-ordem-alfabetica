#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void criar(tlista *l){
    l->first = NULL;
    l->last = NULL;
    l->size = 0;
}//criar

int empty(tlista *l){
    if(l->first==NULL){
        return 1;
    }
    else{
        return 0;
    }
}//empty

int tamanho(tlista *l){
    return l->size;
}//tamanho


int insert(tlista *l, contato c, int p){
    
    if(p>tamanho(l) || p<0){ ////encontrar posição p; se não existe ou não é a ultima retornar erro
        printf("Posicao invalida!\n");
        return 0;
    }
    
    tno *novo = (tno*)malloc(sizeof(tno));//ALOCAR NOVO NÓ - Verificar se ALOCAÇÃO ocorreu corretamente;
	if (novo != NULL){
	   novo->dado = c;
	   //strcpy(novo->dado.nome,c.nome);
	   //strcpy(novo->dado.sobrenome,c.sobrenome);
	   //strcpy(novo->dado.email,c.email);
	   //strcpy(novo->dado.telefone,c.telefone);
	   //strcpy(novo->dado.cpf,c.cpf);
	   
	   novo->next = NULL;// proximo do novo no aponta inicialmente para null
	   novo->prev = NULL;// anterior do novo no aponta inicialmente para null
	   
	  
	  //condicao lista vazia
	  if(l->size ==0){
	      l->first = novo;
	      l->last = novo;
	  }
	  //condicao inserir no inicio
	  else if(p==0){
	      novo->next = l->first;
	      l->first->prev = novo;
	      l->first = novo;
	  }
	  
	  //condicao inserir no final
	  else if(p==tamanho(l)){
	      novo->prev = l->last;
	      l->last->next = novo;
	      l->last = novo;
	      
	  }
	  
	  //condicao inserir no meio
	  else{
	    tno* aux_next;
	    aux_next = l->first;
	    for (int i = 0; i<p; i++){//laço percorre até o elemento daposição p
	        aux_next = aux_next->next;
	    }
        aux_next->prev->next = novo;//elemento anterior
        novo->prev = aux_next->prev; //elemento anterior
        aux_next->prev = novo;//elemento seguinte
        novo->next = aux_next;//elemento seguinte
	  }
	  
	   (l->size)++;
	   printf("\nContato inserido com sucesso na lista!\n");
	   return 1;
	}
	else{
	   printf("\nErro na alocacao da memoria. Tente novamente.\n");
	   return 0;
	}
    
}//insert

int posicao(tlista *l, contato c) {
    tno* atual = l->first;
    int pos = 0;

    char entrada[200];
    strcpy(entrada, c.sobrenome);
    strcat(entrada, c.nome);

    while (atual != NULL) {
        char comparada[200];
        strcpy(comparada, atual->dado.sobrenome);
        strcat(comparada, atual->dado.nome);
        
        if (strcmp(entrada, comparada) <= 0) {// Se a entrada for menor ou ingual, a posicao de insercoa eh a atual
            return pos;
        }
        
        atual = atual->next;
        pos++;
    }
    return l->size;//se chegar ao final da lista, entra no final.
}

void lerContato(contato* c){
    printf("Informe os dados do novo contato... \n");
    printf("Nome: ");
    scanf("%99s",c->nome);getchar();//limita caracteres para impedir estouro de buffer
    printf("Sobrenome: ");
    scanf("%99s",c->sobrenome);getchar();
    printf("Email: ");
    scanf("%149s",c->email);getchar();
    printf("Telefone: ");
    scanf("%14s",c->telefone);getchar();
    printf("CPF: ");
    scanf("%14s",c->cpf);getchar();
}//lerContato

contato criarContato(){
    contato c;
    lerContato(&c);
    return c;
}



void listar(tlista *l){
    tno* aux_next;
    aux_next = l->first;
    if(l->size ==0){
        printf("Lista vazia!\n");
    }
    else{
        for (int i=0; i<tamanho(l);i++){
            printf("%d, %s %s\n",i,aux_next->dado.sobrenome, aux_next->dado.nome);
            aux_next = aux_next->next;
        }
    }
    printf("\n");
}//listar



