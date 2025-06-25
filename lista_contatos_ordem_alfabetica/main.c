/****************************************************************************** 
Situação problema: Armazenar lista de contatos (Primeiro Nome, Sobrenome, E-mail, Telefone, CPF); Sem quantitativo máximo.
1 - Os dados devem ficar armazenados em uma Lista duplamente Encadeada com Header; 
2 – O usuário irá inserir os contatos, o programa deverá colocar, no momento da inserção, na posição correta; conforme ordem ALFABÉTICA CRESCENTE DO SOBRENOME(string) . Se o sobrenome estiver repetido, deverá verificar o primeiro nome. Considerar que não haverá Sobrenome+ Nome repetidos;
A implementação da lista deverá permitir (pelo menos), através de menu de acesso, realizar as operações:
a- Inserir em qualquer posição (começo, meio ou final), conforme ordem alfabética crescente do Sobrenome+nome. O usuário informa os dados do contato e o programa insere na lista, na posição correta da ordem alfabética.
b- Remover itens de qualquer posição (começo, meio ou final);
c- Consultar itens de qualquer posição; (Consultar por posição);
d- Listar os itens da lista; (Percorrer a lista). Sugestão: quando listar todos os itens, incluir os endereços do item, próximo nodo e nodo anterior para cada item. 
*******************************************************************************/

#include <stdio.h>
#include "lista.h"

int main()
{
    //Iniciacao da variaveis, criacao da lista
    tlista lista;
    tlista *plista =&lista; 
    criar(plista);
    
    int opcao = 0;
    
    /*/Insere 1ro contato na lista
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
    
    *///Menu - Laco de repeticao do while para permanecer no menu
    
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
	        case 1:
	            listar(plista);
	            consultar(plista);
                break;
		    case 2: {
                    //ocupados = inserir(lista, ocupados);
                    //exibe_lista(lista, ocupados, tamanhttps://www.onlinegdb.com/online_c_compiler#tab-stderrho);
                    contato c = criarContato();
                    int p = posicao(plista, c);
                    insert(plista, c, p);
                    listar(plista);
                    break;
    		    }
		    case 3: {
                    //ocupados = excluir(lista, ocupados);
                    //exibe_lista(lista, ocupados, tamanho);
                    listar(plista);
                    printf("Informe a posicao do contato a remover: ");
                    int p;
                    if (scanf("%d", &p) != 1) {
                        printf("Entrada invalida! Digite um numero inteiro.\n");
                        while (getchar() != '\n');
                        break;
                    }
                    getchar();
                    remover(plista, p);
                    listar(plista);
                    break;
		    }
		    case 4:
		        listar(plista);
		        break;
		    case 5:
		        //implementar
		        break;
		    case 0:
		        printf("Encerrando o programa...\n");
		        break;
		    default:
		        printf("Opção inválida.\n");
	    }
    }while(opcao!=0);

    liberarMemoria(plista);
    return 0;
}//main
