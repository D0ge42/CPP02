#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <cstdio>
#include <iostream>

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

    // Overload operator (a friend class can access private/protected member of other classes)
    friend std::ostream& operator<<(std::ostream &out, const Fixed &ref);

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


#endif // !__FIXED_HPP__
