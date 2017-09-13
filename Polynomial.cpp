#include "Polynomial.h"
#include <cstdio>
#include <cmath>

Polynomial::Polynomial()
{
    Polynomial::term_count = 0;
    Polynomial::highest_degree = 0;
}
void Polynomial::addTerm( const int& coefficient, const int& exponent )
{
    if ( term_count < polynomial_struct_arr_capacity ){
        Polynomial::arr[term_count].coefficient = coefficient;
        Polynomial::arr[term_count].exponent = exponent;
        
        if ( Polynomial::arr[term_count].exponent > highest_degree ) highest_degree = exponent;
        term_count++;
    } else fprintf( stdout, "Polynomial array has reached capacity. Term NOT added.\n" );
}
int Polynomial::degree()
{
    return highest_degree;
}
int Polynomial::coefficient( const int& power )
{
    int tmp_count = term_count;
    
    while ( tmp_count-- ){
        if ( Polynomial::arr[term_count].exponent == power ) return Polynomial::arr[term_count].coefficient;
    }
    return 0;
}
int Polynomial::numberOfTerms()
{
    return term_count;
}
int Polynomial::value( const int& x )
{
    int tmp_count = term_count;
    int return_value = 0;
    
    while ( tmp_count-- ){
        return_value += Polynomial::arr[tmp_count].coefficient * pow(x, Polynomial::arr[tmp_count].exponent);
    }
}