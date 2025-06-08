use crate::board::Board;
use crate::cursor::Cursor;
use crate::player::{self, Player};
use crate::position::Position;

pub struct Game {
    pub board: Board,
    pub cursor: Cursor,
    pub selection: Option<Position>,
    pub current_player: Player,
    pub white_score: usize,
    pub black_score: usize
}

impl Game {
    pub fn new() -> Self {
        Game {
            selection: None,
            cursor: Cursor::new(0, 0),
            board: Board::new(),
            current_player: Player::White,
            white_score: 2,
            black_score: 2
        }
    }

    pub fn change_turn(&mut self) {
        if self.current_player == Player::White {
            self.current_player = Player::Black;
            return;
        }

        if self.current_player == Player::Black {
            self.current_player = Player::White;
            return;
        }
    }

    fn is_outside(x: usize, y: usize) -> bool {
        return x < 0 || y < 0 || x > 7 || y > 7;
    }

    fn get_line(
        &self,
        mut x: usize,
        mut y: usize,
        increment_x: i8,
        increment_y: i8,
    ) -> Vec<Position> {
        let mut positions: Vec<Position> = Vec::new();

        loop {
            // Apply increments safely
            let new_x = x as isize + increment_x as isize;
            let new_y = y as isize + increment_y as isize;

            // Stop if the new coordinates are negative or outside
            if new_x < 0 || new_y < 0 {
                break;
            }

            let (nx, ny) = (new_x as usize, new_y as usize);

            if Game::is_outside(nx, ny) {
                break;
            }

            x = nx;
            y = ny;

            positions.push(Position::new(x, y));
        }

        positions
    }

    pub fn do_movement(&mut self) -> usize {
        let squares_changed = self.change_squares();
        self.update_scores(squares_changed, self.current_player);
        return squares_changed
    }

    fn update_scores(&mut self, total: usize, player: Player) {

        if total == 0 {
            return;
        }

        if player == Player::White {
            self.white_score += total + 1;
            return;
        }
            
        if player == Player::Black {
            self.black_score += total + 1;
            return;
        }
    }

    fn change_squares(&mut self) -> usize {
        let changes = self.get_all_changes();

        for change in &changes {
            let x = change.x;
            let y = change.y;
            self.board.change_square(x, y);
        }

        if changes.len() > 0 {
            self.board
                .set_player(
                    self.cursor.x,
                    self.cursor.y,
                    self.current_player
                );
        }

        return changes.len();
    }

    fn get_all_changes(&self) -> Vec<Position> {
        let x = self.cursor.x;
        let y = self.cursor.y;
        let player = self.current_player;

        let up = self.get_line(x, y, 0, -1);
        let down = self.get_line(x, y, 0, 1);
        let left = self.get_line(x, y, -1, 0);
        let right = self.get_line(x, y, 1, 0);
        let up_left = self.get_line(x, y, -1, -1);
        let up_right = self.get_line(x, y, 1, -1);
        let down_left = self.get_line(x, y, -1, 1);
        let down_right = self.get_line(x, y, 1, 1);

        let mut changes: Vec<Position> = Vec::new();

        changes.extend(self.get_changes(up, player));
        changes.extend(self.get_changes(down, player));
        changes.extend(self.get_changes(left, player));
        changes.extend(self.get_changes(right, player));
        changes.extend(self.get_changes(up_right, player));
        changes.extend(self.get_changes(up_left, player));
        changes.extend(self.get_changes(down_left, player));
        changes.extend(self.get_changes(down_right, player));

        return changes;
    }

    fn get_changes(&self, line: Vec<Position>, player: Player) -> Vec<Position> {
        let mut changes: Vec<Position> = Vec::new();
        let mut same_color = false;

        for item_line in line {
            let x = item_line.x;
            let y = item_line.y;

            let square = self.board.get_square(x, y);

            if !square.has_player() {
                break;
            }

            if square.circle == player {
                same_color = true;
                break;
            }

            if square.circle != player {
                let pos = Position::new(x, y);
                changes.push(pos);
            }
        }

        if !same_color {
            changes.clear();
        }

        return changes;
    }
}
