#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <vector>
#include <list>
#include <time.h>
#include "Menu.h"
#include "Level.h"
#include "WolfKnight.h"
#include "CaveMan.h"
#include "Wolf.h"
#include "DemonNijia.h"
#include "Arcane.h"
#include "Archer.h"
#include "Canon.h"
#include "Poison.h"
#include "Storm.h"
#include "Attack.h"
#include "Slider.h"
#include "BuiltTower.h"

#define GAME_INIT -1 //title page
#define GAME_SETTING 0 //sound page
#define GAME_SELECT 1 //level page
#define GAME_BEGIN 2
#define GAME_CONTINUE 3 //game level 1
#define GAME_FAIL 4
#define GAME_TERMINATE 5
#define GAME_NEXT_LEVEL 6
#define GAME_EXIT 7
#define GAME_LEVEL_2 8

#define UP 0
#define DOWN 1

// clock rate
const float FPS = 60;

// total number of level
const int LevelNum = 4;

// 1 coin every 2 seconds
const int CoinSpeed = FPS * 2;
const int Coin_Time_Gain = 1;

class GameWindow
{
public:
    // constructor
    GameWindow();
    // each process of scene
    void game_init();
    void game_reset();
    void game_play();
    void game_begin();

    void game_title_page_init();
    int game_title_page_run();
    void game_sound_page_init();
    int game_sound_page_run();
    void game_level_page_init();
    int game_level_page_run();
    void game_level_2_init();
    int game_level_2_run();
    void game_pause();
    int game_run();
    int game_update();

    void show_err_msg(int msg);
    void game_destroy();

    // draw running game map
    void draw_running_map();

    // process of updated event
    int process_event();
    int process_event_of_titlepage();
    // detect if mouse hovers over a rectangle
    bool mouse_hover(int, int, int, int);
    // detect if a tower will be constructed on road
    bool isOnRoad();

    Tower* create_tower(int);
    Monster* create_monster();

public:
    bool initial = true;

private:
    ALLEGRO_BITMAP *icon;
    ALLEGRO_BITMAP *tower[Num_TowerType];
    ALLEGRO_BITMAP *background = NULL;
    ALLEGRO_BITMAP *background2 = NULL;
    ALLEGRO_BITMAP *titlepage = NULL;
    ALLEGRO_BITMAP *soundpage = NULL;
    ALLEGRO_BITMAP *levelpage = NULL;
    ALLEGRO_BITMAP *selectleft = NULL;
    ALLEGRO_BITMAP *selectright = NULL;
    ALLEGRO_BITMAP *level1noflash = NULL;
    ALLEGRO_BITMAP *level1flash = NULL;
    ALLEGRO_BITMAP *level2noflash = NULL;
    ALLEGRO_BITMAP *level2flash = NULL;

    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_FONT *font = NULL;
    ALLEGRO_FONT *Medium_font = NULL;
    ALLEGRO_FONT *Large_font = NULL;

    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_EVENT event;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_TIMER *monster_pro = NULL;

    ALLEGRO_SAMPLE *sample = NULL;
    ALLEGRO_SAMPLE_INSTANCE *startSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *clearSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *failSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *backgroundSound = NULL;

    LEVEL *level = NULL;
    Menu *menu = NULL;

    std::vector<Monster*> monsterSet;
    std::list<Tower*> towerSet;

    int Coin_Inc_Count = 0;
    int mouse_x, mouse_y;
    int selectedTower = -1, lastClicked = -1;
    float volume_of_bgm = 1.0;
    float volume_of_se = 1.0;
    int pos_y; //position of selector
    int bgm_x = 500;
    int se_x = 500;
    bool bgm_x_clicked = false;
    bool se_x_clicked = false;
    bool level_1_flashed = false;
    bool level_2_flashed = false;
    int self;

    bool redraw = false;
    bool mute = false;
    bool* keys;
    bool isClicked(int target_x, int target_y, int mouse_x, int mouse_y){
        int real_x = target_x - 15/2;
        int real_y = target_y - 30/2;

        if(mouse_x >= real_x && mouse_x <= real_x + 15){
            if(mouse_y >= real_y && mouse_y <= real_y + 30){
                return true;
            }
        }
        return false;
    }

};


#endif // MAINWINDOW_H_INCLUDED
