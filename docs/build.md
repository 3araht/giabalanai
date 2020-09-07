# giabalanai Build Guide
**一度すべて読んでから組み立てることをお勧めします。**

## 0 パーツの確認、各部品の実装面の整理
キット付属品

| パーツ名 |  個数  |  備考  |
|--------|-------|-------|  
|左手側基板|1枚|キーが平行四辺形に5行12列配置されているもの。|
|右手側基板|1枚|キーが上から12列、13列、12列、13列、12列配置されていて、右端にはエンコーダーが配置されているもの。|
|ボトムプレート|2枚|左手側基板も右手側基板も同じボトムプレートを使います。|
|M2 スペーサー |20個|左右各10個|
|M2 ネジ|40個|左右各20個|
|クッションシール|10個|左右各5個|
|TRRSジャック|2個||
|リセットスイッチ|2個||
|ダイオード 1N4148|123個|左手側は60個、右手側は62個＋エンコーダ用1個|

別途用意いただく必要のあるもの

| パーツ名 |  個数  |  備考  |
|--------|-------|--------|  
|[Pro Micro （コンスルー付き）](https://yushakobo.jp/shop/promicro-spring-pinheader/)|2個|ファームウェア なし をお選びください（別途書き込みます）。|
|キースイッチ(CherryMX 互換品)|122個|左手側60個＋右手側62個。|
|MX対応キーキャップ|122個|1U、左60個＋右62個。（5pinタイプ推奨） |
|[TRRSケーブル](https://yushakobo.jp/shop/trrs_cable/)|1本|AUXケーブルとも呼ばれている3.5mmオーディオ用の4極ケーブル(左手側のLEDも発光させる場合は4極ケーブルが必須)。|
|[MicroUSBケーブル](https://yushakobo.jp/shop/usb_cable_micro_b/)|1本|Pro Micro側のコネクタの耐久性が低いためマグネット式を推奨。左右の基板のPro Microにファームウェア書き込むときにとても便利です。|

[Optional]別途用意いただく必要のあるもの

| パーツ名 |  個数  |  備考  |
|--------|-------|-------|
|[ロータリーエンコーダ(ノブ付き)](https://yushakobo.jp/shop/pec12r-4222f-s0024/)|1個|右手側のキーボードに配置。音量調整＋ミュート用のロータリーエンコーダを取り付ける場合は必要。|
|LED（SK6812mini）|123個|2の「Backlight RGB LED」を使う場合に必要。左60個＋右62個＋エンコーダ用1個。|

### オモテ面、裏面の実装物

**※ 部品の実装には順番があります。特に、Pro Micro、キースイッチ、エンコーダ、の実装は最後になりますので先に実装しないよう注意ください。
実装の順番はこの後の手順に従ってください。**

基板の裏面には、ダイオードの実装場所やキーボード名が印字されています。

左手側　オモテ面  
<img width="700" alt="RGB" src="https://github.com/3araht/giabalanai/blob/master/pictures/left_front_pcb.jpg">

左手側　裏面  
<img width="700" alt="RGB" src="https://github.com/3araht/giabalanai/blob/master/pictures/left_rear_pcb.jpg">

右手側　オモテ面  
<img width="700" alt="RGB" src="https://github.com/3araht/giabalanai/blob/master/pictures/right_front_pcb.jpg">

右手側　裏面  
<img width="700" alt="RGB" src="https://github.com/3araht/giabalanai/blob/master/pictures/right_rear_pcb.jpg">


#### 裏面には次の部品を実装します
 - LED[Optional]
 - ダイオード
 - TRRSジャック
 - リセットスイッチ
 - Pro Micro

#### オモテ面には次の部品を実装します
 - キースイッチ
 - エンコーダ


## 1 ダイオードの取付け
キーの数が多いキーボードではMatrixという手法を使ってキーが押されたかどうか判断します。
キーが必ず1個ずつしか押されないと保証されているのであれば、このダイオードは不要なのですが、
和音を弾くことがあるので複数のキーを同時に押す場面が出てきます。
このとき、Matrixという手法で複数同時押しを正しく判断するためにこのダイオードが必要になります。
詳しい説明については、[こちら](https://docs.qmk.fm/#/how_a_matrix_works)などをご覧ください。

ダイオードには向きがあります。また、図のように足を曲げておきます。
ダイオードをつまんで両端の足を同時に曲げると図の右のように比較的ちょうどいい形になります。  
<img width="700" alt="diode" src="https://github.com/3araht/giabalanai/blob/master/pictures/diode_bend.jpg">

キースイッチと干渉しないように、ダイオードは基板の裏面に実装します。
ダイオードの黒いほうが四角いフットプリント（Kと印字されている方）に合うように配置します。  
<img width="700" alt="diode" src="https://github.com/3araht/giabalanai/blob/master/pictures/diode_align1.jpg">

足を曲げて基板に這わせてダイオードを仮止めします。  
<img width="700" alt="diode" src="https://github.com/3araht/giabalanai/blob/master/pictures/diode_flatten.jpg">

オモテ面から見た図  
<img width="700" alt="diode" src="https://github.com/3araht/giabalanai/blob/master/pictures/diode_flatten2.jpg">

オモテ面から半田付けします。  
<img width="700" alt="diode" src="https://github.com/3araht/giabalanai/blob/master/pictures/diode_soldered.jpg">

足をニッパでカットします。  
<img width="700" alt="diode" src="https://github.com/3araht/giabalanai/blob/master/pictures/diode_feet_cut.jpg">


## 2 Backlight RGB LEDの取付け[Optional]
バックライト用のチップLED(SK6812mini)はPCBの裏面から実装します。向きに注意して穴に入れてください。
LEDの裏から見て、一番大きいパッド（5V）とシルクの○が同じ位置になります。
LEDはデータを直列に伝送する都合上、最上行はオモテ面からみて左から右、2行目は右から左、3行目はまた左から右に…と並んでいます（右手側の場合）。  
<img width="700" alt="RGB_LED" src="https://github.com/3araht/giabalanai/blob/master/pictures/LED_serial.jpg">

このため、偶数行と奇数行のLEDの向きが違うので十分ご注意ください。
半田付けが軌道に乗った矢先に向きを間違えがちです。
その時のショックと言ったら。。。（経験者談）。  
<img width="700" alt="RGB" src="https://github.com/3araht/giabalanai/blob/master/pictures/SK6812mini_alignment.jpg">

温調半田ごてを使い、約220℃で半田付けします。温度が高いとLEDが壊れますので注意してください。
温調できない半田ごてではすぐに焦げます＆壊れます（これも経験者談）。

こてを斜めにして接触面積を広げるとやり易いという事がわかりました。  
<img width="700" alt="RGB_LED" src="https://github.com/3araht/giabalanai/blob/master/pictures/LED_solder_iron.jpg">

LEDは、右手側Pro Microの1番ピン（Tx）から右手側基板の左上のLEDから直列繋ぎにデータを伝達し、右手側基板上の63個のLEDを通過したデータはTRRSケーブルを通じて左手側基板上面からみて右上のLEDから直列繋ぎにデータを伝達します。

右手側基板および左手側基板の下図の位置を半田でジャンパします。

1、右手側基板の2箇所と、  
<img width="700" alt="Jumper" src="https://github.com/3araht/giabalanai/blob/master/pictures/LED_right_jumper.jpg">

2、左手側基板のここ。  
<img width="700" alt="Jumper" src="https://github.com/3araht/giabalanai/blob/master/pictures/LED_left_jumper.jpg">

LEDの情報は直列に伝送されますので、接続が途切れてしまうと正しくLEDが光らなくなります。


## 3 リセットスイッチとTRRSジャックの取付け
左右の基板共、白い四角い枠のシルクに沿って裏側に取り付けます。浮いたり曲がった状態で実装しないようにマスキングテープなどで予め仮止めしてから半田付けするとミスが少なくなります。  
<img width="700" alt="S_T" src="https://github.com/3araht/giabalanai/blob/master/pictures/TRRS_ResetSW.jpg">

## 4 Pro Micro用ピンヘッダの取付け
**※コンスルー（スプリングピンヘッダ）を使う場合はこの工程は不要です。**
白い四角い枠のシルクに沿って裏側にピンヘッダを取り付けます。
**この時点でPro Microを取り付けてはいけません。一度半田付けしてしまったPro Micro を取り外すのは至難の技です。充分ご注意ください。**


## 5 キースイッチ、エンコーダ（Option）の取付け
**スイッチを取り付ける前に部品の取付けや半田付けができているか確認します。**
（1 のダイオードは必ず済ませておいてください。）  
<img width="700" alt="switch" src="https://github.com/3araht/giabalanai/blob/master/pictures/Keysw_front.jpg">  
<img width="700" alt="switch" src="https://github.com/3araht/giabalanai/blob/master/pictures/Keysw_rear.jpg">

※スプリングピンヘッダを使用する場合は6と8の工程を先に行い、動作確認(下図のようにキースイッチ部をピンセットなどでショートさせ、MIDI機器を認識するソフトで音が出るか確かめる事)をすると失敗する可能性が減ります。  
<img width="700" alt="switch" src="https://github.com/3araht/giabalanai/blob/master/pictures/Keysw_test.jpg">


## 6 Pro Microの取付け
**作業前にPro MicroをUSBでPCと繋げて動作を確認しておきましょう。**
取り付ける前に半田忘れがないか確認します。
左右の基板ともPro Microを表にして取り付けられるようになります。
取り付けたときにPro Microの浮きがないか確認し、浮きがあればPro Micro下のスイッチの足を少しカットします。

※コンスルーを使う場合はPro Micro側のみを半田付けします。  
<img width="700" alt="CT" src="https://github.com/3araht/giabalanai/blob/master/pictures/Con_through.jpg">

コンスルーを斜めに半田付けしないように、基板の**裏面から**コンスルーを差しておいてピンが垂直になるようにします。
下図のように、Pro Micro 側(側面に空いている小さな穴が近い方)を上にして基板にコンスルーを差し込みます。
このとき、図のように、コンスルーの向きを揃えておきます（＝2つとも側面の小さな穴が空いている方向を揃えます）。  
<img width="700" alt="switch" src="https://github.com/3araht/giabalanai/blob/master/pictures/Con_through_onPCB.jpg">

*Pro Micro の上下の向きに注意。Pro Micro の TxD ピンが基板の TxD に刺さるように向きが合っているか確認します。  
<img width="700" alt="CT" src="https://github.com/3araht/giabalanai/blob/master/pictures/Con_throughSoldered2ProMicro.jpg">  
<img width="700" alt="CT" src="https://github.com/3araht/giabalanai/blob/master/pictures/ProMicro_TxD_r01.jpg">

コンスルーを基板の裏面から差し、TxD の位置を見て向きが揃っていることを確認したら、コンスルーとPro Micro を半田付けします。
**一度半田付けしたコンスルーを外すのは困難を極めますので、十分注意してください。**

## 7 ボトムプレート、スペーサーの組み立て
ボトムプレートの、図の赤丸の位置 10 箇所に M2 のねじで スペーサーを取り付けます。  
<img width="700" alt="spacer" src="https://github.com/3araht/giabalanai/blob/master/pictures/BottomPlate.jpg">  
<img width="700" alt="spacer" src="https://github.com/3araht/giabalanai/blob/master/pictures/SpacerOnBottomPlate.jpg">

キースイッチの間にネジをセットするにはピンセットを使います。  
<img width="700" alt="spacer" src="https://github.com/3araht/giabalanai/blob/master/pictures/ScrewSettingWIthTweezers.jpg">

ネジ止めは、たすき掛けで均一に締めつけますが、強く締めつけすぎないようにします。

（左手側は、左上と右下の二箇所がキースイッチと干渉してしまって上からねじ止めができませんでした。。。すみません。）  
<img width="700" alt="spacer" src="https://github.com/3araht/giabalanai/blob/master/pictures/leftUpperLeftCorner.jpg">

緑丸の位置にクッションシールを取り付けます。  
<img width="700" alt="gom" src="https://github.com/3araht/giabalanai/blob/master/pictures/Cushon.jpg">

## 8 Firmwareの書き込み
左右の基板の Pro Micro に同じHEXファイルを書き込みます。
以下を参考に書き込んでください。または、QMKで検索すると書き込み方がすぐに出てくるはずです。  
https://docs.qmk.fm/#/getting_started_build_tools

giabalanai の Firmware は以下にUPされるよう push request 中です。
https://github.com/qmk/qmk_firmware/tree/master/keyboards/giabalanai

それまで、暫定的に[こちら](https://github.com/3araht/giabalanai/blob/master/temp/qmk_firmware/keyboards/giabalanai)のソースコードをお使いください。


コンパイル済のHEXファイルは[こちら](https://github.com/3araht/giabalanai/blob/master/giabalanai_3araht.hex)からダウンロードできます。

初めての方はHEXファイルの書き込みに以下のツールを使うことをお勧めします。  
https://github.com/qmk/qmk_toolbox

このキーボードでタイピングすることはあまり考えていないと思いますが、必要に応じてカスタマイズしてお使いください。

### default について
**上記コンパイル済のHEXファイルは下記に示すdefault 設定に加えてLEDが実装されていれば押したキーのLED が発光するようになっています。**

USBケーブルを接続したら、アコーディオンの配列になります。

エンコーダを右に回すと音量が大きくなり、左に回すと小さくなるようになっています。
エンコーダは押しボタンにもなっており、押すとミュートON/OFFを切り替えるようになっています。

エンコーダボタン（短押しだとミュート）を長押しながら左手側キーボード 2行1列目のD♭Majorのコードのキーを押すと
左手側キーボード の5行12列がQWERTY配列のキーボード になるようになっています（マイナス記号など一部配置されていないので簡易的なものになります）。
アコーディオンの配列に戻す場合は、エンコーダボタンを長押しながら左手側キーボード 1行1列目のD♭のルートコードのキーを押します。
右手側下3行だけはB-systemにすることもできます（エンコーダーボタン長押し＋左手側キーボード 1行2列目のA♭のルートコードのキーを押します）。
なお、電源を再投入（USB抜き差し）したら アコーディオンの配列（C-System）に戻ります。

|                               操作                    |       変更先レイヤー（配列）  |
|------------------------------------------------------|---------------------------|
| エンコーダーボタン長押し＋左手側キーボード 1行1列目のD♭ルート | アコーディオン配列（C-System）＝初期状態|
| エンコーダーボタン長押し＋左手側キーボード 2行1列目のD♭Major | QWERTY 配列（左手側キーボード）|
| エンコーダーボタン長押し＋左手側キーボード 1行2列目のA♭ルート | アコーディオン配列（B-System、ただし下3行のみ)|
| USB ケーブル抜き差し | アコーディオン配列（C-System）＝初期状態|


**このキーボードでは、右手側がマスターとなっていますので、USBケーブルは必ず右手側に接続してください。**

## 9 チェックポイント
簡単なチェック項目を挙げます。参考になれば幸いです。

- Pro Micro は左右の基板共にしっかり基板に刺さっている。
- Pro Micro のピンと基板のピンは一致させた状態で接続できている（Pro Micro の上下の向き確認）。
- Pro Micro にファームウェアを書き込んである（左右同じHEXファイルを書き込みます）。
- TRRS ケーブルはしっかり奥まで刺さっている（少しきついのでこれが問題となりがちです。ご注意ください。）
  また、TRRSケーブル内に 5V と GND 線が走っており、電源投入中に抜き差しするとショートする恐れがあるので、活線挿抜はお控えください。
- MIDI機器に対応したソフトを起動している。
- USBケーブルは右手側のキーボードに接続されている。
- 半田付けに問題はないか。
