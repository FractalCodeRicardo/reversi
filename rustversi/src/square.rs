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

    pub fn change_player(& mut self) {
        if self.circle == Player::None  {
            return;
        }

        if self.circle == Player::White {
            self.set_player(Player::Black);
        } else {
            self.set_player(Player::White);
        }
    }
}
