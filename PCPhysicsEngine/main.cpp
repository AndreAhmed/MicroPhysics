#include <SDL.h>
#include <stdbool.h>

int main(int c, char* a[])
{
	SDL_Window* W;
	if ((W = SDL_CreateWindow("it's a window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		640, 480, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL)) == NULL)
	{
		return 1;
	}
	SDL_Event Event;
	bool running = true;
	while (running)
	{
		while (SDL_PollEvent(&Event))
			if (Event.type == SDL_QUIT)
				running = false;

	}
	free(W);
	return 0;
}
