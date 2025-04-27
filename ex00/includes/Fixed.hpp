#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <cstdio>

class Fixed
{
	private:
		int _fpValue;
		static const int _fract_bits = '8';
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const  &ref);
		Fixed &operator=(const Fixed &other);
		int getRawBits(void)const;
		void setRawBits(int const raw);

};


#endif // !__FIXED_HPP__
