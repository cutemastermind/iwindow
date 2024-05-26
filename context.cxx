#pragma once
#include "context.h"

LRESULT CALLBACK WindowProc(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam);

IWINBOOL iwin::iwin_create(HINSTANCE* hInst, int* n_cmd_show, const wchar_t* window_name, const wchar_t* window_class_name)
{

	WNDCLASS window_class = {};
	window_class.lpfnWndProc = WindowProc;
	window_class.hInstance = (*hInst);
	window_class.lpszClassName = (LPCWSTR)window_class_name;

	RegisterClass(&window_class);

	HWND handlewindow = CreateWindowEx(
		NULL,
		window_class_name,
		window_name,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		IWIDTH,
		IHEIGHT,
		NULL,
		NULL,
		*hInst,
		NULL
	);

	if (handlewindow == NULL)
	{
		std::cerr << "Failed to create window" << std::endl;
		return IWINFALSE;
	}

	ShowWindow(handlewindow, *n_cmd_show);

	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return IWINTRUE;
}

void iwin::button(HDC* hdc, const char* label)
{
	
	icolorset(ICOLBLUE, &iwin::brush);

	irect button_rect(50, 50, 100, 50);

	ibutton(button_rect, &iwin::brush, hdc);
	itextsz((button_rect.x+button_rect.width)/2 + strlen(label), (button_rect.y + (button_rect.height / 2) - 7), label, hdc);

}

void iwin::iwin_free()
{
	DeleteObject(iwin::brush);
}

LRESULT CALLBACK WindowProc(HWND handlewindow, UINT messagecode, WPARAM wideparam, LPARAM longparam)
{
	switch (messagecode)
	{
	case WM_DESTROY:
	{

		PostQuitMessage(0);


	}
	return 0;
	case WM_PAINT:
	{

		PAINTSTRUCT paint_struct;
		HDC h_d_c = BeginPaint(handlewindow, &paint_struct);;

		FillRect(h_d_c, &paint_struct.rcPaint, (ibrush_t)(COLOR_WINDOW + 1));
		iwin::button(&h_d_c, "print");

		iwin::iwin_free();
		EndPaint(handlewindow, &paint_struct);

	}
	return 0;
	}

	return DefWindowProc(handlewindow, messagecode, wideparam, longparam);
}