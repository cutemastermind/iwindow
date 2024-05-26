#pragma once
#include <windows.h>

struct irect
{
	int x;
	int y;
	int width;
	int height;
	irect(int px, int py, int pw, int ph) : x(px), y(py), width(pw), height(ph) {}
	static void irender_rect(HDC* hdc,int px, int py, int pw, int ph)
	{
		RECT trect;
		trect.left = px;
		trect.top = py;
		trect.right = pw;
		trect.bottom = ph;

		Rectangle(*hdc, px, py, pw, ph);

		HBRUSH brushy;
		brushy = CreateSolidBrush(RGB(25, 25, 25));

		FillRect(*hdc, &trect, brushy);
	}
};