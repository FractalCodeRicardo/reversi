#[derive(Clone, Copy, Debug)]
pub struct Square
{
    pub x: i8,
    pub y: i8
}

impl Square {
   pub fn new(x: i8, y: i8) -> Self {
       return Square {
        x: x,
        y: y
       }
   } 
}
