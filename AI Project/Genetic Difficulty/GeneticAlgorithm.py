import random
import matplotlib.pyplot as plt

no_of_params = 7

#Represents the performance metrics of a player such as completion time and success rate
class PlayerProfile:
    def __init__(self, completion_time, success_rate):
        self.completion_time = completion_time
        self.success_rate = success_rate

#Represents a difficulty level with a set of parameters that influence the difficulty
class DifficultyLevel:
    def __init__(self, parameters):
        self.parameters = parameters

#Evaluates the fitness of a difficulty level based on player performance metrics
def evaluate_fitness(difficulty_level):
    fitness = 0
    for i in range (no_of_params):
        fitness += (difficulty_level.parameters[i])

    return fitness

#Perform a crossover to create a new difficulty level by combining parameters from two parent difficulty levels
def crossover(parent1, parent2):
    crossover_point = random.randint(1, len(parent1.parameters) - 1)
    new_parameters = parent1.parameters[:crossover_point] + parent2.parameters[crossover_point:]
    return DifficultyLevel(new_parameters)

#Introduces variability in a difficulty level by mutating its parameters
def mutate(difficulty_level, mutation_rate=0.2):
    mutated_parameters = [param + random.uniform(-mutation_rate, mutation_rate) for param in difficulty_level.parameters]
    return DifficultyLevel(mutated_parameters)

def tournament_selection(population, tournament_size):
    tournament = random.sample(population, tournament_size)
    winner = max(tournament, key=lambda level: evaluate_fitness(level))
    return winner

def genetic_algorithm(population_size, generations, tournament_size=3):
    population = [DifficultyLevel([random.uniform(0, 1) for _ in range(no_of_params)]) for _ in range(population_size)]
    best_fitness_scores = []

    for generation in range(generations):
        fitness_scores = [evaluate_fitness(level) for level in population]
        best_fitness_scores.append(max(fitness_scores))

        # Elitism: Preserve the best difficulty level
        best_difficulty_level = population[fitness_scores.index(max(fitness_scores))]

        # Tournament selection and crossover
        new_population = [best_difficulty_level]  # Add the best difficulty level from the previous generation

        for _ in range(population_size - 1):
            parent1 = tournament_selection(population, tournament_size)
            parent2 = tournament_selection(population, tournament_size)

            child = crossover(parent1, parent2)
            mutated_child = mutate(child)

            new_population.append(mutated_child)

        population = new_population

    return best_fitness_scores

generations = 20
best_fitness_scores = genetic_algorithm(population_size=200, generations=generations)
print("Best Difficulty Level:", best_fitness_scores)

# Plotting the best fitness score of each generation
plt.plot(range(1, generations + 1), best_fitness_scores, marker='o')
plt.title('Evolution of difficulty through genetic algorithm')
plt.xlabel('Generation')
plt.ylabel('Best Fitness Score')
plt.show()