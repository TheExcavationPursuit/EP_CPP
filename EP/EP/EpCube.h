#pragma once

class EpCube {
public:
	EpCube();
	~EpCube();

	void	Render();

private:
	GLuint *vboID;
	GLuint *iboID;
};
