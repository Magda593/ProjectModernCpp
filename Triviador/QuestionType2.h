#pragma once
#include<iostream>
#include<unordered_map>

class QuestionType2
{
public:
	QuestionType2();
	QuestionType2(const std::string& question2, int answer);

	void SaveQuestion(std::string question2, int answer);

	void GetQuestion();

private:
	std::string m_question2;
	int m_answer;
	std::unordered_map<std::string, int> m_questionType2;
};

