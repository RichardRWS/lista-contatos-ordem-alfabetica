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

int main()
{

    //Iniciacao da variaveis, criacao da lista
    tlista lista;
    tlista *plista =&lista; 
    criar(plista);
    
    int opcao = 0;
    
    //Insere 1ro contato na lista
    contato a = criarContato();
    insert(plista,a,posicao(plista,a));
    listar(plista);
    
    //Insere 2do contato na lista
    contato b = criarContato();
    insert(plista,b,posicao(plista,b));
    listar(plista);
    
    //Insere 3ro contato na lista
    contato c = criarContato();
    insert(plista,c,posicao(plista,c));
    listar(plista);
    
    //Insere 4to contato na lista
    contato d = criarContato();
    insert(plista,d,posicao(plista,d));
    listar(plista);
    
    //Menu - Laco de repeticao do while para permanecer no menu
    
    do{
        //Menu de opcoes
        printf("\n<<< ---------- MENU DE OPCOES ---------- >>>\n");
	    printf("Escolha um opcao:\n");
	    printf("1 - Consultar\n");
	    printf("2 - Inserir\n");
	    printf("3 - Remover\n");
	    printf("4 - Listar\n");
	    printf("5 - Teste Funcionamento\n");
	    printf("0 - Sair\n");
	    
	    if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Digite um numero inteiro.\n");
            while (getchar() != '\n'); 
            opcao = -1;
            continue;
        }
        getchar();
        printf("\n");
	    
	    switch(opcao){
	        
	        //OPCAO CONSULTA DE CODIGO
	        case 1:
	            listar(plista);
	            consultar(plista);
                break;
	           
		    //OPCAO INSERCAO DE CODIGO
		    case 2:
		        //ocupados = inserir(lista, ocupados);
		        //exibe_lista(lista, ocupados, tamanho);
		      break;
		      
		    // OPCAO EXCLUIR
		    case 3:
		        //ocupados = excluir(lista, ocupados);
                //exibe_lista(lista, ocupados, tamanho);
                break;
		    //OPCAO EXIBIR      
		    case 4:
		        listar(plista);
		        break;
		    //OPCAO DO TESTE DE FUNCIONALIDADE
		    case 5:
		        //implementar
		        break;
		    case 0:
		        printf("Encerrando o programa...\n");
		        break;
		    default:
		    printf("Opção inválida.\n");
		    
		    
		    
	    }//switch(opcao)
	    
    }while(opcao!=0);
    
    


    liberarMemoria(plista);
    return 0;
}//main