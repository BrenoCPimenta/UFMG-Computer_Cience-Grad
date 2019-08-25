#include "Matrix.hpp"

void Matrix::buildMatrix(std::vector<int> values){
	int cnt = 0;
	for(int i=0; i<this->row; i++){
		for(int j=0; j<this->col; j++){
			this->matrix[i][j] = values[cnt];
			cnt++;
		}
	}
}

Matrix::Matrix(int r, int c):row(r),col(c){}

int Matrix::getRow(){
	return this->row;
}

int Matrix::getCol(){
	return this->col;
}

std::vector<std::vector<int>> Matrix::getMatrix(){
	return this->matrix;
}

void Matrix::showMatrix(){
	for(int i=0; i<this->row; i++){
		for(int j=0; i<this->col; j++){
			cout<<this->matrix[i][j];
		}
		cout<<endl;
	}
}

void Matrix::setMatrix(std::vector<std::vector<int>> inMatrix){
       this->matrix = inMatrix;
}       
