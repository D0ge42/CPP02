#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <cstdio>
#include <iostream>

/* Fixed point are a way to represent fractional numbers
 * in computers, where the position of the decimal part
 * is Fixed.
 * A certain amount of bits are always reserved for the integer
 * part and the other for the decimal.
 * Unlike floating point numbers, which can vary in precision
 * and introduce rounding errors, fixed points number mantain
 * a consistent level of precision.
 * An example could be the way money are represented.
 * Usually there are always two numbers after the decimal point
 * 42.42$ */

class Fixed
{
	private:

		int _fpValue;
		static const int _fract_bits = 8;

	public:

    // Constructors && Destructors
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(Fixed const  &ref);
		Fixed &operator=(const Fixed &other);
		~Fixed();

    // Getters && Setters
    int getRawBits(void)const;
		void setRawBits(int const raw);

    // Conversion methods
    float toFloat(void)const;
		int toInt(void)const;

    // Arithmetic operators
    float operator+(Fixed ref) const;
    float operator-(Fixed ref) const;
    float operator/(Fixed ref) const;
    float operator*(Fixed ref) const;

    // Comparison operators
    bool operator<(const Fixed &ref) const;
    bool operator>(const Fixed &ref) const;
    bool operator<=(const Fixed &ref) const;
    bool operator>=(const Fixed &ref) const;
    bool operator!=(const Fixed &ref) const;
    bool operator==(const Fixed &ref) const;

    // Pre/Post Fix operator
    Fixed operator++(); // PreFix operator
    Fixed operator--();
    Fixed operator++(int); // PostFix operator
    Fixed operator--(int);

    // Min/Max methods.

    static Fixed& min(Fixed &a,Fixed &b);
    static Fixed& max(Fixed &a, Fixed &b);
    const static Fixed& min(const Fixed &a,const Fixed &b);
    const static Fixed& max(const Fixed &a,const Fixed &b);
};

std::ostream& operator<<(std::ostream &out, const Fixed &ref);


#endif // !__FIXED_HPP__
