use crate::board::Board;
use crate::cursor::Cursor;
use crate::player::Player;
use crate::position::Position;


pub struct Game {
    pub board: Board,
    pub cursor: Cursor,
    pub selection: Option<Position>,
    pub current_player: Player,
}

impl Game {
    pub fn new() -> Self {
        Game {
            selection: None,
            cursor: Cursor::new(0, 0),
            board: Board::new(),
            current_player: Player::White,
        }
    }

    pub fn change_turn(&mut self) {
        if self.current_player == Player::White {
            self.current_player = Player::Black;
            return;
        }

        if self.current_player == Player::Black {
            self.current_player = Player::White;
            return;
        }
    }

    fn is_outside(x: i8, y: i8) -> bool {
        return x < 0 || y < 0 || x > 7 || y > 7;
    }

    fn get_line(x: i8, y: i8, increment_x: i8, increment_y: i8) 
        -> Vec<Position> {
        let positions: Vec<Position> = Vec::new();

        
        positions
    }
}
