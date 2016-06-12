#include "EpCube.h"
#include "GL\glew.h"

EpCube::EpCube() {
	//vbo
	glGenBuffers(1, vboID);

	//ibo
	glGenBuffers(1, iboID);
}

EpCube::~EpCube() {

}

void
EpCube::Render() {

}