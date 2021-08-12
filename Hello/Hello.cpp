#include <stdio.h>
#include<conio.h>
int main() 
{
	//const char* name = "혜빈";
	char name[20];		// 포인터
	int age = 10;
	int height = 1700;

	int idx = 0; // 반복문의 수행 횟수 정의
	//while(idx-- > 0)  // while(조건식)
	for(int i = 0; i < idx; i++)
	{
		printf("당신의 이름을 입력하세요 ");
		scanf("%s", name);  //배열의 경우 & 표시는 제외

		printf("당신의 키를 cm 단위로 입력하시고, 나이를 입력해 주세요.\n"); // 프롬프트문자 (안내문자)
		scanf("%d %d", &height, &age);

		printf("안녕하세요.\n %s 씨\n반갑습니다!\n", name);
		printf("저는 %5d살 입니다.\n", age);
		printf("제 키는 %5dcm 입니다.\n", height);  // %d : 10진 정수
		printf("제 키는 %5.2fm 입니다.\n", float(height) / 100);

		
	}

	getch();

	return 0;
}