#include "Mat4x4.h"

Mat4x4::Mat4x4(){
   for(int i = 0; i < 16; i++){
        matVals[i] = 0;
    }
};
Mat4x4::Mat4x4(const float newMatVals[16]){
    for(int i = 0; i < 16; i++){
        matVals[i] = newMatVals[i];
    }
}

Mat4x4::Mat4x4(const float& value){
    for(int i = 0; i < 16; i++){
        matVals[i] = value;
    } 
}

Mat4x4::Mat4x4(const Mat4x4& srcMat){
    for(int i = 0; i < 16; i++){
        matVals[i] = srcMat.matVals[i];
    } 
}
Mat4x4::~Mat4x4(){ 

}

float Mat4x4::operator()(const int& row, const int& col) const{
    return matVals[4*row + col];
}

float& Mat4x4::operator()(const int& row, const int& col){
    return matVals[4*row + col];
}

Mat4x4 operator*(const Mat4x4& LHS, const Mat4x4& RHS){
    Mat4x4 result = Mat4x4();
    float sum;
    for(int a = 0; a < 4; a++){
        for(int c = 0; c < 4; c++){
            sum = 0.0f;
            for(int b = 0; b < 4; b++){                
                sum = sum + (LHS(a,b) * RHS(b,c));
            }
            result(a,c) = sum;
        }
        
    }
    return result;
    
}


Mat4x4 operator*(const float& scalarAmp, const Mat4x4& RHS){
    Mat4x4 newMat = Mat4x4();
    for(int i = 0; i < 16; i++){
        newMat.matVals[i] = scalarAmp * RHS.matVals[i];
    }
    return Mat4x4(newMat);
}

Mat4x4 operator*(const Mat4x4& LHS, const float& scalarAmp){
    return scalarAmp * LHS;
}

Mat4x4 operator+(const Mat4x4& LHS, const Mat4x4& RHS){
    float newMatVals[16];
    for(int i = 0; i < 16; i++){
        newMatVals[i] = LHS.matVals[i] + RHS.matVals[i];
    }
    return Mat4x4(newMatVals);
}

