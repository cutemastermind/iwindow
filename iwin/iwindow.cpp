#include "iwindow.h"

void ibutton(irect rect, ibrush_t* hbrush, HDC* thdc)
{
	//icolorset(ICOLBLUE, hbrush);
	ibutton_t::create_button(ivector2d(rect.x, rect.y), rect.width, rect.height, hbrush, thdc);
}

void itextsz(int posx, int posy, const char* string, HDC* thdc)
{
	SetTextColor((*thdc), RGB(0, 0, 0));
	SetBkMode(*thdc, TRANSPARENT);
	TextOutA((*thdc), posx, posy, string, strlen(string));
}

void itextsz_colored(int posx, int posy, const char* string, COLORREF text_colour, HDC* thdc)
{
	SetTextColor(*thdc, text_colour);
	SetBkMode(*thdc, TRANSPARENT);
	TextOutA(*thdc, posx, posy, string, strlen(string));
}

void icheckbox(irect rect, ibrush_t* hbrush, HDC* thdc)
{
	ibutton_t::create_checkbox(ivector2d(rect.x, rect.y), rect.width, rect.height, hbrush, thdc);
}

ibrush_t icolorset(icolor_t icol, ibrush_t* hbrush)
{
	icolor ticol(210, 205, 200);

	switch (icol)
	{
	case ICOLWHITE:
	{

		ticol.r = 230;
		ticol.g = 230;
		ticol.b = 230;

	}break;
	case ICOLRED:
	{

		ticol.r = 230;
		ticol.g = 10;
		ticol.b = 15;

	}break;
	case ICOLBLUE:
	{

		ticol.r = 15;
		ticol.g = 10;
		ticol.b = 230;

	}break;
	case ICOLGREEN:
	{

		ticol.r = 5;
		ticol.g = 240;
		ticol.b = 10;

	}break;
	case ICOLBLACK:
	{

		ticol.r = 10;
		ticol.g = 10;
		ticol.b = 10;

	}break;
	case ICOLGRAY:
	{
		ticol.r = 35;
		ticol.g = 36;
		ticol.b = 35;
	}break;
	case ICOLCYAN:
	{
		ticol.r = 27;
		ticol.g = 159;
		ticol.b = 171;
	}break;
	case ICOLPINK:
	{
		ticol.r = 163;
		ticol.g = 44;
		ticol.b = 122;
	}break;
	default:
	{
		ticol.r = 25;
		ticol.g = 25;
		ticol.b = 25;
	}
	break;
	}

	(*hbrush) = CreateSolidBrush(icolor::set_icolor(ticol.r, ticol.g, ticol.b));
	if (*hbrush == NULL) {
		// Handle error
		MessageBox(NULL, L"Failed to create brush", L"Error", MB_OK);
	}

	return (*hbrush);
}