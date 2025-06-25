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
        printf("Posicao invalida!");
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
	   printf("Contato inserido com sucesso na lista!\n");
	   return 1;
	}
	else{
	   printf("Erro na alocacao da memoria. Tente novamente.\n");
	   return 0;
	}
    
}//insert

void lerContato(contato* c){
    printf("Informe os dados do novo contato: \n");
    printf("Nome: \n");
    scanf("%99s",c->nome);getchar();//limita caracteres para impedir estouro de buffer
    printf("Sobrenome: ");
    scanf("%99s",c->sobrenome);getchar();
    printf("Email: \n");
    scanf("%149s",c->email);getchar();
    printf("Telefone: \n");
    scanf("%14s",c->telefone);getchar();
    printf("CPF: \n");
    scanf("%14s",c->cpf);getchar();
}//lerContato

contato* criarContato(){
    contato* c = (contato*) malloc(sizeof(contato));
    if(c==NULL){
        printf("Erro na alocação de memória!\n");
        return NULL;
    }
    lerContato(c);
    return c;
}//criarContato



void listar(tlista *l){
    tno* aux_next;
    aux_next = l->first;
    if(l->size ==0){
        printf("Lista vazia!\n");
    }
    else{
        for (int i=0; i<tamanho(l);i++){
            printf("%d, %s\n",i,aux_next->dado.nome);
            aux_next = aux_next->next;
        }
    }
}//listar


//NÃO IMPLEMENTADO. ISSO É RESTO DO CODIGO DE PILHAS
int remover(tlista *l, int p){
    
    if(empty(l)==1 || p < 0 || p >= l->size) {
        printf("Posicao inavalida!\n");
        return 0;
    } //SE A LISTA ESTIVER VAZIA
    
    tno *remover_no;

    if (l->size == 1) {
        remover_no = l->first;
        l->first = NULL;
        l->last = NULL;
    }// SE HOUVER APENAS UM ELEMENTO NA LISTA
    
    else if (p == 0) {
        remover_no = l->first;
        l->first = remover_no->next;
        l->first->prev = NULL;
    } //Remover do inicio da lista
    
    else if (p == l->size - 1) {
        remover_no = l->last;
        l->last = remover_no->prev;
        l->last->next = NULL;
    } // REMOVER DO FIM DA LISTA
    
    else {
        remover_no = l->first;
        for (int i = 0; i < p; i++) {
            remover_no = remover_no->next;
        }
        
        remover_no->prev->next = remover_no->next;
        remover_no->next->prev = remover_no->prev;
    }// REMOVER DE UMA POSICAO INTERMEDIARIA

    free(remover_no);
    l->size--;
    printf("Contato removido com sucesso!\n");
    return 1;
}//remover

