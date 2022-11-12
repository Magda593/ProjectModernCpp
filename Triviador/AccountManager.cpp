#include "AccountManager.h"

AccountManager::AccountManager()
{
}

AccountManager::AccountManager(std::string username, int playedGames):
	m_username(username),
	m_playedGames(playedGames)
{
}

const std::string& AccountManager::GetUsername() const
{
	return m_username;
}

void AccountManager::SaveUser(std::string username, int playedGames)
{
	m_user.insert(std::make_pair(username, playedGames));
}

void AccountManager::PrintUsernames()
{
	for (auto user : m_user)
	{
		std::cout << user.first << " " << user.second;
		std::cout<< std::endl;
	}
}

void AccountManager::Login(std::string username)
{
	if (m_user.find(username) == m_user.end())
	{
		std::cout << "The username " << username << " doesn't exists. Exit and sign-up." << std::endl;
	}
	else
	{
		std::cout << "Welcome back " << username << "!" << std::endl;
	}
}

void AccountManager::SignUp(std::string username)
{
	if (m_user.find(username) == m_user.end())
	{
		SaveUser(username, 0);
	}
	else
	{
		std::cout << "The username " << username << " already exists." << std::endl;
	}
}
