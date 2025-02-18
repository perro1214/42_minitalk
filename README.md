# usleep, signal, getpid(), pause() 関数解説

## 1. usleep()

### 概要

`usleep()` 関数は、指定されたマイクロ秒数の間、実行を一時停止します。

### ヘッダファイル

```c
#include <unistd.h>
```

### プロトタイプ

```c
int usleep(useconds_t usec);
```

### 引数

*   `usec`: 一時停止するマイクロ秒数。

### 返り値

*   成功した場合: 0
*   エラーの場合: -1 (errno が設定されます)

### 注意点

*   `usleep()` は推奨されない関数であり、代わりに `nanosleep()` を使用することが推奨されます。`nanosleep()` はより正確な一時停止を提供します。
*   `usleep()` の精度はシステムに依存します。
*   シグナルによって中断される可能性があります。

### 使用例

```c
#include <unistd.h>
#include <stdio.h>

int main() {
  printf("開始\n");
  usleep(500000); // 500ミリ秒一時停止
  printf("終了\n");
  return 0;
}
```

## 2. signal()

### 概要

`signal()` 関数は、特定のシグナルが発生したときの処理方法を設定します。シグナルハンドラを登録するために使用されます。

### ヘッダファイル

```c
#include <signal.h>
```

### プロトタイプ

```c
void (*signal(int signum, void (*handler)(int)))(int);
```

### 引数

*   `signum`: 処理するシグナルの番号 (例: `SIGINT`, `SIGTERM`, `SIGALRM`)。
*   `handler`: シグナルが発生したときに呼び出される関数へのポインタ。以下のいずれかを指定できます。
    *   `SIG_DFL`: デフォルトのシグナル処理を行う。
    *   `SIG_IGN`: シグナルを無視する。
    *   関数へのポインタ: 独自のシグナルハンドラ関数を指定する。

### 返り値

*   成功した場合: 以前のシグナルハンドラへのポインタ。
*   エラーの場合: `SIG_ERR`。

### 注意点

*   `signal()` は移植性の低い関数であり、代わりに `sigaction()` を使用することが推奨されます。`sigaction()` はより柔軟で、信頼性の高いシグナル処理を提供します。
*   シグナルハンドラ内では、再入可能 (リエントラント) な関数のみを使用する必要があります。
*   シグナルハンドラは非同期的に呼び出されるため、注意が必要です。

### 使用例

```c
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void signal_handler(int signum) {
  printf("シグナル %d を受信しました\n", signum);
  exit(1); // プログラムを終了
}

int main() {
  signal(SIGINT, signal_handler); // Ctrl+C (SIGINT) を受信したときの処理を設定

  printf("プログラム実行中... Ctrl+C で終了\n");
  while (1) {
    // 何らかの処理
  }

  return 0;
}
```

## 3. getpid()

### 概要

`getpid()` 関数は、現在のプロセスのプロセス ID (PID) を取得します。

### ヘッダファイル

```c
#include <unistd.h>
```

### プロトタイプ

```c
pid_t getpid(void);
```

### 引数

*   なし

### 返り値

*   現在のプロセスの PID。

### 使用例

```c
#include <unistd.h>
#include <stdio.h>

int main() {
  pid_t pid = getpid();
  printf("現在のプロセスの PID: %d\n", pid);
  return 0;
}
```

## 4. pause()

### 概要

`pause()` 関数は、シグナルを受信するまでプロセスを一時停止します。

### ヘッダファイル

```c
#include <unistd.h>
```

### プロトタイプ

```c
int pause(void);
```

### 引数

*   なし

### 返り値

*   エラーの場合: -1 (errno が EINTR に設定されます)
*   正常にシグナルを受信した場合: 返り値はありません (関数はシグナルハンドラから戻った後に終了します)。

### 注意点

*   `pause()` は、シグナルハンドラが登録されている場合にのみ意味があります。
*   シグナルを受信すると、`pause()` は中断され、シグナルハンドラが実行されます。シグナルハンドラから戻ると、`pause()` は -1 を返し、`errno` を `EINTR` に設定します。

### 使用例

```c
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void signal_handler(int signum) {
  printf("シグナル %d を受信しました\n", signum);
}

int main() {
  signal(SIGINT, signal_handler); // Ctrl+C (SIGINT) を受信したときの処理を設定

  printf("シグナルを待機中...\n");
  pause(); // シグナルを受信するまで一時停止

  printf("pause() から戻りました\n"); // シグナルハンドラが実行された後に実行される
  return 0;
}
```
```` ▋
