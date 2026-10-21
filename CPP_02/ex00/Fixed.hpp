#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
    private:
        int fixedPointVal;
        static const int fractBits = 8;

    public:
        Fixed();
        Fixed(const Fixed &original);
        Fixed &operator = (const Fixed &original);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif