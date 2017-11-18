#include "text.h"
#include <iostream>
#include "window.h"

Text::Text() {
	
}

Text::~Text() {
}

void Text::updateText(SDL_Renderer *renderer, const std::string &font_path, int font_size, const std::string &message_text, const SDL_Color &color) {
	_text_texture = loadFont(renderer, font_path, font_size, message_text, color);
	// Calculates the size of the character via font and messsagelength
	SDL_QueryTexture(_text_texture, nullptr, nullptr, &_text_rect.w, &_text_rect.h);
}

void Text::setPos(int x, int y){
	_x = x;
	_y = y;
}

void Text::display(SDL_Renderer *renderer) const {
	_text_rect.x = _x;
	_text_rect.y = _y;
	SDL_RenderCopy(renderer, _text_texture, nullptr, &_text_rect);
	// Delete the texture after display
	SDL_DestroyTexture(_text_texture);
}

SDL_Texture *Text::loadFont(SDL_Renderer *renderer, const std::string &font_path, int font_size, const std::string &message_text, const SDL_Color &color) {
	TTF_Font *font = TTF_OpenFont(font_path.c_str(), font_size);
	if (!font) {
		std::cout << "Failed to load font" << std::endl;
	}
	auto text_surface = TTF_RenderText_Solid(font, message_text.c_str(), color);
	if (!text_surface) {
		std::cout << "Failed to create text surface" << std::endl;
	}
	auto *text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
	if (!text_texture) {
		std::cout << "Failed to create text texture" << std::endl;
	}
	SDL_FreeSurface(text_surface);
	TTF_CloseFont(font);
	return text_texture;
}
