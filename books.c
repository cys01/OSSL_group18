#include "books.h"

int createBooks(Book *b){
    printf("\n");
    printf("원하시는 책의 이름을 입력해주세요:");
    scanf("%s", b.name);
    getchar();
    printf("\n저자의 이름을 입력해주세요:");
    scanf("%s", b.auth);
    getchar();
    printf("\n책의 장르를 입력해주세요:");
    scanf("%s", b.genre);
    getchar();
    printf("\n만약 대출이 되어있다면, 책의 대출일을 입력해주세요\n");
    printf("대출이 되어있지 않다면 0000을 입력해주세요:");
    scanf("%s", b.borrDate);
    getchar();
    printf("\n대출 여부를 입력해주세요(yes : 1, no : 0):");
    scanf("%d", b.borrAble);
}

int updateBooks(Book *b){
    printf("\n");
    printf("수정하기를 원하시는 책의 이름을 입력해주세요:");
    scanf("%[^\n]s", b->name);
    getchar();
    printf("\n수정하기를 원하시는 책의 저자의 이름을 입력해주세요:");
    scanf("%[^\n]s", b->auth);
    getchar();
    printf("\n수정하기를 원하시는 책의 장르를 입력해주세요:");
    scanf("%[^\n]s", b->genre);
    getchar();
    printf("\n수정하기를 원하시는 책이 만약 대출이 되어있다면, 책의 대출일을 입력해주세요\n");
    printf("대출이 되어있지 않다면 0000을 입력해주세요:");
    scanf("%[^\n]s", b->borrDate);
    getchar();
    printf("\n수정하기를 원하시는 책의 대출 여부를 입력해주세요:");
    scanf("%d", b->borrAble);
    getchar();
    printf("---------- (: 수정되었습니다 :) -----------");
}

int deleteBooks(Book *b){
    int yn =0;
    printf("\n정말로 삭제하시겠습니까?(yes:1 no:0):");
    scanf("%d", &yn);
    if(yn == 1){
        b->borrAble = -1;
        printf("---------- (: 삭제되었습니다 :) -----------");
    }

}
