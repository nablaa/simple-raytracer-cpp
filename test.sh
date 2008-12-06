#!/bin/sh

scons &&
./test_primitive &&
./test_vector &&
./test_matrix &&
./test_scene &&
./test_file &&
./test_render &&
convert -sample %6400 test_file_ppm_01.ppm test_file_ppm_01.png
#xdg-open test_file_ppm_01.png &
xdg-open test_render_01.ppm &
echo 'Tests completed!'

