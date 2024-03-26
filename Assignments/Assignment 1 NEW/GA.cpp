#include "GA.h"


GA::GA(int populationSize, RandomGenerator* rand, int numGenes, int selectionSize)
{
   this->populationSize = populationSize;
   this->selectionSize = selectionSize;
   population = new Chromosome*[populationSize];
   for (int i = 0; i < populationSize; i++)
   {
        population[i] = new Chromosome(numGenes,rand);
   }
   
}

GA::GA(GA* geneticAlgorithm)
{
    this->populationSize = geneticAlgorithm->populationSize;
    this->selectionSize = geneticAlgorithm->selectionSize;
    this->population = new Chromosome*[geneticAlgorithm->populationSize];
    for (int i = 0; i < geneticAlgorithm->populationSize; i++)
    {

       // this->population = new Chromosome(geneticAlgorithm->population[i]);
    }
    
}

GA::~GA()
{
   for (int i = 0; i < populationSize; i++)
   {
    delete population[i];
   }
    delete [] population;
}

Chromosome** GA::run(FitnessFunction* fitnessFunction)
{
    
}

double** GA::run(FitnessFunction* fitnessFunction, int numGenerations)
{
    
}

Chromosome** GA::selection(FitnessFunction* fitnessFunction)
{
    
}

Chromosome** GA::inverseSelection(FitnessFunction* fitnessFunction)
{
    
}

Chromosome** GA::crossOver(Chromosome* c1, Chromosome* c2)
{
    
}

Chromosome* GA::mutate(Chromosome* c1)
{
    
}

double GA::calculateAvgAccuracy(FitnessFunction* fitnessFunction)
{
    
}

double GA::calculateStd(FitnessFunction* fitnessFunction)
{
    
}

double GA::calculateVariance()
{
    
}

void GA::setPopulation(Chromosome** p)
{
    
}
