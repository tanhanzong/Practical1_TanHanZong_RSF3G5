
#include <Windows.h>
#include <gl/GL.h>
#include <math.h>

#pragma comment (lib, "OpenGL32.lib")

#define WINDOW_TITLE "Practical 1"


LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) PostQuitMessage(0);
		break;

	default:
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
//--------------------------------------------------------------------

bool initPixelFormat(HDC hdc)
{
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.cAlphaBits = 8;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.cStencilBits = 0;

	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;

	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;

	// choose pixel format returns the number most similar pixel format available
	int n = ChoosePixelFormat(hdc, &pfd);

	// set pixel format returns whether it sucessfully set the pixel format
	if (SetPixelFormat(hdc, n, &pfd))
	{
		return true;
	}
	else
	{
		return false;
	}
}
//--------------------------------------------------------------------

void displayPahang() {
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-0.9, 1.0);
	glVertex2f(-0.7, 1.0);
	glVertex2f(-0.7, 0.9);
	glVertex2f(-0.9, 0.9);

	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-0.9, 0.9);
	glVertex2f(-0.7, 0.9);
	glVertex2f(-0.7, 0.8);
	glVertex2f(-0.9, 0.8);

	glEnd();
}

void displayNs() {
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(-0.6, 1.0);
	glVertex2f(-0.4, 1.0);
	glVertex2f(-0.4, 0.8);
	glVertex2f(-0.6, 0.8);

	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-0.6, 1.0);
	glVertex2f(-0.5, 1.0);
	glVertex2f(-0.5, 0.9);

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-0.6, 1.0);
	glVertex2f(-0.6, 0.9);
	glVertex2f(-0.5, 0.9);

	glEnd();
}

void displayEngland() {
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-0.3, 1.0);
	glVertex2f(-0.1, 1.0);
	glVertex2f(-0.1, 0.8);
	glVertex2f(-0.3, 0.8);

	glShadeModel(GL_SMOOTH);
	glBegin(GL_QUADS);
	glColor3f(0.658824, 0.658824, 0.658824);
	glVertex2f(-0.3, 1.0);
	glVertex2f(-0.22, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-0.22, 0.92);
	glVertex2f(-0.3, 0.92);

	glEnd();

	glShadeModel(GL_SMOOTH);
	glBegin(GL_QUADS);
	glColor3f(0.658824, 0.658824, 0.658824);
	glVertex2f(-0.18, 1.0);
	glVertex2f(-0.10, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-0.10, 0.92);
	glVertex2f(-0.18, 0.92);

	glEnd();

	glShadeModel(GL_SMOOTH);
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-0.3, 0.88);
	glVertex2f(-0.22, 0.88);
	glColor3f(0.658824, 0.658824, 0.658824);
	glVertex2f(-0.22, 0.8);
	glVertex2f(-0.3, 0.8);

	glEnd();

	glShadeModel(GL_SMOOTH);
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-0.18, 0.88);
	glVertex2f(-0.10, 0.88);
	glColor3f(0.658824, 0.658824, 0.658824);
	glVertex2f(-0.10, 0.8);
	glVertex2f(-0.18, 0.8);

	glEnd();
}

void displayScotland() {
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(0.0, 1.0);
	glVertex2f(0.2, 1.0);
	glVertex2f(0.2, 0.8);
	glVertex2f(0.0, 0.8);

	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.5, 1.0);
	glVertex2f(0.0, 0.98);
	glVertex2f(0.0, 0.82);
	glVertex2f(0.07, 0.9);

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.5, 1.0);
	glVertex2f(0.2, 0.98);
	glVertex2f(0.2, 0.82);
	glVertex2f(0.13, 0.9);

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.5, 1.0);
	glVertex2f(0.03, 0.8);
	glVertex2f(0.17, 0.8);
	glVertex2f(0.1, 0.88);

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.5, 1.0);
	glVertex2f(0.03, 1.0);
	glVertex2f(0.17, 1.0);
	glVertex2f(0.1, 0.92);

	glEnd();
}

void displayJapan() {
	float x1 = 0.4, y1 = 0.9, x2 = 0.0, y2 = 0.0;
	float angle = 0.0;
	float radius = 0.05;
	//float theta;

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(0.3, 1.0);
	glVertex2f(0.5, 1.0);
	glVertex2f(0.5, 0.8);
	glVertex2f(0.3, 0.8);

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(x1, y1);

	for (angle = 0; angle <= 360.0; angle ++)
	{
		x2 = x1 + cos(angle) * radius;
		y2 = y1 + sin(angle) * radius;
		glVertex2f(x2, y2);
	}

	/*glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	for (float i = 0; i < 360.0; i+= 0.5) {
		theta = i * 3.142 / 180;
		glVertex2f(0.4+0.05*cos(theta), 0.9+0.05*sin(theta));
	}*/

	glEnd();
}

void displayExtraQues() {
	float x1 = -0.2, y1 = -0.1, x2 = 0.0, y2 = 0.0, x3 = -0.2, y3 = 0.28, x4 = 0.0, y4 = 0.0;
	float radius1 = 0.25, radius2 = 0.15; 
	float angle;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(x1, y1);

	for (angle = 0; angle <= 360.0; angle++)
	{
		x2 = x1 + cos(angle) * radius1;
		y2 = y1 + sin(angle) * radius1;
		glVertex2f(x2, y2);
	}

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(x3, y3);

	for (angle = 0; angle <= 360.0; angle++)
	{
		x4 = x3 + cos(angle) * radius2;
		y4 = y3 + sin(angle) * radius2;
		glVertex2f(x4, y4);
	}

	glEnd();

	glShadeModel(GL_SMOOTH);
	glBegin(GL_TRIANGLES);
	glColor3f(0.5, 0.35, 0.05);
	glVertex2f(-0.2, 0.7);
	glColor3f(1.0, 0.5, 0.0);
	glVertex2f(-0.35, 0.41);
	glVertex2f(-0.05, 0.41);

	glEnd();

	float x5 = -0.25, y5 = 0.35, x6 = 0.0, y6 = 0.0, x7 = -0.15, y7 = 0.35, x8 = 0.0, y8 = 0.0;
	float radius3 = 0.025;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x5, y5);

	for (angle = 0; angle <= 360.0; angle++)
	{
		x6 = x5 + cos(angle) * radius3;
		y6 = y5 + sin(angle) * radius3;
		glVertex2f(x6, y6);
	}

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x7, y7);

	for (angle = 0; angle <= 360.0; angle++)
	{
		x8 = x7 + cos(angle) * radius3;
		y8 = y7 + sin(angle) * radius3;
		glVertex2f(x8, y8);
	}

	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-0.58, 0.15);
	glVertex2f(-0.60, 0.28);

	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(0.19, 0.15);
	glVertex2f(0.21, 0.28);

	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-0.43, 0.0);
	glVertex2f(-0.58, 0.15);
	glVertex2f(-0.7, 0.13);

	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(0.03, 0.0);
	glVertex2f(0.19, 0.15);
	glVertex2f(0.31, 0.13);

	glEnd();

	float x9 = -0.2, y9 = 0.225, x10 = 0.0, y10 = 0.0;
	float radius4 = 0.025;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(x9, y9);

	for (angle = 0; angle <= 360.0; angle++)
	{
		x10 = x9 + cos(angle) * radius4;
		y10 = y9 + sin(angle) * radius4;
		glVertex2f(x10, y10);
	}

	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(0, 0.225);
	glVertex2f(-0.2, 0.25);
	glVertex2f(-0.2, 0.2);

	glEnd();

}

void display()
{
	glClearColor(1.0, 0.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	displayPahang();
	displayNs();
	displayEngland();
	displayScotland();
	displayJapan();
	displayExtraQues();
}
//--------------------------------------------------------------------

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow)
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpfnWndProc = WindowProcedure;
	wc.lpszClassName = WINDOW_TITLE;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc)) return false;

	HWND hWnd = CreateWindow(WINDOW_TITLE, WINDOW_TITLE, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
		NULL, NULL, wc.hInstance, NULL);

	//--------------------------------
	//	Initialize window for OpenGL
	//--------------------------------

	HDC hdc = GetDC(hWnd);

	//	initialize pixel format for the window
	initPixelFormat(hdc);

	//	get an openGL context
	HGLRC hglrc = wglCreateContext(hdc);

	//	make context current
	if (!wglMakeCurrent(hdc, hglrc)) return false;

	//--------------------------------
	//	End initialization
	//--------------------------------

	ShowWindow(hWnd, nCmdShow);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		display();

		SwapBuffers(hdc);
	}

	UnregisterClass(WINDOW_TITLE, wc.hInstance);

	return true;
}
//--------------------------------------------------------------------