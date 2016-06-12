#pragma once

#include "GL\glew.h"

class EpCube {
public:
	EpCube();
	~EpCube();

	void	Render();

private:
	GLuint *vboID;
	GLuint *iboID;
};
