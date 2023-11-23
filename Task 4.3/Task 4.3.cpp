#include <iostream>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;
using std::begin;
using std::end;

bool is_polindrom(int start_word, int end_word, char text[])
{
	bool checker;
	int counter = 1;

	for (int i = start_word; i < (start_word + end_word) / 2; ++i)
	{
		if (text[i] == text[end_word - counter])
		{
			checker = true;
		}
		else
		{
			checker = false;
			break;
		}

		++counter;
	}

	return checker;
}

void mince_words(char text[], int TEXT_SIZE)
{
	int start_word = 0;
	int end_word;

	for (int i = 0; i < TEXT_SIZE; ++i)
	{
		if (text[i] == ' ')
		{
			end_word = i;

			if ((end_word - start_word) % 2 != 0)
			{
				for (int n = start_word; n <= end_word; ++n)
				{
					text[n] = '_';
				}
			}
			else
			{
				if (is_polindrom(start_word, end_word, text))
				{
					for (int n = start_word; n <= end_word; ++n)
					{
						text[n] = '_';
					}
				}
			}

			start_word = i + 1;
		}
	}

	end_word = TEXT_SIZE - 1;

	for (int i = start_word; i < end_word; ++i)
	{
		if ((end_word - start_word) % 2 != 0)
		{
			for (int n = start_word; n < end_word; ++n)
			{
				text[n] = '_';
			}
		}
		else
		{
			if (is_polindrom(start_word, end_word, text))
			{
				for (int n = start_word; n <= end_word; ++n)
				{
					text[n] = '_';
				}
			}
		}
	}
}

void remove_divid(char text[], const int TEXT_SIZE, const char DIVIDERES[], const int DIVID_SIZE)
{

	for (int i = 0; i < TEXT_SIZE; ++i)
	{
		for (int n = 0; n < DIVID_SIZE; ++n)
		{
			if (DIVIDERES[n] == text[i])
			{
				text[i] = ' ';
			}
		}
	}
}

int main()
{
	const int TEXT_SIZE = 10;
	char text[TEXT_SIZE];

	while (cin.getline(text, TEXT_SIZE))
	{
		if (!strcmp(text, ""))
		{
			break;
		}
	}

	const int DIVID_SIZE = 10;
	const char DIVIDERES[] = { ' ', '.', ',', ';', ':', '!', '?', '-', '(', ')' };

	remove_divid(text, TEXT_SIZE, DIVIDERES, DIVID_SIZE);
	mince_words(text, TEXT_SIZE);

	for (auto word : text)
	{
		if (word != '_')
		{
			cout << word;
		}
	}
}