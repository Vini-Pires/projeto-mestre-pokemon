#ifndef MOCHILA_H
#define MOCHILA_H

#define TAMANHO_MOCHILA 6 //max 6 pokemons na mochila
#define TAM_NOME_POKEMON 50 //50 caracteres para nomes de pokemons

// estrutura de um pokemon
typedef struct {
    int numero;
    char nome[TAM_NOME_POKEMON];
    char tipo1[20];
    char tipo2[20];
} Pokemon;

// estrutura da Mochila de Pokémon
typedef struct {
    Pokemon pokemons[TAMANHO_MOCHILA]; //Pokémons na mochila
    int quantidade; // Quantidade de Pokémons na mochila
} MochilaPokemon;

// funções para manipular a mochila
void inicializarMochila(MochilaPokemon *mochila);
int adicionarPokemon(MochilaPokemon *mochila, Pokemon pokemon);
void mostrarMochila(MochilaPokemon mochila);
int removerPokemon(MochilaPokemon *mochila, int numero);
void salvarMochilaEmArquivo(MochilaPokemon mochila);
MochilaPokemon carregarMochilaDeArquivo();

#endif
