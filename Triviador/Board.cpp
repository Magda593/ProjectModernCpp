#include "Board.h"
const std::string kEmptyBoardCell = " ____ ";

void Board::SetNumberOfPlayers(int numberOfPlayers)
{
	this->m_numberOfPlayers = numberOfPlayers;
}

void Board::SetWidth(int width)
{
	this->m_kWidth = width;
}

void Board::SetHeight(int height)
{
	this->m_kHeight = height;
}

void Board::SetSize()
{
	this->m_kSize = m_kWidth * m_kHeight;
}

void Board::SetBoard()
{
	switch (m_numberOfPlayers)
	{
	case 2:
	{
		SetWidth(3);
		SetHeight(3);
		SetSize();
		break;
	}
	case 3:
	{
		SetWidth(3);
		SetHeight(5);
		SetSize();
		break;
	}
	case 4:
	{
		SetWidth(4);
		SetHeight(6);
		SetSize();
		break;
	}
	default:
	{
		std::cout << "We can't do a game with that number of players :(";
		break;
	}
	}
}

void Board::MakeBoard()
{
	for (int i = 0; i < m_kHeight; i++)
	{
		std::vector<std::string> curent;
		for (int j = 0; j < m_kWidth; j++)
		{
			curent.push_back(kEmptyBoardCell);
		}
		m_board.push_back(curent);
	}
}

void Board::ChangeBoard(int line, int column)
{
	m_board[line][column] = "  100 ";
	//m_board[line][column] = simpleRegion;
}

int Board::GetSize()
{
	return m_kSize;
}

void Board::Test()
{
	std::cout << "Nr Players: " << m_numberOfPlayers;
	std::cout << "\n";
	std::cout << "Width " << m_kWidth;
	std::cout << "\n";
	std::cout << "Height " << m_kHeight;
	std::cout << "\n";
	std::cout << "Board size: " << m_kSize;
	std::cout << "\n";
}

std::ostream& operator<<(std::ostream& out, const Board& board)
{
	for (int i = 0; i < board.m_kHeight; i++)
	{
		for (int j = 0; j < board.m_kWidth; j++)
		{
			out << board.m_board[i][j];
		}
		out << "\n";
	}
	return out;
}