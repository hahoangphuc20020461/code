#ifndef INDEX_H_
#define INDEX_H_

#include<windows.h>
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include<string>
#include<SDL_mixer.h>
#include<SDL_ttf.h>

using namespace std;

static SDL_Window* g_window = NULL;
static SDL_Renderer* g_renderer = NULL;
static SDL_Event g_event ;

const int WIDTH = 800;
const int HEIGHT = 600;
const int BPP = 32;
const string TITLE = "Mario Jump";
const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;



#endif // INDEX_H
