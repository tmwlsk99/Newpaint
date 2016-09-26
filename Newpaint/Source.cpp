#include <GLFW/glfw3.h>
#include <cstring>
#include <stdlib.h>		  // srand, rand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "math.h"

const int width = 600;
const int height = 400;
double xpos, ypos;
float* pixels = new float[width*height * 3];

bool IsinsideCircle1(const double x, const double y)
{
	double x_c = 60.0;
	double y_c = 60.0;
	double r = 40.0;
	double sol = ((x - x_c)*(x - x_c)) + ((y - y_c)*(y - y_c)) - (r*r);
	if (sol < 0.0)
		return true;
	else
		return false;
}

bool IsinsideCircle2(const double x, const double y)
{
	double x_c = 180.0;
	double y_c = 60.0;
	double r = 40.0;
	double sol = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r*r;
	if (sol < 0.0)
		return true;
	else
		return false;
}

bool IsinsideCircle3(const double x, const double y)
{
	double x_c = 300.0;
	double y_c = 60.0;
	double r = 40.0;
	double sol = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r*r;
	if (sol < 0.0)
		return true;
	else
		return false;
}

bool IsinsideCircle4(const double x, const double y)
{
	double x_c = 420.0;
	double y_c = 60.0;
	double r = 40.0;
	double sol = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r*r;
	if (sol < 0.0)
		return true;
	else
		return false;
}

bool IsinsideCircle5(const double x, const double y)
{
	double x_c = 540.0;
	double y_c = 60.0;
	double r = 40.0;
	double sol = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r*r;
	if (sol < 0.0)
		return true;
	else
		return false;
}

bool IsinsideCircle6(const double x, const double y)
{
	double x_c = 60.0;
	double y_c = 250.0;
	double r = 40.0;
	double sol = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r*r;
	if (sol < 0.0)
		return true;
	else
		return false;
}

bool IsinsideCircle7(const double x, const double y)
{
	double x_c = 180.0;
	double y_c = 250.0;
	double r = 40.0;
	double sol = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r*r;
	if (sol < 0.0)
		return true;
	else
		return false;
}

bool IsinsideCircle8(const double x, const double y)
{
	double x_c = 300.0;
	double y_c = 250.0;
	double r = 40.0;
	double sol = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r*r;
	if (sol < 0.0)
		return true;
	else
		return false;
}
bool IsinsideCircle9(const double x, const double y)
{
	double x_c = 420.0;
	double y_c = 250.0;
	double r = 40.0;
	double sol = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r*r;
	if (sol < 0.0)
		return true;
	else
		return false;
}
bool IsinsideCircle10(const double x, const double y)
{
	double x_c = 540.0;
	double y_c = 250.0;
	double r = 40.0;
	double sol = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r*r;
	if (sol < 0.0)
		return true;
	else
		return false;
}
void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}

// scratched from https://courses.engr.illinois.edu/ece390/archive/archive-f2000/mp/mp4/anti.html
// see 'Rasterization' part.
void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	//i0=60 j0=60
	//원안에 오른쪽화살표

	if (IsinsideCircle1(xpos, ypos) == true)
	{

		for (int i = i0 - 40; i <= i0 + 40; i++)
		{
			int j;

			j = sqrt(1600 - (i - (i0))*(i - (i0))) + (j0);


			drawPixel(i, j, 0.0f, 0.0f, 1.0f);
			int k;

			k = -sqrt(1600 - (i - (i0))*(i - (i0))) + (j0);
			drawPixel(i, k, 0.0f, 0.0f, 1.0f);

		}
	}
	else
	{
		for (int i = i0 - 40; i <= i0 + 40; i++)
		{
			int j;

			j = sqrt(1600 - (i - (i0))*(i - (i0))) + (j0);


			drawPixel(i, j, 1.0f, 0.0f, 0.0f);
			int k;

			k = -sqrt(1600 - (i - (i0))*(i - (i0))) + (j0);
			drawPixel(i, k, 1.0f, 0.0f, 0.0f);

		}
	}

	for (int i = i0 - 20; i <= i0 + 20; i++)
	{
		int j;
		j = j0;
		drawPixel(i, j, 1.0f, 0.0f, 0.0f);
	}
	for (int i = i0 + 10; i <= i0 + 20; i++)
	{
		int j;
		j = -(i - (i0 + 20)) + j0;
		drawPixel(i, j, 1.0f, 0.0f, 0.0f);
	}
	for (int i = i0 + 10; i <= i0 + 20; i++)
	{
		int j;
		j = (i - (i0 + 20)) + j0;
		drawPixel(i, j, 1.0f, 0.0f, 0.0f);
	}
	//원안에 A
	for (int i = i0 + 80; i <= i0 + 160; i++)
	{
		int j;

		j = sqrt(1600 - (i - (i0 + 120))*(i - (i0 + 120))) + (j0);


		drawPixel(i, j, 1.0f, 0.0f, 0.0f);
		int k;

		k = -sqrt(1600 - (i - (i0 + 120))*(i - (i0 + 120))) + (j0);
		drawPixel(i, k, 1.0f, 0.0f, 0.0f);

	}


	for (int i = i0 + 110; i <= i0 + 130; i++)
	{
		int j;
		j = j0;
		drawPixel(i, j, 1.0f, 0.0f, 0.0f);
	}

	for (int i = i0 + 100; i <= i0 + 120; i++)
	{
		int j;
		j = (i - (i0 + 110)) + j0;
		drawPixel(i, j, 1.0f, 0.0f, 0.0f);
	}

	for (int i = i0 + 120; i <= i0 + 140; i++)
	{
		int j;
		j = -(i - (i0 + 130)) + j0;
		drawPixel(i, j, 1.0f, 0.0f, 0.0f);
	}

	//원안에 1자

	for (int i = i0 + 200; i <= i0 + 280; i++)
	{
		int j;

		j = sqrt(1600 - (i - (i0 + 240))*(i - (i0 + 240))) + (j0);


		drawPixel(i, j, 1.0f, 0.0f, 0.0f);
		int k;

		k = -sqrt(1600 - (i - (i0 + 240))*(i - (i0 + 240))) + (j0);
		drawPixel(i, k, 1.0f, 0.0f, 0.0f);
	}

	for (int j = j0 - 20; j <= j0 + 20; j++)
	{
		int i;
		i = i0 + 240;
		drawPixel(i, j, 1.0f, 0.0f, 0.0f);
	}

	//원안에 왼쪽화살표
	for (int i = i0 + 320; i <= i0 + 400; i++)
	{
		int j;

		j = sqrt(1600 - (i - (i0 + 360))*(i - (i0 + 360))) + (j0);


		drawPixel(i, j, 1.0f, 0.0f, 0.0f);
		int k;

		k = -sqrt(1600 - (i - (i0 + 360))*(i - (i0 + 360))) + (j0);
		drawPixel(i, k, 1.0f, 0.0f, 0.0f);
	}


	for (int i = i0 + 340; i <= i0 + 380; i++)
	{
		int j;
		j = j0;
		drawPixel(i, j, 1.0f, 0.0f, 0.0f);
	}
	for (int i = i0 + 340; i <= i0 + 350; i++)
	{
		int j;
		j = (i - (i0 + 340)) + j0;
		drawPixel(i, j, 1.0f, 0.0f, 0.0f);
	}
	for (int i = i0 + 340; i <= i0 + 350; i++)
	{
		int j;
		j = -(i - (i0 + 340)) + j0;
		drawPixel(i, j, 1.0f, 0.0f, 0.0f);
	}

	//원안에 위화살표
	for (int i = i0 + 440; i <= i0 + 520; i++)
	{
		int j;

		j = sqrt(1600 - (i - (i0 + 480))*(i - (i0 + 480))) + (j0);


		drawPixel(i, j, 1.0f, 0.0f, 0.0f);
		int k;

		k = -sqrt(1600 - (i - (i0 + 480))*(i - (i0 + 480))) + (j0);
		drawPixel(i, k, 1.0f, 0.0f, 0.0f);
	}

	for (int j = j0 - 20; j <= j0 + 20; j++)
	{
		int i;
		i = i0 + 480;
		drawPixel(i, j, 1.0f, 0.0f, 0.0f);
	}

	for (int i = i0 + 470; i <= i0 + 480; i++)
	{
		int j;
		j = (i - (i0 + 480)) + j0 + 20;
		drawPixel(i, j, 1.0f, 0.0f, 0.0f);
	}

	for (int i = i0 + 480; i <= i0 + 490; i++)
	{
		int j;
		j = -(i - (i0 + 480)) + j0 + 20;
		drawPixel(i, j, 1.0f, 0.0f, 0.0f);
	}

	//윗칸 원 직선


	for (int i = i0 - 40; i <= i0 + 40; i++)
	{
		int j;

		j = sqrt(1600 - (i - (i0))*(i - (i0))) + (j0 + 190);


		drawPixel(i, j, 1.0f, 0.0f, 0.0f);
		int k;

		k = -sqrt(1600 - (i - (i0))*(i - (i0))) + (j0 + 190);
		drawPixel(i, k, 1.0f, 0.0f, 0.0f);

	}

	for (int i = i0 - 20; i <= i0 + 20; i++)
	{
		int j;
		j = (i - (i0)) + j0 + 190;
		drawPixel(i, j, 1.0f, 0.0f, 0.0f);
	}

	//2번째 원안에 원
	for (int i = i0 + 80; i <= i0 + 160; i++)
	{
		int j;

		j = sqrt(1600 - (i - (i0 + 120))*(i - (i0 + 120))) + (j0 + 190);


		drawPixel(i, j, 1.0f, 0.0f, 0.0f);
		int k;

		k = -sqrt(1600 - (i - (i0 + 120))*(i - (i0 + 120))) + (j0 + 190);
		drawPixel(i, k, 1.0f, 0.0f, 0.0f);

	}

	for (int i = i0 + 105; i <= i0 + 135; i++)
	{
		int j;

		j = sqrt(225 - (i - (i0 + 120))*(i - (i0 + 120))) + (j0 + 190);


		drawPixel(i, j, 1.0f, 0.0f, 0.0f);
		int k;

		k = -sqrt(225 - (i - (i0 + 120))*(i - (i0 + 120))) + (j0 + 190);
		drawPixel(i, k, 1.0f, 0.0f, 0.0f);

	}

	//원안에 사각형
	for (int i = i0 + 200; i <= i0 + 280; i++)
	{
		int j;

		j = sqrt(1600 - (i - (i0 + 240))*(i - (i0 + 240))) + (j0 + 190);


		drawPixel(i, j, 1.0f, 0.0f, 0.0f);
		int k;

		k = -sqrt(1600 - (i - (i0 + 240))*(i - (i0 + 240))) + (j0 + 190);
		drawPixel(i, k, 1.0f, 0.0f, 0.0f);
	}

	for (int j = j0 + 175; j <= j0 + 205; j++)
	{
		int i;
		i = i0 + 225;
		drawPixel(i, j, 1.0f, 0.0f, 0.0f);
	}
	for (int j = j0 + 175; j <= j0 + 205; j++)
	{
		int i;
		i = i0 + 255;
		drawPixel(i, j, 1.0f, 0.0f, 0.0f);
	}
	for (int i = i0 + 225; i <= i0 + 255; i++)
	{
		int j;
		j = j0 + 175;
		drawPixel(i, j, 1.0f, 0.0f, 0.0f);
	}
	for (int i = i0 + 225; i <= i0 + 255; i++)
	{
		int j;
		j = j0 + 205;
		drawPixel(i, j, 1.0f, 0.0f, 0.0f);
	}


	//원안에 X
	for (int i = i0 + 320; i <= i0 + 400; i++)
	{
		int j;

		j = sqrt(1600 - (i - (i0 + 360))*(i - (i0 + 360))) + (j0 + 190);


		drawPixel(i, j, 1.0f, 0.0f, 0.0f);
		int k;

		k = -sqrt(1600 - (i - (i0 + 360))*(i - (i0 + 360))) + (j0 + 190);
		drawPixel(i, k, 1.0f, 0.0f, 0.0f);
	}

	for (int i = i0 + 340; i <= i0 + 380; i++)
	{
		int j;
		j = (i - (i0 + 360)) + j0 + 190;
		drawPixel(i, j, 1.0f, 0.0f, 0.0f);
	}

	for (int i = i0 + 340; i <= i0 + 380; i++)
	{
		int j;
		j = -(i - (i0 + 360)) + j0 + 190;
		drawPixel(i, j, 1.0f, 0.0f, 0.0f);
	}

	//원안에 아래화살표
	for (int i = i0 + 440; i <= i0 + 520; i++)
	{
		int j;

		j = sqrt(1600 - (i - (i0 + 480))*(i - (i0 + 480))) + (j0 + 190);


		drawPixel(i, j, 1.0f, 0.0f, 0.0f);
		int k;

		k = -sqrt(1600 - (i - (i0 + 480))*(i - (i0 + 480))) + (j0 + 190);
		drawPixel(i, k, 1.0f, 0.0f, 0.0f);
	}


	for (int j = j0 + 175; j <= j0 + 205; j++)
	{
		int i;
		i = i0 + 480;
		drawPixel(i, j, 1.0f, 0.0f, 0.0f);
	}

	for (int i = i0 + 470; i <= i0 + 480; i++)
	{
		int j;
		j = -(i - (i0 + 480)) + j0 + 175;
		drawPixel(i, j, 1.0f, 0.0f, 0.0f);
	}

	for (int i = i0 + 480; i <= i0 + 490; i++)
	{
		int j;
		j = (i - (i0 + 480)) + j0 + 175;
		drawPixel(i, j, 1.0f, 0.0f, 0.0f);
	}

}

void drawOnPixelBuffer()
{
	//std::memset(pixels, 1.0f, sizeof(float)*width*height * 3); // doesn't work
	std::fill_n(pixels, width*height * 3, 1.0f);	// white background

													//for (int i = 0; i<width*height; i++) {
													//	pixels[i * 3 + 0] = 1.0f; // red 
													//	pixels[i * 3 + 1] = 1.0f; // green
													//	pixels[i * 3 + 2] = 1.0f; // blue
													//}

	const int i = rand() % width, j = rand() % height;
	drawPixel(i, j, 0.0f, 0.0f, 0.0f);

	// drawing a line
	//TODO: anti-aliasing
	drawLine(60, 60, 100, 100, 1.0f, 0.0f, 0.0f);


	//TODO: try moving object
}

int main(void)
{
	GLFWwindow* window;
	



	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	
	
	int i0 = 60, j0 = 60;
	
	
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glClearColor(1, 1, 1, 1); // while background

							  /* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		
		glfwGetCursorPos(window, &xpos, &ypos);
		/* Render here */
		//glClear(GL_COLOR_BUFFER_BIT);

		drawOnPixelBuffer();
		//TODO: RGB struct
		//Make a pixel drawing function
		//Make a line drawing function

		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);
	
		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		
		

		

		


		if (IsinsideCircle2(xpos, ypos) == true)
		{

			for (int i = i0 + 80; i <= i0 + 160; i++)
			{
				int j;

				j = sqrt(1600 - (i - (i0 + 120))*(i - (i0 + 120))) + (j0);


				drawPixel(i, j, 0.0f, 0.0f, 1.0f);
				int k;

				k = -sqrt(1600 - (i - (i0 + 120))*(i - (i0 + 120))) + (j0);
				drawPixel(i, k, 0.0f, 0.0f, 1.0f);

			}
		}
		if (IsinsideCircle3(xpos, ypos) == true)
		{

			for (int i = i0 + 200; i <= i0 + 280; i++)
			{
				int j;

				j = sqrt(1600 - (i - (i0 + 240))*(i - (i0 + 240))) + (j0);


				drawPixel(i, j, 0.0f, 0.0f, 1.0f);
				int k;

				k = -sqrt(1600 - (i - (i0 + 240))*(i - (i0 + 240))) + (j0);
				drawPixel(i, k, 0.0f, 0.0f, 1.0f);
			}
		}

		if (IsinsideCircle4(xpos, ypos) == true)
		{

			for (int i = i0 + 320; i <= i0 + 400; i++)
			{
				int j;

				j = sqrt(1600 - (i - (i0 + 360))*(i - (i0 + 360))) + (j0);


				drawPixel(i, j, 0.0f, 0.0f, 1.0f);
				int k;

				k = -sqrt(1600 - (i - (i0 + 360))*(i - (i0 + 360))) + (j0);
				drawPixel(i, k, 0.0f, 0.0f, 1.0f);
			}

		}
		if (IsinsideCircle5(xpos, ypos) == true)
		{

			for (int i = i0 + 440; i <= i0 + 520; i++)
			{
				int j;

				j = sqrt(1600 - (i - (i0 + 480))*(i - (i0 + 480))) + (j0);


				drawPixel(i, j, 0.0f, 0.0f, 1.0f);
				int k;

				k = -sqrt(1600 - (i - (i0 + 480))*(i - (i0 + 480))) + (j0);
				drawPixel(i, k, 0.0f, 0.0f, 1.0f);
			}

		}
		if (IsinsideCircle6(xpos, ypos) == true)
		{

			for (int i = i0 - 40; i <= i0 + 40; i++)
			{
				int j;

				j = sqrt(1600 - (i - (i0))*(i - (i0))) + (j0 + 190);


				drawPixel(i, j, 0.0f, 0.0f, 1.0f);
				int k;

				k = -sqrt(1600 - (i - (i0))*(i - (i0))) + (j0 + 190);
				drawPixel(i, k, 0.0f, 0.0f, 1.0f);

			}
		}
		if (IsinsideCircle7(xpos, ypos) == true)
		{

			for (int i = i0 + 80; i <= i0 + 160; i++)
			{
				int j;

				j = sqrt(1600 - (i - (i0 + 120))*(i - (i0 + 120))) + (j0 + 190);


				drawPixel(i, j, 0.0f, 0.0f, 1.0f);
				int k;

				k = -sqrt(1600 - (i - (i0 + 120))*(i - (i0 + 120))) + (j0 + 190);
				drawPixel(i, k, 0.0f, 0.0f, 1.0f);
			}
			}
			if (IsinsideCircle8(xpos, ypos) == true)
			{
				for (int i = i0 + 200; i <= i0 + 280; i++)
				{
					int j;

					j = sqrt(1600 - (i - (i0 + 240))*(i - (i0 + 240))) + (j0 + 190);


					drawPixel(i, j, 0.0f, 0.0f, 1.0f);
					int k;

					k = -sqrt(1600 - (i - (i0 + 240))*(i - (i0 + 240))) + (j0 + 190);
					drawPixel(i, k, 0.0f, 0.0f, 1.0f);
				}
			}
			if (IsinsideCircle9(xpos, ypos) == true)
			{
				for (int i = i0 + 320; i <= i0 + 400; i++)
				{
					int j;

					j = sqrt(1600 - (i - (i0 + 360))*(i - (i0 + 360))) + (j0 + 190);


					drawPixel(i, j, 0.0f, 0.0f, 1.0f);
					int k;

					k = -sqrt(1600 - (i - (i0 + 360))*(i - (i0 + 360))) + (j0 + 190);
					drawPixel(i, k, 0.0f, 0.0f, 1.0f);
				}
			}
			if (IsinsideCircle10(xpos, ypos) == true)
			{
				for (int i = i0 + 440; i <= i0 + 520; i++)
				{
					int j;

					j = sqrt(1600 - (i - (i0 + 480))*(i - (i0 + 480))) + (j0 + 190);


					drawPixel(i, j, 0.0f, 0.0f, 1.0f);
					int k;

					k = -sqrt(1600 - (i - (i0 + 480))*(i - (i0 + 480))) + (j0 + 190);
					drawPixel(i, k, 0.0f, 0.0f, 1.0f);
				}
			}
	}

	glfwTerminate();

	delete[] pixels; // or you may reuse pixels array 

	return 0;
}


//glfw3.lib, opengl32.lib
