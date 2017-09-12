#ifndef POLYNOMIAL_
#define POLYNOMIAL_

struct polynomial_struct
{
    int coefficient;
    unsigned exponent;
};

class Polynomial
{
private:
    static const int polynomial_struct_arr_capacity = 10;
    struct polynomial_struct arr[polynomial_struct_arr_capacity];
    
    static unsigned term_count;
    static unsigned highest_degree;
public:
    Polynomial();
    void addTerm( const int& coefficient, const int& exponent );
    int degree();
    int coefficient( const int& power );
    int numberOfTerms();
    int value( const int& x );
};

#endif