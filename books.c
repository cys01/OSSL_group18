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
    printf("만약 대출이 되어있다면, 책의 대출일을 입력해주세요\n");
    printf("대출이 되어있지 않다면 0000을 입력해주세요:");
    scanf("%s", b->borrDate);
    getchar();
    printf("대출 여부를 입력해주세요(yes : 1, no : 0):");
    scanf("%d", &b->borrAble);
    return 1;
}

void readBooks(Book *b) {
	printf("이름\t저자\t장르\t대출일\t대출 가능\n");
	if(b->borrAble != -1) {
		printf("%s\t%s\t%s\t%s\t", b->name, b->auth, b->genre, b->borrDate);
		printf("%s\n", b->borrAble?"대출 가능":"대출 불가능");
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
    printf("수정하기를 원하시는 책이 만약 대출이 되어있다면, 책의 대출일을 입력해주세요\n");
    printf("대출이 되어있지 않다면 0000을 입력해주세요:");
    scanf("%s", b->borrDate);
    getchar();
    printf("수정하기를 원하시는 책의 대출 여부를 입력해주세요:");
    scanf("%d", &b->borrAble);
    getchar();
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
