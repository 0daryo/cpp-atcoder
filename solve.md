g++ main.cpp -o a && ./a

# ライブラリ

- reverse
- sort
- vector
  隣接リスト
- stack
  　深さ優先
- queue
  幅優先 ABC7C
- priority_queue
  ABC131D,ABC141D
  `priority_queue<P, vector<P>, greater<P>> que;`

  ````
  for (const auto& [key, value] : myMap) {
    std::cout << key << " has value " << value << std::endl;
  }
  ```
  ダイクストラ
  ````

* map
  for(auto x : v) {
  std::cout << x << "\n";
  }
* lower_bound
  ソート済みの配列を見つける系
* set
* pair
  座標
* table
* find
* next_permutation ABC145C 添字あってる？
* bit 系

# アルゴリズム

- (C までは特に)全探索!!
- 式変形
- 偶奇で場合分け
- **全体から余事象を引く**
- 組み合わせの最大値は意外と少ない
- 後ろから見てみる
- 単調増加は二分探索法 数直線乗で狭めていく ABC146C
  lower_bound ABC143D
- 桁数　 ABC146C
- 余事象 n 乗の計算を繰り返し二乗法 ABC156D
- nCa(nCr) n が大きい、a が小さい ABC156D
- long long で宣言してる？
- 隣接する系は累積和
- 深さ優先探索(いけるかいけないか) -> 再帰・stack
- 木は DFS を疑う To の vector 親を持つ再帰
  lib/dfs
  dfsで数字を作っていく ABC165C
  ABC138D
- DP
  　 ABC153E
  添字を入れ替える
  ナップザック dp/knapsack
  桁DP 本質として同じものを共通化 三次元目でそこまでの桁が同じor小さい ABC154E
- ぴったりで行ける時は貪欲でも
  後ろから貪欲法 後ろから見れば片方の条件を無視 ABC137D
- k 回単位 -> modK で分けて抜き出したもの　前と違う手(ABC149:D)
  mod 周期　違う数なら 2 周 ABC133C
- 最小経路探索(n を頂点, m を辺)
- 経路復元はアリ本 p98

幅優先(最短経路　迷路とか) -> queue 最短が決まったらキューに入れる

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
ABC147D
A XOR A = 0
ABC128C

素数判定 ABC149C

最小公約数 lib/gcd ABC142D
素因数分解 ABC142D

タンジェント atan2 戻り値がラジアンなので degree = rad \* (180/π)
π=3.14159265358979323846;
π=r*2*acos(-1)

n-k を続ける==n%k 約数列挙 ABC161E

x1+x2+⋯+xk=n
xi≥0
を満たす整数 (x1,x2,…,xk) の組の個数を重複組合せと呼び、n+k−1Ck−1 通り。

x1+x2+⋯+xk=n
xi≥1
を満たす整数 (x1,x2,…,xk) の組の個数は n−1Ck−1 通りになる

尺取り方
ABC130D

ABC165D
a/b以下の最大の整数
floor(a/b)=(a-a%b)/b
x%bの最大値のxはb-1

10と2019のように互いに素ならmod2019において10の逆元が存在 

char to int n[1] - '0'

ABC138E 部分列
最初から順に登場する部分を探す　二週分取っておく
s[i]-'a'->数字の文字コード 
場所i以降で文字cが最初に現れる位置

ABC135D
modは桁ごとに独立　
一旦`dp[n] // n文字目まで見たとき、〜〜`のように考える　

charをforで扱う
20200314D

ABC84D
エラトステネスのふるい
素数判定
累積和