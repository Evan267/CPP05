#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include "Form.hpp"

# define MIN_GRADE 150
# define MAX_GRADE 1

class Form;

class Bureaucrat {

public:
	Bureaucrat(void);
	Bureaucrat(std::string name);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &obj);
	~Bureaucrat(void);
	Bureaucrat	&operator=(const Bureaucrat &obj);
	void		setGrade(int grade);
	std::string	getName(void) const;
	int			getGrade(void) const;
	void		signForm(Form &form) const;

	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};

private:
	std::string	_name;
	int			_grade;
};

std::ostream&	operator<<(std::ostream &o, const Bureaucrat& bureaucrat);

#endif
