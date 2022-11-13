#pragma once
class Board
{
public:
	Board();
	Board(int kWidth, int hHeight, int kSize);

	void GetSize(int numberOfPlayers);

private:
	int m_kWidth;
	int m_hHeight;
	int m_kSize;
};

