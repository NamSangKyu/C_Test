#include <stdio.h>
#include <string.h>
//연락처 구조체 생성, 전화번호, 이름 가지고 있음
struct contact {
    char name[20];
    char phone[20];
};
//연락처 구조체 배열 선언
struct contact contact_list[100];
//연락처 구조체 배열 인덱스 선언
int contact_index = 0;
//메뉴번호 제어할 열거형 선언
enum menu {
    ADD_CONTACT = 1,
    SEARCH_CONTACT,
    DELETE_CONTACT,
    UPDATE_CONTACT,
    EXIT
};

//메뉴 출력할 함수 선언
void print_menu(){
    printf("1. 연락처 입력\n");
    printf("2. 연락처 검색\n");
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
//이름으로 연락처 찾는 함수 선언
void search_contact(){
    char name[20];
    printf("이름을 입력하세요 : ");
    scanf("%s", name);
    int i;
    for(i = 0; i < contact_index; i++){
        if(strcmp(name, contact_list[i].name) == 0){
            printf("이름 : %s\n", contact_list[i].name);
            printf("전화번호 : %s\n", contact_list[i].phone);
            break;
        }
    }
    //찾는 이름이 없으면 없다고 출력
    if(i == contact_index){
        printf("찾는 이름이 없습니다.\n");
    }
}
//입력한 이름에 해당하는 연락처 삭제하는 함수 선언
void delete_contact(){
    char name[20];
    printf("이름을 입력하세요 : ");
    scanf("%s", name);
    for(int i = 0; i < contact_index; i++){
        if(strcmp(name, contact_list[i].name) == 0){
            for(int j = i; j < contact_index; j++){
                contact_list[j] = contact_list[j+1];
            }
            contact_index--;
            //삭제 완료메시지 출력
            printf("삭제되었습니다.\n");
            break;
        }
    }
}
//입력한 이름으로 연락처를 검색하여 수정하는 함수 선언
void update_contact(){
    char name[20];
    printf("이름을 입력하세요 : ");
    scanf("%s", name);
    for(int i = 0; i < contact_index; i++){
        if(strcmp(name, contact_list[i].name) == 0){
            printf("이름 : ");
            scanf("%s", contact_list[i].name);
            printf("전화번호 : ");
            scanf("%s", contact_list[i].phone);
            //수정 완료메시지 출력
            printf("수정되었습니다.\n");
            break;
        }
    }
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
        //입력 받은 숫자에 따라 함수 호출
        switch(menu){
            case ADD_CONTACT:
                input_contact();
                break;
            case SEARCH_CONTACT:
                search_contact();
                break;
            case DELETE_CONTACT:
                delete_contact();
                break;
            case UPDATE_CONTACT:
                update_contact();
                break; 
        }       
    }
    

    return 0;
}
