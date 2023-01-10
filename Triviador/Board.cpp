#include "Board.h"
const std::string kEmptyBoardCell = "____";

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
	m_optBoard.resize(m_kSize);
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

const std::optional<Region>& Board::operator[](const Position& pos) const
{
	const auto& [line, column] = pos;

	if (line >= m_kHeight || column >= m_kWidth)
		throw "Board index out of bound.";

	return m_optBoard[line * m_kWidth + column];
}

std::optional<Region>& Board::operator[](const Position& pos)
{
	const auto& [line, column] = pos;

	if (line >= m_kHeight || column >= m_kWidth)
		throw "Board index out of bound.";

	return m_optBoard[line * m_kWidth + column];
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
	static const int height = board.m_kHeight;
	static const int width = board.m_kWidth;

	Board::Position position;
	auto& [line, column] = position;

	for (line = 0; line < height; ++line)
	{
		for (column = 0; column < width; ++column)
		{
			if (board[position])
				out << *board[position];
			else
				out << kEmptyBoardCell;	
			out << ' ';
		}
		out << std::endl;
	}
	return out;
}