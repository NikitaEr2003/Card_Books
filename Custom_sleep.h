#pragma once
#ifndef NOMINMAX
#define NOMINMAX
#endif
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
void Custom_sleep();
