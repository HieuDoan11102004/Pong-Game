#pragma once

#include <SDL_ttf.h>
#include <SDL.h>

class Text
{
private:
	SDL_Surface* fontSurface;
	SDL_Texture* fontTexture;
	SDL_Rect textRectScore;


public:
	Text(const char* text, int x, int y, bool isRefreshText, SDL_Renderer* renderer, int color);
	~Text();

	void RenderFont();
};