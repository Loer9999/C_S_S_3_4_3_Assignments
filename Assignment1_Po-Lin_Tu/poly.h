#pragma once

#include <iostream>

// -------------------------------- poly.h ------------------------------------
// Programmer Name: Po-Lin Tu  Course Section Number: CSS 343 B
// Creation Date: 3/28/2022
// Date of Last Modification: 4/2/2022
//
// Purpose: This file is the header file of the Poly class that represents a 
// polynomial. The Poly class stores a polynomial and supports the addition
// operator, the subtraction operator, the multiplication operator, the
// assignment operator, the equality operator, and the inequality operator.
// These operators act on two instances of the Poly class. The Poly class also
// supports accessors and mutators that change or display the entire polynomial
// or a certain coefficient of the polynomial.
//
// Note: The polynomial that the Poly class represents cannot have negative
// exponents.
// ----------------------------------------------------------------------------


class Poly
{
private:
    // The pointer points to a block of memory that stores the polynomial.
    int* poly;
    int max;

public:
    // ---------------------------Default Constructor------------------------------
    // Description: The default constructor creates a zero polynomial.
    //
    // Post: A zero polynomial exists.
    Poly();

    // ------------------------Parametrized Constructor----------------------------
    // Description: This parametrized constructor creates a polynomial whose degree
    // is zero and coefficient is the given integer.
    //
    // Post: A polynomial whose degree is zero and coefficient is the given integer
    // exists.
    //
    // Parameter: coefficient, which is the coefficient of the polynomial to
    // create.
    Poly(int coefficient);

    // ------------------------Parametrized Constructor----------------------------
    // Description: This parametrized constructor creates a polynomial whose degree
    // and coefficient of the highest-power term are the given integers.
    //
    // Pre: The degree of this polynomial cannot be negative.
    //
    // Post: A polynomial whose degree and coefficient of the highest-power term 
    // are the given integers exists. If the integer parameter that specifies the
    // degree is negative, the degree of this polynomial will be zero.
    //
    // Parameter: coefficient, which is the coefficient of the highest-power term.
    //
    // Parameter: degree, which is the degree of the polynomial to create.
    Poly(int coefficient, int degree);

    // ----------------------------Copy Constructor--------------------------------
    // Description: The copy constructor creates a polynomial that is the same as
    // the given polynomial.
    //
    // Post: A polynomial that is the same as the given polynomial exists.
    //
    // Parameter: other, which is another polynomial that this polynomial copies.
    Poly(const Poly& other);

    // ------------------------------Destructor------------------------------------
    // Description: The destructor deletes this polynomial and frees the memory
    // that was dynamically allocated to this polynomial.
    //
    // Post: This polynomial does not exist, and the memory that was dynamically
    // allocated is free.
    ~Poly();

    // ------------------------------operator + -----------------------------------
    // Description: The method operator+ overloads the operator +, adding this
    // polynomial, which is on the left hand side of the operator +, and the
    // polynomial on the right hand side.
    //
    // Post: Both polynomials do not change.
    //
    // Parameter: rhs, the polynomial on the right hand side.
    //
    // Return: A new polynomial that is the result of the addition.
    Poly operator+(const Poly& rhs) const;

    // ------------------------------operator - -----------------------------------
    // Description: The method operator- overloads the operator -, subtracting the
    // polynomial on the right hand side of the operator - from this polynomial,
    // which is on the left hand side.
    //
    // Post: Both polynomials do not change.
    //
    // Parameter: rhs, the polynomial on the right hand side.
    //
    // Return: A new polynomial that is the result of the subtraction.
    Poly operator-(const Poly& rhs) const;

    // ------------------------------operator * -----------------------------------
    // Description: The method operator* overloads the operator *, multiplying this
    // polynomial, which is on the left hand side of the operator *, by the
    // polynomial on the right hand side.
    //
    // Post: Both polynomials do not change.
    //
    // Parameter: rhs, which is the polynomial on the right hand side.
    //
    // Return: A new polynomial that is the result of the multiplication.
    Poly operator*(const Poly& rhs) const;

    // ------------------------------operator = -----------------------------------
    // Description: The method operator= overloads the operator =, assigning the
    // given polynomial, which is on the right hand side of the operator =, to this
    // polynomial, which is on the left hand side.
    //
    // Post: This polynomial becomes the same as the given polynomial.
    //
    // Parameter: rhs, which is the polynomial on the right hand side.
    //
    // Return: A reference to this polynomial.
    Poly& operator=(const Poly& rhs);

    // ------------------------------operator += ----------------------------------
    // Description: The method operator+= overloads the operator +=, adding this
    // polynomial, which is on the left hand side of the operator +=, and the
    // polynomial on the right hand side.
    //
    // Post: This polynomial becomes the result of the addition.
    //
    // Parameter: rhs, which is the polynomial on the right hand side.
    //
    // Return: A reference to this polynomial.
    Poly& operator+=(const Poly& rhs);

    // ------------------------------operator -= ----------------------------------
    // Description: The method operator-= overloads the operator -=, subtracting
    // the polynomial on the right hand side of the operator -= from this
    // polynomial, which is on the left hand side.
    //
    // Post: This polynomial becomes the result of the subtraction.
    //
    // Parameter: rhs, which is the polynomial on the right hand side.
    //
    // Return: A reference to this polynomial.
    Poly& operator-=(const Poly& rhs);

    // ------------------------------operator *= ----------------------------------
    // Description: The method operator*= overloads the operator *=, multiplying
    // this polynomial, which is on the left hand side of the operator *=, by the
    // polynomial on the right hand side.
    //
    // Post: This polynomial becomes the result of the multiplication.
    //
    // Parameter: rhs, which is the polynomial on the right hand side.
    //
    // Return: A reference to this polynomial.
    Poly& operator*=(const Poly& rhs);

    // ------------------------------operator == ----------------------------------
    // Description: The method operator== overloads the operator ==, reporting
    // whether this polynomial, which is on the left hand side of the operator==,
    // is the same as the polynomial on the right hand side.
    //
    // Post: Both polynomials do not change.
    //
    // Parameter: rhs, the polynomial on the right hand side.
    //
    // Return: True if the two polynomials are the same; false otherwise.
    bool operator==(const Poly& rhs) const;

    // ------------------------------operator != ----------------------------------
    // Description: The method operator!= overloads the operator !=, reporting
    // whether this polynomial, which is on the left hand side of the operator==,
    // is the same as the polynomial on the right hand side.
    //
    // Post: Both polynomials do not change.
    //
    // Parameter: rhs, the polynomial on the right hand side.
    //
    // Return: True if the two polynomials are different; false otherwise.
    bool operator!=(const Poly& rhs) const;

    // ------------------------------operator << ----------------------------------
    // Description: The method operator<< overloads the operator <<, writing a
    // polynomial, which is on the right hand side of the operator <<, through an
    // ostream object, which is on the left hand side.
    //
    // Post: The polynomial does not change.
    //
    // Parameter: lhs, which is the ostream object.
    //
    // Parameter: rhs, which is the polynomial to write.
    //
    // Return: A reference to the ostream object.
    friend std::ostream& operator<<(std::ostream& lhs, const Poly& rhs);

    // --------------------------------getCoeff------------------------------------
    // Description: The method getCoeff returns the coefficient of the given power.
    //
    // Pre: The given power cannot be negative or be greater than the degree of
    // of this polynomial.
    //
    // Post: This method returns the coefficient of the given power. If the integer
    // parameter that specifies the power is negative or is greater than the degree
    // of this polynomial, this method returns zero.
    //
    // Parameter: power, which is the power whose coefficient should be returned.
    //
    // Return: An integer that is the coefficient of the given power.
    int getCoeff(int power) const;

    // ------------------------------operator >> ----------------------------------
    // Description: The method operator>> overloads the operator >>, changing a
    // polynomial, which is on the right hand side of the operator >>, based on the
    // pairs of integers that are inputted through an istream object, which is on 
    // the left hand side. The first integer in a pair specifies a new coefficient
    // and the second integer in a pair specifies the power whose coefficient is to
    // be changed to the new one.
    //
    // Pre: The integers that are inputted through the istream object must be in
    // pairs. The last pair of integers in the input must be -1 -1. Except the
    // last pair, the second integer in any other pairs cannot be negative.
    // Finally, the integers in the input must be separated by white spaces or
    // next line characters.
    //
    // Post: The polynomial is changed based on the input. If the integers that are
    // inputed are not in pairs, this method will wait for more input. If the last
    // pair of integers in the input is not -1 -1, this method will also wait for
    // more input. If a pair that is not the last pair specifies a negative power
    // (the second integer is negative), this method will ignore the pair.
    //
    // Parameter: lhs, which is the istream object.
    //
    // Parameter: rhs, which is the polynomial to change.
    //
    // Return: A reference to the istream object.
    friend std::istream& operator>>(std::istream& lhs, Poly& rhs);

    // --------------------------------setCoeff------------------------------------
    // Description: The method setCoeff sets the coefficient of the given power to
    // the given integer.
    //
    // Pre: The given power cannot be negative.
    //
    // Post: The coefficient of the given power becomes the given integer. If the
    // given power is negative, this method does nothing.
    //
    // Parameter: coefficient, which is the new coefficient of the given power.
    //
    // Parameter: power, which is the power that should have the new coefficient.
    void setCoeff(int coefficient, int power);
};