#pragma once
#include <SDL\SDL_ttf.h>
#include <SDL\SDL.h>
#include <string>

class Text {
public:
	Text();
	~Text();
	void display(SDL_Renderer *renderer) const;

	void updateText(SDL_Renderer *renderer, const std::string &font_path, int font_size, const std::string &message_text, const SDL_Color &color);

	void setPos(int x, int y);

	static SDL_Texture *loadFont(SDL_Renderer *renderer, const std::string &font_path, int font_size, const std::string &message_text, const SDL_Color &color);

private:
	SDL_Texture *_text_texture = nullptr;
	mutable SDL_Rect _text_rect;
	int _x, _y;
};