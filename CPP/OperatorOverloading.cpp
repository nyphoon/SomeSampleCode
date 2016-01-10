/****************************************************************
 *  modified from sample at http://www.cnblogs.com/oomusou/archive/2007/01/18/623287.html
 *
 *  Two ways to implement operator overloading
 *
 *  ************************************************************/
//#define VER_MENBER 0

#include <iostream>
using namespace std;

class Complex {
    public:
	Complex(double re = 0.0, double im = 0.0) : re(re), im(im) {}

	Complex operator+(const Complex&) const;
	friend ostream& operator<<(ostream&, const Complex&); // use global function
#ifdef VER_MENBER
	Complex operator*(const Complex&) const;
#else
	friend Complex operator*(const Complex&, const Complex&); // use global function
#endif //VER_MENBER
    private:
	double re; // real part
	double im; // imagenary part
};

Complex Complex::operator+(const Complex& complex) const
{
    Complex _complex;
    _complex.re = this->re + complex.re;
    _complex.im = this->im + complex.im;

    return _complex;
}

ostream& operator<<(ostream& out, const Complex& complex) {
    cout << "real:" << complex.re << " imagenary:" << complex.im;
    return out;
}


// overloads global operator
#ifdef VER_MENBER
Complex Complex::operator*(const Complex& complex1) const
{
    cout<< "menber operator" << endl;
    Complex _complex;
    _complex.re = complex1.re * this->re - complex1.im * this->im;
    _complex.im = complex1.re * this->im + complex1.im * this->re;

    return _complex;
}
#else
Complex operator*(const Complex& complex1, const Complex& complex2) {
    cout<< "global operator" << endl;
    Complex _complex;
    _complex.re = complex1.re * complex2.re - complex1.im * complex2.im;
    _complex.im = complex1.re * complex2.im + complex1.im * complex2.re;

    return _complex;
}
#endif //VER_MENBER

int main() {
    Complex c1;
    Complex c2(1,2);
    Complex c3 = c1 + c2;
    Complex c4 = c1 * c2;

    cout << c3 << endl;
    cout << c4 << endl;
}
