#pragma once
#include <iostream>
#include<string>
class AccountManager
{
public:
	AccountManager();
	AccountManager(std::string username, int playedGames);
	const std::string& GetUsername() const;

private:
	std::string m_username;
	int m_playedGames;
};

