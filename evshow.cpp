#include <linux/input.h>
#include <stdio.h>

int main(void) {
  setbuf(stdin, NULL), setbuf(stdout, NULL);

  struct input_event event;
  while (fread(&event, sizeof(event), 1, stdin) == 1) {
    fprintf(stderr, "\n%d, %d, %d\n", event.type, event.code, event.value);
  }
}
