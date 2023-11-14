#include "pokedex.h"

/*
Para gerenciar a Pokedex, defina uma estrutura Pokémon contendo: número (inteiro), nome (texto), tipo1 (texto), tipo2 (texto), total (inteiro), ataque (inteiro), defesa (inteiro), ataque especial (inteiro) , defesa especial (inteiro), velocidade (inteiro), geração (inteiro), lendário (boleano), cor (texto), altura (real), peso (real), taxa de captura (inteiro), próxima evolução (inteiro), pŕe-evolução (inteiro). Deverá permitir cadastrar (inserir/listar/pesquisar/alterar/excluir) os Pokémons disponíveis para serem capturados. Essa relação deve aumentar e diminuir dinamicamente.
*/

typedef struct 
{
    int numero;
    char nome[30];
    char tipo1[20];
    char tipo2[20];
    int total;
    int ataque;
    int defesa;
    int ataque_especial;
    int defesa_especial;
    int velocidade;
    int geracão;
    //bool lendario;
    char cor[20];
    float altura;
    float peso;
    int taxa_de_captura;
    int proxima_evolucão;
    int pré_evolucão;
}Pokemon;

// Função para inserir um Pokemon no vetor
void inserir_pokemon(struct Pokemon **vetor, int *tamanho, struct Pokemon **novo_vetor) {

    // Aumentando o tamanho do vetor em uma unidade
    (*tamanho)++;

    // Alocando memória para o novo vetor
    struct Pokemon *novo_vetor = (struct Pokemon *) malloc((*tamanho) * sizeof(struct Pokemon));

    // Copiando os elementos do vetor antigo para o novo
    for (int i = 0; i < (*tamanho) - 1; i++) {
        novo_vetor[i] = (*vetor)[i];
    }
    // Inserindo o novo Pokemon na última posição do vetor
    novo_vetor[(*tamanho) - 1] = novo_vetor;

    // Liberando a memória do vetor antigo
    free(*vetor);

    // Atualizando o ponteiro do vetor para apontar para o novo vetor
    *vetor = novo_vetor;
}

