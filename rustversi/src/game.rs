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
            cursor: Cursor::new(0,0),
            board: Board::new(),
            currentPlayer: Player::White
        }
    }
}


