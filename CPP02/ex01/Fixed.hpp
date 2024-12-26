#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int _value;
		static const int _bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed(int value);
		Fixed(float value);

		Fixed&	operator=(const Fixed &fixed);
		friend std::ostream& operator<<(std::ostream &os, const Fixed &fixed);
		
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		int		toInt(void) const;
		float	toFloat(void) const;
};

#endif