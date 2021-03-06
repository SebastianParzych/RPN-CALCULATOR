#include <fstream>
#include "calculation.h"
#include "conversion.h"
#include "interface.h"

using std::ofstream;
void function_x( string expression, Interface ui)
{
    string equation;
    Conversion *conv = new Conversion (expression);
    Calculation *calc= new Calculation(conv);
    double dx=0;
    double top=0;
    double  low=0;
    cout<<"Enter the variability range of x"<<endl;
    cout<<"Lower bound:  ";
    cin>>low;
    cout<<"Upper bound:   ";
    cin>>top;
    cout<<"Set dx."<<endl;
    cin>>dx;
    long double output=0;
    ofstream plik("function.txt");
    for(long double i=low;i<=top+dx;i=i+dx){
        if ( i>top)break;
        output=0;
        calc->set_expression(conv->get_rpn()); // after one iteration, instead of x,X object see iteration value
        output=calc->count(i);
        if(!calc->get_calc_error()){
            cout.precision(ui.get_precission());
            cout<<"  x: "<<i<<" y: "<<fixed<<output<<endl;
            plik<<"x: "<<i<<"\t y: "<<output<<endl;
        }else {
            plik<<"For x="<<i<<" Illegal operation"<<endl;
            cout<<"For x="<<i<<" Illegal operation"<<endl;
        }
    }
    delete conv,calc;
    conv=NULL;
    calc=NULL;
}
