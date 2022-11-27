#include "Board.h"


Board::Board(int kWidth, int hHeight, int kSize):
	m_kWidth(kWidth),
	m_hHeight(hHeight),
	m_kSize(kSize)
{
}

void Board::SetNumberOfPlayers(uint8_t numberOfPlayers)
{
	this->m_numberOfPlayers = numberOfPlayers;
}

void Board::SetWidth(uint8_t width)
{
	this->m_kWidth = width;
}

void Board::SetHeight(uint8_t height)
{
	this->m_hHeight = height;
}

void Board::SetSize()
{
	this->m_kSize = m_kWidth * m_hHeight;
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

void Board::Test()
{
	std::cout << m_numberOfPlayers;
	std::cout << m_kWidth;
}
