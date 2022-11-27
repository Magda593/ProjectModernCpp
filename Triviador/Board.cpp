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

uint8_t Board::GetWidth()
{
	return m_kWidth;
}

void Board::Test()
{
	std::cout << m_numberOfPlayers;
	std::cout << m_kWidth;
}
