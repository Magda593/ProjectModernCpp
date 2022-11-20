#include "QuestionType1.h"

QuestionType1::QuestionType1()
{
}

QuestionType1::QuestionType1(const std::string& question1, std::vector<std::string> answer1):
	m_question1(question1),
	m_answer1(answer1)
{
}

void QuestionType1::saveQuestion(std::string question1, std::vector<std::string> answer1)
{
	m_questionType1.insert(std::make_pair(question1, answer1));
}

QuestionType1& QuestionType1::operator=(const QuestionType1& questionType1)
{
	// TODO: insert return statement here
}

QuestionType1& QuestionType1::operator=(QuestionType1&& questionType1)
{
	// TODO: insert return statement here
}
