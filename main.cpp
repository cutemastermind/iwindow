#include "include.h"

LRESULT CALLBACK WindowProc(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam);

int WINAPI WinMain(_In_ HINSTANCE hInst, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	
	const char nameforclass[] = "wtfwindowclass";

	WNDCLASS wc = {};
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInst;
	wc.lpszClassName = (LPCWSTR)nameforclass;
	
	RegisterClass(&wc);

	HWND hWnd = CreateWindowExW(
		0,
		(LPCWSTR)nameforclass,
		L"wtf_window",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,// x pos
		CW_USEDEFAULT, // y pos
		500, // width
		400, // height
		NULL,
		NULL,
		hInst,
		NULL
	);

	if (hWnd == NULL)
	{
		std::cerr << "Failed to create window\n";

		return 0;
	}

	ShowWindow(hWnd, nCmdShow);

	MSG msg = {};

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;

}

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

}