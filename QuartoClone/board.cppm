export module board;

export import piece;

import <array>;
import <optional>;

namespace quarto {
	constexpr uint16_t BOARD_SIZE = 4;

	export class Board {
		std::array<std::optional<Piece>, BOARD_SIZE* BOARD_SIZE> m_board;
	};
}