#pragma once
#include <iostream>
#include<fstream>
#include<string>
#include<unordered_map>

class AccountManager
{
public:
	AccountManager();
	AccountManager(std::string username, int playedGames);

	const std::string& GetUsername() const;

	bool FoundUserInFile(std::string username);

	void SetPlayedGamesForXUsr(std::string username);

	void SaveUser(std::string username, int playedGames);
	void SaveRegisteredUsersInFile(std::vector < std::pair<std::string, int>> user);
	void SaveRegisteredUsersInFile();
	void SaveUserForCurrentRoom(std::string username);
	void PrintUsernames();
	void Login(std::string username);
	void SignUp(std::string username);

private:
	std::string m_username;
	std::vector<std::pair<std::string, int>> m_user;
	int m_playedGames;
	std::pair<int, int> toAdd = std::make_pair(0, 1);
};

