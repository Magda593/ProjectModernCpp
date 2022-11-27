#pragma once
#include <iostream>
#include <vector>
#include <string>

class Board
{
public:
	Board() = default;

	void SetNumberOfPlayers(int numberOfPlayers);
	void SetWidth(int width);
	void SetHeight(int height);
	void SetSize();
	void SetBoard();
	void MakeBoard();

	int GetSize();

	friend std::ostream& operator<<(std::ostream& out, const Board& board);

	void Test();


private:
	int m_kWidth;
	int m_kHeight;
	int m_kSize;
	int m_numberOfPlayers;

	std::vector<std::vector<std::string>> m_board;
};

