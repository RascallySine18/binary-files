/*
Дистанционное занятие 16.06.2025
Решение заданий из курса Сергея Балакирева
"8.5 Бинарный режим доступа. Функции fwrite() и fread()"
Подвиг 7 (на повторение). Используя вложенные циклы (любые),
вывести в консоль из звездочек (*) следующую симметричную фигуру:
   *
  ***
 *****
*******
Число выводимых строк определяется целочисленной переменной n (натуральное число),
значение которой считывается из входного потока.
Перед звездочками (в начале строк) прописываются пробелы (кроме последней строки).
После звездочек никаких пробелов не должно быть.
Выполнил Базан Игорь 303ИС-22
*/
#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - i; j++) {
			printf(" ");
		}
		for (int k = 1; k <= 2 * i - 1; k++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
