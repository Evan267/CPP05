#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

public:

	Form(std::string name, int gradeSign, int gradeExec); 
	Form(const Form &obj);
	~Form(void);
	Form		&operator=(const Form &obj);
	std::string	getName(void) const;
	bool		getSigned(void) const;
	int			getGradeSign(void) const;
	int			getGradeExec(void) const;
	void		beSigned(const Bureaucrat &bureaucrat);

	class GradeTooHighException: public std::exception {
		virtual const char*	what() const throw();
	};

	class GradeTooLowException: public std::exception {
		virtual const char* what() const throw();
	};

	class AlreadySignedException: public std::exception {
		virtual const char* what() const throw();
	};

private:
	Form(void);
	std::string	_name;
	bool		_signed;
	const int	_gradeSign;
	const int	_gradeExec;

};

std::ostream&	operator<<(std::ostream &o, const Form& form);

#endif
