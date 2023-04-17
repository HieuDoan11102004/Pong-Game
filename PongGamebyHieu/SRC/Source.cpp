#include "GameEngine.h"

int TARGET_FPS = 150;
float FRAME_TIME = 1000.0f / TARGET_FPS;

int main(int argc, char* argv[]) {

	if (!GameEngine::Instance()->InitGameEngine()) return -1;

	GameEngine::Instance()->InitGameWorld();
	GameEngine::Instance()->Music();
	while (GameEngine::Instance()->IsMenuRunning())
	{
		GameEngine::Instance()->setMenu();
	}

	while (GameEngine::Instance()->IsRunning()) { // Setup game loop
		Uint32 frameStart = SDL_GetTicks();

		GameEngine::Instance()->Input();
		GameEngine::Instance()->Update();
		GameEngine::Instance()->Render();

		Uint32 frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < FRAME_TIME) {
			SDL_Delay(FRAME_TIME - frameTime);
		}
	}

	GameEngine::Instance()->Quit(); //system("pause"); // not needed because of Quit()
	return 0;
}