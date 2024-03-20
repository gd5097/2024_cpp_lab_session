#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>

namespace console {

// console 라이브러리를 초기화 한다.
void init();
// 다음 프레임까지 기다린다.
void wait();
// x, y 위치에 문자열 s를 그린다.
void draw(int x, int y, const char *s);
// x, y 위치에 문자열 s를 그린다.
void draw(int x, int y, std::string s);
// 화면에 그려진 것을 전부 지운다.
void clear();

enum Key { K_NONE = 0, K_OTHER, K_LEFT, K_RIGHT, K_UP, K_DOWN, K_ESC, K_ENTER };

// 키가 눌렸는지 확인한다.
bool key(Key k);

} // namespace console

#endif