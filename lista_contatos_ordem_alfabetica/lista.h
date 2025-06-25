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

void criar(tlista *l);

int empty(tlista *l);

int tamanho(tlista *l);

int insert(tlista *l, contato c, int p);

void lerContato(contato* c);

contato* criarContato();

void listar(tlista *l);



