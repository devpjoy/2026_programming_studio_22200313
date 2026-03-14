
// 091: 10-1 비만인 사람 숫자 알아내기 (파일 버전)

/*
fscanf() 함수를 통해 표준입력(stdin)으로부터 5명의 신장(cm 단위)과 체중(kg 단위)를 입력받아 이 중에서 비만인 사람의 숫자를 파악하여 출력하라. 단, 비만여부는 다음 비만도 수치가 25 이상인 경우에 "비만"으로 판단한다.
비만도 수치 = 체중(kg) / (신장(m)의 제곱) 으로 계산한다.
비만도 계산 기능을 수행하는 함수를 작성하여 사용할 것.

float evalBmi(int h, int w);
파라미터 : h : 신장(cm 단위), w : 체중(kg 단위)
리턴값 : 비만도
수행내용 : 파라미터로 받은 신장, 체중을 가지고 비만도를 계산하여 리턴함.
*/

#include <stdio.h>

float evalBmi(int h, int w);

int main()
{
    int height, weight;
    float bmi;
    int count = 0;

    for (int i = 1; i <= 5; i++)
    {
        fscanf(stdin, "%d %d", &height, &weight);

        printf("Person %d : %d %d\n", i, height, weight);

        bmi = evalBmi(height, weight);

        if (bmi >= 25)
            count++;
    }

    printf("Total number of obese people is %d.\n", count);

    return 0;
}

float evalBmi(int h, int w)
{
    float height_m = h / 100.0;
    float bmi = w / (height_m * height_m);
    return bmi;
}