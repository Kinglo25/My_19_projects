#include "Form.hpp"

// ----------------------------- Constructors ------------------------------ //
Form::Form() : _name(""), _signed(false), _grade_sign(1), _grade_exec(1)
{
	_FORM_AUTO(32, "Default Constructor");
}

Form::Form(const Form& c) 
		: _name(c._name), _signed(false), _grade_sign(c.get__grade_sign()), _grade_exec(c.get__grade_exec())
{
	_FORM_AUTO(32, "Copy Constructor");
	*this = c;
}

Form::Form(std::string in__name, int in__grade_sign, int in__grade_exec) 
			: _name(in__name), _signed(false), _grade_sign(in__grade_sign), _grade_exec(in__grade_exec)
{
	_FORM_AUTO(32, "Fields Constructor");
}

// ------------------------------ Destructor ------------------------------- //
Form::~Form()
{
	_FORM_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

Form & Form::operator=(const Form& c)
{
	_FORM_AUTO(32, "Copy Assignement Operator");
	_signed = c.get__signed();
	return *this;
}

std::ostream &operator<<(std::ostream &o, const Form &in)
{
	return (o	<< in.get__name()
				<< " is signed: " << in.get__signed() << std::endl
				<< "Form grade sign: " << in.get__grade_sign() << std::endl
				<< "Form grade exec: " << in.get__grade_exec()) << std::endl;
}

// --------------------------- Getters && Setters -------------------------- //

const std::string Form::get__name() const{ return _name; }

bool Form::get__signed() const{ return _signed; }

int Form::get__grade_sign() const{ return _grade_sign; }

int Form::get__grade_exec() const{ return _grade_exec; }


// --------------------------------- Methods ------------------------------- //

void Form::beSigned(Bureaucrat &in)
{
	if (in.get__grade() > MIN_GRADE)
	{
		throw Form::GradeTooLowException();
	}
	if (in.get__grade() < MAX_GRADE)
	{
		throw Form::GradeTooHighException();
	}
	if (in.get__grade() <= _grade_sign)
	{
		_signed = true;
	}
	else
	{
		throw Form::GradeTooLowException();
	}
}
