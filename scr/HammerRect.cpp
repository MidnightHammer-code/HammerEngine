#include "../include/HammerEngine/HammerRect.h"

// Rect cube noF

HammerRectCube::HammerRectCube(int X, int Y, int Z, int W, int H, int D){
	this->x = X;
	this->y = Y;
	this->z = Z;

	this->w = W;
	this->h = H;
	this->d = D;
}

int HammerRectCube::HammerRectCollideFaceCube(HammerRectCube box) {
    if (this->x < box.x + box.w &&
        this->x + this->w > box.x &&
        this->y < box.y + box.h &&
        this->y + this->h > box.y &&
        this->z < box.z + box.d &&
        this->z + this->d > box.z) 
    {
        int overlapLeft   = (box.x + box.w) - this->x;
        int overlapRight  = (this->x + this->w) - box.x;
        int overlapBottom = (box.y + box.h) - this->y; // Assuming Y is up
        int overlapTop    = (this->y + this->h) - box.y;
        int overlapFront  = (box.z + box.d) - this->z;
        int overlapBack   = (this->z + this->d) - box.z;

        int minOverlap = overlapLeft;
        int face = 1; // Left

        if (overlapTop < minOverlap) {
            minOverlap = overlapTop;
            face = 2;
        }
        if (overlapRight < minOverlap) {
            minOverlap = overlapRight;
            face = 3;
        }
        if (overlapBottom < minOverlap) {
            minOverlap = overlapBottom;
            face = 4;
        }
        if (overlapFront < minOverlap) {
            minOverlap = overlapFront;
            face = 5;
        }
        if (overlapBack < minOverlap) {
            minOverlap = overlapBack;
            face = 6;
        }

        return face;
    }

    /*
    return 0 is that there is no collision
	return 1 is the left side
	return 2 is the top
	return 3 is the right side
	return 4 is to bottum side
	return 5 is front side
	return 6 is back side
    */

    return 0; // No collision
}

bool HammerRectCube::HammerRectCollideCube(HammerRectCube rect) {
    return (
        this->x < rect.x + rect.w && this->x + this->w > rect.x &&
        this->y < rect.y + rect.h && this->y + this->h > rect.y &&
        this->z < rect.z + rect.d && this->z + this->d > rect.z
    );
}

// Rect cube F

HammerRectCubeF::HammerRectCubeF(float X, float Y, float Z, float W, float H, float D){
	this->x = X;
	this->y = Y;
	this->z = Z;

	this->w = W;
	this->h = H;
	this->d = D;
}

bool HammerRectCubeF::HammerRectCollideCubeF(HammerRectCubeF rect) {
    return (
        this->x < rect.x + rect.w && this->x + this->w > rect.x &&
        this->y < rect.y + rect.h && this->y + this->h > rect.y &&
        this->z < rect.z + rect.d && this->z + this->d > rect.z
    );
}

int HammerRectCubeF::HammerRectCollideFaceCubeF(HammerRectCubeF box) {
    if (this->x < box.x + box.w &&
        this->x + this->w > box.x &&
        this->y < box.y + box.h &&
        this->y + this->h > box.y &&
        this->z < box.z + box.d &&
        this->z + this->d > box.z) 
    {
        float overlapLeft   = (box.x + box.w) - this->x;
        float overlapRight  = (this->x + this->w) - box.x;
        float overlapBottom = (box.y + box.h) - this->y; // Assuming Y is up
        float overlapTop    = (this->y + this->h) - box.y;
        float overlapFront  = (box.z + box.d) - this->z;
        float overlapBack   = (this->z + this->d) - box.z;

        float minOverlap = overlapLeft;
        int face = 1; // Left

        if (overlapTop < minOverlap) {
            minOverlap = overlapTop;
            face = 2;
        }
        if (overlapRight < minOverlap) {
            minOverlap = overlapRight;
            face = 3;
        }
        if (overlapBottom < minOverlap) {
            minOverlap = overlapBottom;
            face = 4;
        }
        if (overlapFront < minOverlap) {
            minOverlap = overlapFront;
            face = 5;
        }
        if (overlapBack < minOverlap) {
            minOverlap = overlapBack;
            face = 6;
        }

        return face;
    }

    /*
    return 0 is that there is no collision
	return 1 is the left side
	return 2 is the top
	return 3 is the right side
	return 4 is to bottum side
	return 5 is front side
	return 6 is back side
    */

    return 0; // No collision
}

// Rect square noF

HammerRectSquare::HammerRectSquare(int X, int Y, int W, int H){
	this->x = X;
	this->y = Y;

	this->w = W;
	this->h = H;
}

int HammerRectSquare::HammerRectCollideFaceSquare(HammerRectSquare rect) {
    if (this->x < rect.x + rect.w &&
        this->x + this->w > rect.x &&
        this->y < rect.y + rect.h &&
        this->y + this->h > rect.y) 
    {
        int overlapLeft   = (rect.x + rect.w) - this->x;
        int overlapRight  = (this->x + this->w) - rect.x;
        int overlapTop    = (rect.y + rect.h) - this->y;
        int overlapBottom = (this->y + this->h) - rect.y;

        int minOverlap = overlapLeft;
        int face = 1;

        if (overlapTop < minOverlap) {
            minOverlap = overlapTop;
            face = 2;
        }
        if (overlapRight < minOverlap) {
            minOverlap = overlapRight;
            face = 3;
        }
        if (overlapBottom < minOverlap) {
            minOverlap = overlapBottom;
            face = 4;
        }

        return face;
    }

    /*
    return 0 is that there is no collision
	return 1 is the left side
	return 2 is the top
	return 3 is the right side
	return 4 is to bottum side
    */

    // No collision
    return 0;
}

bool HammerRectSquare::HammerRectCollideSquare(HammerRectSquare rect) {
    return (
        this->x < rect.x + rect.w && this->x + this->w > rect.x &&
        this->y < rect.y + rect.h && this->y + this->h > rect.y
    );
}

// Rect square F

HammerRectSquareF::HammerRectSquareF(float X, float Y, float W, float H){
	this->x = X;
	this->y = Y;

	this->w = W;
	this->h = H;
}

int HammerRectSquareF::HammerRectCollideFaceSquareF(HammerRectSquareF rect) {
    if (this->x < rect.x + rect.w &&
        this->x + this->w > rect.x &&
        this->y < rect.y + rect.h &&
        this->y + this->h > rect.y) 
    {
        float overlapLeft   = (rect.x + rect.w) - this->x;
        float overlapRight  = (this->x + this->w) - rect.x;
        float overlapTop    = (rect.y + rect.h) - this->y;
        float overlapBottom = (this->y + this->h) - rect.y;

        float minOverlap = overlapLeft;
        int face = 1;

        if (overlapTop < minOverlap) {
            minOverlap = overlapTop;
            face = 2;
        }
        if (overlapRight < minOverlap) {
            minOverlap = overlapRight;
            face = 3;
        }
        if (overlapBottom < minOverlap) {
            minOverlap = overlapBottom;
            face = 4;
        }

        return face;
    }

    /*
    return 0 is that there is no collision
	return 1 is the left side
	return 2 is the top
	return 3 is the right side
	return 4 is to bottum side
    */

    // No collision
    return 0;
}

bool HammerRectSquareF::HammerRectCollideSquareF(HammerRectSquareF rect) {
    return (
        this->x < rect.x + rect.w && this->x + this->w > rect.x &&
        this->y < rect.y + rect.h && this->y + this->h > rect.y
    );
}