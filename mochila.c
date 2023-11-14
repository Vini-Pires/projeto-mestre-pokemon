#include <stdio.h>
#include <string.h>
#include "mochila.h"

// Função para inicializar a mochila
void inicializarMochila(MochilaPokemon *mochila) {
    mochila->quantidade = 0; // Inicializa a quantidade de Pokémons na mochila como zero
}

// Função para adicionar um Pokémon na mochila
int adicionarPokemon(MochilaPokemon *mochila, Pokemon pokemon) {
    if (mochila->quantidade < TAMANHO_MOCHILA) {
        mochila->pokemons[mochila->quantidade] = pokemon; // Adiciona o Pokémon na posição atual da mochila
        mochila->quantidade++; // Incrementa a quantidade de Pokémons na mochila
        printf("Pokemon %s adicionado a mochila.\n", pokemon.nome);
        return 1; // Retorna 1, pokemon adicionado.
    } else {
        printf("Mochila cheia. Nao e possivel adicionar mais Pokemons.\n");
        return 0; // Retorna 0, mochila cheia
    }
}

// Função para mostrar os Pokémons na mochila
void mostrarMochila(MochilaPokemon mochila) {
    if (mochila.quantidade == 0) {
        printf("A mochila esta vazia.\n");
    } else {
        printf("Pokemons na mochila:\n");
        for (int i = 0; i < mochila.quantidade; i++) {
            printf("Numero: %d, Nome: %s, Tipo 1: %s, Tipo 2: %s\n",
                   mochila.pokemons[i].numero, mochila.pokemons[i].nome,
                   mochila.pokemons[i].tipo1, mochila.pokemons[i].tipo2);
            //definir posteriormente todos os dados que serão apresentados
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
        printf("Esse Pokemon nao esta na mochila.\n");
        return 0; // Retorna 0, pokemon não encontrado
    }
    return 1; // Retorna 1, pokemon removido
}
