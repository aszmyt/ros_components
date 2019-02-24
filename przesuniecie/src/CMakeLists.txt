
#
# Components, types and plugins.
#
# The CMake 'target' names are identical to the first argument of the
# macros below, except for orocos_typegen_headers, where the target is fully
# controlled by generated code of 'typegen'.
#

# Creates a component library libprzesuniecie-<target>.so
# and installs in the directory lib/orocos/przesuniecie/
#
orocos_component(przesuniecie przesuniecie-component.hpp przesuniecie-component.cpp) # ...you may add multiple source files
#
# You may add multiple orocos_component statements.

#
# Additional headers:
#
# Installs in the include/orocos/przesuniecie/ directory
#
orocos_install_headers(przesuniecie-component.hpp) # ...you may add multiple header files
#
# You may add multiple orocos_install_headers statements.

