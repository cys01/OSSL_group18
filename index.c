#include <stdio.h>

#include "books.h"

int main() {
    // TODO : code menu selection.
    
    Book books[10];
    int menu = -1;
    int index = loadBooks(books);

    if(!index)
	printf("도서 정보를 읽어오지 못했습니다...");
    else
	printf("%d 개의 데이터를 읽어오는 데에 성공했습니다!", index);

    while(menu) {
	printf("\n0 : 종료\n1 : 도서 추가\n2 : 도서 조회\n3 : 도서 정보 수정\n4 : 도서 삭제\n5 : 도서 저장\n6 : 도서 검색\n\n");
	scanf("%d", &menu);

	switch(menu) {
	    case 1:
		index += createBooks(books + index);
		break;
	    case 2:
		readBooks(books, index);
		break;
	    case 3:
		updateBooks(books);
		break;
	    case 4:
		deleteBooks(books);
		break;
	    case 5:
		saveBooks(books, index);
		break;
	    case 6:
		printf("준비중입니다!\n");
	}
    }

    return 0;
}
