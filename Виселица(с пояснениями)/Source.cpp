#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <time.h>
#include <algorithm>

// Виселица
// Использовать две функции, первая для приема варивнта пользователя, вторая для проверки на верность

const int amountWords = 5;
char user_var();
bool vereficatiion(char a, std::string b);

void main()
{

	setlocale(LC_ALL, "rus");
	srand(time(0));

	std::cout << "\n\t\t\tВиселица";
	std::cout << "\n Вэтой игре загадывается слово, которое ты должен отгадать, у тебя восемь попыток, удачи!\n\n ";

	std::string Words[amountWords]{ "SWORD", "HOUSE", "ELF", "TOMB", "SKELETON" }; // Слова на выбор
	std::string word = Words[rand() % 5]; // Выбор случайного слова

	const int size_word = word.size(); // создаем переменную с количеством букв в слове

	std::string hide(size_word, '-'); // создали массив чаров, проинициализтровав каждый символом '-'

	std::vector<char> used;
	std::vector<char>::iterator iter; // объявили вектор чаров, который ъранит в себе неподошедшие буквы

	int amount_try = 8;// количество попыток


	while (hide != word && amount_try != 0)
	{

		std::cout << "Ваше слово: ";        //
		for (int i = 0; i < size_word; i++) // выводим на экран наше скрытое слово, которое будет раскрываться по мере прохождения
			std::cout << hide[i];           //

		std::cout << "\n Ваши буквы: ";
		for (iter = used.begin(); iter != used.end(); iter++)// выводим на экран неподошедшие буквы
			std::cout << *iter << " ";

		std::cout << "\n Осталось попыток: " << amount_try; // выводим колво оставшихся попыток на экран

		char user_varC = user_var();// передаем управление функции, принимающей значение пользователя и объявляем новую переменную со знач пользователя
		if (user_varC == 48)
			break;
		user_varC = toupper(user_varC);

		bool guessed_right = vereficatiion(user_varC, word); // передаем управление в функцию

		if (guessed_right)
		{

			std::cout << "\n Да, откройте эту букву!";

			for (int i = 0; i < size_word; i++)
			{
				if (user_varC == word[i]) // находим индекс буквы в слове и заменяем прочерк на букву в сторке скрытого слова
					hide[i] = user_varC;
			}

			if (hide == word)
				std::cout << "\n\n Это мое слово!Спасибо за игру!\n\n";

		}

		else
		{

			iter = find(used.begin(), used.end(), user_varC);
			if (iter == used.end())
			{
				used.push_back(user_varC);
				std::cout << "\n Нет такой бувы!";
				amount_try -= 1;
			}

			else
				std::cout << "\n\n Вы уже пытали эту букву!\n\n ";

			if (amount_try == 0)
			{
				std::cout << "\n\n Это конец, спасибо за игру!\n\n";
			}

		}

	}


}



char user_var()
{

	std::cout << "\n Ваш вариант(0 для выхода): ";
	char var;
	std::cin >> var;

	return var;

}

bool vereficatiion(char a, std::string b)     // передаем значение пользовательского ввода(чара) и стоки, затем ищем чар в строке, если нашли, 
{                                             // возвращаем тру, если нет - фолс

	if (b.find(a) != std::string::npos)
		return 1;
	else
		return 0;

}

