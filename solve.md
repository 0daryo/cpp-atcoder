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
  ダイクストラ
- map
- lower_bound
  ソート済みの配列を見つける系
- set
- pair
  座標
- table
- find
- next_permutation
- bit系

# アルゴリズム
(Cまでは特に)全探索!!
全体から余事象を引く
単調増加は二分探索法 数直線乗で狭めていく ABC146C
n乗の計算を繰り返し二乗法
long longで宣言してる？
隣接する系は累積和
深さ優先探索(いけるかいけないか) -> 再帰・stack
幅優先(最短経路　迷路とか) -> queue 最短が決まったらキューに入れる
DP ぴったりで行ける時は貪欲でもDPでいい
k回単位 -> modKで分けて抜き出したもの　前と違う手(ABC149:D)
最小経路探索
- 水を流す様な　-> queue ABC160D ABC151D
- 樹形図で上から -> stack, queue
最小領域木

依存するのは先頭と末尾のみ

辞書順で並べたときにPとQがどれだけ離れているか
|func(P)- func(Q)|

nをp(素数)で何回割り切れるか -> ABC148E

XOR
bitごとに独立して考える!!
ABC147E
A XOR A = 0