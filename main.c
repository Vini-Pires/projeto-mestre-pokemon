#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokedex.h"

/*
**************************************************************************************
*
*
* OBSERVACAO: bibliotecas temporariamente desativadas para evitar falhas na main!
*
*
*************************************************************************************
*/

#define MAXIMO_DE_POKEMONS 721 // define utilizado por seguranca / testes

struct Pokemon {
    int numero, total, ataque, defesa, ataqueEspecial, defesaEspecial, velocidade, geracao;
    char nome[50], tipo1[20], tipo2[20], cor[20];
    float altura, peso;
    int lendario, taxaCaptura, proximaEvolucao, preEvolucao;
};

void cadastrarPokemon(struct Pokemon *pokedex, int *numPokemons, FILE *file) {
    if (*numPokemons < MAXIMO_DE_POKEMONS) {
        
        fscanf(file, "%d,%49[^,],%19[^,],%19[^,],%d,%d,%d,%d,%d,%d,%d,%d,%d,%19[^,],%f,%f,%d,%d,%d\n",
               &pokedex[*numPokemons].numero, pokedex[*numPokemons].nome, pokedex[*numPokemons].tipo1,
               pokedex[*numPokemons].tipo2, &pokedex[*numPokemons].total, &pokedex[*numPokemons].ataque,
               &pokedex[*numPokemons].defesa, &pokedex[*numPokemons].ataqueEspecial,
               &pokedex[*numPokemons].defesaEspecial, &pokedex[*numPokemons].velocidade,
               &pokedex[*numPokemons].geracao, &pokedex[*numPokemons].lendario, pokedex[*numPokemons].cor,
               &pokedex[*numPokemons].altura, &pokedex[*numPokemons].peso, &pokedex[*numPokemons].taxaCaptura,
               &pokedex[*numPokemons].proximaEvolucao, &pokedex[*numPokemons].preEvolucao);

        (*numPokemons)++;
        printf("Pokemon cadastrado com sucesso!\n");
    } else {
        printf("Pokedex cheia. Impossível cadastrar mais Pokémons.\n");
    }
}

void listarPokemons(const struct Pokemon *pokedex, int numPokemons) {
    if (numPokemons > 0) {
        // listar todos os Pokémons, ou uma certa quantidade na tela
        for (int i = 0; i < numPokemons; i++) {
            printf("Número: %d, Nome: %s, Tipo1: %s, Tipo2: %s\n", pokedex[i].numero, pokedex[i].nome, pokedex[i].tipo1, pokedex[i].tipo2);
        }
    } else {
        printf("Pokedex vazia. Nenhum Pokémon cadastrado.\n");
    }
}

int main() {
    struct Pokemon pokedex[MAXIMO_DE_POKEMONS];
    int numPokemons = 0;

    FILE *arquivoCSV = fopen("pokedex.csv", "r");
    if (arquivoCSV == NULL) {
        perror("Erro ao abrir o arquivo CSV");
        return 1;
    }

    // Pular a primeira linha do arquivo CSV
    char header[256];
    fgets(header, sizeof(header), arquivoCSV);

    while (numPokemons < MAXIMO_DE_POKEMONS &&
           fscanf(arquivoCSV, "%d,%49[^,],%19[^,],%19[^,],%d,%d,%d,%d,%d,%d,%d,%d,%d,%19[^,],%f,%f,%d,%d,%d\n",
                  &pokedex[numPokemons].numero, pokedex[numPokemons].nome, pokedex[numPokemons].tipo1,
                  pokedex[numPokemons].tipo2, &pokedex[numPokemons].total, &pokedex[numPokemons].ataque,
                  &pokedex[numPokemons].defesa, &pokedex[numPokemons].ataqueEspecial,
                  &pokedex[numPokemons].defesaEspecial, &pokedex[numPokemons].velocidade,
                  &pokedex[numPokemons].geracao, &pokedex[numPokemons].lendario, pokedex[numPokemons].cor,
                  &pokedex[numPokemons].altura, &pokedex[numPokemons].peso, &pokedex[numPokemons].taxaCaptura,
                  &pokedex[numPokemons].proximaEvolucao, &pokedex[numPokemons].preEvolucao) != EOF) {
        numPokemons++;
    }

    fclose(arquivoCSV);

    // Salvar dados em arquivo binário
    FILE *arquivoBinario = fopen("pokedex.bin", "wb");
    if (arquivoBinario == NULL) {
        perror("Erro ao criar o arquivo binário");
        return 1;
    }

    fwrite(pokedex, sizeof(struct Pokemon), numPokemons, arquivoBinario);

    fclose(arquivoBinario);

  

    return EXIT_SUCCESS;
}
