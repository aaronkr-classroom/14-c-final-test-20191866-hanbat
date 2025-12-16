// 다음과 같이 동작하는 성적 처리 프로그램을 만들어 보세요. 이 프로그램은 연결리스트의 개념을 사용하기 때문에 학생 수에 제한이 없어야 합니다.

// Person.c

#include <stdio.h>

typedef unsigned short int us;

typedef struct {
	char name[12];
	us korea;
	us english;
	us math;
} Person;

int calc_sum(int i, int j, int k) {
	int sum = 0;
	sum = i + j + k;
	return sum;
}
int calc_avg(int i, int j, int k) {
	int avg = 0;
	avg = (i + j + k) / 3;
	return avg;
}

void Addstudent(count) {
	Person data;
	int sum, avg, num;

	printf("대상자의 정보를 입력하세요.\n");
	printf("이름: >>> ");
	scanf_s("%s", &data.name+count, sizeof(data.name));

	printf("국어점수: >>> ");
	scanf_s("%hu", &data.korea + count);

	printf("영어 점수: >>> ");
	scanf_s("%hu", &data.english + count);

	printf("수학 점수: >>> ");
	scanf_s("%hu", &data.math + count);
}
void ShowStudent(count) {
	Person data;
	int num=0;
	printf("----------------------------------------------------------\n");
	printf("이름\t국어\t영어\t수학\t총점\t평균\t등수\n");
	printf("----------------------------------------------------------\n");



	for (int i = 0; i < count; i++) {
		printf("%s\t%hu\t%hu\t%hu\t%d\t%d\t%d\n",
			data.name, data.korea, data.english, data.math,
			calc_sum(data.korea + count, data.english + count, data.math + count),
			calc_avg(data.korea + count, data.english + count, data.math + count)
			, num);
	}
}
int main() {
	Person data; // Person 자료형으로 data 변수 선언
	int count=0,menu_num;
	


	while (1) {
		printf("[Menu]\n1. 성적입력\n2. 성적 확인\n3. 종료\n-----------\n선택(1~3): ");
		scanf_s("%d", &menu_num);
		if (menu_num == 1) {
			Addstudent(count);
			count++;
		}
		else if (menu_num == 2) {
			ShowStudent(count);
		}
		else if (menu_num == 3) {
			printf("프래그램을 종료합니다.\n");
			break;
		}
		else {
			printf("잘못된 메뉴 번호입니다. 다시 선택하세요.\n");
		}
	}


	return 0;
}