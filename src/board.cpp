﻿#include "board.h"
// test
std::map<Mass::status, MassInfo> Mass::statusData =
{
	{ BLANK, { 1.0f, ' '}},
	{ WALL,  {-1.0f, '#'}},
	{ WATER, { 3.0f, '~'}},
	{ ROAD,  { 0.3f, '$'}},

	// 動的な要素
	{ START,	{-1.0f, 'S'}},
	{ GOAL,		{-1.0f, 'G'}},
	{ WAYPOINT, {-1.0f, 'o'}},

	{ INVALID,  {-1.0f, '\0'}},
};


bool Board::find(const Point& 始点, const Point& 終点, std::vector<std::vector<Mass>> &mass) const
{
	mass[始点.y][始点.x].set(Mass::START);
	mass[終点.y][終点.x].set(Mass::GOAL);

	// 経路探索
	Point 現在 = 始点;
	while (現在 != 終点) {
		// 歩いた場所に印をつける(見やすさのために始点は書き換えない)
		if (現在 != 始点){mass[現在.y][現在.x].set(Mass::WAYPOINT);}

		// 終点に向かって歩く
		if (現在.x < 終点.x) { 現在.x++; continue; }
		if (終点.x < 現在.x) { 現在.x--; continue; }
		if (現在.y < 終点.y) { 現在.y++; continue; }
		if (終点.y < 現在.y) { 現在.y--; continue; }
	}

	return true;
}
