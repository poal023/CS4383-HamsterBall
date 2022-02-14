#include "Mat4x4.h"

Mat4x4::Mat4x4(){
    matVals = {0};
};
Mat4x4::Mat4x4(const float& newMatVals[16]){
    matVals = newMatVals;
}
Mat4x4::Mat4x4(const Mat4x4& srcMat){
    matVals = srcMat.matVals;
}
virtual Mat4x4::~Mat4x4(){ 

};

float& operator()(const int& row, const int& col){
    return matVals[4*row + col];
}

//to do: add rest