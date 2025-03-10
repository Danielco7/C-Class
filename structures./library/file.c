#include "test1.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_BOOKS 100




void addBook(Library* lib, const Book* book){
    lib->books[lib->count] = *book;
    lib->count++;
}

void loadBooksFromFile(Library* lib, const char* filename) {
    FILE *file = fopen(filename,"r");
    if (!file) {
        perror("Failed to open file");
        return;
    }
    
    char title[LEN], author[LEN], yearStr[10];
    
    while (fgets(title, LEN, file) && fgets(author, LEN, file) && fgets(yearStr, sizeof(yearStr), file)) {
        // הסרת תווי מעבר שורה מהטקסט
        title[strcspn(title, "\n")] = '\0';
        author[strcspn(author, "\n")] = '\0';
        yearStr[strcspn(yearStr, "\n")] = '\0';

        Book book;
        strncpy(book.title, title, LEN);
        strncpy(book.author, author, LEN);
        book.year = atoi(yearStr);
        // printf("%s\n",book.title);

        addBook(lib, &book);
    }

    fclose(file);
}

void sortLibraryByYear(Library* lib){
    int count;
    while(count>0){
        count = 0;
        for(int j = 0; j < lib->count-1; j++){
            if(lib->books[j].year > lib->books[j + 1].year){
                count++;
                Book temp = lib->books[j];
                lib->books[j] = lib->books[j + 1];
                lib->books[j + 1] = temp;
                printf("%d:%d\n",j,temp.year);
            }
        }
        
    }
    
    for(int i = 0; i< lib->count; i++){
        printf("%s\n",lib->books[i].title);
        printf("%d\n",lib->books[i].year);
    }
    
}
