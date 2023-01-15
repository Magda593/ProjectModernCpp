#pragma once
#include<iostream>
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
	void SaveQuestion(std::string question2, int answer);

	std::string GetRandomNumericQuestion();
	int GetRandomNumber(int x);
	int GetAnswer(std::string question);

	void GetQuestion();

private:
	std::string m_question2;
	int m_answer;
	std::unordered_map<std::string, int> m_questionType2;
};

