
#include <iostream>
#include "vgl.h"
#include "LoadShaders.h"
#include <string>
#include <GL/glew.h>

GLuint program;
GLint attribute_coord2d;

int init(void);
void display(void);
void free_resources();

//Main program
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitWindowPosition(10, 10);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA );
  glutInitWindowSize(512, 512);
  glutInitContextVersion(2, 1);
  glutInitContextProfile(GLUT_CORE_PROFILE);
  glewExperimental = GL_TRUE;
  std::string testing = "testing";
  glutCreateWindow(testing.c_str());

  GLenum glew_status = glewInit();
  if(glew_status != GLEW_OK)
  {
    std::cerr << "Unable to initialize GLEW... exiting" << std::endl;
    exit(EXIT_FAILURE);
  }
  std::cout << glGetString( GL_VERSION ) << std::endl;

  if(1 == init())
  {
    /* We can display it if everything goes OK */
    glutDisplayFunc(display);
    glutMainLoop();
  }

  /* If the program exits in the usual way,
  free resources and exit with a success */
  free_resources();

  return (EXIT_SUCCESS);
}

int init(void)
{
  GLint compile_ok = GL_FALSE, link_ok = GL_FALSE;

  GLuint vs = glCreateShader(GL_VERTEX_SHADER);
  const char *vs_source =
#ifdef GL_ES_VERSION_2_0
    "#version 100\n"  // OpenGL ES 2.0
#else
    "#version 120\n"  // OpenGL 2.1
#endif
    "attribute vec2 coord2d;                  "
    "void main(void) {                        "
    "  gl_Position = vec4(coord2d, 0.0, 1.0); "
    "}";
  glShaderSource(vs, 1, &vs_source, NULL);
  glCompileShader(vs);
  glGetShaderiv(vs, GL_COMPILE_STATUS, &compile_ok);
  if (0 == compile_ok)
  {
    std::cerr << "Error in vertex shader\n";
    return (0);
  }

  GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
  const char *fs_source =
    "#version 120           \n"
    "void main(void) {        "
    "  gl_FragColor[0] = 0.0; "
    "  gl_FragColor[1] = 0.0; "
    "  gl_FragColor[2] = 1.0; "
    "}";
  glShaderSource(fs, 1, &fs_source, NULL);
  glCompileShader(fs);
  glGetShaderiv(fs, GL_COMPILE_STATUS, &compile_ok);
  if (!compile_ok)
  {
    std::cerr << "Error in fragment shader\n";
    return (0);
  }
  program = glCreateProgram();
  glAttachShader(program, vs);
  glAttachShader(program, fs);
  glLinkProgram(program);
  glGetProgramiv(program, GL_LINK_STATUS, &link_ok);
  if (!link_ok)
  {
    std::cerr << "glLinkProgram:";
    return (0);
  }

  const char* attribute_name = "coord2d";
  attribute_coord2d = glGetAttribLocation(program, attribute_name);
  if (attribute_coord2d == -1)
  {
    std::cerr << "Could not bind attribute " << attribute_name << std::endl;
    return (0);
  }

  return (1);

}


void display(void)
{
  /* Clear the background as white */
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  glUseProgram(program);
  glEnableVertexAttribArray(attribute_coord2d);
  GLfloat triangle_vertices[] = {
     0.0,  0.8,
    -0.8, -0.8,
     0.8, -0.8,
  };
  /* Describe our vertices array to OpenGL (it can't guess its format automatically) */
  glVertexAttribPointer(
    attribute_coord2d, // attribute
    2,                 // number of elements per vertex, here (x,y)
    GL_FLOAT,          // the type of each element
    GL_FALSE,          // take our values as-is
    0,                 // no extra data between each position
    triangle_vertices  // pointer to the C array
  );

  /* Push each element in buffer_vertices to the vertex shader */
  glDrawArrays(GL_TRIANGLES, 0, 3);
  glDisableVertexAttribArray(attribute_coord2d);

  /* Display the result */
  glutSwapBuffers();
}

void free_resources()
{
  glDeleteProgram(program);
}
