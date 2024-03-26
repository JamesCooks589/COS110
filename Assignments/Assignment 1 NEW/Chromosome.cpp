#include "Chromosome.h"

Chromosome::Chromosome(int numGenes, RandomGenerator* rand)
{
    this->numGenes = numGenes;
    if (numGenes < 0)
    {
        this->numGenes = 0;
        genes = new bool [0];

    }else if (rand == NULL)
    {
        genes = new bool [numGenes];
        for (int i = 0; i < numGenes; i++)
        {
            genes[i] = false;
        }
        
    }else
    {
        genes = new bool [numGenes];
        for (int i = 0; i < numGenes; i++)
        {
            genes[i] = rand->randomBool();
        }
    };   
    
}

Chromosome::Chromosome(Chromosome* chromosome)
{
    if (chromosome == NULL)
    {
        numGenes = 0;
        genes = new bool[0];
    }else
    {
        this->numGenes = chromosome->numGenes;
        this->genes = new bool [this->numGenes];
        for (int i = 0; i < this->numGenes ; i++)
        {
            this->genes[i] = chromosome-genes[i];
        }
        
    }
    
    
}

Chromosome::Chromosome(bool* genes, int numGenes)
{
    this->numGenes = numGenes;
    if (numGenes < 0)
    {
        this->numGenes = 0;
        genes = new bool [0];
    }else if (genes == NULL)
    {
        this->genes = new bool [numGenes];
        for (int i = 0; i < numGenes; i++)
        {
            this->genes[i] = false;
        }
        
    }else
    {
        this->genes = new bool [numGenes];
        for (int i = 0; i < numGenes; i++)
        {
          this->genes[i] = genes[i];  
        }
    };   
    
}

Chromosome::~Chromosome()
{
    delete[] genes;
}

double Chromosome::fitness(FitnessFunction* fitnessFunction, Chromosome* chromosome, int numGenes)
{
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

int Chromosome::getNumGenes()
{
    return numGenes;
}

Chromosome* Chromosome::crossOver(Chromosome* c2)
{
    if (c2 != NULL)
    {
        int crossOverPoint = floor(c2->numGenes/2);
        bool* nGenes = new bool[numGenes];
        for (int i = 0; i < crossOverPoint; i++)
        {
            nGenes[i] = this->genes[i];
        }
        for (int i = crossOverPoint; i < numGenes; i++)
        {
            nGenes[i] = c2->genes[i];
        }
        Chromosome* a = new Chromosome(nGenes,numGenes);
        return a;
    }
    else
    {
        Chromosome* a = new Chromosome(this);
    }
    
        
}

Chromosome* Chromosome::mutate()
{
    bool* nGenes = new bool[numGenes];
    for (int i = 0; i < numGenes; i++)
    {
        if (genes[i] == false)
        {
            nGenes[i] = true;
        }else
        {
            nGenes[i] = false;
        } 
    }
    Chromosome* a = new Chromosome(nGenes,numGenes);
    return a;
    
}

std::string Chromosome::toString()
{
    std::string sOutput;
    if (numGenes == 0)
    {
       return ""; 
    }else
    {
        for (int i = 0; i < numGenes; i++)
        {
            if (genes[i] == true)
            {
                sOutput += "1";
            }else
            {
                sOutput += "0";
            }   
        }

        return sOutput;
        
    }
    
    
}

bool* Chromosome::getGenes()
{
    return genes;
}
