#ifndef POLYNOMIAL_
#define POLYNOMIAL_

const static size_t polynomial_term_capacity = 10;

struct polyterm
{
    int coefficient;
    int exponent;
};

class Polynomial
{
private:
    polyterm term[polynomial_term_capacity];
    
    static int term_count;
    static unsigned highest_degree;

public:
    void addTerm(int coefficient, int exponent);
    int degree();
    int coefficient(int power);
    int numberOfTerms();
    int value(int x);
};

#endif