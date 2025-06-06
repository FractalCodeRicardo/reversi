pub struct Cursor {
   pub x: usize,
   pub y: usize,
}

impl Cursor {
    pub fn new(x: usize, y: usize) -> Self {
        Cursor { x, y }
    }

    pub fn down(&mut self) {
        if self.y == 7 {
            self.y = 0;
        } else {
            self.y += 1;
        }
    }

    pub fn up(&mut self) {
        if self.y == 0 {
            self.y = 7;
        } else {
            self.y -= 1;
        }
    }

    pub fn right(&mut self) {
        if self.x == 7 {
            self.x = 0;
        } else {
            self.x += 1;
        }
    }

    pub fn left(&mut self) {
        if self.x == 0 {
            self.x = 7;
        } else {
            self.x -= 1;
        }
    }

}

#[cfg(test)]
mod tests {
    use super::Cursor;

    #[test]
    fn cusor_up() {
        let mut cursor = Cursor::new(0, 1);
        cursor.up();
        assert_eq!(cursor.y, 0);
    }
}
