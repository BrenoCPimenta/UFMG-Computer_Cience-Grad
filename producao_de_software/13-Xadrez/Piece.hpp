#ifndef PIECE_H
#define PIECE_H

#include <string>

class Piece{
	public:
		Piece(std::string, std::string, std::string);
		virtual void setMovements() {};
};

class Rook : public Piece{
	public:
};

class Bishop : public Piece{
	public:
};

class Knight : public Piece{
	public:
};

#endif