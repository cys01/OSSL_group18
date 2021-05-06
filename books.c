#include "books.h"

int createBooks(Book *b){
    printf("\n");
    printf("원하시는 책의 이름을 입력해주세요:");
    scanf("%[^\n]s", b->name);
    printf("저자의 이름을 입력해주세요:");
    scanf("%[^\n]s", b->auth);
    printf("책의 장르를 입력해주세요:");
    scanf("%[^\n]s", b->genre);
    printf("만약 대출이 되어있다면, 책의 대출일을 입력해주세요\n");
    printf("대출이 되어있지 않다면 0000을 입력해주세요:");
    scanf("%[^\n]s", b->borrDate);
    printf("대출 여부를 입력해주세요:");
    scanf("%d", b->borrAble);
}

int updateBooks(Book *b){
    printf("\n");
    printf("수정하기를 원하시는 책의 이름을 입력해주세요:");
    scanf("%[^\n]s", b->name);
    printf("수정하기를 원하시는 책의 저자의 이름을 입력해주세요:");
    scanf("%[^\n]s", b->auth);
    printf("수정하기를 원하시는 책의 장르를 입력해주세요:");
    scanf("%[^\n]s", b->genre);
    printf("수정하기를 원하시는 책이 만약 대출이 되어있다면, 책의 대출일을 입력해주세요\n");
    printf("대출이 되어있지 않다면 0000을 입력해주세요:");
    scanf("%[^\n]s", b->borrDate);
    printf("수정하기를 원하시는 책의 대출 여부를 입력해주세요:");
    scanf("%d", b->borrAble);
    printf("---------- (: 수정되었습니다 :) -----------");
}

int deleteBooks(Book *b){
    int yn;
    printf("정말로 삭제하시겠습니까?(yes:1 no:0):");
    scanf("%d", &yn);
    if(yn == 1){
        b->borrAble = -1;
        printf("---------- (: 삭제되었습니다 :) -----------");
    }

}
