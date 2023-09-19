#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("unknown"), _grade(1)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string name): _name(name), _grade(1)
{
	std::cout << "Bureaucrat constructor called with name parameter" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	std::cout << "Bureaucrat constructor called with all parameters" << std::endl;
	if (grade > MIN_GRADE)
		throw GradeTooLowException();
	else if (grade < MAX_GRADE)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
	*this = obj;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
	return ;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &obj)
{
	if (this != &obj)
	{
		this->_name = obj._name;
		this->_grade = obj._grade;
	}
	return (*this);
}

void	Bureaucrat::setGrade(int grade)
{
	this->_grade = grade;
	if (grade > MIN_GRADE)
		throw GradeTooLowException();
	else if (grade < MAX_GRADE)
		throw GradeTooHighException();
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int			Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Le grade du bureaucrate est trop bas");
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Le grade du bureaucrate est trop haut");
}

std::ostream&	operator<<(std::ostream &out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat of grade " << bureaucrat.getGrade() << std::endl;
	return (out);
}
