#include "variable_x.h"
#include "interface.h"
#include <sstream>




int Interface::choice()
{
    bool  reading_error=false;
    string choice; // input
    int number = 0; // output
    do{
        number=0;
        if(reading_error){
            cout<<"Reading error"<<endl;
        }
        reading_error=false;
        cin>>choice;
        stringstream conv(choice);
        conv >> number;
        reading_error=true; // when choice is proper this won't trigger

    }while(!(number<5));
    return number;
}

int  Interface::menu(){
    show_home();
    switch(choice())
    {
    case 0:
        set_precission();
        return 3;
    case 1:
        show_info();
        return back_menu();
    case 2:
        show_tutorial();
        return back_menu();
    case 3:
        cout<<"           |Enter the expression :                       "<<endl;
        return -1;

    case 4: exit(0);
        break;
    }
}


void Interface:: result(long double q, string exp_to_show)
{
    cout<<"\n\n\n";
    cout.precision(this->precision);
    cout<<"           |Reverse Polish notation:       "<<exp_to_show<<endl;
    cout<<"           |Result:       "<<fixed<<q<<"                               "<<endl;
    cout<<"           ._____________________________________________________."<<endl;
}
int Interface:: back_result(){
    switch (choice()) {
    case 2:
        cout<<"           ._____________________________________________________."<<endl;
        cout<<"           |Enter the expression :                       "<<endl;
        return 2;
        break;
    case 3:
        return 3;
        break;
    case 4:
        exit(0);
        break;
    }
}
int  Interface::back_menu()
{
    switch (choice()) {
    case 2:
        return 2;
        break;
    case 3:
        return 3;
        break;
    case 4:
        exit(0);
        break;
    }
}



void  Interface::show_home(){

    cout<<"           ._____________________________________________________."<<endl;
    cout<<"           ______________________Calculator MENU__________________"<<endl;
    cout<<"           Press:                                                "<<endl;
    cout<<"           0-Set Precission                                      "<<endl;
    cout<<"           1-Info about calculator                               "<<endl;
    cout<<"           2-How to use calculator                               "<<endl;
    cout<<"           3-Calculator                                          "<<endl;
    cout<<"           4-Exit                                                "<<endl;
}
void Interface:: set_precission(){
    string setting;
    bool  reading_error=false;
    int number;
    cout<<"           ._____________________________________________________."<<endl;
    cout<<"           ______________________Set Precission______________________"<<endl;
    cout<<"           Enter a number to set the precision of your results       "<<endl;
    cout<<"           Number define how many decimal places should be displayed"<<endl;
    cout<<"           Set Precissiion:      "<<endl;

    do{
        number=0;
        if(reading_error){
            cout<<"Reading error"<<endl;
        }
        reading_error=false;
        cin>>setting;
        stringstream conv(setting);
        conv >> number;
        reading_error=true; // when choice is proper this won't trigger
    }while(!reading_error);
    cout<<"           Change has been saved.      "<<endl;
    cout<<"           Current precission : "<< number<<endl;
    this->precision = number;

}
void Interface:: show_info(){
    cout<<"           ._______________________________________."<<endl;
    cout<<"           |______________Calculator INFO___________"<<endl;
    cout<<"           |Calculator based on reverse Polish notation"<<endl;
    cout<<"           |The following actions are available:    "<<endl;
    cout<<"           |-addition,                            "<<endl;
    cout<<"           |-substraction,                          "<<endl;
    cout<<"           |-division,                            "<<endl;
    cout<<"           |-multiplication,                             "<<endl;
    cout<<"           |-exponentiation,                          "<<endl;
    cout<<"           |-percecntages,                             "<<endl;
    cout<<"           |-factorial.                               "<<endl;
    cout<<"           |-natural logarithm.                   "<<endl;
    cout<<"           |It also has suppot for trigonometric functions:"<<endl;
    cout<<"           |-sinus,                                "<<endl;
    cout<<"           |-cosinus,                              "<<endl;
    cout<<"           |-tanges,                               "<<endl;
    cout<<"           |-cotanges.                             "<<endl;
    cout<<"           |The calculator supports math constants: "<<endl;
    cout<<"           |-pi~3.14159265359 -PI number           "<<endl;
    cout<<"           |-e~2,718281828459 -Euler number       "<<endl;
    cout<<"           |It has a function that allows you to count the value of an expression"<<endl;
    cout<<"           |depending on x ( user gives its range of change and dx- its value jump"<<endl;
    cout<<"           |and print out all outputs in function.txt file"<<endl;
    cout<<"           |Press:"<<endl;
    cout<<"           |3- Back to Menu "<<endl;
    cout<<"           |4- Exit. "<<endl;

}
void  Interface::show_tutorial(){
    cout<<"           ._______________________________________________________________________."<<endl;
    cout<<"           |________________________Calculator INSTRUCTION_________________________|"<<endl;
    cout<<"           ._______________________________________________________________________|"<<endl;
    cout<<"           |Main rules for using the calculator                                    |"<<endl;
    cout<<"           |The order of operations is as follows:                                 |"<<endl;
    cout<<"           |- operations in brackets,                                              |"<<endl;
    cout<<"           |- powering and rooting,                                                |"<<endl;
    cout<<"           |- addition,substraction,multiplication  division.                      |"<<endl;
    cout<<"           |If there is only substraction,addition or multiplication and division  |"<<endl;
    cout<<"           |in whole typed expression, these actions are performing in the order   |"<<endl;
    cout<<"           |in which they were written                                             |"<<endl;
    cout<<"           |-Negative numbers should be always put in brackets                     |"<<endl;
    cout<<"           |_______________________________________________________________________|"<<endl;
    cout<<"           |Constants pi and the euler number should be written:                   |"<<endl;
    cout<<"           |-Pi number-                     pi                                     |"<<endl;
    cout<<"           |-Euler number-                   e                                     |"<<endl;
    cout<<"           |Trygonometric functions and logartihm syntax:                          |"<<endl;
    cout<<"           |- Sinus-                      sin(x)                                   |"<<endl;
    cout<<"           |- Cosinus -                   cos(x)                                   |"<<endl;
    cout<<"           |- Tangent -                    tg(x)                                   |"<<endl;
    cout<<"           |- Cotangent -                  ctg(x)                                  |"<<endl;
    cout<<"           |- Logarithm -                  ln(x)                                   |"<<endl;
    cout<<"           |_______________________________________________________________________|"<<endl;
    cout<<"           |The decimal separator can be either a peroid or a comma                |"<<endl;
    cout<<"           |_______________________________________________________________________|"<<endl;
    cout<<"           |When you enter two characters next to each other, e.g.: +,- the program|"<<endl;
    cout<<"           |is detecting an error and is requiring to re-enter expressions.        |"<<endl;
    cout<<"           |_______________________________________________________________________|"<<endl;
    cout<<"           |Arguments of trigonometric functions should be in brackets             |"<<endl;
    cout<<"           |unless the argument is one number, e.g. sin3,cos3                      |"<<endl;
    cout<<"           ._______________________________________________________________________|"<<endl;
    cout<<"           |When your expression includes x , program treat x  like number         |"<<endl;
    cout<<"           |e.g: valid -> 3*x, wrong -> 3x                                         |"<<endl;
    cout<<"           ._______________________________________________________________________."<<endl;
    cout<<"           |Press:"<<endl;
    cout<<"           |3- Back to Menu "<<endl;
    cout<<"           |4- Exit. "<<endl;

}
void Interface:: show_back(){
    cout<<"           |Press:"<<endl;
    cout<<"           |2- To repeat."<<endl;
    cout<<"           |3- Back to Menu "<<endl;
    cout<<"           |4- Exit. "<<endl;
    cout<<"           ._____________________________________________________."<<endl;
}

