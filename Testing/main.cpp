#include <Window.h>
#include <Game.h>
#include <unistd.h>

int main() {
    

    //TODO: Implement hide for linux

    Polaris::Window window("The game of polaris", 800, 600, false, true);
    Polaris::Game *game = Polaris::Game::CreateNew();
    game->frameCap = 60;
    
    
    game->run();


}