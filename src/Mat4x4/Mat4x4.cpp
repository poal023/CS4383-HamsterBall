#include "Mat4x4.h"
#define _USE_MATH_DEFINES
#include <cmath>

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

Mat4x4 operator*(const Mat4x4& RHS, const float& scalarAmp){
    return scalarAmp * RHS;
}

Mat4x4 operator+(const Mat4x4& LHS, const Mat4x4& RHS){
    float newMatVals[16];
    for(int i = 0; i < 16; i++){
        newMatVals[i] = LHS.matVals[i] + RHS.matVals[i];
    }
    return Mat4x4(newMatVals);
}

Mat4x4 Mat4x4::translateMat(float Tx, float Ty, float Tz) {
    Mat4x4 TMat = identityMat();
    
    TMat(0, 3) = Tx;
    TMat(1, 3) = Ty;
    TMat(2, 3) = Tz;


    return TMat;
}

Mat4x4 Mat4x4::rotX(float degrees) {
    float radians = degrees * (M_PI / 180.0f);
    Mat4x4 TMat = identityMat();

    TMat(1, 1) = cosf(radians);
    TMat(2, 2) = cosf(radians);
    TMat(2, 1) = sinf(radians);
    TMat(1, 2) = -sinf(radians);

    return TMat;

}
Mat4x4 Mat4x4::rotY(float degrees) {
    float radians = degrees * (M_PI  / 180.0f);
    Mat4x4 TMat = identityMat();

    TMat(0, 0) = cosf(radians);
    TMat(0, 2) = cosf(radians);
    TMat(2, 1) = sinf(radians);
    TMat(2, 0) = -sinf(radians);

    return TMat;
}
Mat4x4 Mat4x4::rotZ(float degrees) {
    float radians = degrees * (M_PI  / 180.0f);
    Mat4x4 TMat = identityMat();
    
    TMat(0, 0) = cosf(radians);
    TMat(1, 1) = cosf(radians);
    TMat(1, 0) = sinf(radians);
    TMat(0, 1) = -sinf(radians);
   
    return TMat;
}

Mat4x4 Mat4x4::scaleMat(float Sx, float Sy, float Sz) {
    Mat4x4 TMat = identityMat();
    TMat(0,0) = Sx;
    TMat(1,1) = Sy;
    TMat(2,2) = Sz;
    
    return TMat;

}
