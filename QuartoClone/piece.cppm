export module piece;

import <iostream>;
import <cstdint>;

namespace quarto {
	export class Piece {
	public:
		enum class Body : uint8_t { FULL, HOLLOW };
		enum class Color : uint8_t { DARK, LIGHT };
		enum class Height : uint8_t { SHORT, TALL };
		enum class Shape : uint8_t { ROUND, SQUARE };
	private:
		Color m_color : 1;
		Shape m_shape : 1;
		Height m_height : 1;
		Body m_body : 1;
	public:
		Piece(Body body, Color color, Height height, Shape shape);

		Color GetColor() const;
		Shape GetShape() const;
		Height GetHeight() const;
		Body GetBody() const;
	};

	export std::ostream& operator<<(std::ostream& os, const Piece& piece);
}