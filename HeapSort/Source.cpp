//Пирамидальная сортировка или сортировка кучей.
#include <iostream>
#include <cstdlib>
#include <ctime>
#define SIZE 10
using namespace std;
void ShiftDown(int* mass, int i, int n);
void HeapSort(int* mass, int length);
int main()
{
	srand((unsigned int)time(0));
	int mass[SIZE];
	for (int i = 0; i < SIZE; i++)					//Заполнение массива и его вывод.
	{
		mass[i] = rand()%100+1;
		cout << mass[i] << ' ';
	}
	cout << endl;
	HeapSort(mass, SIZE);										//Его сортировка.
	for (int i = 0; i < SIZE; i++)cout << mass[i] << ' ';		//Вывод массива.
	system("pause");
	return 0;
}
void ShiftDown(int* mass, int i, int n)								//Создания дерева.
{
	int maxNode;
	bool repeat = true;
	while (i * 2 + 1 < n && repeat)									//Пока дерево не кончется.
	{
		if (i * 2 + 1 == n - 1 || mass[i * 2 + 1] > mass[i * 2 + 2]) //Если у родителя одна дочь или
		{														//"левая" ветка больше "правой", то
			maxNode = i * 2 + 1;								//То запоминаем индекс "левой"
		}
		else
			maxNode = i * 2 + 2;								//Иначе запоминаем индекс "правой"
		if (mass[i] < mass[maxNode])							//Если большая ветка больше родителя, то
		{
			swap(mass[i], mass[maxNode]);						//Меняем большую ветку и родителя
			i = maxNode;										//Переходим к ветке, которую меняли.
		}
		else repeat = false;									//Иначе родитель больше своих дочерей
	}															// и все хорошо.
}
void HeapSort(int* mass, int length)
{
	int i;
	for (i = length / 2 - 1; i > -1; i--)		//Создавем дерево.
		ShiftDown(mass, i, length);
	for (i = length - 1; i > -1; i--)			
	{
		swap(mass[0], mass[i]);					//Замена корня дерева и последнего элемента.
		ShiftDown(mass, 0, i);					//Получение нового корня.
	}
}