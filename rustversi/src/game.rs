use crate::board::Board;
use crate::cursor::Cursor;
use crate::position::Position;
use crate::player::Player;

pub struct Game
{
    pub board: Board,
    pub cursor: Cursor,
    pub selection: Option<Position>,
    pub currentPlayer: Player
}

impl Game {
   
    pub fn new() -> Self {
        Game {
            selection: None,
            cursor: Cursor::new(0,0),
            board: Board::new(),
            currentPlayer: Player::White
        }
    }
}


