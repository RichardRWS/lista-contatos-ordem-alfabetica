#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

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
        
        if (strcmp(entrada, comparada) <= 0) {// Se a entrada for menor ou ingual, a posicao de insercao eh a atual
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
    scanf("%99s",c->nome);getchar();//limita caracteres para impedir estouro de buffer. Tratar melhor questão de nomes e sobrenomes compostos
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
    printf("Tamanho da lista: %d\n",tamanho(l));
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

void liberarMemoria(tlista *l) {
    tno *aux_next = l->first;
    while (aux_next != NULL) {
        tno *temp = aux_next->next;
        free(aux_next);
        aux_next = temp;
    }
    l->first = NULL;
    l->last = NULL;
    l->size = 0;
    printf("\nMemória liberada com sucesso!\n");
}//liberarMemoria

void consultar(tlista *l) {
    int posicao;
    
    if (empty(l)) {
        printf("A lista vazia!\n");
        return;
    }
    
    printf("Informe a posição do contato a ser consultado de 0 até %d: ", tamanho(l) - 1);
    if (scanf("%d", &posicao) != 1) {
            printf("Entrada invalida! Digite um numero inteiro.\n");
            while (getchar() != '\n');
            return;
        }
    
    if (posicao<0 || posicao>=tamanho(l)) {
        printf("Entrada inválida! Posição não preenchida na lista.\n");
        return;
    }

    tno *atual = l->first;
    for (int i = 0; i < posicao; i++){
        atual = atual->next;
    }

    printf("\nContato na posição %d:\n", posicao);
    printf("Nome: %s %s\n", atual->dado.nome, atual->dado.sobrenome);
    printf("Email: %s\n", atual->dado.email);
    printf("Telefone: %s\n", atual->dado.telefone);
    printf("CPF: %s\n", atual->dado.cpf);
}//consultar

int remover(tlista *l, int p) {
    
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