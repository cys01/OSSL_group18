#include "books.h"

#define atoi(x) (x - 48)

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
    do {
	 printf("대출 가능 여부를 입력해주세요(yes : 1, no : 0):");
	 scanf("%d", &b->borrAble);
    } while(b->borrAble != 1 && b->borrAble != 0);
    if(b->borrAble)
	strcpy(b->borrDate, "00000000");
    else {
	printf("만약 대출이 되어있다면, 책의 대출일을 입력해주세요\n");
	scanf("%s", b->borrDate);
	getchar();
    }
    return 1;
}

void readBooks(Book *b, int index) {
	printf("%s\t%-12s\t%-12s\t%-12s\t%s\t\t%s\n", "No", "이름", "저자", "장르", "대출일", "대출 가능");
	for(int i = 0; i < index; i++) {
		Book *book = b + i;
		if(book->borrAble != -1) {
			printf("%d\t%-12s\t%-12s\t%-12s\t%-10s\t", i + 1, book->name, book->auth, book->genre, book->borrDate);
			printf("%s\n", book->borrAble?"대출 가능":"대출 불가능");
		}
	}
}


int updateBooks(Book *b, int index){
    int no;
    readBooks(b, index);
    printf("수정하고 싶으신 책의 번호를 입력해주세요(취소:0)?");
    scanf("%d" , &no);
    if(no <= 0){
	printf("----취소되었습니다----");
        return 0;
    }
    printf("\n수정하기를 원하시는 책의 이름을 입력해주세요:");
    scanf(" %[^\n]", b[no-1].name);
    getchar();
    printf("수정하기를 원하시는 책의 저자의 이름을 입력해주세요:");
    scanf("%[^\n]", b[no-1].auth);
    getchar();
    printf("수정하기를 원하시는 책의 장르를 입력해주세요:");
    scanf("%[^\n]", b[no-1].genre);
    getchar();
    do {
        printf("수정하기를 원하시는 책의 대출 가능 여부를 입력해주세요(yes : 1, no : 0):");
        scanf("%d", &b[no-1].borrAble);
    }while(b[no - 1].borrAble != 1 && b[no - 1].borrAble != 0);
    if(b[no-1].borrAble)
	strcpy(b[no-1].borrDate, "00000000");
    else {
        printf("수정하기를 원하시는 책의 대출일을 입력해주세요");
        scanf("%s", b[no-1].borrDate);
        getchar();
    }
    printf("---------- (: 수정되었습니다 :) -----------");
    return 1;
}

int deleteBooks(Book *b, int index){
    int no;
    readBooks(b, index);
    printf("수정하고 싶으신 책의 번호를 입력해주세요(취소:0)?");
    scanf("%d" , &no);
    if(no > 0) {
	int yn = 0;
	printf("\n정말로 삭제하시겠습니까?(yes:1 no:0):");
	scanf("%d", &yn);
	if(yn == 1) {
            b[no - 1].borrAble = -1;
            printf("---------- (: 삭제되었습니다 :) -----------");
	    return 1;
    	}
    }
    printf("----취소되었습니다----");
    return 0;
}

int loadBooks(Book *b) {
	FILE *fp = fopen("books.txt", "r");
	if(!fp)
		return 0;

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

void searchBorrow(Book *b, int index) {
	int isFound = 0;

	for(int i = 0; i < index; i++) {
		Book *book = b + i;
		if(book->borrAble == 1) {
			if(!isFound) {
				isFound = !isFound;
				printf("%-12s\t%-12s\t%-12s\t%s\n", "이름", "저자", "장르", "대출 가능");
			}
			printf("%-12s\t%-12s\t%-12s\t", book->name, book->auth, book->genre);
			printf("%s\n", book->borrAble?"대출 가능":"대출 불가능");
		}
	}

	if(!isFound)
		printf("대출 가능한 도서를 찾을 수 없습니다...\n");
}

void searchOverdue(Book *b, int index) {
	int isFound = 0;
	int currDate = 0;
	printf("오늘 날짜를 입력해주세요(예: 20210516) : ");
	scanf("%d", &currDate);

	for(int i = 0; i < index; i++) {
		Book *book = b + i;
		int isOver = 0;

		int m2d[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

		char *date = book->borrDate;

		int yyyy = atoi(date[0]) * 1000 + atoi(date[1]) * 100 + atoi(date[2]) * 10 + atoi(date[3]);
		int mm = atoi(date[4]) * 10 + atoi(date[5]);
		int dd = atoi(date[6]) * 10 + atoi(date[7]);

		if(!book->borrAble && currDate < yyyy * 10000 + mm * 100 + dd) {
			printf("현재 날짜가 대출 날짜보다 이전에 있습니다!\n"); 
			return;
		}

		for(int i = 0; i < 6; i++) {
			dd++;
			if(dd > m2d[mm - 1]) {
				dd = 1;
				mm++;
				if(mm == 13) {
					mm++;
					yyyy++;
				}
			}
		}

		if((currDate / 10000) > yyyy)
			isOver = 1;
		else if((currDate / 100 % 100) > mm)
			isOver = 1;
		else if((currDate % 100) > dd)
			isOver = 1;

		if(!book->borrAble && isOver) {
			if(!isFound) {
				isFound = !isFound;
				printf("%-12s\t%-12s\t%-12s\t%s\t\t%s\n", "이름", "저자", "장르", "대출일", "연체 여부");
			}
			printf("%-12s\t%-12s\t%-12s\t%-10s\t연체됨\n", book->name, book->auth, book->genre, book->borrDate);
		}
	}

	if(!isFound)
		printf("연체된 도서를 찾을 수 없습니다...\n");
}
