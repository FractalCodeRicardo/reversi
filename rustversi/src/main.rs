use macroquad::prelude::*;
use rustversi::drawer::Drawer;
use rustversi::game::Game;
#[macroquad::main("MyGame")]
async fn main() {
    let game = Game::new();
    let drawer = Drawer::new();

    loop {
        clear_background(BLACK);
        
        drawer.draw_board(&game.board);
        next_frame().await
    }
}
