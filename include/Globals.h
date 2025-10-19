#pragma once

const double PERCENT = 0.7;
const float MOUSESPEED = 15.f;
const float CATSPEED = 2.f;
const float WIDTH = 800.f;
const float HEIGHT = 850.f;
const int TOPWINDOW = 50;

const int MAXMAINMENU = 3;


enum Objects {
    SMARTCAT,
    CHEESE,
    DOOR,
    GIFT,
    WALL,
    KEY,
    MOUSE,
    DUMPCAT,
    ADDLIFE,
    NEWTIME,
    FREEZE
};



enum Songs {
    EAT,
    START,
    GAMEPLAY
};


enum class Direction {
    Left,
    Right
};
