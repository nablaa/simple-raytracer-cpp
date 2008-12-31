#!/usr/bin/python
import SCons
import glob
import os

env = Environment(ENV = {'PATH' : os.environ['PATH'],
                         'TERM' : os.environ['TERM'],
                         'HOME' : os.environ['HOME']})

env.Append(CPPFLAGS = Split('-std=c++98 -Wall -Wextra -Wpointer-arith -Wwrite-strings -Wold-style-cast -Woverloaded-virtual -Wundef -Wfloat-equal -Wshadow -Wlong-long -pedantic -Weffc++ -g -DGLIBCXX_DEBUG -DDEBUG'))

env.Program(target = 'test_vector', source = Split('vector.cc test_vector.cc'))
env.Program(target = 'test_matrix', source = Split('vector.cc matrix.cc test_matrix.cc'))
env.Program(target = 'test_primitive', source = Split('primitive.cc vector.cc test_primitive.cc'))
env.Program(target = 'test_scene', source = Split('primitive.cc matrix.cc vector.cc scene.cc test_scene.cc'))
env.Program(target = 'test_file', source = Split('file.cc test_file.cc'))
env.Program(target = 'test_render', source = Split('primitive.cc matrix.cc vector.cc scene.cc file.cc test_render.cc'))

