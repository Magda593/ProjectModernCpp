#include "QuestionType2.h"

QuestionType2::QuestionType2()
{
}

QuestionType2::QuestionType2(const std::string& question2, int answer):
	m_question2(question2),
	m_answer(answer)
{
}

void QuestionType2::SaveQuestion(std::string question2, int answer)
{
	m_questionType2.insert(std::make_pair(question2, answer));
}
