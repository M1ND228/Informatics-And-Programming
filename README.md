# Informatics-And-Programming
Репозиторий, предназначенный для выполнения практических задач с использованием классов на C++

В рамках проекта разработаны следующие задачи:

## Ветка Contacts
Разработан класс Contacts для работы с телефонной книгой. Реализованный класс содержит:

- Все необходимые конструкторы (по умолчанию, копированию, инициализация) и деструктор;

- Метод вывода на экран в виде пронумерованного списка: ;
  ```
   Контакты
	1) Фамилия Имя Отчество
	2) Фамилия Имя Отчество...
  ```
- Реализованы функции ввода/вывода в файл;

- Реализована сортировка списка котактов по алфавиту

- Поиск и изменение/удаление контакта

Проведена проверка реализованных конструкторов, деструкторов и функций.

Пример использования разработанного класса:
```
	system("cls");
	int choose = 0;
	cout << "\t\t      М Е Н Ю\n";
	cout << "|- - - - - - - - - - - - - - - - - - - - - - - -|\n";
	cout << "|1  - Добавить контакт			        |\n";
	cout << "|2  - Добавить контакт в избранный	        |\n";
	cout << "|3  - Изменить контакт                          |\n";
	cout << "|4  - Список контактов			        |\n";
	cout << "|5  - Список избранных контактов	        |\n";
	cout << "|6  - Узнать количество контактов               |\n";
	cout << "|7  - Поиск контакта	                        |\n";
	cout << "|8  - Поиск контактов по первой букве	        |\n";
	cout << "|9  - Поиск контакта по номеру телефона	        |\n";
	cout << "|10 - Удалить контакт из избранных	        |\n";
	cout << "|11 - Удалить контакт выбранный по телефону     |\n";
	cout << "|12 - Прочитать контакты с файла	        |\n";
	cout << "|13 - Вывести список контактов в файл           |\n";
	cout << "|- - - - - - - - - - - - - - - - - - - - - - - -|\n";
	cout << "|0 - Выход из приложения			|\n";
	cout << "|- - - - - - - - - - - - - - - - - - - - - - - -|\n\n";
	cout << "Ввод: ";
	cin >> choose;
	switch (choose)
	{
	case 1:
		system("cls");
		l1.newElement(1);
		system("pause");
		mainMenu(l1);
		break;
	
	case 2:
		system("cls");
		l1.addFavorit();
		system("pause");

		mainMenu(l1);
		break;
	case 3:
		system("cls");
		l1.changeContact();
		getchar(); getchar();
		mainMenu(l1);
	case 4:
		system("cls");
		l1.print();
		system("pause");

		mainMenu(l1);
		break;
	case 5:
		system("cls");
		l1.printFavorit();
		system("pause"); 

		mainMenu(l1);
		break;
	case 6:
		system("cls");
		l1.countContacts();
		system("pause");

		mainMenu(l1);
		break;
	case 7:
		system("cls");
		l1.findSNM();
		system("pause");

		mainMenu(l1);
		break;
	case 8:
		system("cls");
		l1.findFirstChar();
		system("pause");

		mainMenu(l1);
		break;
	case 9:
		system("cls");
		l1.findPhone();
		system("pause"); 

		mainMenu(l1);
		break;	
	case 10:
		system("cls");
		l1.delFavorit();
		system("pause");

		mainMenu(l1);
		break;
	case 11:
		system("cls");
		l1.delContactPhone();
		system("pause");

		mainMenu(l1);
		break;
	case 12:
		system("cls");
		l1.inputFile();
		system("pause");

		mainMenu(l1);
		break;
	case 13:
		system("cls");
		l1.outputFile();
		system("pause");

		mainMenu(l1);
		break;
	case 0:
		system("cls");
		cout << "Спасибо за иcпользование этого приложения!\n";
		Sleep(1000);
		exit(EXIT_SUCCESS);
		break;
	default:
		system("cls");
		cout << "Кажется что-то пошло не так...\n";
		system("pause");
		mainMenu(l1);
		break;

	}
```
