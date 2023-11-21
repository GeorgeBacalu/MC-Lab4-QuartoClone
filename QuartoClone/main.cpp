import std;

import board;

int main() {
	using namespace quarto;
	using enum Piece::Body;
	using enum Piece::Color;
	using enum Piece::Height;
	using enum Piece::Shape;
	Piece piece{ FULL, DARK, SHORT, SQUARE };
	std::cout << "Full, Dark, Short, Square piece: " << piece << "\n";
	Board board;
	std::cout << "Empty board:\n" << board;
	board[{0, 0}] = std::move(piece);
	std::cout << "Moved piece to board:\n" << board;
}