/*
 * opengl_methods.hpp
 *
 *  Created on: Mar 10, 2014
 *      Author: claudiordgz
 */

#ifndef OPENGL_METHODS_HPP_
#define OPENGL_METHODS_HPP_

#include "vgl.h"
#include <GL/glew.h>

#include <string>
#include <iostream>

int init(char *dir);
void display(void);
void free_resources();
void get_shader(char *dir, const char *file_name,
                std::string const& open_gl_ver, std::string &returnVal);


#endif /* OPENGL_METHODS_HPP_ */
