#include <Window.h>
#include <Game.h>
#include <unistd.h>

int main() {
    

    Polaris::Window window("The game of polaris", 800, 600, false, true);
    Polaris::Game *game = Polaris::Game::CreateNew();
    game->frameCap = 60;
    //! LINUX ONLY 
    window.Fullscreen(false); //set to true to make fullscreen
    game->run();
}