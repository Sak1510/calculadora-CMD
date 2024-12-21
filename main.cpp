#include "func_math.cpp"

int main(void) {
    while(1) {
        cout << "Operacion a realizar: ";
        string user_input;
        getline(cin, user_input);

        cout << pts_true(user_input) << endl;
    }
    
    system("PAUSE");
    return 0;
}