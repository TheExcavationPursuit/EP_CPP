#include "EpCube.h"

EpCube::EpCube() {
	//vbo
	glGenBuffers(1, vboID);


	glGenBuffers(1, iboID);
}

EpCube::~EpCube() {

}

void
EpCube::Render() {

}