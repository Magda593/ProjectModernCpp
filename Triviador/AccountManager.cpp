#include "AccountManager.h"

AccountManager::AccountManager()
{
}

AccountManager::AccountManager(std::string username, int playedGames) :
	m_username(username),
	m_playedGames(playedGames)
{
}

const std::string& AccountManager::GetUsername() const
{
	return m_username;
}

bool AccountManager::FoundUserInFile(std::string file, std::string username)
{
	std::ifstream inFile;
	std::string line;
	int ok = 0;
	inFile.open(file);

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

int AccountManager::HowManyPlayersAreLoggedIn()
{
	std::ifstream inFile;
	std::string line;
	int contor = 0;
	inFile.open("LoggedInUsers.txt");

	if (!inFile) std::cout << "Unable to open file.";
	while (!inFile.eof())
	{
		std::getline(inFile, line);
		contor++;
	}
	return contor - 1;
}

void AccountManager::SetPlayedGamesForXUsr(std::string username)
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
		{
			std::pair<std::string, int> are;
			std::string first = line.substr(0, line.find(" "));
			std::string second = line.substr(line.find(" "), line.find(" ") + 1);
			int secondint = std::stoi(second);
			secondint = secondint + 1;
			are = std::make_pair(first, secondint);
			if (secondint != std::stoi(second))
				SaveUser(first, secondint);
			break;
			std::cout << are.first << " " << are.second;
		}
	}
}

void AccountManager::ShowUserStats(std::string username)
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
		{
			std::pair<std::string, int> are;
			std::string first = line.substr(0, line.find(" "));
			std::string second = line.substr(line.find(" "), line.find(" ") + 1);
			int secondint = std::stoi(second);
			secondint = secondint + 1;
			std::cout << first << "'s number of played games is: " << second << std::endl;
		}
	}
}

void AccountManager::SaveUser(std::string username, int playedGames)
{
	m_user.push_back(std::make_pair(username, playedGames));
	SaveRegisteredUsersInFile();
}

void AccountManager::SaveRegisteredUsersInFile(std::vector<std::pair<std::string, int>> user)
{
	std::ofstream out;
	out.open("AllRegisteredUsers.txt", std::ios::app);
	out.close();
}

void AccountManager::SaveRegisteredUsersInFile()
{
	std::ofstream out;
	out.open("AllRegisteredUsers.txt", std::ios::app);
	for (auto& it : m_user)
	{
		if (!FoundUserInFile("AllRegisteredUsers.txt", it.first))
			out << it.first << " " << it.second << "\n";
	}
	out.close();
}

void AccountManager::SaveLoggedInUsers(std::string username)
{
	std::ofstream out;
	out.open("LoggedInUsers.txt", std::ios::app);
	out << username << "\n";
	out.close();
}

void AccountManager::Login(std::string username)
{
	if (!std::regex_search(username, std::regex("[A - Za-z0-9_]+")))
	{
		throw "Please enter a valid username format.\n";
	}
	else
	{
		if (!FoundUserInFile("AllRegisteredUsers.txt", username))
		{
			std::cout << "The username " << username << " doesn't exists. Exit and sign-up." << std::endl;
		}
		else
		{
			std::cout << "Welcome " << username << "!" << std::endl;
		}
	}
}

void AccountManager::SignUp(std::string username)
{
	if (!FoundUserInFile("AllRegisteredUsers.txt", username))
	{
		if (std::regex_search(username, std::regex("[A - Za-z0-9_]+")))
		{
			SaveUser(username, 0);
			std::cout << "Thank you for choosing to be with us. Enjoy your stay!\n";
		}
		else
		{
			throw "Please enter a valid username format.\n";
		}

	}
	else
	{
		std::cout << "The username " << username << " already exists." << std::endl;
	}
}
