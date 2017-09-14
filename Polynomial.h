#ifndef POLYNOMIAL_
#define POLYNOMIAL_

static const int polynomial_term_capacity = 10;
static unsigned term_count;
static unsigned highest_degree;

class Polynomial
{
private:
    int the_coefficient;
    unsigned the_exponent;

public:
    void addTerm(int coefficient, int exponent);
    int degree();
    int coefficient(int power);
    int numberOfTerms();
    int value(int x);
};

#endif