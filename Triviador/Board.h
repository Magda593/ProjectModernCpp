#pragma once
#include <iostream>
#include <vector>
#include <string>
#include<optional>
#include "Region.h"

class Board
{
public:
	Board() = default;
	using Position = std::pair<int, int>;

	void SetNumberOfPlayers(int numberOfPlayers);
	void SetWidth(int width);
	void SetHeight(int height);
	void SetSize();
	void SetBoard();
	int GetSize();
	int GetNumberOfPlayers();

	bool IsFull() const;

	const std::optional<Region>& operator[] (const Position& pos) const;
	std::optional<Region>& operator[] (const Position& pos);

	friend std::ostream& operator<<(std::ostream& out, const Board& board);

	void Test();

private:
	int m_kWidth;
	int m_kHeight;
	int m_kSize;
	int m_numberOfPlayers;
	
	std::vector<std::optional<Region>> m_optBoard;
};

