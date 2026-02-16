#ifndef QRECT_H
#define QRECT_H

#include <vector>

class QRectCube{
public:
	int x;
	int y;
	int z;

	int w;
	int h;
	int d;

	bool QRectCollideRectCube(QRectCube rect);
	QRectCube(int X, int Y, int Z, int W, int H, int D);
};


class QRectCubeF{
public:
	float x;
	float y;
	float z;

	float w;
	float h;
	float d;
	bool QRectCollideRectCubeF(QRectCubeF rect);
	QRectCubeF(float X, float Y, float Z, float W, float H, float D);
};



class QRectSquare{
public:
	int x;
	int y;

	int w;
	int h;
	bool QRectCollideRectSquare(QRectSquare rect);
	QRectSquare(int X, int Y, int W, int H);
};

class QRectSquareF{
public:
	float x;
	float y;

	float w;
	float h;
	bool QRectCollideRectSquareF(QRectSquareF rect);
	QRectSquareF(float X, float Y, float W, float H);
};

#endif
