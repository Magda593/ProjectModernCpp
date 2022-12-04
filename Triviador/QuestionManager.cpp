#include "QuestionManager.h"

QuestionManager::QuestionManager()
{
}

QuestionManager::QuestionManager(std::string question1, std::string option1, std::string option2, std::string option3, std::string option4, std::string correctAnswer) :
	m_question1(question1),
	m_option1(option1),
	m_option2(option2),
	m_option3(option3),
	m_option4(option4),
	m_correctAnswer(correctAnswer)
{
}