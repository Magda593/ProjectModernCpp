#pragma once
#include <iostream>
#include<string>
#include<unordered_map>

class AccountManager
{
public:
	AccountManager();
	AccountManager(std::string username, int playedGames);

	const std::string& GetUsername() const;
	
	void SaveUser(std::string username, int playedGames);
	void PrintUsernames();

private:
	std::string m_username;
	int m_playedGames;
	std::unordered_map<std::string, int> m_user;
};

