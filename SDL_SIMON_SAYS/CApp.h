#pragma once
#ifndef _CAPP_H_
#define _CAPP_H_


#include "CEvent.h"
#include "CMusic.h"
#include "CScreen_Background.h"
#include "CScreen_Font.h"
#include "CScreen_Stone.h"
#include "CWindow_Icon.h"

class CApp : public CEvent
{
public:
    CApp();
    virtual ~CApp();
    
    int onExecute();

private:

    void onEvent(SDL_Event* ev) override;
    void onExit() override;

    void onLButtonDown(int xm, int ym) override;
    void onMouseMove(int xm, int ym, int relx, int rely, bool left, bool right, bool middle) override;

    void onArrowDownDown() override;
    void onArrowUpDown() override;

    void onArrowLeftDown() override;
    void onArrowRightDown() override;

    void onTextInput(char* text) override;
    void onBackspaceDown() override;

    void onReturn() override;

    /*---------*/

    void Menu();
    int choice; //�� ����� ������ ���� �� ���������
    int rec_choice; //�� ����� ������ � �������� �� ���������
    int pas_choice; //�� ����� ������ ����� �� ���������
    
    void menu_draw(); //������� ����
    void settings_draw(); //������� ��������
    void record_draw(); //������� ��������
    void change_draw(); //������� ����� ������
    void pause_draw(); //������� �����
    std::string name; //��� ������


    bool isGame; //�������� �� ��, �� ������ � ���� ��� ���
    bool isSetting; //�������� �� ��, �� ������ � ���������� ��� ���
    bool isRecord; //�������� �� ��, �� ������ � �������� ��� ���
    bool isChanging; //�������� �� ��, �� ������ � ����� ������ ��� ���
    bool isPause; //�������� �� ��, �� ������ � ����� ��� ���

    void LoadInFile();
    void LoadFromFile();

    enum TYPE
    {
        TYPE_X = 1,
        TYPE_O = 2
    };

    bool isRunning;
    
    CScreen_Background* background1;
    CScreen_Background* background2;

    SDL_Surface* screen;
    
    CWindow* type1[2];
    
    CScreen_Stone* stone_x;
    CScreen_Stone* stone_o;

    int field[3][3];
    int score_player;
    int score_pc;
    int score_draw;
    
    struct Info
    {
        std::string name;
        int score_player;
        int score_pc;
        int score_draw;
    };
    std::vector<Info> info;

    CMusic* mus;

    CScreen_Font* font;

    bool onInit();
    void onRender();
    void onQuit();

    /*---------*/

    void field_init();
    void reset();
    void field_draw();
    
    void check_end();
    bool check_playerWin();
    bool check_PCWin();
    bool check_draw();

    void find_move();
    void find_random();
    bool find_win();
    bool find_lose();
    bool find_centre();
};

#endif
