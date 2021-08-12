#include <stdio.h>
// 두 과목의 성적에 각각 가중치를 곱한 후 개인별 합계를 구하여
// 합이 큰 순서대로 정렬하여 출력하시오

const int student = 7;
int kor[] = { 82, 93, 71, 69, 78, 84, 75 };
int eng[] = { 76, 91, 67, 73, 86, 63, 83 };
char name[] = "ABCDEFG";
// 문자열 포인터로 변경 : "홍길동", "홍길이", "홍길삼" 등등
const char* name2[] = {"홍길동", "홍길이", "홍길삼", "홍길사", "홍길오", "김육", "김칠"};  //string array
//string 데이터 타입은 C/C++에 없음 => C++에서 MFC를 쓸 때 string class 사용

void swap(int* a, int* b)  // int형 swap
{
	int temp;
	temp = *a;
	//a = b;     warning! (a의 주소값이 b를 가리키게 되어 b값이 바뀌면 a도 동기화됨)
	*a = *b;
	*b = temp;
}
void swapEx(double* a, double* b) // double형 swap
{
	double temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void swapEx1(char* a, char* b) // char형 swap
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void swapEx2(const char** a, const char** b) // 문자열 swap : string * (스트링 포인터)
{
	const char *temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void AllSwap(void* a, void* b, int i)
{
	int itemp; double dtemp; char ctemp;
	if (i == 1) // 1바이트 :  char
	{
		ctemp = *(char*)a;
		*(char*)a = *(char*)b;
		*(char*)b = ctemp;
	}
	else if (i == 4) // 4바이트 : int, float, const char*(strig)
	{
		itemp = *(int*)a;
		*(int*)a = *(int*)b;
		*(int*)b = itemp;
	}
	else if (i == 8) // 8바이트 : double
	{
		dtemp = *(double*)a;
		*(double*)a = *(double*)b;
		*(double*)b = dtemp;
	}
}
int sort(int* a, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] < a[j])
			{
				swap(&a[i], &a[j]);
			}
		}

	return 0;
}
int sortEx(double* a, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] < a[j])
			{
				//swapEx(&a[i], &a[j]);	// avg : double
				AllSwap(a + i, a + j, 8);

				//swap(kor + i, kor + j);
				AllSwap(kor + i, kor + j, 4);  // 전역변수 kor, eng를 직접 바꿀 수 있음
				
				//swap(eng + i, eng + j);
				AllSwap(eng + i, eng + j, 4);
				
				//swap((int)name + i, (int)name + j);   warning!(name은 char이므로 1바이트, swap은 int자료형을 스왑)
				//swapEx2(name2 + i, name2 + j);  // 문자열 스왑을 위한 함수를 추가해줘야함
				AllSwap(name2 + i, name2 + j, 4);
			}
		}
	return 0;
}

int KorAndEng()
{
	double avg[student];

	for (int i = 0; i < student; i++)
		avg[i] = kor[i] * 0.3 + eng[i] * 0.7;

	printf("Original\n");
	for (int i = 0; i < student; i++)
		printf("%7s %7d %7d %7.2f\n", name2[i], kor[i], eng[i], avg[i]);

	sortEx(avg, student);

	printf("\n\nSorted\n");
	printf("등수  이름      국어     영어   합계\n");
	for (int i = 0; i < student; i++)
		printf("%2d : %7s %7d %7d %7.2f\n", i+1,name2[i], kor[i], eng[i], avg[i]);

	return 0;
}
int main()
{
	KorAndEng();

	return 0;
}