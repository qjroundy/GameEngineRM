#include <GL/glew.h>
#include <GL/GL.h>
#include <GLFW/glfw3.h>

#include <glm/common.hpp>

#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alut.h>

int main(int argc, char ** argv)
{
	glfwInit();
	glewInit();



	alutInit(&argc, argv);
	auto m = alcOpenDevice(NULL);
	auto c = alcCreateContext(m, NULL);

	return 0;
}