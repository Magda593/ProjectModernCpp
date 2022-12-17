#include "AccountManager.h"

AccountManager::AccountManager()
{
}

AccountManager::AccountManager(std::string username, int score) :
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

bool AccountManager::FoundUserInFile(std::string username)
{
	std::ifstream inFile;
	std::string line;
	int ok = 0;
	inFile.open("AllRegisteredUsers.txt");

	if (!inFile) std::cout << "Unable to open file.";
	while (inFile.good())
	{
		std::getline(inFile, line);
		std::size_t pos = line.find(username);
		if (pos != std::string::npos)
			ok = 1;
	}
	if (ok == 1)
		return true;
	else
		return false;
}

void AccountManager::SetScoreForXUsername(std::string username, int newScore)
{
	if (m_user.find(username) == m_user.end())
	{
		std::cout << "There is no " << username << " logged in";
		std::cout << std::endl;
	}
	else
	{
		m_user.find(username)->second = newScore;
	}
}

void AccountManager::SaveUser(std::string username, int score)
{
	m_user.insert(std::make_pair(username, score));
	SaveRegisteredUsersInFile(username);
}

void AccountManager::SaveRegisteredUsersInFile(std::string username)
{
	std::ofstream out;
	out.open("AllRegisteredUsers.txt", std::ios::app);
	out << username << "\n";
	out.close();
}

void AccountManager::SaveUserForCurrentRoom(std::string username)
{
}

void AccountManager::PrintUsernames()
{
	for (auto user : m_user)
	{
		std::cout << user.first << " " << user.second;
		std::cout << std::endl;
	}
}

void AccountManager::Login(std::string username)
{
	if (!FoundUserInFile(username)/*m_user.find(username) == m_user.end()*/)
	{
		std::cout << "The username " << username << " doesn't exists. Exit and sign-up." << std::endl;
	}
	else
	{
		std::cout << "Welcome " << username << "!" << std::endl;
	}
}

void AccountManager::SignUp(std::string username)
{
	if (!FoundUserInFile(username)/*m_user.find(username) == m_user.end()*/)
	{
		SaveUser(username, 0);
		std::cout << "Thank you for choosing to be with us. Enjoy your stay!\n";
	}
	else
	{
		std::cout << "The username " << username << " already exists." << std::endl;
	}
}
