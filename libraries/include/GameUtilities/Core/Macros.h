#ifndef GAMEUTILITIES_MACROS_H
#define GAMEUTILITIES_MACROS_H

#define UNUSED(x) (void)(x)

#define STR(x) #x

#define GU_ASSERT(x) if (!(x)) { printf("GU assert failed: (%s), function %s, file %s, line %d.\n", STR(x), __PRETTY_FUNCTION__, __FILE__, __LINE__); throw std::runtime_error(x); }
 

#endif
