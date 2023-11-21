export module piece;

import std;
using std::uint8_t;

namespace quarto {
	export class Piece {
	public:
		enum class Body : uint8_t { FULL, HOLLOW, NO_BODY };
		enum class Color : uint8_t { DARK, LIGHT, NO_COLOR };
		enum class Height : uint8_t { SHORT, TALL, NO_HEIGHT };
		enum class Shape : uint8_t { ROUND, SQUARE, NO_SHAPE };
	private:
		Body m_body : 2;
		Color m_color : 2;
		Height m_height : 2;
		Shape m_shape : 2;
	public:
		Piece();
		Piece(Body body, Color color, Height height, Shape shape);
		Piece(const Piece& other);
		Piece& operator=(const Piece& other);
		Piece(Piece&& other) noexcept;
		Piece& operator=(Piece&& other) noexcept;
		~Piece();

		void swap(Piece& other) noexcept;

		Body GetBody() const;
		Color GetColor() const;
		Height GetHeight() const;
		Shape GetShape() const;
		void SetBody(Body body);
		void SetColor(Color color);
		void SetHeight(Height height);
		void SetShape(Shape shape);
	};

	export void swap(Piece& piece1, Piece& piece2) noexcept;
	export std::istream& operator>>(std::istream& is, Piece& piece);
	export std::ostream& operator<<(std::ostream& os, const Piece& piece);
}