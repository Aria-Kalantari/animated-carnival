#ifndef BIGNUM_H
#define BIGNUM_H

#pragma once

#include <string>
#include <iostream>

class BigNum
{
    friend std::istream& operator>>(std::istream&, BigNum&);
    friend std::ostream& operator<<(std::ostream&, const BigNum&);

    friend BigNum operator+(const BigNum&, const BigNum&);
    friend BigNum operator-(const BigNum&, const BigNum&);
    friend BigNum operator*(const BigNum&, const BigNum&);
    friend BigNum operator/(const BigNum&, const BigNum&);
    friend BigNum operator%(const BigNum&, const BigNum&);

    friend bool operator<(const BigNum&, const BigNum&);
    friend bool operator<=(const BigNum&, const BigNum&);
    friend bool operator>(const BigNum&, const BigNum&);
    friend bool operator>=(const BigNum&, const BigNum&);
    friend bool operator==(const BigNum&, const BigNum&);
    friend bool operator!=(const BigNum&, const BigNum&);

    friend int& operator+=(int&, const BigNum&);
    friend int& operator-=(int&, const BigNum&);
    friend int& operator*=(int&, const BigNum&);
    friend int& operator/=(int&, const BigNum&);
    friend int& operator%=(int&, const BigNum&);

    friend long int& operator+=(long int&, const BigNum&);
    friend long int& operator-=(long int&, const BigNum&);
    friend long int& operator*=(long int&, const BigNum&);
    friend long int& operator/=(long int&, const BigNum&);
    friend long int& operator%=(long int&, const BigNum&);

    friend long long int& operator+=(long long int&, const BigNum&);
    friend long long int& operator-=(long long int&, const BigNum&);
    friend long long int& operator*=(long long int&, const BigNum&);
    friend long long int& operator/=(long long int&, const BigNum&);
    friend long long int& operator%=(long long int&, const BigNum&);

    friend unsigned int& operator+=(unsigned int&, const BigNum&);
    friend unsigned int& operator-=(unsigned int&, const BigNum&);
    friend unsigned int& operator*=(unsigned int&, const BigNum&);
    friend unsigned int& operator/=(unsigned int&, const BigNum&);
    friend unsigned int& operator%=(unsigned int&, const BigNum&);

    friend unsigned long int& operator+=(unsigned long int&, const BigNum&);
    friend unsigned long int& operator-=(unsigned long int&, const BigNum&);
    friend unsigned long int& operator*=(unsigned long int&, const BigNum&);
    friend unsigned long int& operator/=(unsigned long int&, const BigNum&);
    friend unsigned long int& operator%=(unsigned long int&, const BigNum&);

    friend unsigned long long int& operator+=(unsigned long long int&, const BigNum&);
    friend unsigned long long int& operator-=(unsigned long long int&, const BigNum&);
    friend unsigned long long int& operator*=(unsigned long long int&, const BigNum&);
    friend unsigned long long int& operator/=(unsigned long long int&, const BigNum&);
    friend unsigned long long int& operator%=(unsigned long long int&, const BigNum&);

    friend double& operator+=(double&, const BigNum&);
    friend double& operator-=(double&, const BigNum&);
    friend double& operator*=(double&, const BigNum&);
    friend double& operator/=(double&, const BigNum&);

    friend long double& operator+=(long double&, const BigNum&);
    friend long double& operator-=(long double&, const BigNum&);
    friend long double& operator*=(long double&, const BigNum&);
    friend long double& operator/=(long double&, const BigNum&);

    friend float& operator+=(float&, const BigNum&);
    friend float& operator-=(float&, const BigNum&);
    friend float& operator*=(float&, const BigNum&);
    friend float& operator/=(float&, const BigNum&);
    friend float& operator%=(float&, const BigNum&);

    friend char& operator+=(char&, const BigNum&);
    friend char& operator-=(char&, const BigNum&);
    friend char& operator*=(char&, const BigNum&);
    friend char& operator/=(char&, const BigNum&);
    friend char& operator%=(char&, const BigNum&);

    friend bool& operator+=(bool&, const BigNum&);
    friend bool& operator-=(bool&, const BigNum&);
    friend bool& operator*=(bool&, const BigNum&);
    friend bool& operator/=(bool&, const BigNum&);
    friend bool& operator%=(bool&, const BigNum&);

public:
// Constructor
    BigNum(const char* = "");
    BigNum(const std::string&);
    BigNum(const int);
    BigNum(const long int);
    BigNum(const long long int);

// Setter & Getter
    void setBigNum(const std::string&);
    const std::string& getBigNum(void) const;

// Arithmetic operators    
    BigNum& operator+=(const BigNum&);
    BigNum& operator-=(const BigNum&);
    BigNum& operator*=(const BigNum&);
    BigNum& operator/=(const BigNum&);
    BigNum& operator%=(const BigNum&);

    BigNum& operator++(void);
    BigNum operator++(int);
    BigNum& operator--(void);
    BigNum operator--(int);

// Subscript operator
    char& operator[](const int); // Index starts from 1
    const char& operator[](const int) const; // Index starts from 1

// Print with delimeter
    void printWithDelimeter(void) const;

// Cast operators
    explicit operator int(void) const;
    explicit operator long int(void) const;
    explicit operator long long int(void) const;

    explicit operator unsigned int(void) const;
    explicit operator unsigned long int(void) const;
    explicit operator unsigned long long int(void) const;

private:
    std::string bigNum;

    BigNum plus(const BigNum&, const BigNum&) const;
    BigNum minus(const BigNum&, const BigNum&) const;
    BigNum multiply(const BigNum&, const BigNum&) const;
    BigNum divide(const BigNum&, const BigNum&) const;
    BigNum modulo(const BigNum&, const BigNum&) const;
};

#endif