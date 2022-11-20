#include "../include/OpenGLDebug.h"

static DebugLogLevel s_DebugLogLevel = DebugLogLevel::HighAssert;

void SetGLDebugLogLevel(DebugLogLevel level)
{
	s_DebugLogLevel = level;
}

void OpenGLLogMessage(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
{
	switch (severity)
	{
	case GL_DEBUG_SEVERITY_HIGH:
		if ((int)s_DebugLogLevel > 0)
		{
            std::cout << "OpenGL Debug HIGH " << message << std::endl;
			if (s_DebugLogLevel == DebugLogLevel::HighAssert)
			{
			    printf("GL_DEBUG_SEVERITY_HIGH");
				#if _WIN32
					__debugbreak()
				#else
					__builtin_trap();
				#endif
			}
		}
		break;
	case GL_DEBUG_SEVERITY_MEDIUM:
		if ((int)s_DebugLogLevel > 2)
			printf("[OpenGL Debug MEDIUM] %s", message);
		break;
	case GL_DEBUG_SEVERITY_LOW:
		if ((int)s_DebugLogLevel > 3)
			printf("[OpenGL Debug LOW] %s", message);
		break;
	case GL_DEBUG_SEVERITY_NOTIFICATION:
		if ((int)s_DebugLogLevel > 4)
			printf("[OpenGL Debug NOTIFICATION] %s", message);
		break;
	}
}

void EnableGLDebugging()
{
	glDebugMessageCallback(OpenGLLogMessage, nullptr);
	glEnable(GL_DEBUG_OUTPUT);
	glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
}
