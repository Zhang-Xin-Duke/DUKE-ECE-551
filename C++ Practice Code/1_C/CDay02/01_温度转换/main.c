#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SCALE_FACTOR (5.0f / 9.0f)
#define FREEZING_PT 32

int main(void) {
	float fahrenheit;  // ���뼴ע��	
	printf("Enter Fahrentheit temparature: ");
	scanf("%f", &fahrenheit);

	// ��Ҫʹ��ħ������
	float celsius = SCALE_FACTOR * (fahrenheit - FREEZING_PT); 

	printf("Celsius equivalent: %.1f\n", celsius);
	return 0;
}