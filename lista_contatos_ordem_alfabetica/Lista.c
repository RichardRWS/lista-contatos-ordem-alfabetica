/******************************************************************************
Situação problema: Armazenar lista de contatos (Primeiro Nome, Sobrenome, E-mail, Telefone, CPF); Sem quantitativo máximo.
1 - Os dados devem ficar armazenados em uma Lista duplamente Encadeada com Header; 
2 – O usuário irá inserir os contatos, o programa deverá colocar, no momento da inserção, na posição correta; conforme ordem ALFABÉTICA CRESCENTE DO SOBRENOME(string) . Se o sobrenome estiver repetido, deverá verificar o primeiro nome. Considerar que não haverá Sobrenome+ Nome repetidos;
A implementação da lista deverá permitir (pelo menos), através de menu de acesso, realizar as operações:
a- Inserir em qualquer posição (começo, meio ou final), conforme ordem alfabética crescente do Sobrenome+nome. O usuário informa os dados do contato e o programa insere na lista, na posição correta da ordem alfabética.
b- Remover itens de qualquer posição (começo, meio ou final);
c- Consultar itens de qualquer posição; (Consultar por posição);
d- Listar os itens da lista; (Percorrer a lista). Sugestão: quando listar todos os itens, incluir os endereços do item, próximo nodo e nodo anterior para cada item. 
1 - O grupo deverá demonstrar e testar os  processos que deve acontecer em cada um dos itens (a,b,c,d);
2 - descrever quais problemas podem ocorrer nos itens (a,b,c,d); (se houver);
3 - descrever (pelo menos) um caso de teste para cada item (a,b,c,d) que permitam saber se estes estão funcionando adequadamente;
4 – demonstrar inserção de (pelo menos 5 elementos), demonstrando inserções no começo, meio e final;
5 – demonstrar remoção de (pelo menos 3 elementos), demonstrando remoções no começo, meio e final;
6 - demonstrar outras situações com possibilidade de erros.
Enviar os códigos-fonte anexos.
Dicas:
a - não usar atribuição (=) para copiar strings, use strcpy;
b - implemente uma lista que tenha uma função que permita inserir em qualquer posição, indicada pelo número;
c - Sobrenome e Nome devem ser armazenados separadamente, mas para fins de comparação para achar o ponto de inserção, pode-se manipulá-los concatenados;
d - implemente uma função que identifique qual a posição um registro deve ser inserido para manter a ordem alfabética crescente de Sobrenome + Nome, por exemplo int posicao(Lista *l, char sobrenome[]);
e - usando a posição descoberta na dica d, insira o contato na posição correta com a função da dica b;
Material strings, ordem alfabética:
https://docs.google.com/presentation/d/1XlDy5KNN2HrbIcn3nBvt0UjBHLuN7NWWwz3B1D0-Z9Y/edit#slide=id.g3ef17badb0_0_554
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct{
    char nome[100];
    char sobrenome[100];
    char email[150];
    char telefone[15];
    char cpf[15];
}contato;

typedef struct no{
    contato dado;
    struct no* next;
    struct no* prev;
}tno;

typedef struct{
    tno* first;
    tno *last;
    int size;
}tlista;

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
int remover(tfila *f, int *numero){
    if(empty(f)==0){// VERIFICAR SE NÃO ESTÁ VAZIA;
        tipoNo* temp = f->head;// COPIAR INFORMAÇÕES DO PRIMEIRO
        *numero = temp->dado;
        if(f->head ==f->tail){// SE HEAD==TAIL ENTAO AMBOS RECEBERÃO NULL
            f->head = NULL;
            f->tail =NULL;
        }
        else{
            f->head = f->head->prox;//ANDAR A FILA (F->HEAD=F->HEAD->PROX)
            f->head->ant = NULL;//O anterior do novo Head, aponta para NULO (F->HEAD->ANT=NULL)
        }
        (f->size)--;//F->SIZE--;
        free(temp);//DESALOCAR MEMÓRIA
        return 1;
    }
    else{
        printf("Comando remover não executado. Fila está vazia!\n");
        return 0;
    } 
}//remover


int main()
{

//NÃO IMPLEMENTADO. ISSO É RESTO DO CODIGO DE PILHAS.   
    //1.CRIAR FILA DE NÚMEROS INTEIROS
    tfila fila;
    tfila *p_fila =&fila; 
    criar(p_fila);
    
    //2. INSERIR 7 NÚMEROS
    int numeros[]={1,2,3,4,5,6,7};
    for(int i=0; i<7;i++){
        inserir(p_fila,numeros[i]);
    }

    //3. REMOVER 2 NÚMEROS, 
    int aux=0;
    int *p_aux = &aux;
    remover(p_fila, p_aux);
    printf("Numero removido da fila: %d\n", aux);
    int aux2=0;
    int *p_aux2 = &aux2;
    remover(p_fila, p_aux2);
    printf("Numero removido da fila: %d\n", aux2);
    
    //4. SOMAR E INSERIR O RESULTADO  NA FILA,
    int soma=0;
    soma = aux + aux2;
    inserir(p_fila,soma);

    //5.REPITA 3 E 4 ATÉ QUE RESTE APENAS 1 ELEMENTO NA FILA.
    while(tamanho(p_fila)>1){
        remover(p_fila,p_aux);
        remover(p_fila,p_aux2);
        soma = aux+aux2;
        inserir(p_fila,soma);
    }
    
    //Validação
    int restante;
    primeiro(p_fila,&restante);
    printf("Primeiro na fila: %d\n",restante);
    printf("Ultimo na fila: %d\n",p_fila->tail->dado);






    return 0;
}//main
