#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	bur("bur", 42);
	std::cout << bur;

	try
	{
		Form	formulaire("formulaire", 1000, 1);
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	try
	{
		Form	formulaire("formulaire", 42, 0);
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	try
	{
		Form	formul("formul", 42, 42);
		Form	formulai("formulai", 1, 1);

		std::cout << std::endl << formul << formulai;

		bur.signForm(formul);
		std::cout << formul;
		bur.signForm(formul);

		bur.signForm(formulai);
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}
