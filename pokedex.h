// Pokedex
#ifndef POKEDEX_H
#define POKEDEX_H

struct Pokemon {
    int numero, total, ataque, defesa, ataqueEspecial, defesaEspecial, velocidade, geracao;
    char nome[50], tipo1[20], tipo2[20], cor[20];
    float altura, peso;
    int lendario, taxaCaptura, proximaEvolucao, preEvolucao;
};

void cadastrarPokemon(struct Pokemon *pokedex, int *numPokemons, FILE *file);
void listarPokemons(const struct Pokemon *pokedex, int numPokemons);

#endif

