
#include <string>
#include "Card_index.h"
#include <fstream>

using namespace  std;

const char* strCategory[] =
        {

        "PROSE", "POESY" , "SCIENCE" ,"UNDEF"

        };

CARD_INDEX* LibraryOFBooks()
{
	auto* Card = new CARD_INDEX;

	Card->pB = new BOOK[Card->capacity];

	Card->count = 0;

	return Card;

}

void AddBook(CARD_INDEX*& pCard)
{
	if (pCard->count == pCard->capacity)
    {
		pCard->capacity += 5;

		BOOK* NewArr = new BOOK[pCard->capacity];

		std::copy(pCard->pB, pCard->pB + pCard->count, NewArr);
		
		delete[] pCard->pB;

		pCard->pB = NewArr;
	}

	FillBook(&pCard->pB[pCard->count]);

	pCard->count++;
	std::cout << "Should I add another book? yes or no?\n";
	std::cout << std::endl;
	string answer;
	cin >> answer;
	if (answer == "yes" || answer == "YES" || answer == "Yes")
    {
		Custom_sleep();

		cout << "\033[2J\033[1;1H";

		AddBook(pCard);
	}
	else
    {
		std::cout << "Back to the menu....\n";

		Custom_sleep();

		cout << "\033[2J\033[1;1H";

		Menu(pCard);
	}
}

void DeleteBook(CARD_INDEX* pCard)
{

	if (pCard->count == 0)
    {
        std::cout << "Your file cabinet is empty, there is nothing to delete\n";

        std::cout << "Back to the menu....\n";

		Custom_sleep();

		cout << "\033[2J\033[1;1H";

		Menu(pCard);
        return;
	}

	string AllBooks;
	std::cout << "Do you want to delete all books? yes or no?\n";
	std::cin >> AllBooks;
	if (AllBooks == "Yes" || AllBooks == "yes" || AllBooks == "YES" )
    {
		pCard->count = 0;

        std::cout << "You deleted all the books\n";

        std::cout << "Back to the menu....\n";

		Custom_sleep();

		cout << "\033[2J\033[1;1H";

		Menu(pCard);
	}

	else
    {
        bool Right = false;
        int NumberBook;
        std::cout << "Enter the number of the book you want to delete\n";
        do
        {
            std::cin >> NumberBook;
            if (std::cin.fail())
            {
                std::cout << "Enter the number of the book you want to delete\n";
                std::cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

            }
            else if (NumberBook < 1 || NumberBook > pCard->count)
            {
                std::cout << "Error you don't have such an account book\n";

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
            Right = true;
             }

    } while (!Right);

		if (NumberBook > 0)
        {
			NumberBook -= 1;
		}
		if (pCard->count != 1)
        {
			for (int i = NumberBook; i < pCard->count - 1; ++i)
            {
				pCard->pB[i] = pCard->pB[i + 1];
			}
		}
		pCard->count--;
        std::cout << "You deleted book number: \n" << NumberBook + 1 << std::endl;
		if (pCard->count != 0)
        {
            std::cout << "Delete another book? yes or no?\n";
			std::cout << std::endl;
			string Answer_;
			cin >> Answer_;
			if (Answer_ == "Yes" || Answer_ == "yes" || Answer_ == "YES")
            {
				DeleteBook(pCard);
			}
			else
            {
                std::cout << "Back to the menu....\n";
				Custom_sleep();
				cout << "\033[2J\033[1;1H";
				Menu(pCard);
			}
		}
		else
        {
            std::cout << "Back to the menu....\n";
			Custom_sleep();
			cout << "\033[2J\033[1;1H";
			Menu(pCard);
		}
	}
}

void PrintBook(BOOK* ptr)
{
    std::cout << "Author of the book: \n";
    std::cout << ptr->author;
    std::cout << std::endl;
    std::cout << "Book title: \n";
    std::cout << ptr->name;
    std::cout << std::endl;
    std::cout << "Year of publication of the book: \n";
    std::cout << ptr->year;
    std::cout << std::endl;
    std::cout << "The cost of the book in rubles: \n";
    std::cout << ptr->price;
    std::cout << std::endl;
    std::cout << "Book type: \n";
	if (ptr->category == PROSE)
    {
		std::cout << strCategory[0];
	}

	else if (ptr->category == POETRY)
    {
		std::cout << strCategory[1];
	}

	else if (ptr->category == SCIENCE)
    {
		std::cout << strCategory[2];
	}

	else if (ptr->category == UNDEF)
    {
		std::cout << strCategory[3];
	}
}

void PrintLibrary(CARD_INDEX* ptr)
{
	if (ptr->count == 0)
    {
        std::cout << "You have an empty file of books\n";
        std::cout << "Back to the menu....\n";
		Custom_sleep();
		cout << "\033[2J\033[1;1H";
		Menu(ptr);
	}
	else
    {
		for (int i = 0; i < ptr->count; i++)
        {

			std::cout << "Book № " << i + 1 << "\n";

			PrintBook(&ptr->pB[i]);

			std::cout << std::endl << std::endl;

		}
		std::cout << "Go back to the menu? yes or no?\n";
		std::cout << std::endl;
		string _Answer;
		cin >> _Answer;
		if (_Answer == "yes" ||_Answer == "Yes" || _Answer == "YES" )
        {
			std::cout << "Back to the menu....\n";
			Custom_sleep();
			cout << "\033[2J\033[1;1H";
			Menu(ptr);
		}
		else
        {
			DeleteLibrary(ptr);
			return;
		}
	}
}


void ReadFromFile(CARD_INDEX* ptr)
{
    std::cout << "Specify the path where the file is located\n";
	string WayOfFile;
	std::cin >> WayOfFile;
    if (!(WayOfFile.ends_with(".txt") || WayOfFile.ends_with(".md")))
    {
        std::cout << "Your file extension should be .txt or .md\n";
        std::cout << "Back to the menu....\n";
        Custom_sleep();
        std::cout << "\033[2J\033[1;1H";
        Menu(ptr);
        return;
    }

    std::ifstream file(WayOfFile);
    if (!file.is_open())
    {
        std::cout << "Error, the file did not open, check the data: " << WayOfFile << std::endl;
        std::cout << "Back to the menu....\n";
        Custom_sleep();
        std::cout << "\033[2J\033[1;1H";
        Menu(ptr);
        return;
    }

    file.seekg(0, std::ios::end);
    std::streamsize fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    if (fileSize == 0)
    {
        std::cout << "Your file is empty...\n";
        file.close();
        Custom_sleep();
        std::cout << "\033[2J\033[1;1H";
        Menu(ptr);
        return;
    }

    std::cout << "The file has been opened successfully, we are reading information from the file.... \n";
		int count;
		file >> count;
		while (count)
        {
			BOOK NewBook;

			file.ignore(1);
			file.getline(NewBook.author, 40);
			file.getline(NewBook.name, 80);
			file >> NewBook.year;
			file >> NewBook.price;
			string categoryStr;
			file >> categoryStr;

			if (categoryStr == strCategory[0])
            {
                NewBook.category = PROSE;
			}

			else if (categoryStr == strCategory[1])
            {
                NewBook.category = POETRY;
			}

			else if (categoryStr == strCategory[2])
            {
                NewBook.category = SCIENCE;
			}

			else
            {
                NewBook.category = UNDEF;
			}

			if (ptr->count == ptr->capacity)
			{
				Resize(ptr);
			}

			ptr->pB[ptr->count++] = NewBook;
			count--;
		}

		file.close();


    std::cout << "Back to the menu....\n";
	Custom_sleep();
	cout << "\033[2J\033[1;1H";
	Menu(ptr);

}
void WriteToFile(CARD_INDEX* ptr)
{
	if (ptr->count == 0)
    {
        std::cout << "Oops, your file cabinet is empty, there is nothing to write to the file\n";
        std::cout << "Back to the menu....\n";
		Custom_sleep();
		cout << "\033[2J\033[1;1H";
		Menu(ptr);
        return;
	}

    std::cout << "Specify the path where the file is located \n";
	string WayOfFile;
	std::cin >> WayOfFile;
	std::ofstream file(WayOfFile, std::ofstream::binary);

	if (WayOfFile.ends_with(".txt") || WayOfFile.ends_with(".md"))
    {
        std::cout << "The file extension is suitable for writing)\n";
	}
	else
    {
        std::cout << "Your file extension should be .txt or .md\n";
        std::cout << "Back to the menu....\n";
		Custom_sleep();
		cout << "\033[2J\033[1;1H";
		Menu(ptr);
        return;
	}


		std::cout << "The file has been opened successfully, check it\n";

		file << ptr->count << "\n";
		for (int i = 0; i < ptr->count; i++)
        {

			BOOK* current = &(ptr->pB[i]);

			file << current->author << "\n";
			file << current->name << "\n";
			file << current->year << "\n";
			file << current->price << "\n";

			if (current->category == PROSE)
            {
				file << strCategory[0];
			}

			else if (current->category == POETRY)
            {
				file << strCategory[1];
			}

			else if (current->category == SCIENCE)

            {
				file << strCategory[2];
			}

			else if (current->category == UNDEF)
            {
				file << strCategory[3];
			}

			file << '\n';

		}

		file.close();

        std::cout << "Back to the menu....\n";

		Custom_sleep();

		cout << "\033[2J\033[1;1H";

		Menu(ptr);

}

void Menu(CARD_INDEX* ptr)
{
    std::cout << "Hi, there's a menu in front of you, choose what you want to do :)\n";
    std::cout << "Print the contents of the file cabinet (1)\n";
    std::cout << "Enter a new book (2) \n";
    std::cout << "Delete an existing one(s) (3)\n";
    std::cout << "Write the current contents of the card file to a file (4)\n";
    std::cout << "Read the contents from the file to the card file (5)\n";
    std::cout << "Exit the program (6)\n";
    std::cout << "There are so many books in your file: " << ptr->count << std::endl;
	size_t number = ptr->capacity - ptr->count;
	std::cout << "Reserve: " << number << std::endl;
	int num;
	bool InputNum = false;
	std::cin >> num;
	while (!InputNum)

    {
		if (std::cin.fail() || num <= 0 || num > 6)
        {
			InputNum = false;
            std::cout << "Oops, it looks like you entered a wrong number or there is no such number, let's try again!!\n";
			std::cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            std::cin >> num;
		}
		else
        {
			InputNum = true;
		}
	}
	switch (num)

    {

	case 1: PrintLibrary(ptr); break;

	case 2: AddBook(ptr);  break;

	case 3: DeleteBook(ptr); break;

	case 4: WriteToFile(ptr); break;

	case 5: ReadFromFile(ptr); break;

	case 6: std::cout << "You have logged out of the program\n";  DeleteLibrary(ptr); return; break;

	default: std::cout << "Unknown error, try again)\n"; break;

	}

}

void DeleteLibrary(CARD_INDEX*& ptr)
{

	delete[] ptr->pB;

	delete ptr;

	ptr = nullptr;

}

void Resize(CARD_INDEX* pCard)
{
	pCard->capacity += 5;

	BOOK* NeWArr = new BOOK[pCard->capacity];

	std::copy(pCard->pB, pCard->pB + pCard->count, NeWArr);

	delete[] pCard->pB;

	pCard->pB = NeWArr;

}
