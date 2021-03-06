#ifndef INTERFACE_H
#define INTERFACE_H
#include <iostream>
#include <string>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;
using std::fixed;

class Interface{


public:
    void result(double long q, string exp_to_show);

    void show_back();
    int menu();
    int back_menu();
    int back_result();
    int  choice();
    int get_precission(){
        return this->precision;
    }
private:
    int precision=1;
    void set_precission();
    void show_home();
    void show_tutorial();
    void show_info();

};



#endif // INTERFACE_H


