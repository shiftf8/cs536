#include <cstdio>
#include "Polynomial.h"

int main()
{
    Polynomial poly;
    int in_coefficient = 0;
    int in_exponent = 0;

    FILE* input_file;
    input_file = fopen("input2.Polynomial.txt", "r");
    
    if (input_file != NULL){
        while (fscanf(input_file, "%d %d\n", &in_coefficient, &in_exponent) == 2){
            poly.addTerm(in_coefficient, in_exponent);
        }
    }
    fclose(input_file);
    
    fprintf(stdout, "Degree: \t%u\n# terms:\t%d\n", poly.degree(), poly.numberOfTerms());
    for (int i = 0; i < poly.degree(); ++i){
        fprintf(stdout, "coeff(%d):\t%d\n", i, poly.coefficient(i));
    }
    fprintf(stdout, "value(1):\t%d\nvalue(2):\t%d\n", poly.value(1), poly.value(2));

    return 0;
}