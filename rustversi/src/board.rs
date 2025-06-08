use crate::{player::Player, square::{self, Square}};

pub struct Board {
    pub squares:  [[Square; 8]; 8],
}

impl Board {
    pub fn new() -> Self {
        let squares = Board::create_squares();

        let mut board = Board { squares };
        board.initialize_pieces();
        return board;
    }

    pub fn create_squares() -> [[Square; 8]; 8] {
        let mut squares = [[Square {
            x: 0,
            y: 0,
            circle: Player::None,
        }; 8]; 8];

        for row in 0..8 {
            for col in 0..8 {
                squares[row][col] = Square::new(row as usize, col as usize); // or any constructor
            }
        }

        return squares;
    }

    fn initialize_pieces(&mut self) {
        self.squares[3][3].set_player(Player::White); // poniendo las primeras fichas en el tablero
        self.squares[3][4].set_player(Player::Black);
        self.squares[4][3].set_player(Player::Black);
        self.squares[4][4].set_player(Player::White);
    }

    pub fn change_square(&mut self, x: usize, y:usize ) {
        self.squares[x][y].change_player();
    }

    pub fn set_player(&mut self, x: usize, y:usize, player: Player) {
        self.squares[x][y].set_player(player);
    }

    pub fn get_square(&self, x: usize, y:usize) -> Square {
        return self.squares[x][y];
    }
}
