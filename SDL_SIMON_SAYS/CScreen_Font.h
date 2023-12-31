#pragma once
#ifndef _CSCREEN_H_
#define _CSCREEN_H_

#include "CScreen.h"
class CScreen_Font : public CScreen
{
public:
    CScreen_Font(int size);
    ~CScreen_Font();
    void drawFont(const char* text, int x, int y, int r, int g, int b);
    void drawFont(SDL_Surface* screenDest, const char* text, int x, int y, int r, int g, int b);

private:
    TTF_Font* font;
};

#endif
