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

void QuestionType2::ReadNumericQuestions()
{
	std::ifstream inFile;
	std::string line;
	std::string line2;
	int answer1;
	inFile.open("grillQuestion.txt");

	if (!inFile) std::cout << "Unable to open file.";
	while (std::getline(inFile, line))
	{
		//std::getline(inFile, line);
		inFile >> answer1;
		//std::string line2;

		SaveQuestion(line, answer1);
		std::getline(inFile, line2);
	}
	inFile.close();
}

void QuestionType2::GetQuestion()
{
	for (auto& x : m_questionType2)
		std::cout << x.first << ": " << x.second << std::endl;
}

QuestionType2& QuestionType2::operator=(const QuestionType2& questionType2)
{
	m_question2 = questionType2.m_question2;
	m_answer = questionType2.m_answer;
	m_questionType2 = questionType2.m_questionType2;
	return *this;
}

QuestionType2& QuestionType2::operator=(QuestionType2&& questionType2)
{
	m_question2 = questionType2.m_question2;
	m_answer = questionType2.m_answer;
	m_questionType2 = questionType2.m_questionType2;
	new (&questionType2) QuestionType2;
	return *this;
}


//QuestionType2 QuestionType2::GetQuestionType2() const
//{
//	return QuestionType2();
//}
