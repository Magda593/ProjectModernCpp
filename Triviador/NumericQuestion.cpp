#include "NumericQuestion.h"

NumericQuestion::NumericQuestion()
{
}

NumericQuestion::NumericQuestion(const std::string& question2, int answer):
	m_question2(question2),
	m_answer(answer)
{
}

void NumericQuestion::SaveQuestion(std::string question2, int answer)
{
	m_questionType2.insert(std::make_pair(question2, answer));
}

void NumericQuestion::ReadNumericQuestions()
{
	std::ifstream inFile;
	std::string line;
	std::string line2;
	int answer1;
	inFile.open("NumericQuestion.txt");

	if (!inFile) std::cout << "Unable to open file.";
	while (std::getline(inFile, line))
	{
		inFile >> answer1;

		SaveQuestion(line, answer1);
		std::getline(inFile, line2);
	}
	inFile.close();
}

void NumericQuestion::GetQuestion()
{
	for (auto& x : m_questionType2)
		std::cout << x.first << ": " << x.second << std::endl;
}

int NumericQuestion::GetRandomNumber(int x)
{
	srand(time(NULL));
	int res;
	res = rand() % x + 0;
	return res;
}

int NumericQuestion::GetAnswer(std::string question)
{
	if (auto search = m_questionType2.find(question); search != m_questionType2.end())
		return search->second;
	else
		return 999999;
}

std::string NumericQuestion::GetRandomNumericQuestion()
{
	int position;
	int nr = 0;
	std::pair<std::string, int> p;
	auto x = m_questionType2.begin();
	auto y = m_questionType2.end();
	position = GetRandomNumber(24);
	for (auto el : m_questionType2)
	{
		if (nr == position)
		{
			p = el;
			break;
		}
		nr++;
	}
	return p.first;
}