// Pokedex
#ifndef POKEDEX_H
#define POKEDEX_H

struct Pokemon {
    int numero, total, ataque, defesa, ataqueEspecial, defesaEspecial, velocidade, geracao;
    char nome[51], tipo1[21], tipo2[21], cor[21];
    float altura, peso;
    int lendario, taxaCaptura, proximaEvolucao, preEvolucao;
};

void cadastrarPokemon(struct Pokemon *pokedex, int *numPokemons, FILE *file);
void listarPokemons(const struct Pokemon *pokedex, int numPokemons);

#endif

