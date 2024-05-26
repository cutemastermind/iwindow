#pragma once
#include "context.h"

LRESULT CALLBACK WindowProc(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam);

int WINAPI WinMain(_In_ HINSTANCE hInst, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{

	iwin::iwin_console();
	std::cout << "Console initialized." << std::endl;

	if (iwin::iwin_create(&hInst, &nCmdShow, iwin::iwindow_name, L"iwindow_class") == NULL)
	{
		std::cerr << "Failed to create iwin_create()\n";
		return -1;
	}

	return 0;

}

IWINBOOL iwin::iwin_initialize(const wchar_t* window_name, int iwinodw_height, int iwindow_width)
{

	iwin::iwindow_name = window_name;

	HINSTANCE h_instance = GetModuleHandle(NULL);
	int n_cmd_show = SW_SHOWDEFAULT;
	LPSTR lp_cmd_line = GetCommandLineA();

	if (WinMain(h_instance, NULL, lp_cmd_line, n_cmd_show) != NULL)
	{
		std::cout << "Created window from WinMain entry point" << std::endl;
	}
	else
	{
		std::cout << "Failed to create window from WinMain entry point" << std::endl;
		return IWINFALSE;
	}

	return IWINTRUE;
}

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
		CW_USEDEFAULT, // 2D x position
		CW_USEDEFAULT, // 2D y position
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
	std::cout << "Window created successfully." << std::endl;
	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return IWINTRUE;
}

IWINUNK iwin::iwin_console()
{
	AllocConsole();
	FILE* file_ptr;
	freopen_s(&file_ptr, "CONOUT$", "w", stdout);
	freopen_s(&file_ptr, "CONOUT$", "w", stderr);
	freopen_s(&file_ptr, "CONIN$", "r", stdin);
}

ipoint_t iwin::get_cursor_pos(HWND* handlewin, ipoint_t* cur)
{
	if (GetCursorPos(cur))
	{
		ScreenToClient(*handlewin, cur);

	}

	return (*cur);
}

void iwin::button(HDC* hdc, const char* label)
{
	
	icolorset(ICOLBLUE, &iwin::brush);

	irect button_rect(50, 50, 100, 50);

	if ((iwin::tcursor.x == (button_rect.x + button_rect.width)) && (iwin::tcursor.y == (button_rect.y + button_rect.height)))
	{
		icolorset(ICOLRED, &iwin::brush);

	}
	else
		icolorset(ICOLBLUE, &iwin::brush);

	ibutton(button_rect, &iwin::brush, hdc);
	itextsz((button_rect.x+button_rect.width)/2 + strlen(label), (button_rect.y + (button_rect.height / 2) - 7), label, hdc);

}

void iwin::checkbox(HDC* hdc, const char* label)
{
	icolorset(ICOLRED, &iwin::brush);
	irect button_rect(110, 20, 25, 25);
	icheckbox(button_rect, &iwin::brush, hdc);
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

		ibrush_t bg;
		bg = CreateSolidBrush(RGB(110, 110, 110));

		FillRect(h_d_c, &paint_struct.rcPaint, bg);

		iwin::render_gui(&h_d_c);

		DeleteObject(bg);
		iwin::iwin_free();
		EndPaint(handlewindow, &paint_struct);

	}
	case WM_MOUSEMOVE:
	{
		iwin::get_cursor_pos(&handlewindow, &iwin::tcursor);

	}break;
	return 0;
	}

	return DefWindowProc(handlewindow, messagecode, wideparam, longparam);
}

void iwin::render_gui(HDC* hdc)
{
	irect::irender_rect(hdc, 20, 20, 200, 300);
	iwin::button(hdc, "print");
	iwin::checkbox(hdc, "checkbox");
	itextsz_colored(50, 150, "pos_x: ", icolor::set_icolor(200, 200, 200), hdc);
	itextsz_colored(130, 150, std::to_string(iwin::tcursor.x).c_str(), icolor::set_icolor(200, 100, 100), hdc);
	itextsz_colored(50, 200, "pos_y: ", icolor::set_icolor(255, 255, 255),hdc);
	itextsz_colored(130, 200, std::to_string(iwin::tcursor.y).c_str(), icolor::set_icolor(100, 100, 200), hdc);
}

void iwin::iwin_free()
{
	DeleteObject(iwin::brush);
}