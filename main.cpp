#include "Index.h"
#include "background.h"


bool Init()
{
    bool success = true;
    int ret = SDL_Init(SDL_INIT_VIDEO );
    if(ret<0)
    {
        cout<<" Someting wrong in SDL_Init(SDL_INIT_VIDEO)";
        success = false;
    }

    else{
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
    g_window = SDL_CreateWindow( "Mario Jump", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN );
    if(g_window == NULL)
    {
        cout<<"Someting wrong in SDL_Init( g_window == NULL )";
        success = false;
    }
    else {
        g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
        if(g_renderer == NULL)
        {
            cout<<"Someting wrong in SDL_Init(g_renderer == NULL)";
            success = false;
        }
        else {
            SDL_SetRenderDrawColor(g_renderer, 255,255,255,255);
            int imgFlags = IMG_INIT_JPG;
            if(!(SDL_Init(imgFlags)&&imgFlags))
            {
                cout<<"Someting wrong in (!(SDL_Init(imgFlags)&&imgFlags)";
                success = false;
            }
        }
    }
}
    return success;
}

bool loadMedia()
{
    bool ret = g_background.loadImg("bit map//background.jpg", g_renderer);
    if(ret == false)
    {
        cout<<"Someting wrong in loadMedia";
        return false;
    }
}

void close()
{
    g_background.Free();
    SDL_DestroyRenderer(g_renderer);
    g_renderer=NULL;
    SDL_DestroyWindow(g_window);
    g_window=NULL;
    IMG_Quit();
    SDL_Quit();
}

int main(int agrc, char* agrv[])
{
if(!Init())
{
    cout<<"Failed to initialize!";
    return false;
}
else {
    if(!loadMedia)
    {
        cout<<"Failed to load media!";
        return false;
    }
    else {
        bool quit = false;
        SDL_Event e;
    while (!quit)
    {
        while(SDL_PollEvent(&e)!=0){
            if( e.type == SDL_QUIT )
					{
						quit = true;
					}
        }
        SDL_SetRenderDrawColor( g_renderer, 255, 255, 255, 255 );
        SDL_RenderClear( g_renderer );
        g_background.Render(g_renderer,NULL);
        SDL_RenderPresent(g_renderer);
    }
    }
}
close();
    return 0;
}




