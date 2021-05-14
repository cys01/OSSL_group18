#include <stdio.h>
#include <string.h>

typedef struct book_info{
    char name[50];
    char auth[30];
    char genre[20];
    char borrDate[10];
    int borrAble;
} Book;

// TODO : prototype CRUD functions.
int createBooks(Book *b);
void readBooks(Book *b, int index);
int updateBooks(Book *b);
int deleteBooks(Book *b);

// TODO : prototype save and load functions.
int loadBooks(Books *b);
void saveBooks(Books *b, int index);

// TODO : prototype search functions.

searchBorrow(Books *b, int index);
searchOverdue(Books *b, int index);
