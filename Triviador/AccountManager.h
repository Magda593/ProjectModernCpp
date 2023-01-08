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
	std::string GetScoreForXUsername(std::string username) const;

	bool FoundUserInFile(std::string username);

	void SetScoreForXUsername(std::string username, int newScore);
	void SetPlayedGamesForXUsr(std::pair<std::string, int> user);

	void SaveUser(std::string username, int playedGames);
	void SaveRegisteredUsersInFile(std::pair<std::string, int> user);
	//void SaveRegisteredUsersInFile(std::string username);
	void SaveUserForCurrentRoom(std::string username);
	void PrintUsernames();
	void Login(std::string username);
	void SignUp(std::string username);

private:
	std::string m_username;
	int m_score;
	int m_playedGames;
	std::unordered_map<std::string, int> m_user;
};

