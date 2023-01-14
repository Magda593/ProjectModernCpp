#pragma once
#include<iostream>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include<unordered_map>
#include <fstream>
#include <iostream>
#include <string>

class NumericQuestion
{
public:
	NumericQuestion();
	NumericQuestion(const std::string& question2, int answer);
	void ReadNumericQuestions();

	void ReadQuestions(std::ifstream& infile, std::string question2, int answer);
	void SaveQuestion(std::string question2, int answer);

	std::string GetRandomNumericQuestion();
	int GetRandomNumber(int x);
	int GetAnswer(std::string question);

	void GetQuestion();

	NumericQuestion& operator=(const NumericQuestion& questionType2);
	NumericQuestion& operator=(NumericQuestion&& questionType2);
	NumericQuestion GetQuestionType2() const;

	//void GetRandomQuestion(std::unordered_map<std::string, int> questionType2);

	//friend std::ostream& operator<< (std::ostream os, const QuestionType2& questionType2);

private:
	std::string m_question2;
	int m_answer;
	std::unordered_map<std::string, int> m_questionType2;
};

