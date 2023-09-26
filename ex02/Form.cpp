#include "Form.hpp"

Form::Form(void): _name("unknown"), _signed(0), _gradeSign(1), _gradeExec(1)
{
	std::cout << "Form default constructor called" << std::endl;
	return ;
}

Form::Form(std::string name, int gradeSign, int gradeExec): _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (gradeSign > MIN_GRADE || gradeExec > MIN_GRADE)
		throw GradeTooLowException();
	else if (gradeSign < MAX_GRADE || gradeExec < MAX_GRADE)
		throw GradeTooHighException();
}

Form::Form(const Form &obj): _name(obj._name), _signed(obj._signed), _gradeSign(obj._gradeSign), _gradeExec(obj._gradeExec)
{
	std::cout << "Form copy constructor called" << std::endl;
	return ;
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
	return ;
}

Form&	Form::operator=(const Form &obj)
{
	if (this != &obj) {}
	return (*this);
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getSigned(void) const
{
	return (this->_signed);
}

int	Form::getGradeSign(void) const
{
	return (this->_gradeSign);
}

int	Form::getGradeExec(void) const
{
	return (this->_gradeExec);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_signed)
		throw AlreadySignedException();
	else if (bureaucrat.getGrade() <= this->_gradeSign)
		this->_signed = 1;
	else
		throw GradeTooLowException();
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Le grade est trop bas");
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Le grade est trop haut");
}

const char	*Form::AlreadySignedException::what() const throw()
{
	return ("Le formulaire est deja signe");
}

std::ostream&	operator<<(std::ostream &out, const Form& form)
{
	if (form.getSigned())
		out << form.getName() << ", formulaire avec le grade de signature " << form.getGradeSign() << " et avec le grade d'execution " << form.getGradeExec() << ", est signe." << std::endl;
	else
		out << form.getName() << ", formulaire avec le grade de signature " << form.getGradeSign() << " et avec le grade d'execution " << form.getGradeExec() << ", n'est pas signe." << std::endl;
	return (out);
}
