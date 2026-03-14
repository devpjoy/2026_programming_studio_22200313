// 111: 12-1 비만도 관리 프로그램 (동적 메모리 할당)

/*
비만 판정 함수버전에서 키와 몸무게 데이터를 입력받아 비만도 데이터를 완성하여 출력하라.
제작할 함수는 다음과 같다. 이 중에서 addBmi()는 이미 제공됨.
사용하는 구조체는 다음과 같다.

struct st_bmi{
    int height, weight; 		// 키(cm), 몸무게(kg)
    float bmi; 				// 비만도
    int bmi_index; 			// 1,2,3,4 --> 각각 저체중, 정상, 과체중, 비만
};

struct st_bmi* addBmi();
파라미터 : 없음
리턴값 : 메모리 할당받아 키, 몸무게, 비만도, 비만도등급이 저장된 구조체 포인터

void evalBmi(struct st_bmi* p);
파라미터 : 비만도 구조체 포인터
리턴값 : 없음
수행내용 : 포인터로 키, 몸무게를 가지고 비만도, 비만도등급을 저장
비만도 수치 = 체중(kg) / (신장(m)의 제곱) 으로 계산한다. 이 때, 신장은 미터 단위로 환산해야 함을 유의 하라.

비만도 수치에 따른 비만도 판정
18.5 미만 : 저체중
18.5 ~ 23 미만 : 정상체중
23~25미만 : 과체중
25이상 : 비만

단, main에서는 다음과 같이 구조체 포인터만을 사용하고, addBmi()를 통해 메모리가 할당되도록 해야 한다.
main() 코드는 이미 제공되니 수정하지 말 것!
*/

#include <stdio.h>
#include <stdlib.h>

struct st_bmi
{
    int height, weight; // Height(cm), Weight(kg)
    float bmi;          // Degree of obesity
    int bmi_index;      // 1,2,3,4 --> Underweight, Normal, Overweight, Obese
};

struct st_bmi *addBmi();
void evalBmi(struct st_bmi *p);

int main(void)
{
    struct st_bmi *one;
    char bmi_string[4][20] = {"Underweight", "Normal", "Overweight", "Obese"};

    one = addBmi();

    printf("Height: %d ", one->height);
    printf("Weight: %d ", one->weight);
    printf("Degree of obesity: %.1f ", one->bmi);
    printf("Assessment results : %s\n", bmi_string[one->bmi_index - 1]);

    return 0;
}

struct st_bmi *addBmi()
{
    struct st_bmi *p = (struct st_bmi *)malloc(sizeof(struct st_bmi));

    printf("Enter height and weight > ");
    scanf("%d %d", &(p->height), &(p->weight));

    evalBmi(p);

    return p;
}

void evalBmi(struct st_bmi *p)
{
    float height_m;

    height_m = p->height / 100.0;
    p->bmi = p->weight / (height_m * height_m);

    if (p->bmi < 18.5)
        p->bmi_index = 1;

    else if (p->bmi < 23)
        p->bmi_index = 2;

    else if (p->bmi < 25)
        p->bmi_index = 3;

    else
        p->bmi_index = 4;
}