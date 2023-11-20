// MyVector2.0.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <math.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <typeinfo>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
//#include <cstdlib>
#include <ctype.h>
#include <fstream>
#include <vector>

using namespace std;

class Integers
{
private:
	vector<int> _numbers;

public:
	Integers() {};

	int SearchMax()
	{
		int res = 0;
		for (int i = 0; i <= _numbers.size() - 1; i++)
		{
			res = max(_numbers[i], _numbers[i + 1]);
		}
		return res;
	}

	int SearchMin()
	{
		int res = 0;
		for (int i = 0; i < _numbers.size() - 1; i++)
		{
			res = min(_numbers[i], _numbers[i + 1]);
		}
		return res;
	}

	void GenerateRandNumVector()
	{
		srand(time(NULL));

		for (int item : _numbers)
		{
			item = 1 + rand() % 100;
		}
	}

	void SortMax()
	{
		int length = _numbers.size();
		while (length--) {
			bool isSwapped = false;
			for (int i = 0; i < _numbers.size(); i++)
			{
				if (_numbers[i] > _numbers[i + 1])
				{
					swap(_numbers[i], _numbers[i + 1]);
					isSwapped = true;
				}
			}
			if (isSwapped == false) break;
		}
	}
	void SortMin()
	{
		int length = _numbers.size();
		while (length--) {
			bool isSwapped = false;
			for (int i = 0; i < _numbers.size(); i++)
			{
				if (_numbers[i] < _numbers[i + 1])
				{
					swap(_numbers[i], _numbers[i + 1]);
					isSwapped = true;
				}
			}
			if (isSwapped == false) break;
		}
	}

	void IncreaseSize(const int& NewSize)
	{
		if(NewSize>_numbers.size()) 
		{
			_numbers.resize(NewSize);
		}else
		{
			cout << "Введенный размер должен быть больше размера вектора";
		}
	}

	void DecreaseSize(const int& NewSize)
	{
		if (NewSize < _numbers.size())
		{
			_numbers.resize(NewSize);
		}
		else
		{
			cout << "Введенный размер должен быть меньше размера вектора";
		}
	}

	void DeleteElem(const int& Elem)
	{
		auto iter = _numbers.begin();
		int count = 0;
		for (int i = 0; i < _numbers.size(); i++)
		{
			if(_numbers[i]==Elem)
			{
				_numbers.emplace(iter + i, 0);
				count++;
			}
		}
		SortMin();
		DecreaseSize(count);
	}
};
int main()
{
	setlocale(LC_ALL, "RUS");
}
