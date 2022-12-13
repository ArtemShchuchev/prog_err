#include <iostream>
using namespace std;	// эта часть не особо нужна, но она и не мешает

struct point
{
	double m_x;
	double m_y;
	point(double x, double y)
	{
		m_x = x;
		m_y = y;	// y = y; - семантическая ошибка (присвоение самому себе)
	}
};	// при определении структуры в коце не хватало ; - синтаксическая ошибка

void print_point(const point& point_object);
/*
* видимо имелось ввиду только объявление функции, тогда
* не хватает ;
* а остальное наоборот лишнее, т.к. реализация находится ниже main
* ошибка линковки
{
	std::cout << "x:" << point_object.m_x << ", y: "
		<< point_object.m_y << std::endl;
}
*/

//int Main() - не правильное имя главной функции (наверное линковка)
int main()
{
	int i;	// не хватает инициализации
	for (i = 0; i < 5; i++)	// лишнее ; - семантическая ошибка (цикл - ради цикла)
	{
		point my_point(i, 2 * i);
		print_point(my_point);
	}
	return 0;
}

void print_point(const point& point_object)
{
	/*
		Не знаю насколько это важно, но вывод этой функции
		не очень похож на вывод по ТЗ (не хватает пробелов).
		Если это важно... даже не знаю какая это ошибка - логическая наверно?!
	
	std::cout << "x:" << point_object.m_x << ", y: "
		<< point_object.m_y << std::endl;
	*/
	std::cout << "x : " << point_object.m_x << ", y : "
		<< point_object.m_y << std::endl;
}

/*
Пример правильной работы программы
x : 0, y : 0
x : 1, y : 2
x : 2, y : 4
x : 3, y : 6
x : 4, y : 8
*/