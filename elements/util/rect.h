#pragma once

struct irect
{
	int x;
	int y;
	int width;
	int height;
	irect(int px, int py, int pw, int ph) : x(px), y(py), width(pw), height(ph) {}
};