#include "books.h"

int createBooks(Book *b){
    printf("\n원하시는 책의 이름을 입력해주세요:");
    scanf(" %[^\n]", b->name);
    getchar();
    printf("저자의 이름을 입력해주세요:");
    scanf("%[^\n]", b->auth);
    getchar();
    printf("책의 장르를 입력해주세요:");
    scanf("%[^\n]", b->genre);
    getchar();
    printf("대출 여부를 입력해주세요(yes : 1, no : 0):");
    scanf("%d", &b->borrAble);
    if(!b->borrAble)
	strcpy(b->borrDate, "00000000");
    else {
	printf("만약 대출이 되어있다면, 책의 대출일을 입력해주세요\n");
	scanf("%s", b->borrDate);
	getchar();
    }
    return 1;
}

void readBooks(Book *b, int index) {
	printf("%-12s\t%-12s\t%-8s\t%s\t\t%s\n", "이름", "저자", "장르", "대출일", "대출 가능");
	for(int i = 0; i < index; i++) {
		Book *book = b + i;
		if(book->borrAble != -1) {
			printf("%-12s\t%-12s\t%-8s\t%-10s\t", book->name, book->auth, book->genre, book->borrDate);
			printf("%s\n", book->borrAble?"대출 불가능":"대출 가능");
		}
	}
}


int updateBooks(Book *b){
    printf("\n수정하기를 원하시는 책의 이름을 입력해주세요:");
    scanf(" %[^\n]", b->name);
    getchar();
    printf("수정하기를 원하시는 책의 저자의 이름을 입력해주세요:");
    scanf("%[^\n]", b->auth);
    getchar();
    printf("수정하기를 원하시는 책의 장르를 입력해주세요:");
    scanf("%[^\n]", b->genre);
    getchar();
    printf("수정하기를 원하시는 책의 대출 여부를 입력해주세요(yes : 1, no : 0):");
    scanf("%d", &b->borrAble);
    getchar();
    if(!b->borrAble)
	strcpy(b->borrDate, "00000000");
    else {
	printf("수정하기를 원하시는 책의 대출일을 입력해주세요");
	scanf("%s", b->borrDate);
	getchar();
    }
    printf("---------- (: 수정되었습니다 :) -----------");
    return 1;
}

int deleteBooks(Book *b){
    int yn = 0;
    printf("\n정말로 삭제하시겠습니까?(yes:1 no:0):");
    scanf("%d", &yn);
    if(yn == 1){
        b->borrAble = -1;
        printf("---------- (: 삭제되었습니다 :) -----------");
    }
    else if(!yn) {
	return 0;
    }
    return 1;
}

int loadBooks(Book *b) {
	FILE *fp = fopen("books.txt", "r");
	int index;
	for(index = 0; fscanf(fp, " %[^;]", b[index].name) != EOF; index++)
		fscanf(fp, "%*c%[^;]%*c%[^;]%*c%[^;]%*c%d", b[index].auth, b[index].genre, b[index].borrDate, &b[index].borrAble);

	fclose(fp);
	return index;
}

void saveBooks(Book *b, int index) {
	FILE *fp = fopen("books.txt", "w");

	for(int i = 0; i < index; i++) {
		Book *book = b + i;
		if(book->borrAble != -1)
			fprintf(fp, "%s;%s;%s;%s;%d\n", book->name, book->auth, book->genre, book->borrDate, book->borrAble);
	}
	fclose(fp);
}

//void searchBorrow(Book *b, int index);
//void searchOverdue(Book *b, int index);
