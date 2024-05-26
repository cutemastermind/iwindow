#include "include.h"

//LRESULT CALLBACK WindowProc(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam);

int WINAPI WinMain(_In_ HINSTANCE hInst, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	if (!iwin::iwin_create(&hInst, &nCmdShow, L"windowyippy", L"someclassname"))
	{
		std::cerr << "Failed to create wndow\n";
	}

	while (1)
	{
	}

	return 0;

}

/*
LRESULT CALLBACK WindowProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lparam)
{

	switch (msg)
	{
	case WM_DESTROY:
	{

		PostQuitMessage(0);


	}
	return 0;
	case WM_PAINT:
	{

		PAINTSTRUCT paint_struct;
		HDC h_d_c = BeginPaint(wnd, &paint_struct);;

		FillRect(h_d_c, &paint_struct.rcPaint, (ibrush_t)(COLOR_WINDOW + 1));
		iwin::button(&h_d_c, "print");
		
		iwin::iwin_free();
		EndPaint(wnd, &paint_struct);

	}
	return 0;
	}

	return DefWindowProc(wnd, msg, wParam, lparam);

}*/