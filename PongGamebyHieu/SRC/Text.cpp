#include "Text.h"	
#include "GameEngine.h"

TTF_Font* GameEngine::font = nullptr;

Text::Text(const char* text, int x, int y, bool isRefreshText, SDL_Renderer* renderer, int color)
{
	if (isRefreshText) {
		SDL_Color textColor = { 255, 255, 255, 255 }; // white
		SDL_Color red = { 255, 0, 0 };

		if (color == 1)
			fontSurface = TTF_RenderText_Blended(GameEngine::font, text, textColor);
		else
			fontSurface = TTF_RenderText_Blended(GameEngine::font, text, red);

		if (fontTexture) // de-allocate previously assigned font texture, if any
			SDL_DestroyTexture(fontTexture);

		fontTexture = SDL_CreateTextureFromSurface(GameEngine::renderer, fontSurface);
		if (!fontTexture) {
			cout << "error";
			exit(1);
		}

		textRectScore = { x, y, fontSurface->w, fontSurface->h };

	}
}


void Text::RenderFont()
{
	SDL_RenderCopy(GameEngine::renderer, fontTexture, NULL, &textRectScore);
}