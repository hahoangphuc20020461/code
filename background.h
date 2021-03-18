#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include "Index.h"

class loadBackground
{
public:
   loadBackground();
   ~loadBackground();

   void setRect(const int& x, const int& y){rect_.x=x, rect_.y=y;}
   SDL_Rect GetRect() const {return rect_;}
   SDL_Texture* GetTexture() const {return p_backgr;}

   bool loadImg(std::string path, SDL_Renderer* screen);
   void Render (SDL_Renderer* des, const SDL_Rect *clip/*=NULL*/);
   void Free();

private:
    SDL_Texture *p_backgr;
    SDL_Rect rect_;
};

static loadBackground g_background;
#endif // BACKGROUND_H_

