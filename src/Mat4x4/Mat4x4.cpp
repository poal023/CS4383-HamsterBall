#include "Mat4x4.h"
#include <cassert>

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
        matVals[i] = (float)value;
    } 
}

Mat4x4::Mat4x4(const Mat4x4& srcMat){
    for(int i = 0; i < 16; i++){
        matVals[i] = (float)srcMat.matVals[i];
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
    for(int a = 0; a < 4; a+=1){
        for(int c = 0; c < 4; c+=1){
            sum = 0.0f;
            for(int b = 0; b < 4; b+=1){
                
                sum = sum + (LHS(a,b) * RHS(b,c));
            }
            result(a,c) = sum;
        }
        
    }
    return result;
    
}


Mat4x4 operator*(const float& scalarAmp, const Mat4x4& RHS){
    Mat4x4 newMat = Mat4x4();
    for(int i = 0; i < 16; i+=1){
        newMat.matVals[i] = scalarAmp * RHS.matVals[i];
    }
    return Mat4x4(newMat);
    
}
Mat4x4 operator+(const Mat4x4& LHS, const Mat4x4& RHS){
    float newMatVals[16];
    for(int i = 0; i < 16; i+=1){
        newMatVals[i] = LHS.matVals[i] + RHS.matVals[i];
    }
    return Mat4x4(newMatVals);
}

//to do: add rest
