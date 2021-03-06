#include "conversion.h"
#include "calculation.h"
#include "interface.h"
#include "Inspector.h"
#include "variable_x.h"


bool calculations_run(string expression, Interface ui){ // standard calculations
    double long output;
    bool calc_error=false;
    Conversion *conv = new Conversion (expression);
    Calculation *calc= new Calculation(conv);
    output=calc->count(0);
    calc_error=calc->get_calc_error();
    if(!calc_error){
       conv->get_print_rpn();
        ui.result(output, conv->get_print_rpn());
    }
    delete conv,calc;
    return calc_error;
    conv=NULL;
    calc=NULL;
}
void run_calculator(){
    string expression;
    int menu_pick=0;
    bool calculation_error;
    Interface ui;
    do{
        do{
            calculation_error=false;
            menu_pick=ui.menu();
        }while(menu_pick !=-1); // first loop to move in main menu
        do{
            std::getline(std::cin >> std::ws, expression);
            if(!inspect(expression)){ // checking if syntax of epression is good
                if( expression .find('x')!=string::npos or expression .find('X')!=string::npos){ // run calculations with unknown variable
                    function_x(expression,ui);
                    ui.show_back();
                    menu_pick=ui.back_result();
                }else{ // standard calculations
                    calculation_error=calculations_run(expression,ui);
                    ui.show_back();
                    menu_pick=ui.back_result();
                }
            }else{
                ui.show_back();
                menu_pick=ui.back_result();
            }
        }while (menu_pick == 2 || calculation_error); // second loop to repeat calculations with different expressions

        expression.clear();

    }while(true);
}

int main()
{
    run_calculator();
    return 0;
}
