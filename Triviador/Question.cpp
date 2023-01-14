#include "Question.h"

Question::Question()
{
}

Question::Question(std::string question1, std::string option1, std::string option2, std::string option3, std::string option4) :
	m_question1(question1),
	m_option1(option1),
	m_option2(option2),
	m_option3(option3),
	m_option4(option4)
{
}

void Question::ReadQuestion()
{
	std::ifstream inFile;
	inFile.open("questionType1.txt");
	while (!inFile.fail())
	{
		getline(inFile, m_question1);
		getline(inFile, m_option1);
		getline(inFile, m_option2);
		getline(inFile, m_option3);
		getline(inFile, m_option4);
		getline(inFile, m_correctAnswer);
		std::string question1;
		SaveQuestion(m_question1, m_option1, m_option2, m_option3, m_option4, m_correctAnswer);
	}
	inFile.close();
}

void Question::SaveQuestion(std::string question1, std::string option1, std::string option2, std::string option3, std::string option4, std::string correctAnswer)
{
	m_grillQuestion.push_back(question1);
	m_grillQuestion.push_back(option1);
	m_grillQuestion.push_back(option2);
	m_grillQuestion.push_back(option3);
	m_grillQuestion.push_back(option4);
	m_grillQuestion.push_back(correctAnswer);
}

int Question::GetRandomNumber()
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(0, m_grillQuestion.size()-1);

	return distr(eng);
}

void Question::GetQuestion()
{
	for (int i = 0; i < m_grillQuestion.size(); i++)
		std::cout << m_grillQuestion[i]<<std::endl;
}

std::string Question::GetRandomQuestion()
{
	int position = GetRandomNumber();
	while (position % 6 != 0)
	{
		position = GetRandomNumber();
		std::cout << position << std::endl;
	}
	std::cout << m_grillQuestion[position] << '\n'<< m_grillQuestion[1 + position] << '\n' << m_grillQuestion[2 + position] << '\n' << m_grillQuestion[3 + position] << '\n' << m_grillQuestion[4 + position] << '\n';
	return m_grillQuestion[position+5];
}

Question& Question::operator=(Question&& question)
{
	m_question1 = question.m_question1;
	m_correctAnswer = question.m_correctAnswer;
	new (&question) Question;
	return *this;
}

int Question::Equal(std::string correctAnswer, std::string answer)
{
	if (std::string(correctAnswer) == std::string(answer))
		return true;
	return false;
}

void Question::ShowTwoOptions(Question question)
{
	if (question.Equal(question.m_correctAnswer, "a"))
	{
		std::cout << question.m_option2 << std::endl;
		std::cout << question.m_option4 << std::endl;
	}
	if (question.Equal(question.m_correctAnswer, "b"))
	{
		std::cout << question.m_option1 << std::endl;
		std::cout << question.m_option3 << std::endl;
	}
	if (question.Equal(question.m_correctAnswer, "c"))
	{
		std::cout << question.m_option1 << std::endl;
		std::cout << question.m_option4 << std::endl;
	}
	if (question.Equal(question.m_correctAnswer, "d"))
	{
		std::cout << question.m_option2 << std::endl;
		std::cout << question.m_option3 << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Question& question)
{
	os << question.m_question1 << std::endl;
	os << question.m_option1 << std::endl;
	os << question.m_option2 << std::endl;
	os << question.m_option3 << std::endl;
	os << question.m_option4 << std::endl;
	return os;
}
