#pragma once
#include "context.h"

void iwin::button(HDC* hdc, const char* label)
{
	
	icolorset(ICOLBLUE, &iwin::brush);

	irect button_rect(50, 50, 100, 50);

	ibutton(button_rect, &iwin::brush, hdc);
	itextsz((button_rect.x+button_rect.width)/2 + strlen(label), (button_rect.y + (button_rect.height / 2) - 7), label, hdc);

}

void iwin::text(HDC* hdc, const char* s)
{

}

void iwin::iwin_free()
{
	DeleteObject(iwin::brush);
}