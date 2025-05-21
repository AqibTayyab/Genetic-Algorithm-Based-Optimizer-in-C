#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POP_SIZE 6         // Number of individuals in population
#define CHROM_LENGTH 5     // Binary length (since 2^5 = 32, covers range 0–31)
#define GENERATIONS 10     // Number of generations
#define MUTATION_RATE 0.1  // Probability of mutation

// Function to convert binary to decimal
int binaryToDecimal(int *chrom) {
    int value = 0;
    for (int i = 0; i < CHROM_LENGTH; i++) {
        value = value * 2 + chrom[i];
    }
    return value;
}

// Fitness function: f(x) = x * x
int fitness(int *chrom) {
    int x = binaryToDecimal(chrom);
    return x * x;
}

// Randomly initialize population
void initializePopulation(int pop[POP_SIZE][CHROM_LENGTH]) {
    for (int i = 0; i < POP_SIZE; i++) {
        for (int j = 0; j < CHROM_LENGTH; j++) {
            pop[i][j] = rand() % 2;
        }
    }
}

// Select best two individuals based on fitness
void selectParents(int pop[POP_SIZE][CHROM_LENGTH], int parent1[CHROM_LENGTH], int parent2[CHROM_LENGTH]) {
    int best = -1, secondBest = -1;
    int bestFit = -1, secondFit = -1;

    for (int i = 0; i < POP_SIZE; i++) {
        int fit = fitness(pop[i]);
        if (fit > bestFit) {
            secondBest = best;
            secondFit = bestFit;
            best = i;
            bestFit = fit;
        } else if (fit > secondFit) {
            secondBest = i;
            secondFit = fit;
        }
    }

    for (int i = 0; i < CHROM_LENGTH; i++) {
        parent1[i] = pop[best][i];
        parent2[i] = pop[secondBest][i];
    }
}

// Single-point crossover
void crossover(int parent1[], int parent2[], int child1[], int child2[]) {
    int point = rand() % CHROM_LENGTH;
    for (int i = 0; i < CHROM_LENGTH; i++) {
        if (i < point) {
            child1[i] = parent1[i];
            child2[i] = parent2[i];
        } else {
            child1[i] = parent2[i];
            child2[i] = parent1[i];
        }
    }
}

// Mutation: flip random bit with a small probability
void mutate(int chrom[]) {
    for (int i = 0; i < CHROM_LENGTH; i++) {
        if (((float)rand() / RAND_MAX) < MUTATION_RATE) {
            chrom[i] = !chrom[i];
        }
    }
}

// Replace the two worst individuals with the new children
void replaceWorst(int pop[POP_SIZE][CHROM_LENGTH], int child1[], int child2[]) {
    int worst = -1, secondWorst = -1;
    int worstFit = 999999, secondFit = 999999;

    for (int i = 0; i < POP_SIZE; i++) {
        int fit = fitness(pop[i]);
        if (fit < worstFit) {
            secondWorst = worst;
            secondFit = worstFit;
            worst = i;
            worstFit = fit;
        } else if (fit < secondFit) {
            secondWorst = i;
            secondFit = fit;
        }
    }

    for (int i = 0; i < CHROM_LENGTH; i++) {
        pop[worst][i] = child1[i];
        pop[secondWorst][i] = child2[i];
    }
}

// Print a chromosome
void printChromosome(int chrom[]) {
    for (int i = 0; i < CHROM_LENGTH; i++) {
        printf("%d", chrom[i]);
    }
}

int main() {
    srand(time(NULL));
    int population[POP_SIZE][CHROM_LENGTH];
    int parent1[CHROM_LENGTH], parent2[CHROM_LENGTH];
    int child1[CHROM_LENGTH], child2[CHROM_LENGTH];

    initializePopulation(population);

    printf("Initial Population:\n");
    for (int i = 0; i < POP_SIZE; i++) {
        printChromosome(population[i]);
        printf(" -> f(x) = %d\n", fitness(population[i]));
    }

    // Run for a number of generations
    for (int gen = 0; gen < GENERATIONS; gen++) {
        selectParents(population, parent1, parent2);
        crossover(parent1, parent2, child1, child2);
        mutate(child1);
        mutate(child2);
        replaceWorst(population, child1, child2);
    }

    // Final population
    printf("\nFinal Population after %d generations:\n", GENERATIONS);
    for (int i = 0; i < POP_SIZE; i++) {
        printChromosome(population[i]);
        printf(" -> f(x) = %d\n", fitness(population[i]));
    }

    return 0;
}
