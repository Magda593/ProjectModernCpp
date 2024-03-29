#pragma once
#include <iostream>
#include<fstream>
#include<string>
#include<unordered_map>
#include<regex>

class AccountManager
{
public:
	AccountManager();
	AccountManager(std::string username, int playedGames);

	const std::string& GetUsername() const;

	bool FoundUserInFile(std::string file, std::string username);
	int HowManyPlayersAreLoggedIn();

	void SetPlayedGamesForXUsr(std::string username);
	void ShowUserStats(std::string username);

	void SaveUser(std::string username, int playedGames);
	void SaveRegisteredUsersInFile(std::vector < std::pair<std::string, int>> user);
	void SaveRegisteredUsersInFile();
	void SaveLoggedInUsers(std::string username);

	void Login(std::string username);
	void SignUp(std::string username);

private:
	std::string m_username;
	std::vector<std::pair<std::string, int>> m_user;
	int m_playedGames;
};

