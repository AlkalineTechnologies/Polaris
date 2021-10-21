#include <Window.h>
#include <Game.h>

int main() {
    

    //TODO: Implement hide for linux

    Polaris::Game *game = Polaris::Game::CreateNew();
    game->frameCap = 60;
    Polaris::Window window("Hello, world!");
    window.show();
    game->run();
    return 0;

}