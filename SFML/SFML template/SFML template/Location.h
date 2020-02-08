#pragma once


struct Location {
	int x;
	int y;



	Location& operator +=(const Location& other) {
		x = x + other.x;
		y = y + other.y;
		return *this;
	}
};