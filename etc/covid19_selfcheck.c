#include<stdio.h> 
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct Person {
	bool mask_on;
	int distance;
	bool handwash;
	bool test;
}person;

bool still_alive = true;
bool COVID19 = true;
person SEO;

void WearMask();
void Stay6ftApart();
void WashHands();
void GetTested();
bool CheckAll();

int main() {
	int num;	
	while (still_alive) {
		if (!COVID19) break;
		printf("\n-----------당신은 코로나로부터 안전합니까?--------------\n");

		WearMask();
		Stay6ftApart();
		WashHands();
		GetTested();

		if (!CheckAll()) {
			printf("당신은 죽었습니다!\n\n");
			still_alive = false;
		}
	}
	return 0;
}

void WearMask() {
	char* res;
	res = (char*)malloc(sizeof(char) * 10);
	printf("\n마스크를 쓰셨다면 OK를 입력해주세요: ");
	scanf("%s", res);
	if (strcmp(res, "OK") == 0)
		SEO.mask_on = true;
	else SEO.mask_on = false;
	free(res);
}
void Stay6ftApart() {
	printf("평균적으로 사람들과 몇 피트 이상 떨어져 계시나요?: ");
	scanf("%d", &SEO.distance);
}
void WashHands() {
	char* res;
	res = (char*)malloc(sizeof(char) * 10);
	printf("손을 깨끗이 씻으셨다면 OK를 입력해주세요: ");
	scanf("%s", res);
	if (strcmp(res, "OK") == 0)
		SEO.handwash = true;
	else SEO.handwash = false;
	free(res);
}
void GetTested() {
	char* res;
	res = (char*)malloc(sizeof(char) * 10);
	printf("증상 발현 시 검사를 받으실거면 OK를 입력해주세요: ");
	scanf("%s", res);
	if (strcmp(res, "OK") == 0)
		SEO.test = true;
	else SEO.test = false;
	free(res);
}
bool CheckAll() {
	if (!SEO.mask_on || SEO.distance < 6 || !SEO.handwash || !SEO.test)
		return false;
	else {
		printf("\n아직 안전하시군요. 항상 조심해주세요!\n\n");
		return true;
	}
}
