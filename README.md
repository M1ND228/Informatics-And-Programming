# Informatics-And-Programming
Репозиторий, предназначенный для выполнения практических задач с использованием классов на C++

В рамках проекта разработаны следующие задачи:

## Ветка Date
Разработан класс Date для работы с датой представленной в виде тройки day, month, year. Реализованный класс содержит:

1) Все необходимые конструкторы (по умолчанию, копированию, инициализация) и деструктор;

2) Метод вывода на экран даты в виде: "dd.mm:yyyy";

3) Метод сложения, вычитания, сравнения двух дат;
В классе перегружены следующие операции:

1) Присваивание;

2) Две операции сравнения;

3) Сложения и вычитания;

4) Операции Ввода/Вывода в поток;
Также проведена проверка реализованных конструкторов, деструкторов, функций и перегруженных операторов.
Пример использования разработанного класса:

	int d = 9, m = 11, y = 2001;
	
	Date present;
	
	std::cout << "Тест конструкторов" << std::endl;
	
	std::cout << "Конструктор по умолчанию: " << Date();
	
	std::cout << "\nКонструктор с параметрами: " << Date(d, m, y);
	
	Date t4(11,11,2112);
	
	std::cout << "\nКонструктор копирования: " << Date(t4);
	
	std::cout << "\nДиструктор: ";
	
	present.~Date();
	
	present.print();



	std::cout << "\nТест функционала" << std::endl;

	Date c1(1, 1, 2000), c2(9, 9, 2005);

	std::cout << "Сложение двух дат " << c1 + c2;

	std::cout << "\nВычитание даты из даты " << c2 - c1;

	std::cout << "\nСравнение двух дат ";

	if (c1 == c2) {

		std::cout << "\nДаты ровны " << c1 << " = " << c2;

	} else { std::cout << "\nДаты не ровны " << c1 << " != " << c2; }

	