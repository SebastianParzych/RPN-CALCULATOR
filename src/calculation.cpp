#include "conversion.h"
#include "calculation.h"


using std::cout;
using std::endl;
using std::string;
using std::stringstream;

Calculation::Calculation(Conversion *conv){
    this->expression=conv->get_rpn();
}
void Calculation:: substition (long double value){ // replacing x,X with lowe bound + dx value
    this->calc_error=false; // reseting calc_error, if previous iteration had incorrect operation
    stringstream strs;
    strs<<value;
    string str = strs.str();
    string temp;

    for ( int i = 0; i<expression.length(); i ++){
        if( expression[i]=='x' || expression[i]=='X'){
            if((value>=0)){ // if iteration is netagive, and '-x' is also negtive, minuses cancel out. e.g. ln(-x)
                temp+=str;
            }else{
                if(expression[i-1]=='-'){
                    temp[i-1]='+';
                    temp+=str;
                }
            }

        }else{
            temp+=expression[i];
        }
    }
    this->expression=temp;
}

long double Calculation::count(long double value){

    int p=0; // pointer for stack
    long  double stack[expression.length()];
    std::fill(stack,stack+expression.length(),0);
    int factorial=1;
    string pom; // string to trasfer substrings of expressions to numbers
    long  double a,b; // numbers of stack
    stringstream ss;
    substition(value);
    for(int i=0;i<expression.length();i++){ // Calculating expression using reverse polish notation
        if(expression[i]=='p' && expression[i+1]=='i'){

            stack[p++]=pi;
        }
        if(expression[i]=='e'){
            stack[p++]=e;
        }
        if(expression[i]=='(' and expression[i+1]=='-'){
            pom+='-';
        }
        if((expression[i]<='9'  && expression[i]>='0') ||  expression[i]=='.'){
            pom+=expression[i];

            if(expression[i+1]=='_'){
                ss.clear();
                ss<<pom;
                pom.clear();
                if(ss >> a){
                    stack[p++] = a;
                }
            }
        }
        if(  expression[i]=='$' || expression[i]=='@' || expression[i]=='#' || expression[i]=='&' || expression[i]=='q' || expression[i]=='!'){
            a=stack[--p];
            switch (expression[i]) {
            case '!' :
                if(a>=0){
                    for(int j=a;j>1;j--){
                        factorial*=j;
                    }
                    a=factorial;}
                else {
                    cout<<"The Factorial has to be performed on a natural number."<<endl;
                    this->calc_error=true;
                }
                break;
            case '$' :

                a=sin(a);
                break;
            case '@':

                a=1/tan(a);
                if(tan(a)==0){
                    cout<<"You cannot divide by 0."<<endl;
                    this->calc_error=true;
                }
                break;
            case '&':
                a=tan(a);
                break;
            case '#':
                a=cos(a);
                break;
            case 'q':
                if(a>0)
                    a=log(a);
                else{
                    this->calc_error=true;
                    cout<<"Logarithm argument has to be natural number."<<endl;
                }
                break;
            }
            stack[p++]=a;
        }
        if(p>1 && expression[i]=='+'|| expression[i]=='*'||
                (expression[i]=='-' && expression[i-1]!='(')||
                expression[i]=='/'|| expression[i]=='^'|| expression[i]=='%')
        {
            b = stack[--p];
            a = stack[--p];
            switch(expression[i])
            {
            case '+' : a += b; break;
            case '-' : a -= b; break;
            case '*' : a *= b; break;
            case '/' :
                if(b==0){
                    this->calc_error=true;
                    cout<<"You cannot divide by 0."<<endl;
                }else a /= b;
                break;
            case '%' : a=a*b/100; break ;
            case '^' :  a=pow(a,b); break;
            }

            stack[p++]=a;
        }

    }


    return stack[0];
}







