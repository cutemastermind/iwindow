#pragma once

#include "iwin/iwindow.h"

namespace iwin
{
	inline ibrush_t brush;

	void button(HDC* hdc, const char* label);
	void text(HDC* hdc, const char* s);

	void iwin_free();


};