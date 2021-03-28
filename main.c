#include <stdio.h>
#define SYZE 10
//1.) Описать очередь с приоритетным исключением
//Указание: См. видео 9.4 Приоритетная и двусторонняя очередь.
//В видео рассказано о двух типах очереди с приоритетами -
//- С приоритетным исключением. В данном случае элемент вставляется как и в обычной очереди - в конец, а когда элемент удаляется, то выбирается тот, что имеет наивысший приоритет.
//- С приоритетным включением. В данном случае элемент вставляется сразу на место согласно своему приоритету (чем выше приоритет, тем ближе к началу), а удаляется элемент также как и в обычной очереди - тот что стоит в начале.
//В видео показана реализация очереди с приоритетным включением, вам же надо реализовать очередь с приоритиным исключением.
//Подсказка: Вам понадобится -
//a) структура Node из урока
//b) функция void Init() - Данная функция инициализирует значения.
//c) void insert(int pr, int dat) - Данная функция вставляет элемент c приоритетом pr и значением dat в очередь.
//d) Node* rem() - Данная функция удаляет элемент из очереди и возвращает указатель на него.
//2.) Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.
//Входные данные: число в десятичной системе счисления.
//Выходные данные: двоичное представление числа, выведенное в консоль
//Примеры:
//25 - 11001
//15 - 1111
//Указание: реализуйте структуру данных Стек и напишите две функции PushStack(...) и PopStack(...). Стек разбирается в видео "Создание стека с использованием массива".
//Результатом работы должен стать один файл с кодом на языке С, содержащий функцию main, а также функции, необходимые для работы приоритетной очереди и перевода систем счисления

typedef struct {
  int priority;
  int data;
} Node;

Node* arr[SYZE];
int head;
int tail;
int items;

void init() {
  for (int i = 0; i < SYZE; ++i) {
      arr[i] = NULL;
    }
  head = 0;
  tail = 0;
  items = 0;
}

void insert(int priority, int data) {
  int flag;
  Node* node = (Node*) malloc(sizeof (Node));
  node->data = data;
  node->priority = priority;

  if (items == 0) {
      arr[tail++] = node;
      items++;
    }
  else if (items == SYZE) {
      printf("%s \n", "Queue is full");
      return;
    }
  else {
      int index = 0;
      Node* temp;
      int i = 0;

      for (i = head; i < tail; ++i) {
          index = i % SYZE;
          if (arr[index]->priority > priority) {
              break;
            }
          else {
              index++;
            }
        }

      flag = index % SYZE;
      i++;

      while (i <= tail) {
          index = i % SYZE;
          temp = arr[index];
          arr[flag] = temp;
          i++;
        }

      arr[flag] = node;
      items++;
      tail++;
    }
}

Node* remoove() {
  if (items == 0) {
      return NULL;
    }
  else {
      int index = head++ % SYZE;
      Node *temp = arr[index];
      arr[index] = NULL;
      items--;
      return temp;
    }
}

void printQueue() {
  printf("[");
  for (int i = 0; i < SYZE; ++i) {
      if (arr[i] == NULL) {
          printf("[*, *]");
        }
      else {
          printf("[%d, %d]", arr[i]->priority, arr[i]->data);
        }
    }
  printf("]\n");
}

int main()
{
  init();
  insert(1, 11);
  insert(1, 12);

  printQueue();

  insert(2, 31);

  printQueue();
  insert(1, 1);
  printQueue();

  return 0;
}
