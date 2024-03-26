#include "FitnessFunction.h"

double FitnessFunction::calculateFitness(Chromosome* chromosome, int numGenes){
    double numTrue = 0;
    for (int i = 0; i < numGenes; i++)
    {
        if (chromosome->getGenes()[i] == true)
        {
            numTrue += 1;
        }
        
    }
    return numTrue/numGenes;
    
}