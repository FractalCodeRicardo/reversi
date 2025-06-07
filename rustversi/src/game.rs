use crate::board::Board;
use crate::cursor::Cursor;
use crate::player::Player;
use crate::position::Position;
use crate::square;

pub struct Game {
    pub board: Board,
    pub cursor: Cursor,
    pub selection: Option<Position>,
    pub current_player: Player,
}

impl Game {
    pub fn new() -> Self {
        Game {
            selection: None,
            cursor: Cursor::new(0, 0),
            board: Board::new(),
            current_player: Player::White,
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

    fn do_movement(&self) {
        let x = self.cursor.x;
        let y = self.cursor.y;
        let player = self.current_player;

        let arriba = self.get_line(x, y, 0, -1);
        let abajo = self.get_line(x, y, 0, 1);
        let izquierda = self.get_line(x, y, -1, 0);
        let derecha = self.get_line(x, y, 1, 0);
        let arriba_izquierda = self.get_line(x, y, -1, -1);
        let arriba_derecha = self.get_line(x, y, 1, -1);
        let abajo_izquierda = self.get_line(x, y, -1, 1);
        let abajo_derecha = self.get_line(x, y, 1, 1);

        let mut cambios: Vec<Position> = Vec::new();

        cambios.extend(self.get_changes(arriba, player));
        cambios.extend(self.get_changes(abajo, player   ));
        cambios.extend(self.get_changes(izquierda, player));
        cambios.extend(self.get_changes(derecha, player));
        cambios.extend(self.get_changes(arriba_izquierda, player));
        cambios.extend(self.get_changes(arriba_derecha, player));
        cambios.extend(self.get_changes(abajo_izquierda, player));
        cambios.extend(self.get_changes(abajo_derecha, player));
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
