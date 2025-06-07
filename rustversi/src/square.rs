use crate::player::Player;

#[derive(Clone, Copy, Debug)]
pub struct Square {
    pub x: usize,
    pub y: usize,
    pub circle: Player,
}

impl Square {
    pub fn new(x: usize, y: usize) -> Self {
        return Square {
            x: x,
            y: y,
            circle: Player::None,
        };
    }

    pub fn set_player(&mut self, player: Player) {
        self.circle = player;
    }

    pub fn has_player(&self) -> bool {
        return self.circle != Player::None;
    }
}
