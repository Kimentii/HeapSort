//������������� ���������� ��� ���������� �����.
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
	for (int i = 0; i < SIZE; i++)					//���������� ������� � ��� �����.
	{
		mass[i] = rand()%100+1;
		cout << mass[i] << ' ';
	}
	cout << endl;
	HeapSort(mass, SIZE);										//��� ����������.
	for (int i = 0; i < SIZE; i++)cout << mass[i] << ' ';		//����� �������.
	system("pause");
	return 0;
}
void ShiftDown(int* mass, int i, int n)								//�������� ������.
{
	int maxNode;
	bool repeat = true;
	while (i * 2 + 1 < n && repeat)									//���� ������ �� ��������.
	{
		if (i * 2 + 1 == n - 1 || mass[i * 2 + 1] > mass[i * 2 + 2]) //���� � �������� ���� ���� ���
		{														//"�����" ����� ������ "������", ��
			maxNode = i * 2 + 1;								//�� ���������� ������ "�����"
		}
		else
			maxNode = i * 2 + 2;								//����� ���������� ������ "������"
		if (mass[i] < mass[maxNode])							//���� ������� ����� ������ ��������, ��
		{
			swap(mass[i], mass[maxNode]);						//������ ������� ����� � ��������
			i = maxNode;										//��������� � �����, ������� ������.
		}
		else repeat = false;									//����� �������� ������ ����� �������
	}															// � ��� ������.
}
void HeapSort(int* mass, int length)
{
	int i;
	for (i = length / 2 - 1; i > -1; i--)		//�������� ������.
		ShiftDown(mass, i, length);
	for (i = length - 1; i > -1; i--)			
	{
		swap(mass[0], mass[i]);					//������ ����� ������ � ���������� ��������.
		ShiftDown(mass, 0, i);					//��������� ������ �����.
	}
}