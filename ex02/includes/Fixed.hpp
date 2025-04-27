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


    Fixed operator++(); // Prexif operator
    Fixed operator--();
    Fixed operator++(int); // Postfix operator
    Fixed operator--(int);

    static int& min(int &fp_num0,int &fp_num1);
    static int& min(const int &fp_num0,const int &fp_num1);
    static int& max(int &fp_num0,int &fp_num1);
    static int& max(const int &fp_num0,const int &fp_num1);
};


#endif // !__FIXED_HPP__
