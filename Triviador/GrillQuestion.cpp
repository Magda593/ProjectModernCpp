#include "GrillQuestion.h"

GrillQuestion::GrillQuestion()
{
}

GrillQuestion::GrillQuestion(std::string question1, std::string option1, std::string option2, std::string option3, std::string option4) :
	m_question1(question1),
	m_option1(option1),
	m_option2(option2),
	m_option3(option3),
	m_option4(option4)
{
}

void GrillQuestion::ReadQuestion()
{
	std::ifstream inFile;
	inFile.open("GrillQuestion.txt");
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

void GrillQuestion::SaveQuestion(std::string question1, std::string option1, std::string option2, std::string option3, std::string option4, std::string correctAnswer)
{
	m_grillQuestion.push_back(question1);
	m_grillQuestion.push_back(option1);
	m_grillQuestion.push_back(option2);
	m_grillQuestion.push_back(option3);
	m_grillQuestion.push_back(option4);
	m_grillQuestion.push_back(correctAnswer);
}

int GrillQuestion::GetRandomNumber()
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(0, 300-1);

	return distr(eng);
}

void GrillQuestion::GetQuestion()
{
	for (int i = 0; i < m_grillQuestion.size(); i++)
		std::cout << m_grillQuestion[i]<<std::endl;
}

std::string GrillQuestion::GetRandomQuestion()
{
	int position = GetRandomNumber();
	while (position % 6 != 0)
	{
		position = GetRandomNumber();
	}
	std::cout <<"\033[96m" << m_grillQuestion[position] << '\n'<< m_grillQuestion[1 + position] << '\n' << m_grillQuestion[2 + position] << '\n' << m_grillQuestion[3 + position] << '\n' << m_grillQuestion[4 + position] << '\n' << "\033[0m";
	return m_grillQuestion[position+5];
}
