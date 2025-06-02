use macroquad::prelude::*;
use rustversi::drawer::Drawer;
use rustversi::game::Game;
#[macroquad::main("MyGame")]
async fn main() {
    let mut game = Game::new();
    let drawer = Drawer::new();

    loop {
        clear_background(BLACK);

        if is_key_released(KeyCode::Right) {
            game.cursor.right();
        }

        if is_key_released(KeyCode::Left) {
            game.cursor.left();
        }

        if is_key_released(KeyCode::Up) {
            game.cursor.up();
        }

        if is_key_released(KeyCode::Down) {
            game.cursor.down();
        }

        drawer.draw_game(&game);
        next_frame().await
    }
}
