#include "AccountManager.h"

AccountManager::AccountManager()
{
}

AccountManager::AccountManager(std::string username, int score):
	m_username(username),
	m_score(score)
{
}

const std::string& AccountManager::GetUsername() const
{
	return m_username;
}

std::string AccountManager::GetScoreForXUsername(std::string username) const
{
	if (m_user.find(username) == m_user.end())
	{
		return "Nonexistent";
	}
	else
	{
		int value = m_user.find(username)->second;
		return std::to_string(value);
	}
}

void AccountManager::SetScoreForXUsername(std::string username)
{
}

void AccountManager::SaveUser(std::string username, int score)
{
	m_user.insert(std::make_pair(username, score));
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
