use crate::board::Board;
use crate::cursor::{self, Cursor};
use crate::game::Game;
use crate::player::Player;
use crate::square::Square;

use macroquad::prelude::*;
const SQUARE_SIZE: f32 = 50.0;

pub struct Drawer {}

impl Drawer {
    pub fn new() -> Self {
        Drawer {}
    }

    pub fn draw_game(&self, game: &Game) {
        self.draw_board(&game.board);
        self.draw_cursor(&game.cursor);
        self.draw_score(game.white_score, game.black_score);
    }

    pub fn draw_cursor(&self, cursor: &Cursor) {
        let x = SQUARE_SIZE * cursor.x as f32;
        let y = SQUARE_SIZE * cursor.y as f32;
        self.draw_square_border(x, y, YELLOW);
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

        self.draw_square_raw(x, y, GRAY);
    }

    fn draw_square_raw(&self, x: f32, y: f32, color: Color) {
        draw_rectangle(x, y, SQUARE_SIZE - 1.0, SQUARE_SIZE - 1.0, color);
    }

    fn draw_circle(&self, square: &Square) {
        if square.circle == Player::None {
            return;
        }

        let x = SQUARE_SIZE * square.x as f32;
        let y = SQUARE_SIZE * square.y as f32;
        let mut color = WHITE;

        if square.circle == Player::Black {
            color = BLACK;
        }

        let radius = SQUARE_SIZE / 2.0;
        draw_circle(x + radius, y + radius, radius - 5.0, color);
    }

    pub fn draw_square_border(&self, x: f32, y: f32, color: Color) {
        let w = SQUARE_SIZE;
        let h = SQUARE_SIZE;
        let thickness = 5.0;
        // top
        draw_line(x, y, x + w, y, thickness, color);
        // Bottom
        draw_line(x, y + h, x + w, y + h, thickness, color);
        // Left
        draw_line(x, y, x, y + h, thickness, color);
        // Right
        draw_line(x + w, y, x + w, y + h, thickness, color);
    }

    fn draw_score(&self, white: usize, black: usize) {
        let score_white = format!("WHITE: {}", white);
        let score_black = format!("BLACK: {}", black);

        draw_text(&score_white, 20.0, 600.0, 30.0, WHITE);
        draw_text(&score_black, 20.0, 650.0, 30.0, WHITE);
    }
}
