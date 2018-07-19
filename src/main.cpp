#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "wdt_dio.h"

#define DI_INDEX 0
#define DO_INDEX 0

#define WAIT_TIME 10

int main(int argc, char* argv[]){
  int  i, j;
  WORD  data_di = 0;
  bool data_do = 0;

  char sh_name[300] = "/home/midearobot/Program/WatchDIO/script/shutdown.sh";

  if ( ! InitDIO() ) {
      printf("InitDIO <-- ERROR\n");
      return -1;
  }
  else{
    printf("InitDIO <-- OK\n");
  }

  bool exit_flag = false;
  int exit_count = 0;

  while (!exit_flag){
    // Digital Input status
    bool data_di = DIReadLine((BYTE) DI_INDEX);

    if (!data_di)
      exit_count ++;
    else
      exit_count = 0;

    if (exit_count > WAIT_TIME){
      int re = system(sh_name);

      return 0;
    }

    // Digital Output Status
    if (!data_do){
      DOWriteLineChecked((BYTE) DO_INDEX, true);
      data_do = true;
      printf("Output channel %d is changed to %d\n", DO_INDEX, data_do);
    }

    printf("Input channel %d's status is %d. Output channel %d's status is %d.\
 Exit_count is %d\n", DI_INDEX, data_di, DO_INDEX, data_do, exit_count);

    sleep(1);
  }
  return 0;
}
