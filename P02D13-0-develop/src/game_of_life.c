
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FILD_WIDTH 80  // размер поля
#define FILD_HEIGHT 25 // размер поля
#define CELL 'O'
#define DEAD_CELL ' '

// находим живых соседий
int getNeighbor(char arr[][FILD_WIDTH], int i, int j) {
  int neighborCnt = 0;

  for (int k = i - 1; k <= i + 1; ++k) {
    for (int q = j - 1; q <= j + 1; ++q) {
      if (k == i && q == j)
        continue;

      if (arr[(k + FILD_HEIGHT) % FILD_HEIGHT][(q + FILD_WIDTH) % FILD_WIDTH] ==
          CELL) {
        ++neighborCnt;
      }
    }
  }

  return neighborCnt;
}
// отображение поля
void display(char tmp[][80]) {
  for (int i = 0; i < 25; ++i) {
    for (int j = 0; j < 80; ++j) {
      printf("%c", tmp[i][j]);
    }
    printf("\n");
  }
}
// регулируем скорость игры
void speed(int *time, char *k) {
  char push = getch();
  switch (push) {
  case 'z':
    if ((*time + 100000) < 840000)
      *time = *time + 100000;
    break;
  case 'x':
    if ((*time - 100000) > 40000)
      *time = *time - 100000;
    break;
  case 'q':
    *k = 'q';
    break;
  default:
    break;
  }
}

int game_over(char arr[][FILD_WIDTH], char tmp[][FILD_WIDTH]) { // конец игры
  int count = 0;
  for (int i = 0; i < FILD_HEIGHT; i++) {
    for (int j = 0; j < FILD_WIDTH; j++) {
      if (arr[i][j] != tmp[i][j]) {
        count = 1;
        break;
      }
    }
    if (count > 0) {
      break;
    }
  }
  return count;
}

void life(char arr[][FILD_WIDTH],
          char tmp[][FILD_WIDTH]) { // убей или оживи клетки
  for (int i = 0; i < FILD_HEIGHT; ++i) {
    for (int j = 0; j < FILD_WIDTH; ++j) {
      int cnt = getNeighbor(arr, i, j);
      if (arr[i][j] == DEAD_CELL) {
        if (cnt == 3) {
          tmp[i][j] = CELL;
        } else {
          tmp[i][j] = DEAD_CELL;
        }
      } else {
        if (cnt == 2 || cnt == 3) {
          tmp[i][j] = CELL;
        } else {
          tmp[i][j] = DEAD_CELL;
        }
      }
    }
  }
}
// основное тело
int main() {
    int Numder;
  char k;
  int n, g, f, time = 700000;
  char arr[FILD_WIDTH][FILD_WIDTH], tmp[FILD_WIDTH][FILD_WIDTH];

  for (int i = 0; i < FILD_HEIGHT; ++i) {
    for (int j = 0; j < FILD_WIDTH; ++j) {
      arr[i][j] = DEAD_CELL;
    }
  }

  scanf("%d", &n); // кол-во живых точек на начальном поле

  for (int i = 0; i < n; ++i) { // ввод живых клеток
    scanf("%d %d", &g, &f);
    arr[g][f] = CELL;
  }

  initscr(); // инициализация curses режима
  noecho(); // запрет на отображение вводимых символов
  halfdelay(1); // ограничивает время на ввод символа
  (void)freopen("/dev/tty", "r",
                stdin); // активация клавиатуры после перенапрвавления

  while (1) {
    Numder++;
    usleep(900000);
    life(arr, tmp);

    display(tmp);
    speed(&time, &k);
    if (k == 'q') {
      break;
    }

    // задержка по времени (микросекунды)
    refresh(); // обновление изменившиеся зоны терминала
    clear(); // чистка терминала
    int game = game_over(arr, tmp);
    if (game == 0) {
      break;
    }

    for (int i = 0; i < FILD_HEIGHT; ++i) {
      for (int j = 0; j < FILD_WIDTH; j++)
        arr[i][j] = tmp[i][j];
    }
  }

  endwin(); // закрытие curses режима
  printf("GAME OVER, The world has changed %d generations", Numder);
  return 0;
}