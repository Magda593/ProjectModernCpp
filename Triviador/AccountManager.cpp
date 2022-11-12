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
