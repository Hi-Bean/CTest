#include <stdio.h> // C++ 전용 헤더파일 : iostream

int main()
{
    int age = 10;
    char var = 'a';
    short var2 = 2;
    long var3 = 4;
    float var4 = 5;
    double var5 = 20;

    printf("age = %d    sizeof(age) = %d\n", age, sizeof(age));
    printf("var = %c    sizeof(var) = %d\n", var, sizeof(var));
    printf("var2 = %d    sizeof(var2) = %d\n", var2, sizeof(var2));
    printf("var3 = %d    sizeof(var3) = %d\n", var3, sizeof(var3));
    printf("var4 = %f    sizeof(var4) = %d\n", var4, sizeof(var4));
    printf("var5 = %f    sizeof(var5) = %d\n", var5, sizeof(var5));

    //sizeof : 가변적 데이터타입의 크기 확인에 유용하게 사용됨
}
