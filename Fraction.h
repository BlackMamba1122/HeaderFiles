#pragma once
#include <iostream>
using namespace std;

class Fraction
{
private:
    int num;
    int den;
    int GCD(int _n, int _d)
    {
        for (int i = min(_n, _d); i >= 1; i--)
            if (_n % i == 0 && _d % i == 0)
                return i;
        return 1;
    }
    int LCM(int _n, int _d)
    {
        return _n * _d / GCD(_n, _d);
    }

public:

    Fraction(int _n = 0, int _d = 1)
    {
        setNum(_n);
        setDen(_d);
    }
    Fraction& setNum(int _n)
    {
        num = _n;
        return *this;
    }
    Fraction& setDen(int _d)
    {
        if (_d == 0)
            _d = 1;
        if (_d < 0)
        {
            num = -num;
            _d = -_d;
        }
        den = _d;
        return *this;
    }
    int getNum()
    {
        return num;
    }
    int getDen()
    {
        return den;
    }
    void printFraction()
    {
        cout << this->num << "/" << (*this).den << endl;
    }
    Fraction AddFraction(Fraction _f)
    {
        Fraction _ans;
        int lcm = LCM(den, _f.den);
        _ans.setNum(lcm / den * num + lcm / _f.den * _f.num);
        _ans.setDen(lcm);
        return _ans;
    }
    Fraction SubtractFraction(Fraction _f)
    {
        Fraction _ans;
        int lcm = LCM(den, _f.den);
        _ans.setNum(lcm / den * num - lcm / _f.den * _f.num);
        _ans.setDen(lcm);
        return _ans;
    }
    Fraction MultiplyFraction(Fraction _f)
    {
        Fraction _ans;
        _ans.setNum(num * _f.num);
        _ans.setDen(den * _f.den);
        return _ans;
    }
    Fraction DivideFraction(Fraction _f)
    {
        Fraction _ans;
        _ans.setNum(num * _f.den);
        _ans.setDen(den * _f.num);
        return _ans;
    }
    Fraction AdditiveInverse()
    {
        Fraction _ans;
        _ans.setNum(-num);
        _ans.setDen(den);
        return _ans;
    }
    Fraction MultiplicativeInverse()
    {
        Fraction _ans;
        _ans.setNum(den);
        _ans.setDen(num);
        return _ans;
    }
    Fraction Reduce()
    {
        Fraction _ans;
        int gcd = GCD(num, den);
        _ans.setNum(num / gcd);
        _ans.setDen(den / gcd);
        return _ans;
    }
};