#include <cstdio>
#include <cstdlib>
#include "Polynomial.h"

int main(int argc, char* argv[])
{
    FILE* input = NULL;
    Polynomial poly;
    int in_coefficient = 0;
    int in_exponent = 0;

    if (argc == 2){
        input = fopen(argv[1], "r")
    } else {
        input = fopen("input1.Polynomial.txt", "r");
        // input = fopen("input12.Polynomial.txt", "r");
    }
    
    while (fscanf(input, "%d %d\n", &in_coefficient, &in_exponent) == 2){
        poly.addTerm(in_coefficient, in_exponent);
    }
    fclose(input);
    
    fprintf(stdout, "Degree: \t%u\n# terms:\t%d\n", poly.degree(), poly.numberOfTerms());
    for (int i = 0; i < poly.degree(); ++i){
        fprintf(stdout, "coeff(%d):\t%d\n", i, poly.coefficient(i));
    }
    fprintf(stdout, "value(1):\t%d\nvalue(2):\t%d\n", poly.value(1), poly.value(2));

    return 0;
}