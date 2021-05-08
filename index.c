#include <stdio.h>

int main() {
    // TODO : code menu selection.
    
    Book books[10];
    int count = 0;
    int menu = -1;

    while(menu) {
	printf("0 : 종료\n1 : 도서 추가\n2 : 도서 조회\n3 : 도서 정보 수정\n4 : 도서 삭제\n5 : 도서 저장\n6 : 도서 검색\n);
	switch(menu) {
	    case 1:
		count += createBooks(books[count]);
		break;
	    case 2:
		readBooks(books);
		break;
	    case 3:
		updateBooks(books);
		break;
	    case 4:
		deleteBooks(books);
		break;
	    case 5:
	    case 6:
		printf("준비중입니다!\n");
	}
    }

    return 0;
}
