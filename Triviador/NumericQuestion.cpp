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

NumericQuestion& NumericQuestion::operator=(const NumericQuestion& questionType2)
{
	m_question2 = questionType2.m_question2;
	m_answer = questionType2.m_answer;
	m_questionType2 = questionType2.m_questionType2;
	return *this;
}

NumericQuestion& NumericQuestion::operator=(NumericQuestion&& questionType2)
{
	m_question2 = questionType2.m_question2;
	m_answer = questionType2.m_answer;
	m_questionType2 = questionType2.m_questionType2;
	new (&questionType2) NumericQuestion;
	return *this;
}

int NumericQuestion::GetRandomNumber(int x)
{
	srand(time(NULL));
	int res;
	res = rand() % x + 0;
	return res;
}

NumericQuestion NumericQuestion::GetQuestionType2() const
{
	return NumericQuestion();
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
	position = GetRandomNumber(25);
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

//QuestionType2 QuestionType2::GetQuestionType2() const
//{
//	return QuestionType2();
//}
