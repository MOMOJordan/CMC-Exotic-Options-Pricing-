//
// Created by Jordan MOMO JUPOU on 13/05/2024.
//
#include <vector>;
using namespace std;

template <class T>
class matrix{
    //Dimensions
    int n_rows;
    int n_cols;

    //Data
    vector<T> myVector;

public:

    using value_type=T;

    matrix():n_rows(0),n_cols(0){}
    matrix(const int n_rows, const int n_cols):n_rows(n_rows),n_cols(n_cols),myVector(n_rows*n_cols){}

    int rows() const {return n_rows;};
    int cols() const {return n_cols;};

    T* operator[] (const int row){
        return &myVector[row*n_cols];
    }
    const T* operator[] (const int row) const{
        return &myVector[row*n_cols];
    }
};