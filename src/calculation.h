#ifndef CALCULATION_H
#define CALCULATION_H


#include <cmath>
#include <string>
#include <sstream>
#include <iostream>
#include "conversion.h"

class Calculation{
public:
    Calculation(Conversion *conv);
    long double count(long double value);
    string get_expression(){
        return this->expression;
    }

    double long get_output(){
        return this->output;
    }
    bool get_calc_error (){
        return this->calc_error;
    }
    void set_expression (string expression){
        this->expression=expression;
    }

    void substition (long double value);
private:
    bool calc_error = false;
    string expression;
    double long output;
    const double pi=M_PI;
    const double e=exp(1.0);
};




#endif // CALCULATION_H
