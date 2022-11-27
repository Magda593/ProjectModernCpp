#include "Board.h"

Board::Board()
{
}

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

void Board::GetSize(int numberOfPlayers)
{
	if (numberOfPlayers == 2)
	{
		m_kWidth = 3;
		m_hHeight = 3;
		m_kSize = m_kWidth * m_hHeight;
	}
	if (numberOfPlayers == 3)
	{
		m_kWidth = 3;
		m_hHeight = 5;
		m_kSize = m_kWidth * m_hHeight;
	}
	if (numberOfPlayers == 4)
	{
		m_kWidth = 4;
		m_hHeight = 6;
		m_kSize = m_kWidth * m_hHeight;
	}
}
