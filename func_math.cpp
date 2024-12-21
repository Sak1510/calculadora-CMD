#include <iostream>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

string without_space(string input) {
    string output = "";
    for(int i = 0; i < input.length(); i++) if(input[i] != ' ') output += input[i];
    return output;
}

string plus_dot(string input) {
    bool have_dot;
    for(int i = 0; i < input.length(); i++) {
        have_dot = input[i] == '.';
        if(have_dot) break;
    }

    if(!have_dot) input += ".0";
    return input;
}

bool is_a_number(char input) {
    char natural_num[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};
    int natural_num_size = sizeof(natural_num)/sizeof(natural_num[0]);
    bool actual_num = false;

    for(int i = 0; i < natural_num_size; i++) {
        if(input == natural_num[i]) {
            actual_num = true;
            break;
    }} return actual_num;
}

bool is_operable(char oper) {
    return (oper == '+' || oper == '-' || oper == '*' || oper == '/') && oper != ' ';
}

double simple_operation(double A, double B, char oper) {
    double returned;
    switch(oper) {
        case '+': returned = A + B; break;
        case '-': returned = A - B; break;
        case '/': returned = A / B; break;
        case '*': returned = A * B; break;
        case ' ': returned = 0;     break;

        default:
            returned =  0;
            cout << "Operacion no identificada!!" << endl;
    }

    return returned;
}

#pragma region Revision parentesis
bool is_parentesis(char C) {
    string pts = "()[]{}";
    bool is_pts;
    for(int i = 0; i < 6; i++) {
        is_pts = C == pts[i];
        if(is_pts) break;
    } return is_pts;
}

bool is_first_pts(char C) {
    string pts = "([{";
    bool is_pts;
    for(int i = 0; i < 3; i++) {
        is_pts = C == pts[i];
        if(is_pts) break;
    } return is_pts;
}

bool is_end_pts(char C) {
      string pts = ")]}";
    bool is_pts;
    for(int i = 0; i < 3; i++) {
        is_pts = C == pts[i];
        if(is_pts) break;
    } return is_pts;
}

bool e_pts_exist(string input) {
    string pts = ")]}";
    bool pts_exist = false;
    for(int i = 0; i < input.length(); i++) {
        if(pts_exist) break;
        else for(int j = 0; j < 6; j++) {
            pts_exist = input[i] == pts[j];
            if(pts_exist) break;
    }} return pts_exist;
}

bool f_pts_exist(string input) {
    string pts = "([{";
    bool pts_exist = false;
    for(int i = 0; i < input.length(); i++) {
        if(pts_exist) break;
        else for(int j = 0; j < 6; j++) {
            pts_exist = input[i] == pts[j];
            if(pts_exist) break;
    }} return pts_exist;
}

bool pts_exist(string input) {
    string pts = "()[]{}";
    bool pts_exist = false;
    for(int i = 0; i < input.length(); i++) {
        if(pts_exist) break;
        else for(int j = 0; j < 6; j++) {
            pts_exist = input[i] == pts[j];
            if(pts_exist) break;
    }} return pts_exist;
}

#pragma endregion

bool pts_true(string input) {
    //Verifica que existan parentesis
    string f_pts = "([{", e_pts = ")]}";
    bool returned, _continue = true;
    char pts_kind, pts_e_kind;
    int pts_int, pts_eint;

    if(!pts_exist(input)) { 
        _continue = false;
        returned = true;
    } else for(int i = 0; i < input.length(); i++) {
        if(is_parentesis(input[i]) && is_first_pts(input[i])) {
            cout << "kind of parentesis is \'" << input[i] << "\'" << endl;
            pts_kind = input[i];
            break;
        } else if(is_end_pts(input[i])) {
            _continue = false;
            returned = false;
            break;
        }
    }

    if(_continue && e_pts_exist(input)) {
        //Obtiene el tipo de parentesis
        pts_int = f_pts.find(pts_kind);
        pts_eint = input.find(e_pts[pts_int]);

        returned = e_pts[pts_int] == input[pts_eint];
    } else if(!e_pts_exist(input)) returned = false;

    if(input.find(e_pts[pts_int]) != input.length() -1)
        cout << "has more string for analize!" << endl;
    
    return returned;
}

//En desarrollo la jerarquía de operaciones
double _operation(string for_operate) {
    //1.- Quitar todo espacio posible
    for_operate = without_space(for_operate);

    //2.- Identificar la jerarquía de operaciónes
    //  I   -> (), {}, []       II  -> x^n
    //  III -> /, *             IV  -> +, - 

    return 0;
}

/*
double _operation(string for_operate, double subtotal = 0, int stop = 0) {
    //1.- Quitar los espacios de una operacion
    string for_operate_inf = without_space(for_operate);

    //2.- Remplazar los valores int por double (en tipo string)
    string temp = ""; int i = stop == 0 ? 0 : stop +1;
    while(i < for_operate_inf.length()) {
        if(is_a_number(for_operate_inf[i])) {
            temp += for_operate_inf[i];
            i++;
        } else break;
    } temp = plus_dot(temp);

    //3.- Convertir los debidos valores tipo string a double
    double number = stod(temp);

    //4.- Operar los valores dados respecto a su simbolo (+, -, *, /)
    int integer = stop == 0 ? i : stop;
    char oper = for_operate_inf[integer];
    double total = subtotal == 0 ? simple_operation(number, subtotal, oper) : simple_operation(subtotal, number, oper);

    //5.- Repetir todo en caso de tener más signos de operación
    if(i < for_operate_inf.length())
        return _operation(for_operate_inf, total, i);
    else
        return total;
}
*/