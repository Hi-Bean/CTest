#include <stdio.h>
#include <stdlib.h>		// srand(), rand()
#include <time.h>		//time()
#include <conio.h>

const int students = 20;  // 학생 수는 상수로 지정

int score()
{
	double avg = 0, tot = 0, all_tot = 0; // 평균, 합
	double kor[students], eng[students], mat[students];		// 각 학생들의 국어, 영어, 수학 점수를 위한 배열

	srand(time(NULL));
	for (int i = 0; i < students; i++)
	{
		// kor[i] = (rand() % 1000 + 1) / 10;  
		//   -> rand()는 정수 난수를 발생하기 때문에 소숫점이하가 모두 0으로 저장됨
		//      따라서 형변환이 아래와 같이 필요함
		kor[i] = (double)(rand() % 1000 + 1) / 10;  // rand() : 난수 발생기 (정수)
		eng[i] = (double)(rand() % 1000 + 1) / 10;
		mat[i] = (double)(rand() % 1000 + 1) / 10;

	}
	printf("국어  영어  수학 /  총합  / 평균\n");
	printf("---------------------------------\n");
	for (int i = 0; i < students; i++)
	{
		tot = kor[i] + eng[i] + mat[i];
		all_tot += tot;
		avg = tot / 3;
		printf("%4.1f  %4.1f  %4.1f / %6.1f / %4.1f\n", kor[i], eng[i], mat[i], tot, avg);
	}

	printf("\t\t  반 평균 : %4.1f\n", all_tot / (students * 3));

	return 0;
}
int Good()
{
	int i, j, k;
	char good[5] = "Good";
	char mon[] = "morning";
	char noon[] = "afternoon";
	char even[] = "evening";

	while (1)
	{
		printf("지금 몇시죠? "); scanf("%d", &k);
		if (k > 7 && k < 12)
		{
			printf("%s %s \n ", good, mon);
		}
		else if (k < 18)
		{
			printf("%s %s \n ", good, noon);
		}
		else if (k < 23)
		{
			printf("%s %s \n ", good, even);
		}
		else
		{
			printf("Hi!\n ");
		}
	}

	return 0;
}
int PointerTest()
{
	int a[3][2] = { 1, 2, 3, 4, 5, 6 };

	printf("a[0] : %x \n", a[0]);
	printf("a[1] : %x \n", a[1]);
	printf("a[2] : %x \n", a[2]);
	printf("a    : %x \n\n\n\n", a);

	printf("a   : %x \n", a);
	printf("a+1 : %x \n", a + 1);
	printf("a+2 : %x \n", a + 2);

	return 0;
}
// function define 
//     Prototype  :  int str_len(char *str)
// 문자열 str을 받아서 해당 문자열의 길이를 되돌려 줌.
int str_len(char* str)  // 배열이 아닌 포인터로 받음  int str_len(char str[])과 동일 (배열과 포인터 혼용가능)
{
	int ret = 0;
	//	while (*(str + ret++)); return ret;
	while (1)
	{
		if (str[ret] != 0) ret++;
		else break;
	}
	return ret;

	// return strlen(str);    // <string.h> 파일에 포함된 문자열 길이 반환 함수
}
int solution1()
{
	//문1) scanf 함수를 이용하여 문자열을 입력후
	//    해당 문자열을 한 글자씩 공백(_)을 삽입하여
	//	  출력하시오.
	//    > 12345   ==>  1_2_3_4_5
	//문2) scanf 함수를 이용하여 문자열을 입력후
	//     getch() 함수를 이용하여 숫자 키를 누르면
	//	   해당 위치의 문자를 출력하시오

	char buf[100];  //	buffer : 버퍼 : 배열의 이름 == 포인터
	int i, str_length, input_num;

	printf("문자열을 입력하세요 : "); scanf("%s", buf);
	printf("입력문자열 [%s] 의 길이는 %d 입니다 \n", buf, str_length = str_len(buf));
	for (i = 0; i < str_length; i++)
	{
		printf("%c_", buf[i]);
	}
	printf("\n");
	while (1)
	{
		input_num = getch() - 0x30;   // 0 ~ 9 숫자키 (    ) 입력
		if (input_num >= 0 && input_num <= 9)
		{
			printf("%c\n", buf[input_num]);
			continue;
		}
		break;
	}

	return 0;
}

// function define 
//     Prototype  :  int swap(int a, int b)
// 정수 변수 a와 b의 값을 교환
void swap(int* a, int* b)	// a,b를 포인터로 선언하고 전달된 매개변수 값으로 설정(초기화)
{							// 포인터 사용방법 - 포인터가 가리키는 주소의 값 :*p
							//				   - 주소 자체 : p
	// 여기서 a와 b는 주소 값임을 주의하자!
	int temp;
	//printf("	input>  a(%08x) : %d,  b(%08x) : %d\n", a, *a, b, *b);
	temp = *a;	// *a 포인터가 가리키는 주소의 값을 가져오기 위함
	//a = b;     warning! (a의 주소값이 b를 가리키게 되어 b값이 바뀌면 a도 동기화됨)
	*a = *b;
	*b = temp;
	//printf("	result>  a(%08x) : %d,  b(%08x) : %d\n", a, *a, b, *b);
}
int SwapTest()
{
	int a = 50, b = 60;

	// %x : 16진수 출력, %8x : 8자리로 16진수 출력, %08x : 빈자리는 0으로 채움
	printf("original>  a(%08x) : %d,  b(%08x) : %d\n", &a ,a, &b, b);

	//swap a & b
	//swap(a, b);     warning! (해당 함수에서는 a, b가 변하지 않음)
	swap(&a, &b);	//주소값 전달을 위해 &를 붙여줌

	printf("after swap>  a(%08x) : %d,  b(%08x) : %d\n", &a, a, &b, b);

	return 0;
}

int sort(int *a, int n)
{
	for (int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
		{
			if (a[i] < a[j])
				//swap(&a[i], &a[j]);  //아래와 동일함
				swap(a + i, a + j);
		}

	return 0;
}
int sortTest()
{
	int nArr = 11;  // arr의 개수
	int arr[] = {25, 27, 30, 47, 35, 68, 40, 79, 45, 85, 50};
	
	// print original data
	printf("original : ");
	for (int i = 0; i < nArr; i++)
		printf("%d  ", arr[i]);
	printf("\n");

	sort(arr, nArr);

	// print sorted data
	printf("sorted : ");
	for (int i = 0; i < nArr; i++)
		printf("%d  ", arr[i]);
	printf("\n");

	return 0;
}

void VoidPrint(void* p, int i) // argument : void pointer
{
	if (i == 1)
	{
		char* cp = (char*)p;  // char형으로 casting
		printf("%c\n", *cp);
	}
	else if (i == 2)
		printf("%d\n", *(int*)p);	// int형으로 casting
	else if (i == 3)
		printf("%f\n", *(double*)p);	// double형으로 casting
}
void VoidTest()
{
	char c = 'z';
	int n = 10;
	double a = 1.414;
	
	// void 포인터
	void* vp;
	VoidPrint(vp = &c, 1);
	VoidPrint(vp = &n, 2);
	VoidPrint(vp = &a, 3);
}

int main()
{
	//score();
	//Good();
	//PointerTest();
	//solution1();
	//SwapTest();
	//sortTest();
	VoidTest();
	return 0;
}