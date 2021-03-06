#include <algorithm>
#include "conversion.h"


using std::cout;
using std::endl;
using std::string;
Conversion::Conversion(string raw_exp)
{
    this->normalized_exp=prep_conv(raw_exp); // at beginning always normalize expression
    rpn_conv(normalized_exp);

}

std::string Conversion::get_print_rpn()
{
    string exp_to_show=this->rpn_exp;
    for( int i =0;i<exp_to_show.length();i++){
        if(replace(exp_to_show[i]) !="none"){
            exp_to_show.replace(i,1,replace(exp_to_show[i])); //replacing symbols made in prep_conv, to initial mathematical functions.
        }
    }
    exp_to_show.erase(std::remove(exp_to_show.begin(), exp_to_show.end(), ' '), exp_to_show.end());// deleting all spaces

    return exp_to_show;
}

string Conversion:: prep_conv(string raw_exp)
{
    raw_exp.erase(std::remove(raw_exp.begin(), raw_exp.end(), ' '), raw_exp.end());// deleting all spaces
    if(raw_exp[raw_exp.size()-1]!='='){
        raw_exp+='=';
    }
    for(int i=0;i<raw_exp.length();i++){
        if((raw_exp[i]>='9' || raw_exp[i]<='0') and raw_exp[i] != '=')
        {
            this->symbols++;
        }
    }

    string converted_expression;
    for(int i=0;i<raw_exp.length();i++){
        if(raw_exp[i]=='X' || raw_exp[i]=='x' || raw_exp[i]=='+' ||
                raw_exp[i]=='-' || raw_exp[i]=='%'|| raw_exp[i]=='*'||
                raw_exp[i]=='/'|| raw_exp[i]=='^'){
            converted_expression+=raw_exp[i];

        }
        if(raw_exp[i]=='l' && raw_exp[i+1]=='n'){
            converted_expression+='q';
            raw_exp[i]=' ';
            raw_exp[i+1]=' ';
        }

        if(raw_exp[i]=='s' && raw_exp[i+1]=='i' && raw_exp[i+2]=='n'){
            converted_expression+='$';
            raw_exp[i]=' ';
            raw_exp[i+1]=' ';
            raw_exp[i+2]=' ';
        }
        if(raw_exp[i]=='c' && raw_exp[i+1]=='o' && raw_exp[i+2]=='s'){
            converted_expression+='#';
            raw_exp[i]=' ';
            raw_exp[i+1]=' ';
            raw_exp[i+2]=' ';
        }
        if(raw_exp[i]=='c' && raw_exp[i+1]=='t' && raw_exp[i+2]=='g'){
            converted_expression+='@';
            raw_exp[i]=' ';
            raw_exp[i+1]=' ';
            raw_exp[i+2]=' ';
        }
        if(raw_exp[i]=='t' && raw_exp[i+1]=='g'){
            converted_expression+='&';
            raw_exp[i]=' ';
            raw_exp[i+1]=' ';
        }
        if( raw_exp[i]!='X' && raw_exp[i]!='x' && raw_exp[i]!='+'  && raw_exp[i]!='-'
                && raw_exp[i]!='%'&& raw_exp[i]!='*'&& raw_exp[i]!='/'&& raw_exp[i]!='^'){
            converted_expression+=raw_exp[i];
        }
        if(((raw_exp[i]<='9' && raw_exp[i]>='0') || (raw_exp[i]=='i' && raw_exp[i-1]=='p')
            ||(raw_exp[i]=='X') ||(raw_exp[i]=='x') ||(raw_exp[i]=='e') || raw_exp[i]=='!')
                && (raw_exp[i+1]=='+' || raw_exp[i+1]=='-' || raw_exp[i+1]=='*'|| raw_exp[i+1]=='/'|| raw_exp[i+1]=='^'
                    || raw_exp[i+1]=='%'|| raw_exp[i+1]=='='  || raw_exp[i+1]==')')){

            converted_expression+='_';
        }
        if(raw_exp[i+1]==','){
            raw_exp[i+1]='.';
        }
    }
    return converted_expression;
}

void   Conversion::rpn_conv(string expression)
{
    int ws=0; //ws- pointer to the  last element of  stack
    int ww=0;//ww- pointer to the  last element of  output
    int len=expression.size();
    char output[len]; // output
    char stack[this->symbols]; // stack ,which is containing temporary symbols
    for(int i =0;i <len;i++){
        stack[i]='_';
    }
    for(int i=0;i<len;i++){ // transforming  expression to reverse polsih notation
        if(expression[i]=='='){
            for(int j=ws;j>=0;j--){
                if(stack[j]!=')'  and weight(stack[j])!=-1 ){ // relaeaseed stored symbols in stack, if this is end of bracket
                    output[ww]=stack[j];
                    ww++;
                }
            }
            break;
        }
        switch(expression[i]){
        case ' ' : break ;
        case '(' :
            output[ww]=expression[i];
            stack[ws]=expression[i];
            ws++;
            ww++;
            break;
        case ')' :
            while(stack[ws-1]!='('){
                output[ww]=stack[ws-1];
                ww++;
                ws--;
                stack[ws]=' ';
            }
            if(stack[ws-1]=='('){
                stack[ws-1]=' ';
            }
            output[ww]=stack[ws-1];
            stack[ws]==' ';
            ws--;
            ww++;
            break;
        case '-' :
            if(expression[i-1]=='('){         //thanks to that 1-(-1) is not read as 11-- , but 1_(-1-
                output[ww]='-';
                ww++;
                break;
            }else {
                while(weight(expression[i])<=weight(stack[ws-1]) && ws>0){
                    output[ww]=stack[ws-1];
                    stack[ws-1]=' ';
                    ws--;
                    ww++;
                }
                stack[ws]=expression[i];
                ws++;
                break;
            }
        case '+' :
        case '*' :
        case 'q' ://Natural Logarithm
        case '$' ://sinus
        case '@' ://cotanges
        case '#' ://cos
        case '&' ://tanges
        case '/' :
        case '%' :
        case '!' :
        case '^' :
            while(weight(expression[i])<=weight(stack[ws-1]) && ws>0){
                output[ww]=stack[ws-1];
                stack[ws-1]=' ';
                ws--;
                ww++;
            }
            stack[ws]=expression[i];
            ws++;
            break;
        default:
            output[ww]=expression[i];
            ww++;
            break;
        }
    }
    string temp;
    for(int i =0;i < ww; i++){ // Be sure if rpn_exp is having only entered symbols,numbers
        this->rpn_exp+=output[i];
    }


}








