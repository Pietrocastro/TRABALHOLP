typedef struct contas {
    int num;
    void* pont;
} Contador;

//um inteiro numero e um ponteiro genérico para endereço('pont'), logo após, a struct contas é renomeada para Contador.

Contador* Vet[500];
int ct = 0;

//criação de um vetor de 500 ponteiros para a struct Contador, enquanto contavetor(ct) é declarado e inicializado em 0.

void* malloc2(int n) {
    Contador* particao = (Contador *)malloc(sizeof(Contador));
    particao->num = 1;
    Vet[ct] = particao;
    ct++;
    
/* malloc é chamado para alocar memória do tamanho de Contador e, em seguida, ele é convertido para um ponteiro de Contador,  por meio do cast '(Contador *)'. 
Essa memória alocada fica na variável 'Partição'. 'numero' da struct 'partição' é = 1. O ponteiro 'partição' é adicionado ao vetor 'Vetorzão' na posição do 'contravetor', 
sendo cada vez incrementada em 1.*/
    
    void* conteudo = malloc(n);
    particao->pont = conteudo;
    return particao->pont;
}

/*mais uma chamada 'malloc' ocorre e aloca a quantidade especificada de memória (n) 
e ponteiro retornado fica armazenado em 'conteudo'
O 'endereço' da struct 'particao' atualiza-se para armazenar o valor do ponteiro 'conteudo'. 
O endereço da memória alocada 'conteúdo' é retornado como resultado da f*/

void atualizaheap(int posicao) {
    for (int i = posicao; i < ct; i++) {
        Vet[i] = Vet[i + 1];
    }
    ct--;
}

/* a função recebe um parametro 'posicao' e remove o elemento correspondente do vetor 'vetorzao'. Percorre o vetor a partir da posicao 'posicao' e move cada elemento uma posição p esquerda, substituindo o elemento que vai ser removido.
Depois desse loop, o contador 'ct' decrementa-se em 1 para refletir a remoção.*/

void add(void* p, int cont) {
    for (int i = 0; i < ct; i++)
        if (p == Vet[i]->pont) {
            Vet[i]->num += cont;
            if (Vet[i]->num == 0) {
                atualizaheap(i);
            }
            break;
        }
}

/* 'add' recebe o ponteiro 'p' e um valor 'cont' como argum., onde essa função adiciona um valor 'cont' ao campo 'numero' da struct 'Contador', a qual corresponde ao ponteiro 'p' no 'Vetorzão'.
Se o valor resultante em 'numero' = 0, a função chama 'atualizaheap' para remover a esturura do vetor. */

void atribui(void* esq, void* dir) {
    add(esq, -1);
    esq = dir;
    add(dir, +1);
}

/* a função 'atribui' recebe os ponteiros 'esq' e 'dir' e realiza uma operação de atribuição entre eles.
Primeiro, chama a função 'add' com 'esq' e '-1' para reduzir o valor de 'numero' da struct correspondente a 'esq'.
Depois, atrubui o valor de 'dir' a 'esq' e, por fim, chama a função 'add' com 'dir' e '+1', para aumentar o valor da struct correspond a 'dir'*/

void dump() {
    int* j;
    for (int i = 0; i < ct; i++) {
        j = (int*)Vet[i]->pont;
        printf("Endereco de memoria: %d\n Numero de aparicoes: %d\n", j, Vet[i]->num);
    }
}

  /* 'dump imprime infos das structs armazenadas no 'vetorzao', percorrendo o vetor e, para cada struct,
  ela imprime o endereço 'endereco' e o numero de ocorrências 'numero'.
  O ponteiro 'j' é convertido para 'int*' antes de ser impresso no 'printf'*/
