use macroquad::prelude::*;

mod cursor;
mod player;
mod square;
mod position;
mod board;
mod drawer;
mod game;

use crate::game::Game;
use crate::drawer::Drawer;
use std::vec::Vec;

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

        if is_key_released(KeyCode::Enter) {
            game.do_movement();
        }

        drawer.draw_game(&game);
        next_frame().await
    }
}
