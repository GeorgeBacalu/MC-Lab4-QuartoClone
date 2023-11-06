import <iostream>;

import board;

int main() {
	using namespace quarto;
	using enum Piece::Color;
	using enum Piece::Shape;
	using enum Piece::Height;
	using enum Piece::Body;
	Piece piece{ FULL, DARK, SHORT, SQUARE };
	std::cout << "Full, Dark, Short, Square piece: " << piece << "\n";
}