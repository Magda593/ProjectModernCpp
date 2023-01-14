#pragma once

#include "Question.h"

#include<vector>

class GrillQuestion
{
public:
	GrillQuestion();
	void ReadQuestion();

private:
	std::vector<Question> m_grillQuestion;
};

