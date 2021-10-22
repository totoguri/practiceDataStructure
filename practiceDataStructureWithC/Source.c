// Data Structure ¿­Ç÷ °­ÀÇ
// Start at 21, Oct, 2021

#include <stdio.h>

//int main(int argc, char** argv) {
//	int i;
//
//	puts("Now I will count from 1 to 10");
//	for (i = 1; i <= 10; i++) {
//		printf("%d\n", i);
//	}
//
//	return 0;
//}


//#include <stdlib.h>
//#include <assert.h>
//
//int main(int argc, char** argv) {
//	char* s;
//	s = malloc(2);
//	free(s);
//
//	s[0] = 'a';
//	s[1] = '\0';
//
//	puts(s);
//	return 0;
//}


// p.77


//int main() {
//	typedef struct student {
//		char name[30];
//		double korean;
//		double english;
//		double math;
//		int average;
//	} Student;
//	
//	Student* student = (Student*)malloc(sizeof(Student) * 5);
//	for (int i = 0; i < 5; i++) {
//		printf("Name: "); scanf_s("%s", student[i].name, sizeof(student[i].name));
//		printf("Korean: "); scanf_s("%lf", &student[i].korean);
//		printf("English: "); scanf_s("%lf", &student[i].english);
//		printf("Math: "); scanf_s("%lf", &student[i].math);
//	}
//	
//	for (int i = 0; i < 5; i++) {
//		student[i].average = (int)(((student[i].korean) + (student[i].english) + (student[i].math)) / 3);
//		printf("Average of %s : %d\n", student[i].name, student[i].average);
//	}
//
//	free(student);
//	return 0;
//}


//int main() {
//	int int_array[10] = { 0, };
//	int* ptr_int = &int_array;
//	*ptr_int = 10;
//	*(ptr_int + 1) = 12;
//	*(ptr_int + 2) = 14;
//
//	printf("%d\n", int_array[1]);
//	return 0;
//}


//int main() {
//	int int_value_A = 100;
//	int int_value_B = 200;
//
//	int* ptr_int1 = &int_value_A;
//	int* ptr_int2 = &int_value_B;
//
//	*ptr_int1 = *ptr_int2;
//	printf("%d, %d\n", *ptr_int1, *ptr_int2);
//	printf("%p, %p\n", &int_value_A, &int_value_B);
//	printf("%p, %p\n", ptr_int1, ptr_int2);
//
//	*ptr_int2 = 300;
//	printf("%p, %p\n", ptr_int1, ptr_int2);
//	printf("%d, %d\n", *ptr_int1, *ptr_int2);
//	return 0;
//}


//int main() {
//	int i = 0;
//	int j = 0;
//	int value = 0;
//	int row = 4, col = 5;
//
//	int** pptr_int_array = (int**)malloc(sizeof(int*) * row);
//	for (i = 0; i < row; i++) {
//		pptr_int_array[i] = (int*)malloc(sizeof(int) * col);
//	}
//	for (i = 0; i < row; i++) {
//		for (j = 0; j < col; j++) {
//			value++;
//			pptr_int_array[i][j] = value;
//		}
//	}
//
//	printf("%d\n", *(*(pptr_int_array + 3) + 2));
//}


