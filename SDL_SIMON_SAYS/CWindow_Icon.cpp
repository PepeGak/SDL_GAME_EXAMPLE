#include "CWindow_Icon.h"

CWindow_Icon::CWindow_Icon()
{
    this->icon = nullptr;
};

bool CWindow_Icon::Load()
{
    this->icon = IMG_Load("./Assets/icon.png");
    if (this->icon == nullptr)
        return false;
    SDL_SetWindowIcon(this->window, this->icon);
    
    return true;
};

CWindow_Icon::~CWindow_Icon()
{
    SDL_FreeSurface(this->icon);
    this->icon = nullptr;
};
