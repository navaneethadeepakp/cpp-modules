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

		Fixed operator+(const Fixed &otherobject) const;
		Fixed operator-(const Fixed &otherobject) const;
		Fixed operator*(const Fixed &otherobject) const;
		Fixed operator/(const Fixed &otherobject) const;

		bool operator>(const Fixed &otherobject) const;
		bool operator<(const Fixed &otherobject) const;
		bool operator>=(const Fixed &otherobject) const;
		bool operator<=(const Fixed &otherobject) const;
		bool operator==(const Fixed &otherobject) const;
		bool operator!=(const Fixed &otherobject) const;

		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);

		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);

		static const Fixed &min(const Fixed &a, const Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
