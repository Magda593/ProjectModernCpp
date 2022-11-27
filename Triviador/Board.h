#pragma once
#include <iostream>

class Board
{
public:
	Board() = default;
	Board(int kWidth, int hHeight, int kSize);

	void SetNumberOfPlayers(uint8_t numberOfPlayers);
	void SetWidth(uint8_t width);
	void SetHeight(uint8_t height);

	uint8_t GetWidth();

	void Test();


private:
	uint8_t m_kWidth;
	uint8_t m_hHeight;
	uint8_t m_kSize;
	uint8_t m_numberOfPlayers;
};

