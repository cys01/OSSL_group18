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
int updateBooks(Book *b, int index);
int deleteBooks(Book *b, int index);

// TODO : prototype save and load functions.
int loadBooks(Book *b);
void saveBooks(Book *b, int index);

// TODO : prototype search functions.
void searchBorrow(Book *b, int index);
void searchOverdue(Book *b, int index);
