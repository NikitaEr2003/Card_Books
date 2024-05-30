

#ifndef CARD_INDEX_H
#define CARD_INDEX_H
#include "Custom_sleep.h"
#include <cstdlib>
#include "Book.h"


struct CARD_INDEX{

    size_t count = 0;

    size_t capacity= 1;

    BOOK *pB=nullptr;
};

CARD_INDEX* LibraryOFBooks();

void Menu(CARD_INDEX*ptr);

void PrintBook(BOOK*);

void PrintLibrary(CARD_INDEX *);

void ReadFromFile(CARD_INDEX*ptr);

void WriteToFile(CARD_INDEX*ptr);

void Resize(CARD_INDEX *pCard);

void AddBook(CARD_INDEX *&pCard);

void DeleteBook(CARD_INDEX *pCard);

void DeleteLibrary(CARD_INDEX *&ptr);

#endif 
