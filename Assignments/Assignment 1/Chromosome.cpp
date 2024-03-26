#include "Chromosome.h"

Chromosome::Chromosome(int numGenes, RandomGenerator* rand){
    this->numGenes = numGenes;

    if (numGenes < 0)
    {
        this->numGenes = 0;
        genes[0];
    }else if (rand == NULL)
    {
        genes[numGenes];
        for (int i = 0; i < numGenes; i++)
        {
            genes[i] = false;
        }
        
    }else
    {
        genes[numGenes];
        for (int i = 0; i < numGenes; i++)
        {
            genes[i] = rand->randomBool();
        }
    };   
    
}

Chromosome::Chromosome(Chromosome* chromosome){
   if (chromosome == NULL)
   {
    this->numGenes = 0;
        genes[0];
   }
   else
   {
    
    for (int i = 0; i < chromosome->getNumGenes(); i++)
    {
        this->genes[i] = chromosome->getGenes()[i];
    }
    this->numGenes = chromosome->getNumGenes();
   }
   
    
}

Chromosome::Chromosome(bool* genes, int numGenes){
    this->numGenes = numGenes;

    if (numGenes < 0)
    {
        this->numGenes = 0;
        this->genes[0];
    }else if (genes == NULL)
    {
        this->genes[numGenes];
        for (int i = 0; i < numGenes; i++)
        {
            this->genes[i] = false;
        }
        
    }else
    {
        this->genes[numGenes];
        for (int i = 0; i < numGenes; i++)
        {
          this->genes[i] = genes[i];  
        }
    };   
}

Chromosome::~Chromosome(){

}

double Chromosome::fitness(FitnessFunction* fitnessFunction, Chromosome* chromosome, int numGenes){
    if (fitnessFunction == NULL)
    {
        return 0;
    }
    else if (chromosome == NULL)
    {
        return 0;
    }
    else if (numGenes <= 0)
    {
        return 0;
    }
    else
    {
        return fitnessFunction->calculateFitness(chromosome, numGenes);
    }
    
    
}

int Chromosome::getNumGenes(){
    return numGenes;
}

Chromosome* Chromosome::crossOver(Chromosome* c2){
    if (c2 == NULL)
    {
         
    }
    
}

Chromosome* Chromosome::mutate(){

}

std::string Chromosome::toString(){

}

bool* Chromosome::getGenes(){
    return genes;
}