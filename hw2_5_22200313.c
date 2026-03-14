// 084: 9-4 비만인 사람 숫자 알아내기 (포인터 버전 2)

/*
5명의 신장(cm 단위)과 체중(kg 단위)를 입력받아 이 중에서 비만인 사람의 숫자를 파악하여 출력하라. 단, 제공된 main() 함수 코드를 수정없이 함수 내용만 작성하라. 신장과 체중의 입력은 bmiFromHW() 함수를 통해 진행하라.

float bmiFromHW(float* h, float* w);
파라미터 : 키과 몸무게 값을 저장할 변수의 포인터 (h, w)
리턴값 : 계산된 bmi 지수
수행내용 : 키(cm)과 몸무게(kg)을 화면에서 입력받아 h포인터를 사용해 미터(float)로 환산한 키, w포인터를 사용해 몸무게(float)값을 저장하고, bmi 지수를 계산해서 리턴함
*/

#include <stdio.h>

float bmiFromHW(float *h, float *w);

int main()
{
    float height, weight, bmi;
    int count = 0;

    for (int i = 0; i < 5; i++)
    {
        bmi = bmiFromHW(&height, &weight);

        if (bmi > 25)
        {
            printf("Person %d is obese.\nHeight: %.2fm, Weight: %.1fkg\n", i + 1, height, weight);
            count++;
        }
    }

    printf("Total number of obese people is %d.\n", count);
    return 0;
}

float bmiFromHW(float *h, float *w)
{
    float height_cm, weight, bmi;

    scanf("%f %f", &height_cm, &weight);

    *h = height_cm / 100.0;
    *w = weight;

    bmi = (*w) / ((*h) * (*h));

    return bmi;
}