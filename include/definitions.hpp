#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define SPLASH_STATE_SHOW_TIME 1

#define SPLASH_SCENE_BACKGROUND_FILEPATH "resources/prato-logo.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "resources/main-menu.png"

#define MAIN_MENU_TITLE_FILEPATH "resources/main-menu.png"
#define MAIN_MENU_PLAY_BUTTON "resources/main-menu/play_btn.png"
#define MAIN_MENU_QUIT_BUTTON "resources/main-menu/quit_btn.png"

#define GAME_BACKGROUND_FILEPATH "resources/splash.png"

#define PAUSE_BUTTON "resources/pause_btn.png"

#define X_PIECE_FILEPATH "resources/X.png"
#define O_PIECE_FILEPATH "resources/O.png"
#define X_WINNING_PIECE_FILEPATH "resources/x_win.png"
#define O_WINNING_PIECE_FILEPATH "resources/o_win.png"

#define X_PIECE 8
#define O_PIECE 0
#define EMPTY_PIECE -1
#define PLAYER_PIECE X_PIECE
#define AI_PIECE O_PIECE

#define STATE_PLAYING 98
#define STATE_PAUSED 97
#define STATE_WON 96
#define STATE_LOSE 95
#define STATE_PLACING_PIECE 94
#define STATE_AI_PLAYING 93
#define STATE_DRAW 92

#define PAUSE_BACKGROUND_FILEPATH "resources/pause_bg.png"
#define PAUSE_MENU_RESUME_BUTTON "resources/pause-menu/resume_btn.png"
#define PAUSE_MENU_HOME_BUTTON "resources/pause-menu/home_btn.png"

#define DEFAULT_FONT_PATH "resources/fonts/VT323.ttf"

#endif