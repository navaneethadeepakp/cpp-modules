#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int fixedPointVal;
        static const int fractBits = 8;

    public:
        Fixed();
		Fixed(const int n);
		Fixed(const float f);
        Fixed(const Fixed &original);
        Fixed &operator = (const Fixed &original);
        ~Fixed();


		int toInt(void) const;
		float toFloat(void) const;

        int getRawBits(void) const;
        void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif