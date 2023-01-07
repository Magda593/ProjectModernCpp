#include "Question.h"

Question::Question()
{
}

Question::Question(std::string question1, std::string option1, std::string option2, std::string option3, std::string option4, std::string correctAnswer) :
	m_question1(question1),
	m_option1(option1),
	m_option2(option2),
	m_option3(option3),
	m_option4(option4),
	m_correctAnswer(correctAnswer)
{
}

void Question::ReadQuestion(std::string question1, std::string option1, std::string option2, std::string option3, std::string option4, std::string correctAnswer)
{
	std::ifstream question;
	question.open("questionType2.txt");
	while (!question.fail())
	{
		getline(question, question1);
		question >> option1;
		question >> option2;
		question >> option3;
		question >> option4;
		question >> correctAnswer;
		std::string question1;
		getline(question, question1);
	}
	question.close();
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
