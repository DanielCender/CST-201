#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator, denominator;
public:
    // Constructor
    Fraction(int n, int d) {
        numerator = n;
        denominator = d;
    }
    Fraction operator+(const Fraction& f) {
        int denominator = this->denominator * f.denominator;
        int numerator = (this->denominator * f.denominator) + (f.numerator * denominator);

        return Fraction(numerator, denominator);
    }
    Fraction operator-(const Fraction& f) {
        int denom = this->denominator * f.denominator;
        int numer = (this->denominator * f.denominator) - (f.numerator * denominator);
        return reduce(numer, denom);
    }
    Fraction reduce(int a, int b = 1) {
        // Find the lowest reduction of
    }
};

// Function to reduce two numbers to the greatest common factor
int reduce(int a, int b, int gcf = 0) {
    int num = a;
    int den = b;
    int lastGCF = gcf;
    for(int i = 0; i <= 9; i++) {
        if((num % i) == 0 && (den % i == 0)) {
            reduce(a / i, b / i, gcf * i);
        } else return lastGCF;
    }
}

int reduce_fraction(int& a, int& b) {

}

// Function to return the lowest common divisor of two numbers
int lcf(int a, int b) {
    int first = a;
    int second = b;
    // If b is larger, switch a and b
    if(b > a) {
        second = a;
        first = b;
    }
    if(second != 0) {
        return lcf(second, first % second);
    }
    cout << first;
    return first;
}

int main() {

int test [] = {18, 9};
int result = lcf(test[0], test[1]);
    cout << "sample element: " << test[0] << endl;
    cout << "Other sample: " << test[1] << endl;
    cout << "result of reduction: " << result << endl;
    cout << "Hello, World!" << endl;
    return 0;
}