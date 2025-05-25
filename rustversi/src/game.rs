use board::Board;
use cursor::Cursor;
use position::Position;
use player::Player;

pub struct Game
{
    board: Board,
    cursor: Cursor,
    selection: Option<Position>,
    currentPlayer: Player
}

impl Game {
   
    fn new() -> Self {
        Game {
            selection: None,
            currentPlayer: Player::White
        }
    }
}


