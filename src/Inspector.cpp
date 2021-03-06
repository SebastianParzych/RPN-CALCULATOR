#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

bool inspect(string expression)
{

    bool error=false;
    bool illegal_char_error=false;
    bool name_error=false;
    bool beside=false;

    char symbols[7]={'+','-','*','/','^','%'};
    for(int i=0;i<expression.size();i++){
        for(int j=0;j<7;j++){
            if(expression[i]==symbols[j] and ( expression[i+1]=='+' || expression[i+1]=='=' ||
                                               expression[i+1]=='-' || expression[i+1]=='*' ||
                                               expression[i+1]=='/' || expression[i+1]=='%')){
                error=true;
                beside=true;
            }
        }
        if(expression[i]=='c')
            if( (expression[i+1]!='o' or expression[i+2]!='s') and (expression[i+1]!='t' or expression[i+2]!='g')){
                name_error=true;
                error=true;
            }
            else if(expression[i]=='s')
                if (expression[i+1]!='i' or expression[i+2]!='n'){
                    name_error=true;
                    error=true;
                }
        if(expression[i]=='t')
            if (expression[i+1]!='g'){
                name_error=true;
                error=true;
            }
        if(expression[i]=='l')
            if(expression[i+1]!='n'){
                name_error=true;
                error=true;
            }
        if(expression[i]=='p')
            if(expression[i+1]!='i'){
                name_error=true;
                error=true;
            }
        string all_chars="+*-X=.,%sincot 9e^)(gp0xl!/";
        if(expression[i]>='9' or expression[i]<='0'){
            if( all_chars .find(expression[i])==string::npos){
                error=true;
                illegal_char_error=true;
            }
        }
    }
    bool last_symbol_error=false;
    for(int j=0;j<7;j++){
        if(expression[expression.length()-1]==symbols[j]){
            error=true;
            last_symbol_error=true;
        }
    }
    if(last_symbol_error)
        cout<<"At the end of an expression cannot be symbols like: +,-,*,/,^,%,= "<<endl;
    if(beside)
        cout<<"There cannot be symbols like  +,-,*,/,^,%,= next to each other."<<endl;
    if(illegal_char_error)cout<<"Illegal characters were used."<<endl;
    if(name_error)
        cout<<"Incorrect name of function"<<endl;

    return error;
}
