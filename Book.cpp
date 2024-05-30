
#include "Book.h"
void FillBook(BOOK* book)
{
    std::cout << "Enter the author of the book 30 characters\n";
	std::cin.ignore(1);
	std::cin.getline(book->author, 30);
    std::cout << "Enter the title of the book 80 characters\n";
	std::cin.getline(book->name, 80);
    std::cout << "Enter the year of publication of the book\n";
	std::cin >> book->year;
	bool InputNum = false;
	while (!InputNum )
    {
		if (std::cin.fail())
        {
			InputNum = false;
            std::cout << "Oops, it looks like you entered the wrong number, let's try again!!\n";
			std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cin >> book->year;
		}
		else {

			InputNum = true;
		}
	}
	std::cout << "Enter the cost of the book in rubles\n";
	std::cin >> book->price;
	bool InputNum_ = false;
	while (!InputNum_ )
    {
		if (std::cin.fail())
        {
			InputNum_ = false;
            std::cout << "Oops, it looks like you entered the wrong number, let's try again!!\n";
			std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> book->price;
		}
		else {

			InputNum_ = true;

		}
	}
    std::cout << "Enter the book type PROSE(0), POETRY(1), SCIENCE(2), UNDEF(3) \n";
	int num;
	std::cin >> num;
	switch (num) {
	case 0:
		book->category = PROSE;
		break;
	case 1:
		book->category = POETRY;
		break;
	case 2:
		book->category = SCIENCE;
		break;
	case 3:
		book->category = UNDEF;
		break;
	default:
		bool number = false;
		while (!number) {
            std::cout << "Looks like there is no such number\n";
            std::cout << "Enter book type PROSE(0), POETRY(1), SCIENCE(2), UNDEF(3) \n";
			std::cin >> num;
			if (num < 0 || num > 3)
            {
				number = false;
			}
			else
            {
				number = true;
			}
		}
	}
}

