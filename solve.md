g++ main.cpp -o a && ./a

# ライブラリ

- reverse
- sort
- vector
  隣接リスト
- stack
  　深さ優先
- queue
  幅優先
- priority_queue
  ABC141D
  `priority_queue<P, vector<P>, greater<P>> que;`

  ダイクストラ

- map
- lower_bound
  ソート済みの配列を見つける系
- set
- pair
  座標
- table
- find
- next_permutation 添字あってる？
- bit 系

# アルゴリズム

- (C までは特に)全探索!!

- **全体から余事象を引く**
- 組み合わせの最大値は意外と少ない
- 単調増加は二分探索法 数直線乗で狭めていく ABC146C
  lower_bound ABC143D
- 桁数　 ABC146C
- 余事象 n 乗の計算を繰り返し二乗法 ABC156D
- nCa(nCr) n が大きい、a が小さい ABC156D
- long long で宣言してる？
- 隣接する系は累積和
- 深さ優先探索(いけるかいけないか) -> 再帰・stack
- 木は DFS を疑う
- 幅優先(最短経路　迷路とか) -> queue 最短が決まったらキューに入れる
- DP ぴったりで行ける時は貪欲でも DP でいい
- k 回単位 -> modK で分けて抜き出したもの　前と違う手(ABC149:D)
- 最小経路探索(n を頂点, m を辺)
- 経路復元はアリ本 p98

- BFS queue ABC160D
  o(n+m)
  辺のコストが全部 1
- ダイクストラ
  o(mlogm)
- ワーシャルフロイド
  o(n^3)
  実装が楽
  全点間の最短距離
- ベルマンフォード
  o(nm)
  負の辺がある
- 水を流す様な　-> queue ABC160D ABC151D
- 樹形図で上から -> stack, queue
  最小領域木

依存するのは先頭と末尾のみ
先頭の桁・末尾の桁 ABC152D

辞書順で並べたときに P と Q がどれだけ離れているか
`|func(P)- func(Q)|`

n を p(素数)で何回割り切れるか -> ABC148E

XOR
bit ごとに独立して考える!!
ABC147E
A XOR A = 0

素数判定 ABC149C

最小公約数 lib/gcb ABC142D
素因数分解 ABC142D

タンジェント atan2 戻り値がラジアンなので degree = rad \* (180/π)
π=3.14159265358979323846;

n-k を続ける==n%k 約数列挙 ABC161E
