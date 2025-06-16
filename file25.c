/*
Дистанционное занятие 16.06.2025
Решение заданий для самостоятельной работы из электронного задачника Абрамяна
File25. Дан файл вещественных чисел. Заменить в нем все элементы на их квадраты.
Тестирование:
Входные данные:
	Файл numbers.bin с содержимым: 1.5, 2.0, 3.5, 4.0
Вывод программы:
	Original: 1.50 2.00 3.50 4.00
	Modified: 2.25 4.00 12.25 16.00
Выполнил Базан Игорь 303ИС-22
*/
#include <stdio.h>

//Функция для печати содержимого бинарного файла
void print_file(const char* filename) {
	FILE* fp = fopen(filename, "rb"); //Открываем файл для чтения в бинарном режиме
	if (!fp) return;
	
	double num;
	//Читаем и выводим все числа типа double из файла
	while (fread(&num, sizeof(double), 1, fp) == 1) {
		printf("%.2f ", num);
	}
	printf("\n");
	fclose(fp);
}

int main() {
	const char* filename = "numbers.bin";
	
	//Выводим исходное содержимое файла
	printf("Original: ");
	print_file(filename);
	
	//Открываем файл для чтения и записи
	FILE* fp = fopen(filename, "r+b");
	if (!fp) return 1;
	
	double num;
	//Обрабатываем файл: читаем, возводим в квадрат, перезаписываем
	while (fread(&num, sizeof(double), 1, fp) == 1) {
		fseek(fp, -sizeof(double), SEEK_CUR); //Возвращаемся на позицию числа
		num *= num; //Возводим в квадрат
		fwrite(&num, sizeof(double), 1, fp); //Перезаписываем число
		fflush(fp); //Сбрасываем буфер
	}
	fclose(fp);
	
	//Выводим измененное содержимое файла
	printf("Modified: ");
	print_file(filename);
	
	return 0;
}
