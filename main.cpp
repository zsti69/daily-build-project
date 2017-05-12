#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Question
{
private:
	string question;
	string answers[3];

	char answer;

public:
	Question (string _question, string _answers[3], char _answer)
	{
		question = _question;

		for (int i = 0; i < 3; i++)
		{
			answers[i] = _answers[i];
		}

		answer = _answer;
	}

	string GetQuestion()
	{
		return question;
	}

	string GetAnswer(int id)
	{
		if (id > 3)
		{
			return "";
		}

		return answers[id];
	}

	bool Check(char _answer)
	{
		return (_answer == answer);
	}
};

vector<Question> Questions;

void init()
{
	Questions.push_back(Question("Co robi Adamczyk", new string[3] {"Nic xD", "Nic xD", "Nic xD?"}, 'A'));
}

void getQuestion(int id)
{
	if (id > Questions.size())
	{
		return;
	}

	cout << id << ". " << Questions[id].GetQuestion() << endl;
	cout << "A. " << Questions[id].GetAnswer(0) << endl;
	cout << "B. " << Questions[id].GetAnswer(1) << endl;
	cout << "C. " << Questions[id].GetAnswer(2) << endl;
	cout << "Odpowiedz: ";
}

bool checkAnswer(char answer)
{
	// A B C a b c   as int numbers
	char valid[6] = {'A', 'B', 'C', 'a', 'b', 'c'};

	for (int i = 0; i < 6; i++)
	{
		if (answer == valid[i])
		{
			return true;
		}
	}

	return false;
}

int main()
{
	init();

	int id = 0;
	int counter = 0;
	char answer;

	while(true)
	{
		getQuestion(id);
		cin >> answer;

		if (!checkAnswer(answer))
		{
			continue;
		}

		Questions[id].Check(answer);

		id ++;
	}
}
