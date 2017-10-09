#include <cstdio>
#include <cmath>
#include "Polynomial.h"

int Polynomial::term_count = 0;
unsigned Polynomial::highest_degree = 0;

void Polynomial::addTerm(int coefficient, int exponent)
{
    if (term_count < polynomial_term_capacity){
        term[term_count].coefficient = coefficient;
        term[term_count].exponent = exponent;
        term_count++;
        if (exponent > highest_degree) highest_degree = exponent;
        
    } else fprintf(stdout, "Polynomial terms array has reached capacity. Term NOT added.\n");
}
int Polynomial::degree()
{
    return highest_degree;
}
int Polynomial::coefficient(int power)
{
    int i = 0;
    
    for (i; i < numberOfTerms(); ++i){
        if (term[i].exponent == power) return term[i].coefficient;
    }
    return 0;
}
int Polynomial::numberOfTerms()
{
    return term_count;
}
int Polynomial::value(int x)
{
    int i = 0;
    int retVal = 0;
    
    for (i; i < numberOfTerms(); ++i){
        retVal += term[i].coefficient * pow(x, term[i].exponent);
    }
    
    return retVal;
}