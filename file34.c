/*
Дистанционное занятие 16.06.2025
Решение заданий для самостоятельной работы из электронного задачника Абрамяна
File34. Дан файл целых чисел. Удалить из него все отрицательные числа.
Тестирование:
Входные данные:
	Файл test.bin с содержимым: 1, -2, 3, -4, 5, -6, 7
Вывод программы:
	Original: 1 -2 3 -4 5 -6 7 
	Modified: 1 3 5 7 
Выполнил Базан Игорь 303ИС-22
*/
#include <stdio.h>
#include <stdlib.h>

//Функция для печати содержимого бинарного файла
void print_file(const char* filename) {
	FILE* fp = fopen(filename, "rb"); //Открываем файл для чтения в бинарном режиме
	if (!fp) return;
	
	int num;
	//Читаем и выводим все целые числа из файла
	while (fread(&num, sizeof(int), 1, fp) == 1) {
		printf("%d ", num);
	}
	printf("\n");
	fclose(fp);
}

int main() {
	const char* filename = "test.bin";
	
	//Выводим исходное содержимое файла
	printf("Original: ");
	print_file(filename);
	
	//Чтение и фильтрация чисел
	FILE* fp = fopen(filename, "rb"); //Открываем файл для чтения
	if (!fp) return 1;
	
	int* buffer = NULL; //Буфер для хранения неотрицательных чисел
	int count = 0; //Количество чисел в буфере
	int num; //Переменная для чтения чисел
	
	//Читаем файл и сохраняем только неотрицательные числа
	while (fread(&num, sizeof(int), 1, fp) == 1) {
		if (num >= 0) {
			//Увеличиваем буфер и добавляем число
			buffer = realloc(buffer, (count + 1) * sizeof(int));
			buffer[count++] = num;
		}
	}
	fclose(fp);
	
	//Перезапись файла
	fp = fopen(filename, "wb"); //Открываем файл для записи (очищаем содержимое)
	if (!fp) {
		free(buffer); //Освобождаем память в случае ошибки
		return 1;
	}
	
	//Записываем отфильтрованные числа обратно в файл
	if (count > 0) {
		fwrite(buffer, sizeof(int), count, fp);
	}
	fclose(fp);
	free(buffer); //Освобождаем память
	
	//Выводим измененное содержимое файла
	printf("Modified: ");
	print_file(filename);
	
	return 0;
}
