#include <stdio.h>

//연락처 구조체 생성, 전화번호, 이름 가지고 있음
struct contact {
    char name[20];
    char phone[20];
};
//연락처 구조체 배열 선언
struct contact contact_list[100];
//연락처 구조체 배열 인덱스 선언
int contact_index = 0;
//메뉴 출력할 함수 선언
void print_menu(){
    printf("1. 연락처 입력\n");
    printf("2. 연락처 출력\n");
    printf("3. 연락처 삭제\n");
    printf("4. 연락처 수정\n");
    printf("5. 종료\n");
}

//연락처 입력할 함수 선언
void input_contact(){
    //더이상 입력할수 없으면 함수 강제 종료
    if(contact_index >= 100){
        printf("연락처가 너무 많습니다.\n");
        return;
    }
    printf("이름을 입력하세요 : ");
    scanf("%s", contact_list[contact_index].name);
    printf("전화번호를 입력하세요 : ");
    scanf("%s", contact_list[contact_index].phone);
    contact_index++;
}



// Function: main
// Description: Main function
// Input: None
// Output: None
int main()
{
    int menu;

    while(1){
        //메뉴 출력
        print_menu();
        //메뉴 입력
        printf("메뉴를 선택하세요: ");
        scanf("%d", &menu);
        //입력 받은 숫자가 5이면 반복문 종료
        if(menu == 5){
            break;
        }
    }
    

    return 0;
}
