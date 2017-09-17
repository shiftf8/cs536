#ifndef POLYNOMIAL_
#define POLYNOMIAL_

static const unsigned polynomial_term_capacity = 10;

class Polynomial
{
private:
    int the_coefficient;
    int the_exponent;

public:
    static unsigned term_count;
    static unsigned highest_degree;

    void addTerm(int coefficient, int exponent);
    int degree();
    int coefficient(int power);
    int numberOfTerms();
    int value(int x);
    
    // const int get_the_coefficient();
    // const int get_the_exponent();
    // const unsigned get_term_count();
    // const unsigned get_highest_degree();
};

#endif