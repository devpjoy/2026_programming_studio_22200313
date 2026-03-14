// 101: 11-1 비만인 사람 숫자 알아내기 (구조체 버전)
/*
다음 구조체를 사용하여 data.txt stdin으로부터 fscanf()를 사용하여 5명의 신장(cm 단위)과 체중(kg 단위)를 입력 받아, 그 중에서 비만인 사람의 숫자를 파악하여 출력하라.
단, 비만 여부는 다음 비만도 수치가 25 이상인 경우에 "비만"으로 판단한다.
이때, "비만도 수치 = 체중(kg) / (신장(m)의 제곱)" 으로 계산한다.
다음 구조체, 비만도 계산 기능을 수행하는 함수를 모두 사용하라.
(※ 주의 - fscanf(), 구조체, 주어진 함수를 모두 사용하지 않을 경우, 오답 처리됩니다)
*/

#include <stdio.h>

struct bmi_struct
{
    int height, weight;
    float bmi;
};

float evalBmi(int h, int w);

int main()
{
    struct bmi_struct p[5];
    int count = 0;

    for (int i = 0; i < 5; i++)
    {
        fscanf(stdin, "%d %d", &p[i].height, &p[i].weight);

        p[i].bmi = evalBmi(p[i].height, p[i].weight);

        if (p[i].bmi >= 25)
            count++;

        printf("%d번째 사람 : %d %d\n", i + 1, p[i].height, p[i].weight);
    }

    printf("총 %d명\n", count);

    return 0;
}

float evalBmi(int h, int w)
{
    float height_m = h / 100.0;
    return w / (height_m * height_m);
}