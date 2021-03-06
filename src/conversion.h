#ifndef CONVERSION_H
#define CONVERSION_H



#include <iostream>


using std::cout;
using std::endl;
using std::string;

class Conversion{

private:

public:
    Conversion(string raw_exp);
    string get_rpn(){
        return this->rpn_exp;}
    string get_normalized_exp(){
        return this->normalized_exp;}
    string get_print_rpn();
private:
    string  prep_conv(string raw_exp); // initial expression eddtion
    void rpn_conv(string raw_exp); // edition of expression to RPN expresssion
    string normalized_exp; //Normalized expressioon, which is easy to modify
    string rpn_exp;  // expression translated with RPN
    int symbols=0; // math symbols number.
    int weight(char symbol) // Weight particular char
    {
        switch (symbol)
        {
        case ' ' : return 0;
        case '(' :  return 0;
        case '+' : return 1;
        case '-' : return 1;
        case ')' : return 1;
        case '*' : return 2;
        case '/' : return 2;
        case '%' : return 2;
        case '^' : return 3;
        case '!' : return 4;
        case '$' : return 4; //sinus
        case '#' : return 4; //cos
        case '@' : return 4; //cotanges
        case '&' : return 4; //tanges
        case 'q' : return 4; //Natural Logarithm
        default: return -1;
        }
    }
    string replace(char symbol ){  // function runned in get_prin_rpn to re-convert convertet mathematical functions.
        switch(symbol){
        case '$' : return "sin";
        case '#' : return "cos";
        case '@' : return "ctg";
        case '&' : return "tan";
        case 'q' : return "ln";
        default: return "none";
        }
    }
};






#endif // ZAMIANA_H
