// 002: 1-2. 키와 몸무게로 비만도(BMI) 계산

/*
신장(cm 단위)과 체중(kg 단위)를 입력받은 후, 비만도(BMI)를 계산하여 출력하라.
비만도 수치 = 체중(kg) / (신장(m)의 제곱) 으로 계산한다.
이 때, 신장은 미터 단위로 환산해야 하므로 입력받는 수치(cm 단위)에 0.01을 곱해 m 단위로 바꾸어 계산하라.
*/

#include <stdio.h>
#include <math.h>

int main()
{
    int height, weight; // 신장(cm), 체중(kg)
    float bmi;          // 비만도 수치

    scanf("%d %d", &height, &weight);
    bmi = weight / pow(height * 0.01, 2);
    printf("%.1f\n", bmi);
    return 0;
}
