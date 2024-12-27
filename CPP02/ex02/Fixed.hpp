#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int _value;
		static const int _bits = 8;
	public:
		// Constructors
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed(int value);
		Fixed(float value);

		// Operators overload
		Fixed&	operator=(const Fixed &fixed);
		bool	operator>(const Fixed &fixed) const;
		bool	operator<(const Fixed &fixed) const;
		bool	operator>=(const Fixed &fixed) const;
		bool	operator<=(const Fixed &fixed) const;
		bool	operator==(const Fixed &fixed) const;
		bool	operator!=(const Fixed &fixed) const;

		Fixed	operator+(const Fixed &fixed) const;
		Fixed	operator-(const Fixed &fixed) const;
		Fixed	operator*(const Fixed &fixed) const;
		Fixed	operator/(const Fixed &fixed) const;

		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);

		friend std::ostream& operator<<(std::ostream &os, const Fixed &fixed);

		// Destructor
		~Fixed();

		// Getter and setter
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		// Converters
		int		toInt(void) const;
		float	toFloat(void) const;

		// Static functions
		static Fixed&		min(Fixed &a, Fixed &b);
		static Fixed&		max(Fixed &a, Fixed &b);
		static const Fixed&	min(const Fixed &a, const Fixed &b);
		static const Fixed&	max(const Fixed &a, const Fixed &b);
};

#endif