#include <bits/stdc++.h>
#include <random>
#include <unordered_map>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

// Global randomizer macros
std::random_device rd;
std::mt19937 gen(rd());

void scanGraph(
    std::vector<std::vector<int64_t>>* graph,
    std::string filename
) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file: " << filename << std::endl;
    }

    // Declare variables
    std::string line;

    // Scan every line and store each number in the line accordingly
    int64_t i = 1;
    graph->push_back({0, 0, 0});
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        //std::cout << i << " scanned " << line << "\n";
        graph->push_back({0, 0, 0});
        iss >> (*graph)[i][0] >> (*graph)[i][1] >> (*graph)[i][2];
        i += 1;
    }
}

void getDists(
    std::vector<std::vector<int64_t>>* graph,
    std::unordered_map<int64_t, std::unordered_map<int64_t, double>>* edges
) {
    int64_t numof_vertices = graph->size();
    for (int64_t i = 1; i <= 500; ++i) {
        //std::cout << "branching node " << i << "\n";
        for (int64_t j = i + 1; j <= 1000; ++j) {
            int64_t 
                x1 = (*graph)[i][1],
                y1 = (*graph)[i][2],
                x2 = (*graph)[j][1],
                y2 = (*graph)[j][1]
            ;

            //std::cout << "connected node " << i << " with " << j << "\n";
            (*edges)[i][j] = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
            (*edges)[j][i] = (*edges)[i][j];
        }
    }
}

void getInitialPopulation(
    std::vector<std::vector<int64_t>>* batch,
    int64_t* batch_size
) {
    // Create initial chromosome (path ascending from 1 to num of vertices)
    std::vector<int64_t> init_chromosome;
    init_chromosome.push_back({});
    for (int64_t i = 1; i <= 1000; ++i) {
        //std::cout << "setting chromosome " << i << "\n";
        init_chromosome.push_back({});
        init_chromosome[i] = i;
    }

    for (int64_t i = 0; i < *batch_size; ++i) {
        std::shuffle(init_chromosome.begin(), init_chromosome.end(), gen);
        batch->push_back(init_chromosome);
    }
}

double evaluateFitness(
    std::vector<int64_t>* path,
    std::unordered_map<int64_t, std::unordered_map<int64_t, double>>* edges
) {
    double total_distance = 0;
    int64_t numof_vertices = path->size();
    for (int64_t i = 0; i < numof_vertices - 1; ++i) {
        total_distance += (*edges)[(*path)[i]][(*path)[i + 1]];
    }

    return total_distance;
}

void getParents(
    std::vector<std::vector<int64_t>>* parents,
    std::vector<std::vector<int64_t>>* batch,
    std::unordered_map<int64_t, std::unordered_map<int64_t, double>>* edges,
    std::vector<std::vector<int64_t>>* graph,
    int64_t* tournament_size
) {
    for (int64_t i = 0; i < 2; ++i) {
        std::vector<std::vector<int64_t>> tournament = *batch;
        std::shuffle(tournament.begin(), tournament.end(), gen);
        tournament.resize(*tournament_size);

        // Find the best path of current tournament
        auto best_tour_it = std::min_element(tournament.begin(), tournament.end(),
            [&](std::vector<int64_t>& path1, std::vector<int64_t>& path2) {
                return
                    evaluateFitness(
                        &path1, edges
                    ) < evaluateFitness(
                        &path2, edges
                    )
                ;
            }
        );

        parents->push_back(*best_tour_it);
    }
}

void crossOver(
    std::vector<int64_t>* parent1,
    std::vector<int64_t>* parent2,
    std::vector<int64_t>* child
) {
    //std::cout << "entering crossover \n";
    std::uniform_int_distribution<int64_t> dist(1, parent1->size() - 1);
    int64_t cross_over_idx = dist(gen);

    for (int64_t i = 0; i < cross_over_idx; ++i) {
        child->push_back((*parent1)[i]);
    }

    for (int64_t i = 0; i < (int64_t)parent2->size(); ++i) {
        if (std::find(child->begin(), child->end(), (*parent2)[i]) == child->end()) {
            child->push_back((*parent2)[i]);
        }
    }
}

void mutate(
    std::vector<int64_t>* path
) {
    // Create a random index on chromosome
    std::uniform_int_distribution<int64_t> dist(0, (int64_t)(path->size() - 1));

    // Create 2 mutate points and ensure they are different
    int64_t idx1 = dist(gen);
    int64_t idx2;
    do {
        idx2 = dist(gen);
    } while (idx1 == idx2);

    // Swap the 2 points/indeces
    std::swap((*path)[idx1], (*path)[idx2]);
}

void geneticGetTspMinimum(
    std::vector<int64_t>* best_path,
    double* best_distance,
    std::vector<double>* best_distance_history,
    std::unordered_map<int64_t, std::unordered_map<int64_t, double>>* edges,
    std::vector<std::vector<int64_t>>* graph,
    double* mutation_rate,
    int64_t* numof_epochs,
    int64_t* batch_size,
    int64_t* tournament_size
) {
    // Declare variables
    int64_t* numof_vertices = new int64_t();
    std::vector<std::vector<int64_t>>* batch = new std::vector<std::vector<int64_t>>();

    // Generate the initial population
    getInitialPopulation(
        batch,
        batch_size
    );

    for (int64_t i = 0; i < *numof_epochs; ++i) {
        std::vector<std::vector<int64_t>> new_batch;
        for (int64_t j = 0; j < (*batch_size / 2); ++j) {
            std::vector<std::vector<int64_t>>* parents = 
                new std::vector<std::vector<int64_t>>();
            //std::cout << "testing\n";
            getParents(
                parents,
                batch,
                edges,
                graph,
                tournament_size
            );

            // Create a randomizer from 0.0 to 1.0
            std::uniform_real_distribution<double> dist(0.0, 1.0);
            double random_val = dist(gen);

            // Declare Children
            std::vector<int64_t>* child1 = new std::vector<int64_t>();
            std::vector<int64_t>* child2 = new std::vector<int64_t>();

            crossOver(
                &parents->front(),
                &parents->back(),
                child1
            );

            crossOver(
                &parents->front(),
                &parents->back(),
                child2
            );

            if (random_val < *mutation_rate) {
                mutate(child1);
            } new_batch.push_back(*child1);
            random_val = dist(gen);
            if (random_val < *mutation_rate) {
                mutate(child2);
            } new_batch.push_back(*child2);
        } *batch = new_batch;

        
        auto best_path_it = std::min_element(batch->begin(), batch->end(), 
            [&](std::vector<int64_t>& path1, std::vector<int64_t>& path2) {
                return
                    evaluateFitness(
                        &path1, edges
                    ) < evaluateFitness(
                        &path2, edges
                    )
                ;
            }
        );
        *best_path = *best_path_it;
        *best_distance = evaluateFitness(best_path, edges);
        best_distance_history->push_back(*best_distance);

        std::cout << "Epoch " << i + 1 << " \t /" << *numof_epochs << "\t: " << *best_distance << "\n";
    }

    auto final_best_path_it = std::min_element(batch->begin(), batch->end(), compareFitness);
    *best_path = *final_best_path_it;
    *best_distance = evaluateFitness(best_path, graph, edges);
}

int main() {
    std::cout << "Starting Genetic Algorithm\n";
    std::cout << "This code was made by Taib Izzat Samawi\n";
    // Declare Variables
    std::vector<int64_t>* best_path = new std::vector<int64_t>();
    double* best_distance = new double();
    std::vector<double>* best_distance_history = new std::vector<double>();
    std::unordered_map<int64_t, std::unordered_map<int64_t, double>>* edges = new std::unordered_map<int64_t, std::unordered_map<int64_t, double>>();
    std::vector<std::vector<int64_t>>* graph = new std::vector<std::vector<int64_t>>();
    double* mutation_rate = new double();
    int64_t* numof_epochs = new int64_t();
    int64_t* batch_size = new int64_t();
    int64_t* tournament_size = new int64_t();

    // Set Variable Values
    *mutation_rate = 1.0;
    *numof_epochs = 100;
    *batch_size = 100;
    *tournament_size = 10;

    std::string filename = "F:\\OneDrive - ITS\\Skills and Diciplines\\standalones_and_algorithms\\source\\if_its-concepts_of_artificial_intelligence\\cities1000.txt";
    scanGraph(
        graph,
        filename
    );

    /*std::cout << "printing graph" << "\n";
    for (auto it : *graph) {
        for (auto jt : it) {
            std::cout << jt << " ";
        } std::cout << "\n";
    }*/

    getDists(
        graph,
        edges
    );

    // Set {best} to contain the TSP minimum data
    geneticGetTspMinimum(
        best_path,
        best_distance,
        best_distance_history,
        edges,
        graph,
        mutation_rate,
        numof_epochs,
        batch_size,
        tournament_size
    );

    plt::plot(*best_distance_history);
    plt::show();
}