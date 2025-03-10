#pragma once

#define LEN 50

typedef struct {
    char title[LEN];
    char author[LEN];
    int year;
} Book;

typedef struct {
    Book* books;
    int count;
} Library;

void loadBooksFromFile(Library* lib, const char* filename);
void addBook(Library* lib, const Book* book);


void sortLibraryByYear(Library* lib);
