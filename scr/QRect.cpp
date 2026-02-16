#include "../include/QEngine/QRect.h"

QRectCube::QRectCube(int X, int Y, int Z, int W, int H, int D){
	x = X;
	y = Y;
	z = Z;

	w = W;
	h = H;
	d = D;
}

bool QRectCube::QRectCollideRectCube(QRectCube rect) {
    return (
        x < rect.x + rect.w && x + w > rect.x &&
        y < rect.y + rect.h && y + h > rect.y &&
        z < rect.z + rect.d && z + d > rect.z
    );
}


QRectCubeF::QRectCubeF(float X, float Y, float Z, float W, float H, float D){
	x = X;
	y = Y;
	z = Z;

	w = W;
	h = H;
	d = D;
}

bool QRectCubeF::QRectCollideRectCubeF(QRectCubeF rect) {
    return (
        x < rect.x + rect.w && x + w > rect.x &&
        y < rect.y + rect.h && y + h > rect.y &&
        z < rect.z + rect.d && z + d > rect.z
    );
}



QRectSquare::QRectSquare(int X, int Y, int W, int H){
	x = X;
	y = Y;

	w = W;
	h = H;
}

bool QRectSquare::QRectCollideRectSquare(QRectSquare rect) {
    return (
        x < rect.x + rect.w && x + w > rect.x &&
        y < rect.y + rect.h && y + h > rect.y
    );
}



QRectSquareF::QRectSquareF(float X, float Y, float W, float H){
	x = X;
	y = Y;

	w = W;
	h = H;
}

bool QRectSquareF::QRectCollideRectSquareF(QRectSquareF rect) {
    return (
        x < rect.x + rect.w && x + w > rect.x &&
        y < rect.y + rect.h && y + h > rect.y
    );
}