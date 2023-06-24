#include <iostream>
#include "conio.h"
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>

class cuadrotablero {
  private: int cx;
  int cy;
  int circulo;

  public: void pintarcuadro(int);

  cuadrotablero() {
    cx = -1;
    cy = -1;
    circulo = 0;
  }

  int Ocx() {
    return cx;
  }

  int Ocy() {
    return cy;
  }

  int Oc() {
    return circulo;
  }

  void Cc(int g) {
    circulo = g;
  }

  void cambiarcirculo() {
    if (circulo == 1)
      circulo = 2;
    else
      circulo = 1;
  }

  void cambiarcoordenada(int y, int x) {
    cx = x * 50;
    cy = y * 50;
  }

  void asignarcirculo(int c) { //si circulo=1 es blanco, si circulo=2 es negro, si circulo=0 no hay nada
    circulo = c;
  }
};

int son = 1;
void leyendas();
void establecertablero(cuadrotablero t[8][8]);
void iniciargraficos();
void cerrargraficos();
int movimiento(cuadrotablero t[8][8], cuadrotablero B, int jug);
void pintarmarcador(int, int, int);
void sonido(int error);

void main() {
  iniciargraficos();
  leyendas();
  FILE * temp;

  cuadrotablero tablero[8][8]; //creando el tablero
  establecertablero(tablero); //asignar coordenadas y pintarlo

  temp = fopen("c:\\tmpreversi.txt", "w");
  fwrite( & tablero, sizeof(tablero), 1, temp); //guardando los valores preestablecidos para un nuevo juego
  fclose(temp);
  //derecha:77
  //arriba:72
  //izquierda:75
  //abajo:80
  //G:71
  //enter:13
  //escape 27
  // N:78
  //alt + a: 30

  int x = 0;
  int y = 0; /*principal       */ /////
  int opc = 0;
  int jugador = 2; //2 para el turno de las negras, 1 para el turno de las blancas
  int cN = 2, cB = 2; //contador de fichas
  pintarmarcador(jugador, cN, cB);
  do {
    switch (opc) {
    case 77: //derecha
    {
      if (x == 7)
        x = 0;
      else
        x++;
    }
    break;

    case 115: //activar o desactivar sonido
    {
      if (son == 1)
        son = 0;
      else
        son = 1;
    }
    break;

    case 72: //arriba
    {
      if (y == 0)
        y = 7;
      else
        y--;
    }
    break;
    case 71: //guardar partida
    {
      temp = fopen("c:\\reversi.txt", "w");
      fseek(temp, SEEK_SET, 0);
      fwrite( & tablero, sizeof(tablero), 1, temp);
      fclose(temp);
      gotoxy(55, 20);
      cout << "Guardado:c:\\reversi.txt";
      delay(2000);
      gotoxy(55, 20);
      cout << "                        ";
    }
    break;
    /*	case 30:     //abrir
    		{
    		  temp=fopen("c:\\reversi.txt","r");
    		  fseek(temp,SEEK_SET,0);
    		  while(fread(&tablero,sizeof(tablero),1,temp)==1);
    		  fclose(temp);
    		}   */
    case 78: //juego nuevo
    {
      temp = fopen("c:\\tmpreversi.txt", "r");
      while (fread( & tablero, sizeof(tablero), 1, temp) == 1);
      fclose(temp);

      //restableciendo variables
      jugador = 2;
      x = 0;
      y = 0;
      opc = 0;
      cN = 2;
      cB = 2;

      //pintando de nuevo el tablero
      cleardevice();
      leyendas();
      pintarmarcador(jugador, cN, cB);
      for (int z = 0; z < 8; z++)
        for (int f = 0; f < 8; f++)
          tablero[z][f].pintarcuadro(WHITE);

    }
    break;

    case 80: //abajo
    {
      if (y == 7)
        y = 0;
      else
        y++;
    }
    break;

    case 75: //izquierda
    {
      if (x == 0)
        x = 7;
      else
        x--;
    }
    break;

    case 13: //enter: realizar movimiento
    {
      int cambiadas;
      cambiadas = movimiento(tablero, tablero[y][x], jugador);

      if (cambiadas) { //si el movimiento es valido (cambiadas!=0) hace el cambio de jugador  y aumenta sus fichas
        if (jugador == 1) {
          cB = cB + cambiadas + 1; //se le aumenta tambien la ficha provocada por el tiro, no solo las cambiadas de color
          cN = cN - cambiadas;
          jugador = 2;
        } else {
          cN = cN + cambiadas + 1;
          cB = cB - cambiadas;
          jugador = 1;
        }
      } else {
        sonido(1);
        gotoxy(55, 30);
        cout << "Movimiento invalido";
        delay(1000);
        gotoxy(55, 30);
        cout << "                    ";
      }
      pintarmarcador(jugador, cN, cB);
    } //case 13

    } //switch

    while (!kbhit()) //cuadro parpadeante
    {
      tablero[y][x].pintarcuadro(BLUE);
      delay(200);
      tablero[y][x].pintarcuadro(WHITE);
      delay(200);
    }

    opc = getch();
  } while (opc != 27 && (cN + cB) < 64); //while de hasta arribota

  remove("c:\\tmpreversi.txt");
  cerrargraficos();
} //main

void sonido(int error = 0) {
  if (son == 0)
    return;

  if (error == 1) {
    sound(600);
    delay(500);
    nosound();
    return;
  }

  sound(700);
  delay(200);
  nosound();
}

void pintarmarcador(int jugador, int N, int B) {
  char cad[4];
  if (N == 2 && B == 2) {
    rectangle(450, 50, 620, 100);
    line(450, 75, 620, 75);
    line(580, 50, 580, 100);
    setfillstyle(SOLID_FILL, BLUE);
    floodfill(451, 70, getmaxcolor());
    setfillstyle(SOLID_FILL, RED);
    floodfill(451, 76, getmaxcolor());
    outtextxy(455, 40, "Turno:    ");
    outtextxy(455, 65, "Negras");
    outtextxy(455, 90, "Blancas");
    setfillstyle(SOLID_FILL, DARKGRAY);
  }

  if (jugador == 2) {
    setcolor(0);
    outtextxy(590, 80, "���");
    outtextxy(590, 83, "���");
    setcolor(WHITE);
    circle(595, 65, 5);
    floodfill(595, 65, getmaxcolor());
  } else {
    setcolor(0);
    outtextxy(590, 60, "���");
    outtextxy(590, 63, "���");
    setcolor(WHITE);
    circle(595, 85, 5);
    floodfill(595, 85, getmaxcolor());
  }
  setcolor(BLUE);
  outtextxy(515, 65, "����");
  setcolor(RED);
  outtextxy(515, 90, "����");
  setcolor(WHITE);
  outtextxy(515, 65, itoa(N, cad, 10));
  outtextxy(515, 90, itoa(B, cad, 10));

}

int movimiento(cuadrotablero t[8][8], cuadrotablero B, int jug) {
  /* hay 8 formas de tiro posibles: arriba,abajo,izquierda
      derecha,diagonal arriba izquierda, diagonal arriba derecha,diagonal abajo derecha
      y diagonal abajo izquierda
  */

  int x = (B.Ocx() / 50) - 1;
  int y = (B.Ocy() / 50) - 1;
  int contrario;
  int flag = 0;
  int ccambiadas = 0;

  if (jug == 1)
    contrario = 2;
  else
    contrario = 1;

  if (t[y][x].Oc() != 0)
    return 0; //el cuadro tiene que estar vacio

  //EVALUANDO EL TIRO HACIA ARRIBA

  y--;
  if (t[y][x].Oc() == contrario) //hay fichas contrarias para arriba movimiento valido
    while (y >= 0) {

      if (t[y][x].Oc() == jug) //movimiento valido
      {
        flag = 1;
        break;
      }

      if (t[y][x].Oc() == 0) //si no hay una ficha del jugador seguida de una del jugador contrario es un movimiento invalido
        break;

      if (t[y][x].Oc() == contrario) //la ficha siguiente es contraria
        y--;

    }

  if (flag == 1) // Si la bandera (flag) es uno el movimiento se puede realizar
  {
    y++;
    while (y <= (B.Ocy() / 50) - 1) //cambiando la ficha de color
    {
      t[y][x].Cc(jug);
      t[y][x].pintarcuadro(WHITE);
      sonido();
      ccambiadas++;
      y++;
    }
    ccambiadas--; //se descuenta el cambio por el tiro, solo nos interesan las fichas contrarias que cambiaron
  }

  //EVALUANDO EL TIRO HACIA ABAJO

  y = (B.Ocy() / 50) - 1;
  y++;
  flag = 0;
  if (t[y][x].Oc() == contrario)
    while (y <= 7) {
      if (t[y][x].Oc() == jug) {
        flag = 1;
        break;
      }
      if (t[y][x].Oc() == 0)
        break;

      if (t[y][x].Oc() == contrario)
        y++;

    }

  if (flag == 1) {
    y--;

    while (y >= (B.Ocy() / 50) - 1) //cambiando la ficha de color
    {
      t[y][x].Cc(jug);
      t[y][x].pintarcuadro(WHITE);
      sonido();
      ccambiadas++;
      y--;
    }
    ccambiadas--;
  }

  //EVALUANDO TIRO HACIA LA IZQUIERDA

  x--;
  y = (B.Ocy() / 50) - 1;
  flag = 0;
  if (t[y][x].Oc() == contrario)
    while (x >= 0) {
      if (t[y][x].Oc() == jug) {
        flag = 1;
        break;
      }
      if (t[y][x].Oc() == 0)
        break;

      if (t[y][x].Oc() == contrario)
        x--;

    }

  if (flag == 1) {
    x++;
    while (x <= (B.Ocx() / 50) - 1) {
      t[y][x].Cc(jug);
      t[y][x].pintarcuadro(WHITE);
      sonido();
      ccambiadas++;
      x++;
    }
    ccambiadas--;
  }

  //EVALUANDO TIRO HACIA LA DERECHA
  x = (B.Ocx() / 50) - 1;
  flag = 0;
  x++;
  if (t[y][x].Oc() == contrario)
    while (x <= 7) {
      if (t[y][x].Oc() == jug) {
        flag = 1;
        break;
      }
      if (t[y][x].Oc() == 0)
        break;

      if (t[y][x].Oc() == contrario)
        x++;
    }

  if (flag == 1) {
    x--;
    while (x >= (B.Ocx() / 50) - 1) {
      t[y][x].Cc(jug);
      t[y][x].pintarcuadro(WHITE);
      sonido();
      ccambiadas++;
      x--;
    }
    ccambiadas--;
  }

  //EVALUANDO TIRO ARRIBA-IZQUIERDA
  flag = 0;
  x = (B.Ocx() / 50) - 1;
  y = (B.Ocy() / 50) - 1;
  x--;
  y--;
  if (t[y][x].Oc() == contrario)
    while (x >= 0 && y >= 0) {
      if (t[y][x].Oc() == jug) {
        flag = 1;
        break;
      }

      if (t[y][x].Oc() == 0)
        break;

      if (t[y][x].Oc() == contrario) {
        x--;
        y--;
      }
    }

  if (flag == 1) {
    x++;
    y++;
    while (x <= (B.Ocx() / 50) - 1 || y <= (B.Ocy() / 50) - 1) {
      t[y][x].Cc(jug);
      t[y][x].pintarcuadro(WHITE);
      sonido();
      ccambiadas++;
      x++;
      y++;
    }
    ccambiadas--;
  }

  // EVALUANDO TIRO ABAJO-DERECHA
  flag = 0;
  x = (B.Ocx() / 50) - 1;
  y = (B.Ocy() / 50) - 1;
  x++;
  y++;
  if (t[y][x].Oc() == contrario)
    while (x <= 7 && y <= 7) {
      if (t[y][x].Oc() == jug) {
        flag = 1;
        break;
      }

      if (t[y][x].Oc() == 0)
        break;

      if (t[y][x].Oc() == contrario) {
        x++;
        y++;
      }
    }

  if (flag == 1) {
    x--;
    y--;
    while (x >= (B.Ocx() / 50) - 1 || y >= (B.Ocy() / 50) - 1) {
      t[y][x].Cc(jug);
      t[y][x].pintarcuadro(WHITE);
      sonido();
      ccambiadas++;
      x--;
      y--;
    }
    ccambiadas--;
  }
  //EVALUANDO TIRO ABAJO -IZQUIERDA
  flag = 0;
  x = (B.Ocx() / 50) - 1;
  y = (B.Ocy() / 50) - 1;
  y++;
  x--;

  if (t[y][x].Oc() == contrario)
    while (x >= 0 && y <= 7) {
      if (t[y][x].Oc() == jug) {
        flag = 1;
        break;
      }

      if (t[y][x].Oc() == 0)
        break;

      if (t[y][x].Oc() == contrario) {
        y++;
        x--;
      }
    }

  if (flag == 1) {
    y--;
    x++;
    while (y >= (B.Ocy() / 50) - 1 || x <= (B.Ocx() / 50) - 1) {
      t[y][x].Cc(jug);
      t[y][x].pintarcuadro(WHITE);
      sonido();
      ccambiadas++;
      y--;
      x++;
    }
    ccambiadas--;
  }

  flag = 0;
  x = (B.Ocx() / 50) - 1;
  y = (B.Ocy() / 50) - 1;
  y--;
  x++;

  if (t[y][x].Oc() == contrario)
    while (x <= 7 && y >= 0) {
      if (t[y][x].Oc() == jug) {
        flag = 1;
        break;
      }

      if (t[y][x].Oc() == 0)
        break;

      if (t[y][x].Oc() == contrario) {
        y--;
        x++;
      }
    }

  if (flag == 1) {
    y++;
    x--;
    while (y <= (B.Ocy() / 50) - 1 || x >= (B.Ocx() / 50) - 1) {
      t[y][x].Cc(jug);
      t[y][x].pintarcuadro(WHITE);
      sonido();
      ccambiadas++;
      y++;
      x--;
    }
    ccambiadas--;
  }

  return ccambiadas;
}

void leyendas() {
  gotoxy(1, 1);
  cout << "REVERSI - Ricardo Serrato Barrera -  Zamora Mich - Empezado: 22-Dic-2005";
  gotoxy(55, 10);
  cout << "Guardar:     G";
  gotoxy(55, 11);
  cout << "Mover:       Flechas";
  gotoxy(55, 12);
  cout << "Seleccionar: Enter";
  gotoxy(55, 13);
  cout << "Sonido:      s";
  gotoxy(55, 14);
  cout << "Juego nuevo: N";
  gotoxy(55, 15);
  cout << "Salir:       Escape";
}

void iniciargraficos() {
  int gmode, gdriver = DETECT;
  initgraph( & gdriver, & gmode, "\\TC\\BGI\\");
}

void cerrargraficos() {
  closegraph();
}

/*asigna coordenadas y pinta tablero*/
void establecertablero(cuadrotablero t[8][8]) {
  t[3][3].asignarcirculo(1); //poniendo las primeras fichas en el tablero
  t[3][4].asignarcirculo(2);
  t[4][3].asignarcirculo(2);
  t[4][4].asignarcirculo(1);

  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      t[y][x].cambiarcoordenada(y + 1, x + 1); //cambia las coordenadas mandadas por el centro de cada cuadro
      t[y][x].pintarcuadro(WHITE); //se imaginan que hace no ? :P

    }
  }
}

void cuadrotablero::pintarcuadro(int color) {
  setcolor(color);
  rectangle(cx - 24, cy - 24, cx + 24, cy + 24);

  if (circulo == 1) {
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    circle(cx, cy, 15);
    floodfill(cx, cy, getmaxcolor());
  }

  if (circulo == 2) {
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, DARKGRAY);
    circle(cx, cy, 15);
    floodfill(cx, cy, getmaxcolor());
  }
}