#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	test1("test1", 1);
		std::cout << test1;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	test2("test2", 0);
		std::cout << test2;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	test3("test3", 160);
		std::cout << test3;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}
