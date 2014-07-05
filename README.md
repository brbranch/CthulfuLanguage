cocos2d-xでインタプリタパターン(クトゥルフ言語)
======================
c++でインタプリタパターンを勉強しようと思って作成したソースファイルです。

cocos2d-xのCCLabelTTFをクトゥルフ言語で操作できるようにしています。

クトゥルフ言語の構文  
-------------
### ■最初には以下の宣言をしなければならない。 ###
フングルイムグルウナフ！クトゥルフ！フォマルハウト・ンガア・グア！ナフルタグン！イア！クトゥグア！  

### ■終了時には以下の宣言をしなければならない。  ###
フングルイムグルウナフ！クトゥルフ！ルル・イエー・ウガ＝ナグル・フタグン！  

### ■単語の間は半角スペースあるいは改行あるいはタブを入れる。  ###

### ■数字を作る際には「イア！イア！」〜「フタグン！」の間に記述をする(足し算) ###
※イア！イア！宣言時の初期値：1  
イグ！ 1  
イタカ！ 2  
ハスタア！ 3  
アブホース！ 5  
チャウグナル・ファウグン！ 7  
ニャル・シュタン！ 11   
ニャル・ガシャンナ！ 13  
シャメッシュ！シャメッシュ！ 17  
イア！ 10  
イア！イア！ 次からの数字は加算していく  
クトゥルフ！ 次からの数字はかけ算でかけていく  
イア・ル・リェー！クトゥルフ・フタグン！ 次からの数字は減算していく  
  
(例)数字の20を作成する場合  
イア！イア！ イタカ！ シャメッシュ！シャメッシュ！ フタグン！  
(1 + 2 + 17)  
  
### ■文字列の作成方法 ###
クトゥルフ言語には文字列配列のメモリがひとつ用意されており、その中にアスキーコード  
を加えていくことで文字列を作成する。  
  
文字列の追加方法  
(命令文以外の言葉) (数字)  
  
(例)Aをメモリ配列に追加する  
イエ・イエ・シュブ・ニグラス！千匹の仔を孕みし森の黒山羊よ！ イア！イア！ イタカ！ クトゥルフ！ イア！ イア！イア！ アブホース！ フタグン！  
  
※命令文以外の言葉なら何でも許容するが、クトゥルフコーディング規約に沿うことが望ましい。  
  
### ■数値の保存 ###
クトゥルフ言語には数値のメモリ領域がひとつ用意されており、条件分岐の際に使用できる。  
  
数値の保存方法  
ニャルラトホテップ・ツガー！ (数値)  
  
### ■繰り返し処理 ###
ティビ・マグヌム・イノミナンドゥム・シグナ！ステラルム！イグラルム！エブファニフォルミス！ (数字) 〜命令文〜 イア！イア！クトゥルフ＝フタグン！   

### ■条件分岐 ###
メモリに内蔵した数値と比較して条件分岐をする。  
  
条件分岐文 比較演算子 (数値) 〜処理〜 イア！イア！クトゥルフ＝フタグン！  
【条件分岐構文】  
クトゥルフ・ダイクン！ if  
アザトース！ elseif  
ヨグ・ソトース！ else  
【比較演算子】  
ネブロッド・ヅイン！ネブロッド・ヅイン！ >  
ヤール・ムテン！ダクタリンカ・フタグン！ <  
シュブ・ニグラス！ ==  
フングルイ＝ムグルウナフ！ウガ＝ナグル・フタグン !=  
  
※イア！イア！クトゥルフ＝フタグン！は条件分岐の度に書く必要がある。  
	(例)  
	クトゥルフ・ダイクン！  
	〜  
	イア！イア！クトゥルフ＝フタグン！  
	アザトース！  
	〜  
	イア！イア！クトゥルフ＝フタグン！  

### ■その他のクトゥルフ言語の命令文 ###
・クトゥルフ・フタグン！ニャルラトホテップ・ツガー！シャメッシュ！シャメッシュ！  
char配列のメモリを初期化する  
  
イアール・ムナール！ウガ＝ナグル・トナロロ・ヨナラナーク・シラーリー！  
char配列のメモリを使い、ログを出力する。  
  
CCLabelTTFのフォントサイズを設定  
ヤイ・ングナガ！ヨグ・ソトホース！ヘエ＝ルゲブ！ファイ・サロドグ・ウアフ！ (数字)  
  
CCLabelTTFに文字を追加  
ウザ・イエイ！ウザ・イエイ！イカア・ハ・ブホウイイ！ラアン＝テゴス！クトゥルフ・フタグン！  
※内蔵された文字列が使用される。  
  
文字を膨張・縮小するアニメーションを追加  
イア！イア！ハスタア！ハスタア・クフアヤク＝ブルグトム・ブグトラグルン！ブルグトム！ (数値1) (数値2)  
数値1ーアニメーションの時間  
数値2ー膨張する大きさ  
  
文字をジャンプさせるアニメーションを追加  
オング・ダクタ・リンカ！ネブロッド・ヅイン！ネブロッド・ヅイン！オング・ダクタ・リンカ！ (数値1) (数値2)  
数値1ーアニメーションの時間  
数値2ージャンプする高さ  
  
文字を回転させるアニメーションを追加  
ヘイ・アア＝シャンタ・ナイグ！ (数値1) (数値2)  
数値1ーアニメーションの時間  
数値2ー回転する角度  
  
文字を動かすアニメーションを追加  
イア・ル・リェー！クトゥルフ・フタグン！イア！イア！ (数値1) (数値2) (数値3)  
数値1ーアニメーションの時間  
数値2ー移動するx方向  
数値3ー移動するy方向  
  
アニメーションを待機させる  
オグトロド・アイ・フ！ゲブル＝エエヘ！ヨグ・ソトト・ンガーング！アイイ・ズロー！ (数値)  
数値ーアニメーションの時間  
