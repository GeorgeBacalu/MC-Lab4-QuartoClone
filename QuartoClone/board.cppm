export module board;

export import piece;

import std;
using std::uint16_t;

namespace quarto {
	export class Board {
	public:
		using Position = std::pair<size_t, size_t>;

		static const uint16_t kWidth{ 4 };
		static const uint16_t kHeight{ 4 };

		Board() = default;

		const std::optional<Piece>& operator[](const Position& position) const;
		std::optional<Piece>& operator[](const Position& position);

		/*template<class S>
		auto&& operator[](this S&& self, const Position& position) {
			const auto& [row, column] = position;
			return self.m_pieces[row * kWidth + column];
		}*/
	private:
		static const size_t kSize{ kWidth * kHeight };
		std::array<std::optional<Piece>, kSize> m_pieces;
	};

	export std::ostream& operator<<(std::ostream& os, const Board& board);
}