#include <iostream>
#include <queue>
using namespace std;

int H, W, startX, startY, endX, endY; // 迷路の大きさ
char c[1009][1009];                   // 迷路のマップ、'.' の場合白マス、'#' の場合黒マス
int dist[1009][1009];

int main()
{
  // 迷路を入力する
  cin >> H >> W;
  cin >> startX >> startY;
  cin >> endX >> endY;

  for (int i = 1; i <= H; i++)
  {
    for (int j = 1; j <= W; j++)
      cin >> c[i][j];
  }

  // 距離を初期化する
  for (int i = 1; i <= H; i++)
  {
    for (int j = 1; j <= W; j++)
      dist[i][j] = 1000000007;
  }

  // 幅優先探索により、最短移動回数を求める
  queue<pair<int, int>> Q;
  Q.push(make_pair(startX, startY));
  dist[startX][startY] = 0;

  while (!Q.empty())
  {
    int cx = Q.front().first, cy = Q.front().second;
    Q.pop();

    // 右なら(1,0)下なら(0,1)...
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
      int ex = cx + dx[i], ey = cy + dy[i];
      if (c[ex][ey] != '.' || dist[ex][ey] != 1000000007)
        continue;
      // 進んだら座標をキューに入れる
      Q.push(make_pair(ex, ey));
      // distは最小経路
      dist[ex][ey] = dist[cx][cy] + 1;
    }
  }

  // 最短距離を出力する
  cout << dist[endX][endY] << endl;
  return 0;
}