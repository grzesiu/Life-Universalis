#pragma once

#define LIFEUNIVERSALISEXPORTS

#ifdef LIFEUNIVERSALISEXPORTS
  #define LIFEUNIVERSALIS_EXPORT __declspec(dllexport)
#else
  #define LIFEUNIVERSALIS_EXPORT __declspec(dllimport)
#endif