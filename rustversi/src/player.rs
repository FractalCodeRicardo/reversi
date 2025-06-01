#[repr(u8)]
#[derive(Clone, Copy, Debug, PartialEq)]
pub enum Player {
    None = 0,
    White = 1,
    Black = 2,
}
