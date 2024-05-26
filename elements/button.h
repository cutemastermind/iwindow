#pragma once
#include "util/vector.h"

struct ibutton_t
{
	ivector2d coords;
	
	ibutton_t(ivector2d coordinates, int width, int height, HDC* thdc) : coords(coordinates.pos_x, coordinates.pos_y)
	{
		Rectangle((*thdc), coordinates.pos_x, coordinates.pos_y, coordinates.pos_x + width, coordinates.pos_y + height);
	}

	static void create_button(ivector2d coordinates, int width, int height, HBRUSH* hbrush, HDC* thdc)
	{
		RECT hrect;
		hrect.left = coordinates.pos_x;
		hrect.top = coordinates.pos_y;
		hrect.right = coordinates.pos_x + width;
		hrect.bottom = coordinates.pos_y + height;

		Rectangle((*thdc), coordinates.pos_x, coordinates.pos_y, coordinates.pos_x + width, coordinates.pos_y + height);
		FillRect((*thdc), &hrect, (*hbrush));
	}
	
	static void create_checkbox(ivector2d coordinates, int width, int height, HBRUSH* hbrush, HDC* thdc)
	{
		RECT hrect;
		hrect.left = coordinates.pos_x;
		hrect.top = coordinates.pos_y;
		hrect.right = coordinates.pos_x + width;
		hrect.bottom = coordinates.pos_x + height;

		Rectangle(*thdc, coordinates.pos_x, coordinates.pos_y, coordinates.pos_x + width, coordinates.pos_y + height);
		FillRect(*thdc, &hrect, *hbrush);

	}
	
};