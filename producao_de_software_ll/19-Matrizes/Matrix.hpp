#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <iostream>

class Matrix{
	private:
		int row, col;
		std::vector<std::vector<int>> matrix;
	public:
		void buildMatrix(std::vector<int>);
		Matrix(int, int);
		int getRow();
		int getCol();
		std::vector<std::vector<int>> getMatrix();
		void showMatrix();
		void setMatrix(std::vector<std::vector<int>>);
};

#endif
