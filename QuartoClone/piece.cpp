module piece;

import <format>;

using quarto::Piece;
using enum Piece::Body;
using enum Piece::Color;
using enum Piece::Height;
using enum Piece::Shape;

void Piece::swap(Piece& other) noexcept {
	Body tempBody{ m_body };       m_body = other.m_body;     other.m_body = tempBody;
	Color tempColor{ m_color };    m_color = other.m_color;   other.m_color = tempColor;
	Height tempHeight{ m_height }; m_height = other.m_height; other.m_height = tempHeight;
	Shape tempShape{ m_shape };    m_shape = other.m_shape;   other.m_shape = tempShape;
}

Piece::Piece() : Piece{ NO_BODY, NO_COLOR, NO_HEIGHT, NO_SHAPE } {}

Piece::Piece(Body body, Color color, Height height, Shape shape) : m_body{ body }, m_color{ color }, m_height{ height }, m_shape{ shape } { static_assert(sizeof(*this) <= 2, "This class should be at most 2 bytes in size"); }

Piece::Piece(const Piece& other) : Piece{ other.m_body, other.m_color, other.m_height, other.m_shape } {}

Piece& Piece::operator=(const Piece& other) {
	if (this != &other) { Piece temp{ other }; swap(temp); }
	return *this;
}

Piece::Piece(Piece&& other) noexcept { this->swap(other); }

Piece& Piece::operator=(Piece&& other) noexcept {
	if (this != &other) this->swap(other);
	return *this;
}

Piece::~Piece() { m_body = NO_BODY; m_color = NO_COLOR; m_height = NO_HEIGHT; m_shape = NO_SHAPE; }

Piece::Body Piece::GetBody() const { return m_body; }

Piece::Color Piece::GetColor() const { return m_color; }

Piece::Height Piece::GetHeight() const { return m_height; }

Piece::Shape Piece::GetShape() const { return m_shape; }

void Piece::SetBody(Body body) { m_body = body; }

void Piece::SetColor(Color color) { m_color = color; }

void Piece::SetHeight(Height height) { m_height = height; }

void Piece::SetShape(Shape shape) { m_shape = shape; }

void swap(Piece& piece1, Piece& piece2) noexcept { piece1.swap(piece2); }

std::istream& operator>>(std::istream& is, Piece& piece) {
	int bodyInt, colorInt, heightInt, shapeInt;
	is >> bodyInt >> colorInt >> heightInt >> shapeInt;
	piece.SetBody(static_cast<Piece::Body>(bodyInt));
	piece.SetColor(static_cast<Piece::Color>(colorInt));
	piece.SetHeight(static_cast<Piece::Height>(heightInt));
	piece.SetShape(static_cast<Piece::Shape>(shapeInt));
	return is;
}

std::ostream& operator<<(std::ostream& os, const Piece& piece) {
	return os << std::format("{}{}{}{}", static_cast<int>(piece.GetBody()), static_cast<int>(piece.GetColor()), static_cast<int>(piece.GetHeight()), static_cast<int>(piece.GetShape()));
}