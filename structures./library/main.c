#include <stdlib.h>
#include <stdio.h>
#include "test1.h"
#define MAX_BOOKS 100

void main(){
    Library lib;
    lib.books = malloc(MAX_BOOKS * sizeof(Book));
    lib.count = 0;
    
    loadBooksFromFile(&lib, "library.txt");
    
    sortLibraryByYear(&lib);
    
    
}
