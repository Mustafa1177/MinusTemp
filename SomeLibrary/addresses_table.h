#ifndef ADDRESSES_TABLE_H
#define ADDRESSES_TABLE_H

//============================================//
//             Table Abstracts                //
//============================================//

struct GameAddressTable
{ //abstract structure for global addresses
    virtual void f() = 0;  // pure virtual

    int PLAYER_STRUCT_SIZE;
    DWORD PLAYERS_ARRAY;
    DWORD MAX_SCORE;  
    DWORD GAME_MODE;
    DWORD SERVER_NAME;
    DWORD GAME_TICKS;

    //Code Segment
    DWORD NET_DEF_INTERNET_UPDATE_DELAY; //byte
};


struct PlayerPropertiesOffsetsTable
{ //abstract structure for offsets of player properties relative to player start address

public:
    int WEAPONS_COUNT = 10;
    DWORD HEALTH;
    DWORD NAME;
    DWORD POS_X;
    DWORD POS_Y;
    DWORD SELECTED_WEAPON;
    DWORD LIVES;  
    DWORD AMMO_ARRAY; //GUN1, GUN2, ....
    DWORD GUN_POWERED_UP_ARRAY;
    DWORD ROASTS;
};


//============================================//
//          Version specific Tables           //
//============================================//

//1.24 (TSF)

struct GameAddressTableTSF : GameAddressTable
{
    void f() override {}   // non-pure virtual

public:
    GameAddressTableTSF();

};

struct PlayerPropertiesOffsetsTableTSF : PlayerPropertiesOffsetsTable
{
public:
    PlayerPropertiesOffsetsTableTSF();
};


//1.23

struct GameAddressTableV23 : GameAddressTable
{
    void f() override {}   // non-pure virtual

public:
    GameAddressTableV23();
};

struct PlayerPropertiesOffsetsTableV23 : PlayerPropertiesOffsetsTable
{
public:
    PlayerPropertiesOffsetsTableV23();
};

#endif //ADDRESSES_TABLE_H