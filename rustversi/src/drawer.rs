use crate::board::Board;
use crate::square::{self, Square};
use crate::player::Player;

use macroquad::prelude::*;
const SQUARE_SIZE: f32 = 50.0;

pub struct Drawer {}

impl Drawer {
    pub fn new() -> Self {
        Drawer {}
    }

    pub fn draw_board(&self, board: &Board) {
        for square_rows in board.squares {
            for square in square_rows {
                self.draw_square(&square);
                self.draw_circle(&square);
            }
        }
    }

    fn draw_square(&self, square: &Square) {
        let x = SQUARE_SIZE * square.x as f32;
        let y = SQUARE_SIZE * square.y as f32;

        draw_rectangle(
            x as f32,
            y as f32,
            SQUARE_SIZE - 1.0,
            SQUARE_SIZE - 1.0,
            GRAY,
        );
    }

    fn draw_circle(&self, square:&Square) {

        if square.circle == Player::None {
            return;
        }

        let x = SQUARE_SIZE * square.x as f32;
        let y = SQUARE_SIZE * square.y as f32;
        let mut color = WHITE;
        
        if square.circle == Player::Black {
            color = BLACK;
        }

        draw_circle(x, y, (SQUARE_SIZE / 2.0) - 5.0, color);
    }
}
