#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

class Bureaucrat {

public:
	Bureaucrat(void);
	Bureaucrat(Bureaucrat &obj);
	~Bureaucrat(void);
	Bureaucrat	&operator=(Bureaucrat &obj);
	void		setName(std::string name);
	void		setGrade(int grade);
	std::string	getName(void) const;
	int		getGrade(void) const;

class GradeTooHighException : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return ("Le grade que tu transmets est trop haut");
	}
};

class GradeTooLowException : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return ("Le grade que tu transmets est trop bas");
	}
};

private:
	std::string	_name;
	int		_grade;


};

#endif
