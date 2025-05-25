#include "Square.h"
#include "Drawer.h"

Square::Square() {
  cx = -1;
  cy = -1;
  circulo = 0;
}

void Square::setDrawer(Drawer *drawer) { this->drawer = drawer; }

int Square::Ocx() { return cx; }

int Square::Ocy() { return cy; }

int Square::Oc() { return circulo; }

int Square::Cc(int g) { circulo = g; }

void Square::cambiarcirculo() {
  if (circulo == 1)
    circulo = 2;
  else
    circulo = 1;
}

void Square::cambiarcoordenada(int x, int y) {
  cx = x * 50;
  cy = y * 50;
}

void Square::asignarcirculo(
    int c) { // si circulo=1 es blanco, si circulo=2 es negro, si circulo=0 no
             // hay nada
  circulo = c;
}

void Square::pintarcuadro(int color) {
  this->drawer->setColor(color);
  this->drawer->rectangle(cx - 24, cy - 24, cx + 24, cy + 24);

  if (circulo == 1) {
    this->drawer->setColor(Drawer::GREEN);
    this->drawer->circle(cx, cy, 15);
  }

  if (circulo == 2) {
    this->drawer->setColor(Drawer::RED);
    this->drawer->circle(cx, cy, 15);
  }
}

void Square::pintarCuadroSeleccion(int color) {
  this->drawer->setColor(color);
  this->drawer->rectangle(cx - 20, cy - 20, cx + 20, cy + 20);
}
