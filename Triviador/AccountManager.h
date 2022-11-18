#pragma once
#include <iostream>
#include<string>
#include<unordered_map>

class AccountManager
{
public:
	AccountManager();
	AccountManager(std::string username, int score);

	const std::string& GetUsername() const;
	std::string GetScoreForXUsername(std::string username) const;

	void SetScoreForXUsername(std::string username);
	
	void SaveUser(std::string username, int score);
	void PrintUsernames();
	void Login(std::string username);
	void SignUp(std::string username);


private:
	std::string m_username;
	int m_score;
	std::unordered_map<std::string, int> m_user;
};

