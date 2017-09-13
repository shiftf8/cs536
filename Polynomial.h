#ifndef POLYNOMIAL_
#define POLYNOMIAL_

class Polynomial
{
private:
    static const int coefficient;
    static const unsigned exponent;
    static unsigned term_count;
    static unsigned highest_degree;

public:
    void addTerm( const int& coefficient, const int& exponent );
    int degree();
    int coefficient( const int& power );
    int numberOfTerms();
    int value( const int& x );
};

#endif