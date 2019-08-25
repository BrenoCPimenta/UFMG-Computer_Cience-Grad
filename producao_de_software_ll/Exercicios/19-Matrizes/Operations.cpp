#include "Operations.hpp"
std::vector<std::vector<int>> Operations::add(std::vector<std::vector<int>> m1, std::vector<std::vector<int>> m2){
	if(m1.getRow() != m2.getRow() || m1.getCol() != m2.getCol()){
		throw exception();
	}else{
		std::vector<std::vector<int>> mres;
		for(int i=0; i<m1.getRow();i++){
			for(int j=0; j<m1.getCol(); j++){
				mres[i][j]=m1[i][j]+m2[i][j];
			}
		}
		return mres;
	}
}

std::vector<std::vector<int>> Operations::multiply(std::vector<std::vector<int>> m1, std::vector<std::vector<int>> m2){
	if(m1.getCol() != m2.getRow()){
		throw exception();
	}
	else{
		std::vector<std::vector<int>> mres;
		for(int m1i=0; m1i<m1.getRow();m1i++){
			for(int m2j=0; m2j<m2.getCol(); m2j++){
				for(int k=0; k<m1.getCol(); k++){
					//Tratamento para valores nao iniciados da matriz mres
					if(k==0){
						mres[m1i][m2j] = m1[m1i][k]*m2[k][m2j];
					}else{
      	      					mres[m1i][m2j] += m1[m1i][k]*m2[k][m2j];
					}
				}
			}
		}
		return mres;
	}
}
