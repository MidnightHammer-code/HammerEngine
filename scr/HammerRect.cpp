#include "../include/HammerEngine/HammerRect.h"

HammerRectCube::HammerRectCube(int X, int Y, int Z, int W, int H, int D){
	x = X;
	y = Y;
	z = Z;

	w = W;
	h = H;
	d = D;
}

bool HammerRectCube::HammerRectCollideRectCube(HammerRectCube rect) {
    return (
        x < rect.x + rect.w && x + w > rect.x &&
        y < rect.y + rect.h && y + h > rect.y &&
        z < rect.z + rect.d && z + d > rect.z
    );
}


HammerRectCubeF::HammerRectCubeF(float X, float Y, float Z, float W, float H, float D){
	x = X;
	y = Y;
	z = Z;

	w = W;
	h = H;
	d = D;
}

bool HammerRectCubeF::HammerRectCollideRectCubeF(HammerRectCubeF rect) {
    return (
        x < rect.x + rect.w && x + w > rect.x &&
        y < rect.y + rect.h && y + h > rect.y &&
        z < rect.z + rect.d && z + d > rect.z
    );
}



HammerRectSquare::HammerRectSquare(int X, int Y, int W, int H){
	x = X;
	y = Y;

	w = W;
	h = H;
}

bool HammerRectSquare::HammerRectCollideRectSquare(HammerRectSquare rect) {
    return (
        x < rect.x + rect.w && x + w > rect.x &&
        y < rect.y + rect.h && y + h > rect.y
    );
}



HammerRectSquareF::HammerRectSquareF(float X, float Y, float W, float H){
	x = X;
	y = Y;

	w = W;
	h = H;
}

bool HammerRectSquareF::HammerRectCollideRectSquareF(HammerRectSquareF rect) {
    return (
        x < rect.x + rect.w && x + w > rect.x &&
        y < rect.y + rect.h && y + h > rect.y
    );
}