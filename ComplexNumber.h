#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class ComplexNumber
{
private:
    float real;
    float imag;

public:

    ComplexNumber(int _r = 0, int _i = 0)
    {
        setReal(_r);
        setImag(_i);
    }
    ComplexNumber& setReal(float _r)
    {
        real = _r;
        return *this;
    }
    ComplexNumber& setImag(float _i)
    {
        imag = _i;
        return *this;
    }
    float getReal()
    {
        return real;
    }
    float getImag()
    {
        return imag;
    }
    void printComplex()
    {
        cout << this->real << " + i" << (*this).imag << endl;
    }
    ComplexNumber AddComplex(ComplexNumber _c)
    {
        ComplexNumber _ans;
        _ans.real = real + _c.real;
        _ans.imag = imag + _c.imag;
        return _ans;
    }
    ComplexNumber SubtractComplex(ComplexNumber _c)
    {
        ComplexNumber _ans;
        _ans.real = real - _c.real;
        _ans.imag = imag - _c.imag;
        return _ans;
    }
    ComplexNumber MultiplyComplex(ComplexNumber _c)
    {
        ComplexNumber _ans;
        _ans.real = real * _c.real - imag * _c.imag;
        _ans.imag = real * _c.imag + imag * _c.real;
        return _ans;
    }
    ComplexNumber DivideComplex(ComplexNumber _c)
    {
        ComplexNumber _ans;
        _ans.real = (real * _c.real + imag * _c.imag) / (real * real + imag * imag);
        _ans.imag = (real * _c.imag - imag * _c.real) / (real * real + imag * imag);
        return _ans;
    }
    ComplexNumber AdditiveInverse()
    {
        ComplexNumber _ans;
        _ans.real = -real;
        _ans.imag = -imag;
        return _ans;
    }
    ComplexNumber MultiplicativeInverse()
    {
        ComplexNumber _ans;
        _ans.real = real / (real * real + imag * imag);
        _ans.imag = -imag / (real * real + imag * imag);
        return _ans;
    }
    ComplexNumber ConjugateComplex()
    {
        ComplexNumber _ans;
        _ans.real = real;
        _ans.imag = -imag;
        return _ans;
    }
    float ModulusComplex()
    {
        float _ans;
        _ans = sqrt(real * real + imag * imag);
        return _ans;
    }
};