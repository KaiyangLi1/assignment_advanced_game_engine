#include "Shader.h"



Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	string vertexCode;
	string fragmentCode;
	ifstream vShaderFile;
	ifstream fShaderFile;

	vShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
	fShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
	try 
	{
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);
		stringstream vShaderStream, fShaderStream;
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();

		vShaderFile.close();
		fShaderFile.close();

		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (ifstream::failure e)
	{
		cout << "Shader file not successfully read! " << e.what() << endl;
	}

	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str();

	unsigned int vertexShaderID, fragmentShaderID;
	int success;

	vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderID, 1, &vShaderCode, NULL);
	glCompileShader(vertexShaderID);	
	checkCompileErrors(vertexShaderID, "Vertex");

	fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderID, 1, &fShaderCode, NULL);
	glCompileShader(fragmentShaderID);
	checkCompileErrors(fragmentShaderID, "Fragment");

	ID = glCreateProgram();
	glAttachShader(ID, vertexShaderID);
	glAttachShader(ID, fragmentShaderID);
	glLinkProgram(ID);
	checkCompileErrors(ID, "Program");

	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);

}
void Shader::use()
{
	glUseProgram(ID);
}

void Shader::checkCompileErrors(unsigned int shaderID, string type)
{
	int success;
	char infoLog[1024];
	if (type != "Program")
	{
		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shaderID, 1024, NULL, infoLog);
			cout << "Shader Compile Error: " << infoLog << endl;
		}
	}
	else
	{
		glGetShaderiv(shaderID, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shaderID, 1024, NULL, infoLog);
			cout << "Program Compile Error: " << infoLog << endl;
		}
	}

}
