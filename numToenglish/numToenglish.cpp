#include <stdio.h>
int main()
{
	//int a;
	char a;
	while (1)
	{
		//scanf_s("%d", &a);
		scanf_s("%c", &a);  // scanf는 엔터가 입력되는 순간까지의 값을 버퍼에 저장함
		while (getchar() != '\n'); // 엔터값(LF)을 만날 때까지 입력버퍼를 비워주는 역할

		// if문 정수값 사용
		/*if (a == 1)
			printf("One\n");
		else if (a == 2)
			printf("Two\n");
		else if (a == 3)
			printf("Three\n");
		else if (a == 4)
			printf("Four\n");
		else if (a == 5)
			printf("Five\n");
		else if (a == 6)
			printf("Six\n");
		else if (a == 7)
			printf("Seven\n");
		else if (a == 8)
			printf("Eight\n");
		else if (a == 9)
			printf("Nine\n");
		else if (a == 0)
			break;*/

		// switch문 정수값 사용
		/*switch (a)
		{
		case 0: printf("Zero\n"); break;
		case 1: printf("One\n"); break;
		case 2: printf("Two\n"); break;
		case 3:	printf("Three\n"); break;
		case 4: printf("Four\n"); break;
		case 5: printf("Five\n"); break;
		case 6: printf("Six\n"); break;
		case 7:	printf("Seven\n"); break;
		case 8: printf("Eight\n"); break;
		case 9: printf("Nine\n"); break;
		default:break;
		}
		if (a > 9 || a < 0) break;*/

		
		// switch문 아스키코드값 사용
		switch (a)
		{
		case 48:
			printf("Zero\n");
			break;
		case 49:
			printf("One\n");
			break;
		case 50:
			printf("Two\n");
			break;
		case 51:
			printf("Three\n");
			break;
		case 52:
			printf("Four\n");
			break;
		case 53:
			printf("Five\n");
			break;
		case 54:
			printf("Six\n");
			break;
		case 55:
			printf("Seven\n");
			break;
		case 56:
			printf("Eight\n");
			break;
		case 57:
			printf("Nine\n");
			break;
		default:
			break;
		}

		if ((a > 57) || (a < 48)) break;
	}

	return 0;
}