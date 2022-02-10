#include <cmath>
#include "Vector3.h"

Vector3::Vector3(){
	x = 0;
	y = 0;
	z = 0;
}

Vector3::~Vector3() {
    
}


Vector3::Vector3(const Vector3& srcVec){
    x = srcVec.x;
    y = srcVec.y;
    z = srcVec.z;    
}

Vector3::Vector3(float xComp, float yComp, float zComp){
	x = xComp;
	y = yComp;
	z = zComp;
}

Vector3& operator+(const Vector3& LHS, const Vector3& RHS){
	Vector3 *V3 = new Vector3(LHS.x + RHS.x, LHS.y + RHS.y, LHS.z + RHS.z);
	return *V3;
}


float operator*(const Vector3& LHS, const Vector3& RHS){
	return (LHS.x * RHS.x) + (LHS.y * RHS.y) + (LHS.z * RHS.z);
}

Vector3& operator*(const float& scalarAmp, const Vector3& RHS){
	Vector3 *V3 = new Vector3(scalarAmp * RHS.x, scalarAmp * RHS.y, scalarAmp * RHS.z);
	return *V3;
}


Vector3& operator%(const Vector3& LHS, const Vector3& RHS){
	Vector3 *V3 = new Vector3((LHS.y*RHS.z - LHS.z*RHS.y), (LHS.z*RHS.x - LHS.x*RHS.z), (LHS.x*RHS.y - LHS.y*RHS.x));
	return *V3;
}

float Vector3::vecMagnitude(){
	return sqrt((x * x) + (y * y) + (z * z));
}

Vector3 Vector3::normalizedVec(){
	return Vector3((x * (1/vecMagnitude())), (y * (1/vecMagnitude())), (z * (1/vecMagnitude())));
} 
