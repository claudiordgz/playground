
#include "opengl_methods.hpp"

//Main program
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  if(argc != 2)
  {
    std::cerr << "No resource folder defined in CMD Arguments" << std::endl;
    exit(EXIT_FAILURE);
  }

  glutInitWindowPosition(10, 10);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA );
  glutInitWindowSize(512, 512);
  glutInitContextVersion(2, 1);
  glutInitContextProfile(GLUT_CORE_PROFILE);
  glewExperimental = GL_TRUE;
  glutCreateWindow("testing");

  GLenum glew_status = glewInit();
  if(glew_status != GLEW_OK)
  {
    std::cerr << "Unable to initialize GLEW... exiting" << std::endl;
    exit(EXIT_FAILURE);
  }
  std::cout << glGetString( GL_VERSION ) << std::endl;

  /*
   * The entry point for our
   * OpenGL implementation
   * currently supports only one Draw
   */
  OpenGLProgram program(argv[argc-1]);
  program.run();

  return (EXIT_SUCCESS);
}

