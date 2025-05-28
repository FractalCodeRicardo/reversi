use crate::square::Square;

pub struct Board {
    pub squares: [[Square; 8]; 8],
}

impl Board {
    fn new() -> Self {
        let mut squares = [[Square{x: 0, y:0}; 8]; 8];

        for row in 0..8 {
            for col in 0..8 {
                squares[row][col] = Square::new(row as i8, col as i8); // or any constructor
            }
        }

        Board { squares }
    }
}
