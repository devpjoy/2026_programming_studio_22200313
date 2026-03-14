// 073: 8-3. 비만 판정 (함수 버전)

/*
10명의 신장(cm 단위)과 체중(kg 단위)를 입력받으면서 askBiman() 함수를 통해 이들이 비만도를 출력하고 다음 기준에 따라 비만여부를 판정하여 출력하라.
비만도 수치 = 체중(kg) / (신장(m)의 제곱) 으로 계산한다.
이 때, 신장은 미터 단위로 환산해야 함을 유의 하라.

< 비만도 수치에 따른 비만도 판정 >
18.5 미만 : 저체중
18.5 ~ 23 미만 : 정상체중
23~25미만 : 과체중
25~30미만 : 경도비만
30이상 : 고도비만

int askBiman(int height, int weight);
파라미터 : height : 신장(cm), weight : 체중(kg)
수행내용 : 비만도 계산 후 판정결과 리턴
리턴값 : 저체중 0, 정상체중 1, 과체중 2, 경도비만 3, 고도비만 4
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int askBiman(int height, int weight);

int main()
{
    int height[10], weight[10];
    int result[10];

    for (int i = 0; i < 10; i++)
    {
        scanf("%d %d", &height[i], &weight[i]);
        result[i] = askBiman(height[i], weight[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        printf("Person %d: ", i + 1);

        switch (result[i])
        {
        case 0:
            printf("Underweight\n");
            break;
        case 1:
            printf("Normal weight\n");
            break;
        case 2:
            printf("Overweight\n");
            break;
        case 3:
            printf("Mild obesity\n");
            break;
        case 4:
            printf("Severe obesity\n");
            break;
        }
    }

    return 0;
}

int askBiman(int height, int weight)
{
    double h = height / 100.0;
    double bmi = weight / (h * h);

    if (bmi < 18.5)
        return 0;
    else if (bmi < 23)
        return 1;
    else if (bmi < 25)
        return 2;
    else if (bmi < 30)
        return 3;
    else
        return 4;
}