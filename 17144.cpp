#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;

enum arrow{
  up = 0,
  left = 1,
  right = 2,
  down = 3,
};

int main (){
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


  int R,C,T; // R = Row, C = count, T = time

  cin >> R >> C >> T;

  int micro_dust[R][C];
  int tot_dust = 0;

  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
      cin >> micro_dust[i][j];


  int pos_cleaner, under_cleaner;
  for (pos_cleaner = 0; pos_cleaner < R; pos_cleaner++)
    if (micro_dust[pos_cleaner][0] == -1) break;

  under_cleaner = pos_cleaner + 1;

  int check_dust[R][C];

  for (int Time = 0; Time < T; Time++) {

      //확산 먼지 량
      for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
          if (micro_dust[i][j] > 0) {
            check_dust[i][j] = micro_dust[i][j] / 5;
          } else {
            check_dust[i][j] = 0;
          }


      for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {

          if (check_dust[i][j] > 0) {
            int count = 0;

            if ((micro_dust[i - 1][j] >= 0) && i - 1 >= 0) {
                micro_dust[i - 1][j] += check_dust[i][j]; count++;
            }

            if ((micro_dust[i][j - 1] >= 0) && j - 1 >= 0) {
                micro_dust[i][j - 1] += check_dust[i][j]; count++;
            }

            if ((micro_dust[i + 1][j] >= 0) && i + 1 < R) {
                micro_dust[i + 1][j] += check_dust[i][j]; count++;
            }

            if ((micro_dust[i][j + 1] >= 0) && j + 1 < C) {
                micro_dust[i][j + 1] += check_dust[i][j]; count++;
            }

            micro_dust[i][j] -= count * check_dust[i][j];
          }
        }
      }

      // upper 공기청정기
      //가장 위부터 공기청정기까지
      for (int i = 1; (pos_cleaner - i) >= 0; i++)
        micro_dust[pos_cleaner - i][0] = micro_dust[pos_cleaner - 1 - i][0];

      //가장오른쪽 위부터 왼쪽까지
      for (int i = 0; i < C - 1; i++)
        micro_dust[0][i] = micro_dust[0][i + 1];

      //pos_cleaner오른쪽끝 부터 가장 위에쪽 까지
      for (int i = 0; i < pos_cleaner; i++)
        micro_dust[i][C - 1] = micro_dust[i + 1][C - 1];

      //pos_cleaner 부터 가장 오른쪽까지
      for (int i = 1; (C - i) > 1; i++)
        micro_dust[pos_cleaner][C - i] = micro_dust[pos_cleaner][C - i - 1];
      //가장 가까운부분 = 0
        micro_dust[pos_cleaner][1] = 0;
      //under 공기청정기
      //가장아래부터 공기청정기까지
      for (int i = under_cleaner; i + 2 < R; i++)
        micro_dust[i + 1][0] = micro_dust[i + 2][0];


      for (int i = 0; (i + 1) < C; i++)
        micro_dust[R - 1][i] = micro_dust[R - 1][i + 1];

      for (int i = 1; (R - i) > under_cleaner; i++)
        micro_dust[R - i][C - 1] = micro_dust[R - i - 1][C - 1];

      for (int i = 1; (C - i) > 1; i++)
        micro_dust[under_cleaner][C - i] = micro_dust[under_cleaner][C - 1 - i];

        micro_dust[under_cleaner][1] = 0;

  }
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
      tot_dust += micro_dust[i][j];

  cout << tot_dust + 2;
}
