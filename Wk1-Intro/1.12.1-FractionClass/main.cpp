#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

/*
 *
 *  Exercise 1.12.1 Fraction Class
 *  Author: Daniel Cender
 *  Date: 04/28/2019
 *  Description: A class of Fraction that defines adding, subtracting, multiplying and dividing fractions by overloading standard
 *  operators for these operations. Includes function member for reducing fractions.
 *  Overloads I/O operators to input and output fractions.
 */

class Fraction {
private:
    int numerator, denominator;
public:
    // Constructor - in case someone calls without args
    Fraction() {
        this->numerator = 1;
        this->denominator = 1;
    }
    // Overloaded
    Fraction(int n, int d) {
        numerator = n;
        denominator = d;
    }
    void display() {
        cout << this->numerator << "/" << this->denominator;
    }
    int getNum() {
        return numerator;
    }
    void setNum(int n) {
        this->numerator = n;
    }
    int getDenom() {
        return denominator;
    }
    void setDenom(int d) {
        this->denominator = d;
    }
    static int lcd(int a, int b) {
        int first = a;
        int second = b;
        // If b is larger, switch a and b
        if(b > a) {
            second = a;
            first = b;
        }
        if(second != 0) {
            return lcd(second, first % second);
        }
        return first;
    }
    Fraction operator + (const Fraction& f) const {
        int denominator = this->denominator * f.denominator;
        int numerator = (this->numerator * f.denominator) + (f.numerator * denominator);
        Fraction result(numerator, denominator);
        return (result);
    }
    Fraction operator - (Fraction& f) {
        int denominator = this->denominator * f.denominator;
        int numerator = (this->numerator * f.denominator) - (f.numerator * denominator);
        Fraction result(numerator, denominator);
        return (result);
    }
    Fraction operator * (Fraction& f) {
        int numerator = this->numerator * f.numerator;
        int denominator = this->denominator * f.denominator;
        Fraction result(numerator, denominator);
        result.reduce();
        return (result);
    }
    Fraction operator / (Fraction& f) {
        int numerator = this->numerator * f.denominator; // Divide by flipping second fraction and multiplying
        int denominator = this->denominator * f.numerator;
        Fraction result(numerator, denominator);
        result.reduce();
        return (result);
    }
    friend ostream& operator << (ostream& out, Fraction& f) {
        out << f.getNum() << "/" << f.getDenom();
        return (out);
    }
    friend istream& operator>>(istream& in, Fraction& f) {
        cout << endl << "Enter the numerator: ";
        in >> f.numerator;
        cout << endl << "Enter the denominator: ";
        in >> f.denominator;
        cout << endl;
        return (in);
    }
    void reduce() {
        // Find the lowest reduction of a num/denom
        int a = this->numerator;
        int b = this->denominator;
        int lowestCommonDivisor = lcd(a, b);
        int newNum = a / lowestCommonDivisor;
        int newDenom = b / lowestCommonDivisor;
        if((newNum == a) && (newDenom == b)) {
            return;
        }
        this->numerator = newNum;
        this->denominator = newDenom;
        return this->reduce();
    }
};


int main() {
    string betweenNum;
    cout << "Please enter a numerator: ";
    cin >> betweenNum;
    int num = stoi(betweenNum); // String to int conversion
    cout << endl;
    cout << "Please enter a denominator: ";
    cin >> betweenNum;
    int denom = stoi(betweenNum);
    cout << "Fraction entered: " << num << "/" << denom << endl;

    Fraction f(num, denom); // Should prompt for user input
    f.reduce();
    f.display();

    Fraction threeFifths(3, 5);

    cout << "Multiplying entered fraction with 3/5..." << endl;
    f = f * threeFifths;
    cout << "Result: " << f << endl;

    cout << "Dividing entered fraction with 3/5..." << endl;
    f = f / threeFifths;
    cout << "Result: " << f << endl;

    cout << "Subtracting entered fraction with 3/5..." << endl;
    f = f - threeFifths;
//    f.reduce(); // Causes error in reducing
    cout << "Result: " << f << endl;

    cout << "Adding entered fraction to 3/5..." << endl;
    f = f + threeFifths;
//    f.reduce(); // Causes error in reducing
    cout << "Result: " << f << endl;


    return 0;
}