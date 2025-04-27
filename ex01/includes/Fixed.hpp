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

    friend std::ostream& operator<<(std::ostream &out, const Fixed &ref);

};


#endif // !__FIXED_HPP__
