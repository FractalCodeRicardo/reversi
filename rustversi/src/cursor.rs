struct Cursor {
    x: u8,
    y: u8,
}

impl Cursor {

    fn new(x: u8, y: u8) -> Self {
        Cursor { x, y }
    }

    fn down(&mut self) {
        if self.y == 7 {
            self.y = 0;
        } else {
            self.y += 1;
        }
    }

    fn up(&mut self) {
        if self.y == 0 {
            self.y = 7;
        } else {
            self.y -= 1;
        }
    }

    fn right(&mut self) {
        if self.x == 7 {
            self.x = 0;
        } else {
            self.x += 1;
        }
    }

    fn left(&mut self) {
        if self.x == 0 {
            self.x = 7;
        } else {
            self.x -= 1;
        }
    }

    fn get_x(&self) -> u8 {
        self.x
    }

    fn get_y(&self) -> u8 {
        self.y
    }
}

fn main() {
    // Create a new Cursor instance at position (0, 0)
    let mut cursor = Cursor::new(0, 0);

    // Move the cursor in various directions
    cursor.derecha();
    cursor.abajo();
    cursor.izquierda();
    cursor.arriba();

    // Print the current position of the cursor
    println!("Cursor position: ({}, {})", cursor.get_x(), cursor.get_y());
}
