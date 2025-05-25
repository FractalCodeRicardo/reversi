use crate::square::Square;

pub struct Board {
    pub squares: [[Square; 8]; 8],
}

impl Board {
    fn new() -> Self {
        // let mut squares = [[Square::default(); 8]; 8];
        //
        // for row in 0..8 {
        //     for col in 0..8 {
        //         let iRow: i8 = row;
        //         let iCol: i8= col;
        //         squares[row][col] = Square::new(iRow, iCol); // or any constructor
        //     }
        // }
        //
        // Board { squares }
    }
}
