module board;

using namespace quarto;

std::string_view kEmptyBoardCell{"____"};

const std::optional<Piece>& Board::operator[](const Position& position) const {
	const auto& [row, column] = position;
	return m_pieces[row * kWidth + column];
}

std::optional<Piece>& Board::operator[](const Position& position) {
	return const_cast<std::optional<Piece>&>(std::as_const(*this)[position]);
}

std::ostream& operator<<(std::ostream& os, const Board& board) {
    Board::Position position;
    auto& [row, column] = position;
    for (; row < Board::kHeight; ++row) {
        for (column = 0; column < Board::kWidth; ++column) {
            if (const auto& pieceOptional{ board[position] }; pieceOptional.has_value())
                os << pieceOptional.value();
            else
                os << kEmptyBoardCell;
            // or
            // const auto& pieceOptional = board[position];
            // os << (pieceOptional.has_value() ? pieceOptional.value() : kEmptyBoardCell);
            os << ' ';
        }
        os << "\n";
    }
    return os;
}