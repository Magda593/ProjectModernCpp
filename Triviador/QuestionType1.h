#pragma once
#include<unordered_map>
#include<vector>
#include<iostream>

class QuestionType1
{
public:
	QuestionType1();
	QuestionType1(const std::string& question1, std::vector<std::string> answer1);

	void saveQuestion(std::string question1, std::vector<std::string> answer1);

private:
	std::string m_question1;
	std::vector<std::string> m_answer1;
	std::unordered_map<std::string, std::vector<std::string>> m_questionType1;
};

