#pragma once

#include "iwin/iwindow.h"
#include <iostream>
#include <string>

#define IWIDTH 500
#define IHEIGHT 400

namespace iwin
{

	IWINBOOL iwin_create(HINSTANCE* hInst, int* n_cmd_show, const wchar_t* window_name, const wchar_t* window_class_name);
	IWINBOOL iwin_initialize(const wchar_t* window_name, int iwinodw_height, int iwindow_width);
	IWINUNK iwin_console();

	ipoint_t get_cursor_pos(HWND* handlewin, ipoint_t* cur);

	inline const wchar_t* iwindow_name;
	static inline ipoint_t tcursor;
	inline ibrush_t brush;
	
	void button(HDC* hdc, const char* label);
	void checkbox(HDC* hdc, const char* label);

	// define this functin in your main loop and include all elements you wanna render in your interface
	void render_gui(HDC* hdc);
	// free all objects and healp shit
	void iwin_free();


};