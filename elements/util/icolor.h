#pragma once

typedef enum
{
	ICOLWHITE = 0,
	ICOLRED,
	ICOLBLUE,
	ICOLGREEN,
	ICOLBLACK,
	ICOLGRAY,
	ICOLCYAN,
	ICOLPINK
} icolor_t;

struct icolor
{
	int r;
	int g;
	int b;
	icolor(int pr, int pg, int pb) : r(pr), b(pb), g(pg) { RGB(r, g, b); }

	static COLORREF set_icolor(int r, int g, int b)
	{

		return RGB(r, g, b);
	}


};