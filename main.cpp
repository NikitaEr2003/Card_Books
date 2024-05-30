#include <iostream>
#include "Card_index.h"
#include <fstream>

using namespace std;

int main() {

	
	CARD_INDEX* ptr = LibraryOFBooks();

	Menu(ptr);
	
	return 0;

}