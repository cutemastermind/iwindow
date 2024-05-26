#pragma once
#include <windows.h>
#include "../elements/button.h"
#include "../elements/util/rect.h"
#include "../elements/util/icolor.h"

#define IWINAPI extern
#define IWINBOOL bool
#define IWINTRUE true
#define IWINFALSE false
typedef HBRUSH ibrush_t;

void ibutton(irect rect, ibrush_t* hbrush, HDC* thdc);
void itextsz(int posx, int posy, const char* string, HDC* thdc);

ibrush_t icolorset(icolor_t icol, ibrush_t* hbrush);