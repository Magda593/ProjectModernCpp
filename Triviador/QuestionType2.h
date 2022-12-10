#pragma once
#include<iostream>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include<unordered_map>

class QuestionType2
{
public:
	QuestionType2();
	QuestionType2(const std::string& question2, int answer);

	void SaveQuestion(std::string question2, int answer);

	void GetQuestion();

	QuestionType2& operator=(const QuestionType2& questionType2);
	QuestionType2& operator=(QuestionType2&& questionType2);
	QuestionType2 GetQuestionType2() const;

	//void GetRandomQuestion(std::unordered_map<std::string, int> questionType2);

	//friend std::ostream& operator<< (std::ostream os, const QuestionType2& questionType2);

private:
	std::string m_question2;
	int m_answer;
	std::unordered_map<std::string, int> m_questionType2;
};

