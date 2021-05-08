typedef struct book_info{
    char name[50];
    char auth[30];
    char genre[20];
    char borrDate[10];
    int borrAble;
} Book;

// TODO : prototype CRUD functions.
int createBooks(Book *b);
int readBooks(Book *b);
int updateBooks(Book *b);
int deleteBooks(Book *b);

// Please use Book data type as parameter.
