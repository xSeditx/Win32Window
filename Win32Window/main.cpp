
#include"NativeWin32.h"
#include"Application.h"

/*
 WINDOW
========
~ INPUT
 =======
 ~ MOUSE  [ X ]
  =======
  ~ Position     [ x ]
  ~ Relative     [ x ]
  ~ Buttons      [   ]
 
 ~ KEYBOARD [ X ] 
  ==========
  ~ Keys[]       [ x ]
  ~ KeyDown      [ x ]
  ~ KeyUp        [ x ]

~ EVENTS
 ========
 ~ Window Close  [   ]
 ~ GUI Events    [   ]

 Create GUI Elements [  ]
 GUI Management      [  ]
*/

class TestApp
	:
	public Application
{
public:

	Vec2 Vertices[3] =
	{
		{-1.0,-1.0 },
		{ 1.0,-1.0 },
		{ 0.0, 1.0 }
	};
 
	Vec2 UVcoords[3] =
	{
		{ 0.0, 0.0 },
		{ 1.0, 0.0 },
		{ 1.0, 1.0 }
	};

	GLuint Indices[3] = 
	{
		0,1,2
	};
	GLuint VAO{ 0 }, VBO{ 0 }, IBO{ 0 };

	TestApp()
		:
		Application()
	{
	}

	void OnCreate()
	{


		glUseProgram(ApplicationWindow->BasicShader);
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices) , &Vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		GLuint Location = 4;

		Location = glGetAttribLocation(ApplicationWindow->BasicShader, "aPos");
		glEnableVertexAttribArray(Location);
		glVertexAttribPointer(Location, 3, GL_FLOAT, GL_FALSE, 0, (char *)NULL);
		uint32_t ERR = 0;
		if ((ERR = glGetError()))
		{
			Print("Error" << ERR);
			__debugbreak();
		}
		//glBindBuffer(GL_ARRAY_BUFFER, 0);
		//
		//glGenBuffers(1, &IBO);
	    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int)*3, &Indices, GL_STATIC_DRAW);
		//glUseProgram(0);
		ERR = 0;
		if ((ERR = glGetError()))
		{
			Print("Error" << ERR);
			__debugbreak();
		}

	}
	void OnRender()
	{
		glUseProgram(ApplicationWindow->BasicShader);
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		//glVertexAttribPointer(
		//	0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		//	3,                  // size
		//	GL_FLOAT,           // type
		//	GL_FALSE,           // normalized?
		//	0,                  // stride
		//	(void*)0            // array buffer offset
		//);

		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glUseProgram(0);
	}

};


//int WINAPI WinMain(HINSTANCE instance,
//	HINSTANCE prev_instance,
//	LPSTR cmd_line,
//	int cmd_show) 
//

	int main()
{
	TestApp mApp;
	mApp.Start();
	mApp.Run();
	return 0;
}