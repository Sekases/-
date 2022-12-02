#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <time.h>
#include <algorithm>

// ��������
// ������������ ��� �������, ������ ��� ������ �������� ������������, ������ ��� �������� �� ��������

const int amountWords = 5;
char user_var();
bool vereficatiion(char a, std::string b);

void main()
{

	setlocale(LC_ALL, "rus");
	srand(time(0));

	std::cout << "\n\t\t\t��������";
	std::cout << "\n ����� ���� ������������ �����, ������� �� ������ ��������, � ���� ������ �������, �����!\n\n ";

	std::string Words[amountWords]{ "SWORD", "HOUSE", "ELF", "TOMB", "SKELETON" }; // ����� �� �����
	std::string word = Words[rand() % 5]; // ����� ���������� �����

	const int size_word = word.size(); // ������� ���������� � ����������� ���� � �����

	std::string hide(size_word, '-'); // ������� ������ �����, ������������������ ������ �������� '-'

	std::vector<char> used;
	std::vector<char>::iterator iter; // �������� ������ �����, ������� ������ � ���� ������������ �����

	int amount_try = 8;// ���������� �������


	while (hide != word && amount_try != 0)
	{

		std::cout << "���� �����: ";        //
		for (int i = 0; i < size_word; i++) // ������� �� ����� ���� ������� �����, ������� ����� ������������ �� ���� �����������
			std::cout << hide[i];           //

		std::cout << "\n ���� �����: ";
		for (iter = used.begin(); iter != used.end(); iter++)// ������� �� ����� ������������ �����
			std::cout << *iter << " ";

		std::cout << "\n �������� �������: " << amount_try; // ������� ����� ���������� ������� �� �����

		char user_varC = user_var();// �������� ���������� �������, ����������� �������� ������������ � ��������� ����� ���������� �� ���� ������������
		if (user_varC == 48)
			break;
		user_varC = toupper(user_varC);

		bool guessed_right = vereficatiion(user_varC, word); // �������� ���������� � �������

		if (guessed_right)
		{

			std::cout << "\n ��, �������� ��� �����!";

			for (int i = 0; i < size_word; i++)
			{
				if (user_varC == word[i]) // ������� ������ ����� � ����� � �������� ������� �� ����� � ������ �������� �����
					hide[i] = user_varC;
			}

			if (hide == word)
				std::cout << "\n\n ��� ��� �����!������� �� ����!\n\n";

		}

		else
		{

			iter = find(used.begin(), used.end(), user_varC);
			if (iter == used.end())
			{
				used.push_back(user_varC);
				std::cout << "\n ��� ����� ����!";
				amount_try -= 1;
			}

			else
				std::cout << "\n\n �� ��� ������ ��� �����!\n\n ";

			if (amount_try == 0)
			{
				std::cout << "\n\n ��� �����, ������� �� ����!\n\n";
			}

		}

	}


}



char user_var()
{

	std::cout << "\n ��� �������(0 ��� ������): ";
	char var;
	std::cin >> var;

	return var;

}

bool vereficatiion(char a, std::string b)     // �������� �������� ����������������� �����(����) � �����, ����� ���� ��� � ������, ���� �����, 
{                                             // ���������� ���, ���� ��� - ����

	if (b.find(a) != std::string::npos)
		return 1;
	else
		return 0;

}

