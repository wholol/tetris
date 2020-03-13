#pragma once


struct Location {
	double x;
	double y;

	Location& operator +=(const Location& other) {
		x = x + other.x;
		y = y + other.y;
		return *this;
	}

	bool operator !=(const Location other) const {
		return (x != other.x && y != other.y);
	}
};