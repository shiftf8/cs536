#include "Polynomial.h"
#include <cstdio>
// #include <cmath>

void Polynomial::addTerm(int coefficient, int exponent)
{
    if (term_count < polynomial_term_capacity){
        the_coefficient = coefficient;
        the_exponent = exponent;
        
        if (exponent > highest_degree) highest_degree = exponent;
        term_count++;
    } else fprintf(stdout, "Polynomial terms array has reached capacity. Term NOT added.\n");
}
int Polynomial::degree()
{
    return highest_degree;
}
int Polynomial::coefficient(int power)
{
    int tmp_count = term_count;
    
    while (tmp_count--){
        if (the_exponent == power) return the_coefficient;
    }
    return 0;
}
int Polynomial::numberOfTerms()
{
    // return term_count;
}
int Polynomial::value(int x)
{
    // int tmp_count = term_count;
    // int return_value = 0;
    
    // while ( tmp_count-- ){
    //     return_value += the_coefficient * pow(x, the_exponent);
    // }
}