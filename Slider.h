#ifndef SLIDER_H_INCLUDED
#define SLIDER_H_INCLUDED

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "Object.h"

class Slider : public Object
{
public:
    Slider(int, int);
    ~Slider();

    void Draw();
    void set_color(ALLEGRO_COLOR);
    void set_label_content(const char*);
    void toggleDrag() { dragged = !dragged; }
    void drawTarget();
    void destroyTarget();

    float Drag(int, int);
    float getDegree() { return degree; }

    int getLength() { return lengthOftrack; }
    void changeTargetX(int mouse_X){
        target_x = mouse_X;
        return ;
    }
    int getTargetX(){
        return target_x;
    }

    bool isClicked(int, int);
    bool isDragged() { return dragged; }

private:
    int target_x, target_y; //target_x = track_x + lengthOftrack;
    int track_x, track_y;
    int lengthOftrack = 200;
    float degree = 1.0;
    bool dragged = false;
    char label[20];
    ALLEGRO_COLOR target_color;
    ALLEGRO_FONT *font;
    ALLEGRO_BITMAP* target;
};

#endif // SLIDER_H_INCLUDED
