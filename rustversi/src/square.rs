use crate::player::Player;

#[derive(Clone, Copy, Debug)]
pub struct Square
{
    pub x: i8,
    pub y: i8,
    pub circle: Player
}

impl Square {
   pub fn new(x: i8, y: i8) -> Self {
       return Square {
        x: x,
        y: y,
        circle: Player::None
       }
   } 

   pub fn set_player(&mut self, player: Player)
   {
       self.circle = player;
   }
}
