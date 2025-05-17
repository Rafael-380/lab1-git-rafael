#include <iostream>

class Complex{
public:
    // Constructors
    Complex(double r, double i){
        real = r;
        imag = i;
    }

    /*Complex(double r){
        real = r;
    }*/
    Complex(double r) : real(r), imag(0.0) {}

    // Getters
    double get_re() const {
        return real;
    }

    double get_im() const {
        return imag;
    }

    // Setters
    void set_re(double r) {
        real = r;
    }

    void set_im(double i) {
        imag = i;
    }

    // Print the number correctly
    void print() const {
        std::cout << real;
        if (imag >= 0)
            std::cout << "+" << imag << "i" << std::endl;
        else
            std::cout << imag << "i" << std::endl;
    }

    // Add a complex nr
    Complex add(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Add a real nr
    Complex add(double number) const {
        return Complex(real + number, imag);
    }

private:
    double real;
    double imag;
};

int main()
{
    Complex a(1.0, -2.0);  // 1 - 2i
    Complex b(3.14);       // 3.14 + 0i

    b.set_im(-5);          // b = 3.14 - 5i

    Complex c = a.add(b);  // (1 + 3.14, -2 + (-5)) = 4.14 - 7i

    c.print();             // Print: 4.14-7i

    return 0;
}

