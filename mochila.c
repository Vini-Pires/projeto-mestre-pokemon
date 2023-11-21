#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mochila.h"

// Função para inicializar a mochila
void inicializarMochila(MochilaPokemon *mochila) {
    mochila->quantidade = 0; // Inicializa a quantidade de Pokémons na mochila como zero
}

// Função para adicionar um Pokémon na mochila, com verificação do número máximo
int adicionarPokemon(MochilaPokemon *mochila, Pokemon pokemon) {
    if (mochila->quantidade < TAMANHO_MOCHILA) {
        mochila->pokemons[mochila->quantidade] = pokemon; // Adiciona o Pokémon na posição atual da mochila
        mochila->quantidade++; // Incrementa a quantidade de Pokémons na mochila
        printf("Pokemon %s adicionado à mochila.\n", pokemon.nome);
        return 1; // Retorna 1, pokemon adicionado.
    } else {
        printf("Mochila cheia. Não é possível adicionar mais Pokemons.\n");
        return 0; // Retorna 0, mochila cheia
    }
}

// Função para mostrar os Pokémons na mochila
void mostrarMochila(MochilaPokemon mochila) {
    if (mochila.quantidade == 0) {
        printf("A mochila está vazia.\n");
    } else {
        printf("Pokemons na mochila:\n");
        for (int i = 0; i < mochila.quantidade; i++) {
            printf("Numero: %d, Nome: %s, Tipo 1: %s, Tipo 2: %s\n",
                   mochila.pokemons[i].numero, mochila.pokemons[i].nome,
                   mochila.pokemons[i].tipo1, mochila.pokemons[i].tipo2);
            // Dados a serem apresentados
        }
    }
}

// Função para remover um Pokémon da mochila
int removerPokemon(MochilaPokemon *mochila, int numero) {
    int encontrado = 0;
    for (int i = 0; i < mochila->quantidade; i++) {
        if (mochila->pokemons[i].numero == numero) {
            // Move os Pokémons restantes uma posição para trás para preencher o espaço vazio
            for (int j = i; j < mochila->quantidade - 1; j++) {
                mochila->pokemons[j] = mochila->pokemons[j + 1];
            }
            mochila->quantidade--; // Decrementa a quantidade de Pokémons na mochila
            encontrado = 1;
            printf("Pokemon de numero %d removido da mochila.\n", numero);
            break;
        }
    }
    if (!encontrado) {
        printf("Esse Pokemon não está na mochila.\n");
        return 0; // Retorna 0, pokemon não encontrado
    }
    return 1; // Retorna 1, pokemon removido
}

// Função para salvar os dados da mochila em um arquivo binário
void salvarMochilaEmArquivo(MochilaPokemon mochila) {
    FILE *arquivo;
    arquivo = fopen("mochila_dados.bin", "wb");

    if (arquivo != NULL) {
        fwrite(&mochila, sizeof(MochilaPokemon), 1, arquivo);
        fclose(arquivo);
        printf("Dados da mochila salvos com sucesso no arquivo binário.\n");
    } else {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }
}

// Função para carregar os dados da mochila de um arquivo binário
MochilaPokemon carregarMochilaDeArquivo() {
    FILE *arquivo;
    MochilaPokemon mochila;

    arquivo = fopen("mochila_dados.bin", "rb");

    if (arquivo != NULL) {
        fread(&mochila, sizeof(MochilaPokemon), 1, arquivo);
        fclose(arquivo);
        printf("Dados da mochila carregados do arquivo binário.\n");
    } else {
        printf("Arquivo de dados da mochila não encontrado ou erro ao abrir o arquivo.\n");
        inicializarMochila(&mochila);
    }

    return mochila;
}
