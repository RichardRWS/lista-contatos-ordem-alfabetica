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
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

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
