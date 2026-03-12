#include <iostream>

using namespace std;

typedef float (*lpfnOperation)(float, float);
// CVector of pointer to functions
float Addition(float a, float b) {
    return a + b;
}
float Subtraction(float a, float b) {
    return a - b;
}
float Multiplication(float a, float b) {
    return a * b;
}
float Division(float a, float b) {
    if (b == 0) {
        throw runtime_error("Error: division por cero");
    }
    return a / b;
}

lpfnOperation vpf[4] = { &::Addition, &::Subtraction,
                        &::Multiplication, &::Division };

int main() {
    float a, b, c;
    int opt;
    cout << "enter the operands:";
    cin >> a >> b;
    cout << "enter the operation 1-Addition, 2-Subtraction, 3-Multiplication, 4-Division:\n";
    cin >> opt;
    // The next line replaces the switch and replaces the whole switch
    c = (*vpf[--opt])(a, b);
    cout << c;
}