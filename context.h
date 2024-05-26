#pragma once

#include "iwin/iwindow.h"
#include <iostream>

#define IWIDTH 500
#define IHEIGHT 400

namespace iwin
{

	IWINBOOL iwin_create(HINSTANCE* hInst, int* n_cmd_show, const wchar_t* window_name, const wchar_t* window_class_name);

	inline ibrush_t brush;

	void button(HDC* hdc, const char* label);

	void iwin_free();


};