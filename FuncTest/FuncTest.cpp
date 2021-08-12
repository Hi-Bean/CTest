#include <stdio.h>
#include <conio.h>

// Function Test 프로그램
// 기능 : 키보드에서 단일 문자를 입력받고
//        해당 문자가 대(0)/소문자(1)/특수(2)/숫자키(3) 임을 분류
//        'z'를 입력받으면 프로그램 종료
// 
// --> 함수를 선언하고 호출할 것. - 함수명 whatIsThis

int whatIsThis(char c); // whatIsThis 함수의 prototype (함수의 원형)

int main()
{
	char input;
	int result;

	while (1)
	{
		printf("아무 키나 누르세요.\n");
		input = getch();

		if (input == 'z') // 'z' 입력시 while문을 빠져나가고 프로그램 종료
			break;

		result = whatIsThis(input);
		switch(result)
		{
		case 0:
			printf(">> 입력하신 Key ['%c']는 대문자키입니다.\n", input);
			break;
		case 1:
			printf(">> 입력하신 Key ['%c']는 소문자키입니다.\n", input);
			break;
		case 2:
			printf(">> 입력하신 Key ['%c']는 특수문자키입니다.\n", input);
			break;
		case 3:
			printf(">> 입력하신 Key ['%c']는 숫자자키입니다.\n", input);
			break;
		default:
			break;
		}
	}
	return 0;
}

int whatIsThis(char c)
{
	int ret;

	if ((c >= 65) && (c <= 90)) // 대문자키 : 'A' (65) ~ 'Z' (90)
		ret = 0;
	else if ((c >= 97) && (c <= 122)) // 소문자키 : 'a' (97) ~ 'z' (122)
		ret = 1;
	else if ((c >= 48) && (c <= 57)) // 숫자키 : '0' (48, 0x30) ~ '9' (57, 0x39)
		ret = 3;
	else // 특수문자키 (기타 나머지)
		ret = 2;
	
	return ret;
}