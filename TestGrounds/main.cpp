#include "utils.h"
#include "shaderhelper.h"
#include "model.h"
#include "camera.h"
#include "inputmanager.h"

GLuint modelShader;
Camera* camera;
Model* model;

static void RenderSceneCB()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	model->Draw();

	glutSwapBuffers();
}


static void Update()
{
	glutPostRedisplay();
}

static void InitializeGlutCallbacks()
{
	glutDisplayFunc(RenderSceneCB);
	glutIdleFunc(Update);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Test world");
	glEnable(GL_DEPTH_TEST);
	InitializeGlutCallbacks();

	GLenum res = glewInit();

	if (res != GLEW_OK)
	{
		std::cout << "error: ," << glewGetErrorString(res);
		return 1;
	}

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	camera = new Camera();
	ShaderHelper::CompileAndLinkShaders("model_vs.glsl", "model_fs.glsl", modelShader);
	model = new Model("Resource/Models/sad2/JeffersSad3.obj", camera, modelShader);

	InputManager::Initialize();

	glutMainLoop();

	if (camera)
		delete camera;

	if (model)
		delete model;

	return 0;
}