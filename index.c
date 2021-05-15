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
		printf("새로운 도서 정보를 추가하였습니다.\n");
		break;
	    case 2:
		readBooks(books, index);
		break;
	    case 3:
		updateBooks(books, index);
		break;
	    case 4:
		deleteBooks(books, index);
		break;
	    case 5:
		saveBooks(books, index);
		printf("도서 정보들을 파일에 저장하였습니다.\n");
		break;
	    case 6:
		{
			int searchMenu = 0;
			printf("0 : 메뉴로 돌아가기\n1 : 책 이름 검색\n2 : 저자 검색\n3 : 장르 검색\n4 : 대출 가능 여부 검색\n5 : 연체 여부 검색\n\n");
			scanf("%d", &searchMenu);
			switch(searchMenu) {
				case 1:
					searchName(books, index);
					break;
				case 2:
					searchAuthor(books, index);
					break;
				case 3:
					searchGenre(books, index);
					break;
				case 4:
					searchBorrow(books, index);
					break;
				case 5:
					searchOverdue(books, index);
			}
		}
	}
    }

    return 0;
}
