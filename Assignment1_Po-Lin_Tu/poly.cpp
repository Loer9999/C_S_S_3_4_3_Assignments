#include <iostream>
#include "poly.h"

// -------------------------------- poly.cpp ----------------------------------
// Programmer Name: Po-Lin Tu  Course Section Number: CSS 343 B
// Creation Date: 3/28/2022
// Date of Last Modification: 4/2/2022
//
// Purpose: This file is the implementation file of the Poly class that
// represents a polynomial. The Poly class stores a polynomial and supports the
// addition operator, the subtraction operator, the multiplication operator,
// the assignment operator, the equality operator, and the inequality operator.
// These operators act on two instances of the Poly class. The Poly class also
// supports accessors and mutators that change or display the entire polynomial
// or a certain coefficient of the polynomial.
//
// Note: The polynomial that the Poly class represents cannot have negative
// exponents.
// ----------------------------------------------------------------------------


// ---------------------------Default Constructor------------------------------
// Description: The default constructor creates a zero polynomial.
//
// Post: A zero polynomial exists.
Poly::Poly() : poly(new int[1]), max(1)
{
    poly[0] = 0;
} // end of the default constructor

// ------------------------Parametrized Constructor----------------------------
// Description: This parametrized constructor creates a polynomial whose degree
// is zero and coefficient is the given integer.
//
// Post: A polynomial whose degree is zero and coefficient is the given integer
// exists.
//
// Parameter: coefficient, which is the coefficient of the polynomial to
// create.
Poly::Poly(int coefficient) : poly(new int[1]), max(1)
{
    poly[0] = coefficient;
} // end of this parametrized constructor

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
Poly::Poly(int coefficient, int degree)
{
    // Set the negative degree to zero.
    if (degree < 0)
    {
        degree = 0;
    }
    poly = new int[degree + 1];
    poly[degree] = coefficient;
    max = degree + 1;

    // Set the other elements of the block of memory to zero.
    for (int i = 0; i < degree; i++)
    {
        poly[i] = 0;
    }
} // end of this parametrized constructor

// ----------------------------Copy Constructor--------------------------------
// Description: The copy constructor creates a polynomial that is the same as
// the given polynomial.
//
// Post: A polynomial that is the same as the given polynomial exists.
//
// Parameter: other, which is another polynomial that this polynomial copies.
Poly::Poly(const Poly& other) : poly(new int[other.max]), max(other.max)
{
    operator=(other);
} // end of the copy constructor

// ------------------------------Destructor------------------------------------
// Description: The destructor deletes this polynomial and frees the memory
// that was dynamically allocated to this polynomial.
//
// Post: This polynomial does not exist, and the memory that was dynamically
// allocated is free.
Poly::~Poly()
{
    delete[] poly;
    poly = nullptr;
} // end of the destructor

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
Poly Poly::operator+(const Poly& rhs) const
{
    if (max >= rhs.max)
    {
        // Make the result be this polynomial.
        Poly result = *this;

        // Perform the addition.
        for (int i = 0; i < rhs.max; i++)
        {
            result.poly[i] += rhs.poly[i];
        }
        return result;
    }
    else
    {
        // Make the result be the polynomial on the right hand side since it is
        // larger.
        Poly result = rhs;

        // Perform the addition.
        for (int i = 0; i < max; i++)
        {
            result.poly[i] += poly[i];
        }
        return result;
    }
} // end of the method operator+

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
Poly Poly::operator-(const Poly& rhs) const
{
    if (max >= rhs.max)
    {
        // Make the result be this polynomial.
        Poly result = *this;

        // Perform the subtraction.
        for (int i = 0; i < rhs.max; i++)
        {
            result.poly[i] -= rhs.poly[i];
        }
        return result;
    }
    else
    {
        // Make the result be the polynomial on the right hand side since it is
        // larger.
        Poly result = rhs;

        // Perform the subtraction.
        for (int i = 0; i < max; i++)
        {
            result.poly[i] = poly[i] - result.poly[i];
        }
        for (int i = max; i < rhs.max; i++)
        {
            result.poly[i] = -result.poly[i];
        }
        return result;
    }
} // end of the method operator-

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
Poly Poly::operator*(const Poly& rhs) const
{
    // Dynamically allocate memory for the result.
    Poly result(0, (max - 1) + (rhs.max - 1));
    
    // Perform the multiplication.
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < rhs.max; j++)
        {
            result.poly[i + j] += poly[i] * rhs.poly[j];
        }
    }
    return result;
} // end of the method operator*

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
Poly& Poly::operator=(const Poly& rhs)
{
    if (max < rhs.max)
    {
        // Free the original block of memory and dynamically allocate a new
        // block of memory that has the size of the memory that stores the
        // right-hand-side polynomial.
        delete[] poly;
        poly = new int[rhs.max];
        max = rhs.max;
    }

    // Copy the right-hand-side polynomial.
    for (int i = 0; i < rhs.max; i++)
    {
        poly[i] = rhs.poly[i];
    }

    for (int i = rhs.max; i < max; i++)
    {
        poly[i] = 0;
    }

    return *this;
} // end of the method operator=

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
Poly& Poly::operator+=(const Poly& rhs)
{
    if (max >= rhs.max)
    {
        // Perform the addition.
        for (int i = 0; i < rhs.max; i++)
        {
            poly[i] += rhs.poly[i];
        }
    }
    else
    {
        // Dynamically allocate a larger block of memory to this polynomial.
        setCoeff(0, rhs.max - 1);

        // Perform the addition.
        for (int i = 0; i < max; i++)
        {
            poly[i] += rhs.poly[i];
        }
    }
    return *this;
} // end of the method operator+=

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
Poly& Poly::operator-=(const Poly& rhs)
{
    if (max >= rhs.max)
    {
        // Perform the subtraction.
        for (int i = 0; i < rhs.max; i++)
        {
            poly[i] -= rhs.poly[i];
        }
    }
    else
    {
        // Dynamically allocate a larger block of memory to this polynomial.
        setCoeff(0, rhs.max - 1);

        // Perform the subtraction.
        for (int i = 0; i < max; i++)
        {
            poly[i] -= rhs.poly[i];
        }
    }
    return *this;
} // end of the method operator-=

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
Poly& Poly::operator*=(const Poly& rhs)
{
    operator=(operator*(rhs));
    return *this;
} // end of the method operator*=

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
bool Poly::operator==(const Poly& rhs) const
{
    if (max >= rhs.max)
    {
        // Return false if the two polynomials have different coefficients for
        // the same power.
        for (int i = 0; i < rhs.max; i++)
        {
            if (poly[i] != rhs.poly[i])
            {
                return false;
            }
        }
        for (int i = rhs.max; i < max; i++)
        {
            if (poly[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        // Return false if the two polynomials have different coefficients for
        // the same power.
        for (int i = 0; i < max; i++)
        {
            if (poly[i] != rhs.poly[i])
            {
                return false;
            }
        }
        for (int i = max; i < rhs.max; i++)
        {
            if (rhs.poly[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
} // end of the method operator==

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
bool Poly::operator!=(const Poly& rhs) const
{
    return !operator==(rhs);
} // end of the method operator!=

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
std::ostream& operator<<(std::ostream& lhs, const Poly& rhs)
{
    bool isZero = true;
    int index = rhs.max - 1;

    // Write every term in this polynomial except the terms with whose powers
    // are less than two.
    for (index; index > 1; index--)
    {
        int coefficient = rhs.poly[index];
        if (coefficient > 0)
        {
            lhs << " +" << coefficient << "x^" << index;
            isZero = false;
        }
        else if (coefficient < 0)
        {
            lhs << " " << coefficient << "x^" << index;
            isZero = false;
        }
    }

    // Write the term whose power is one.
    if (index == 1)
    {
        int coefficient = rhs.poly[index];
        if (coefficient > 0)
        {
            lhs << " +" << coefficient << "x";
            isZero = false;
        }
        else if (coefficient < 0)
        {
            lhs << " " << coefficient << "x";
            isZero = false;
        }
        index--;
    }

    // Write the term whose power is zero.
    if (index == 0)
    {
        int coefficient = rhs.poly[index];
        if (coefficient > 0)
        {
            lhs << " +" << coefficient;
            isZero = false;
        }
        else if (coefficient < 0)
        {
            lhs << " " << coefficient;
            isZero = false;
        }
    }

    if (isZero)
    {
        lhs << "0";
    }
    return lhs;
} // end of the method operator<<

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
int Poly::getCoeff(int power) const
{
    if (power < 0 || power >= max)
    {
        return 0;
    }
    else
    {
        return poly[power];
    }
} // end of the method getCoeff

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
std::istream& operator>>(std::istream& lhs, Poly& rhs)
{
    int coefficient, power;
    lhs >> coefficient >> power;

    // Change the coefficients of this polynomial.
    while (coefficient != -1 || power != -1)
    {
        rhs.setCoeff(coefficient, power);
        lhs >> coefficient >> power;
    }
    return lhs;
} // end of the method operator>>

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
void Poly::setCoeff(int coefficient, int power)
{
    // Dynamically allocate a new block of memory if the given power is greater
    // than the maximum power of this polynomial.
    if (power >= max)
    {
        int* previousPoly = poly;
        int previousMax = max;
        poly = new int[power + 1];
        max = power + 1;

        for (int i = 0; i < previousMax; i++)
        {
            poly[i] = previousPoly[i];
        }
        delete[] previousPoly;
        previousPoly = nullptr;

        for (int i = previousMax; i < max; i++)
        {
            poly[i] = 0;
        }
    }

    if (power >= 0)
    {
        poly[power] = coefficient;
    }
} // end of the method setCoeff