#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <iostream>
# include <iomanip>
# include <string>
# include <fstream>
# include <cstdlib>
# include <stdexcept>
# include <cmath>
# include <ctgmath>

class Conversion
{
public:
	
	struct Impossible : public std::exception
    {
            const char *what() const throw()
			{
				return ("Impossible");
			}
    };
    struct NotDisplayable : public std::exception
    {
            const char *what() const throw()
			{
				return ("Not displayable");
			}
    };

// ----------------------------- Constructors ------------------------------ //
	Conversion();	// Default Constructor
	Conversion(std::string in_input);	// Fields Constructor
	Conversion(const Conversion& c);	// Copy Constructor

// ------------------------------ Destructor ------------------------------- //
	~Conversion();	// Destructor

// ------------------------------- Operators ------------------------------- //
	Conversion & operator=(const Conversion& a);
	// Copy Assignement Operator

// --------------------------- Getters && Setters -------------------------- //
	std::string get_input() const;
	void set_input(std::string input);
	

// --------------------------------- Methods ------------------------------- //

	int  is_okay(void) const;
    int  get_precision(void) const;
    void tochar(void) const;
    void toint(void) const;
    void tofloat(void) const;
    void todouble(void) const;

private:
	std::string input;

};

# ifndef NO_DEBUG

#  ifndef _ARG
#   define _ARG(arg) #arg << "(" << arg << ") "
#  endif /* _ARG */

#  define _CONVERSION_ARGS _ARG(input)
#  define _CONVERSION_AUTO(COLOR_CODE, TEXT) \
	std::cout << "{ \e[" << COLOR_CODE << ";1m"                 \
			  << TEXT << " " << __PRETTY_FUNCTION__ << "\e[0m " \
			  << "[\033[34;47m" << this                         \
			  << "\033[0m]\033[0m: " << _CONVERSION_ARGS  \
			  << "}" << std::endl;
# else

#  define _CONVERSION_AUTO(x, y) ;
#  define _CONVERSION_ARGS ""
#  define _ARG ""

# endif /* NO_DEBUG */

#endif /* CONVERSION_HPP */
