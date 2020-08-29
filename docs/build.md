# giabalanai Build Guide
**一度すべて読んでから組み立てることをお勧めします。**

## 0 パーツの確認、各部品の実装面の整理
キット付属品

| パーツ名 |  個数  |  備考  | 写真 |
|--------|-------|-------|-------|  
|左手側基板|1枚|キーが平行四辺形に5行12列配置されているもの。||
|右手側基板|1枚|キーが上から12列、13列、12列、13列、12列配置されていて、右端にはエンコーダーが配置されているもの。||
|背面基板|2枚|左手側基板も右手側基板も同じ背面基板を使います。||
|ダイオード 1N4148W|123個|左手側は60個、右手側は62個＋エンコーダ用1個||
|タクトスイッチ|2個|左右のリセットスイッチ用。||
|TRRSジャック|2個|||
|M2 スペーサー |20個|左右各10個|
|M2 ネジ|40個|左右各20個||
|ゴム足|10個|左右各5個||


別途用意いただく必要のあるもの

| パーツ名 |  個数  |  備考  | 写真 |
|--------|-------|-------|-------|  
|キースイッチ(CherryMX 互換品)|122個|左手側60個＋右手側62個。||
|キーキャップ|122個|1U、左60個＋右62個。||
|[コンスルー付きPro Micro](https://yushakobo.jp/shop/promicro-spring-pinheader/)|2個|ファームウェア なし をお選びください（別途書き込みます）。||
|TRRSケーブル|1本|AUXケーブルとも呼ばれている3.5mmオーディオ用の4極ケーブル(左手側のLEDも発光させる場合は4極ケーブルが必須)。||
|MicroUSBケーブル|1本|Pro Micro側のコネクタの耐久性が低いためマグネット式を推奨。左右の基板のPro Microにファームウェア書き込むときにとても便利です。||

[Optional]別途用意いただく必要のあるもの

| パーツ名 |  個数  |  備考  | 写真 |
|--------|-------|-------|-------|  
|LED（SK6812mini）|63個 or 123個|1の「Backlight RGB LED」を使う場合に必要。左60個＋右62個＋エンコーダ用1個。右手側だけ光らせたい場合は63個、両手とも光らせたい場合は123個必要。||
|[ロータリーエンコーダ(ノブ付き)](https://yushakobo.jp/shop/pec12r-4222f-s0024/)|1個|右手側のキーボードに配置。音量調整＋ミュート用のロータリーエンコーダを取り付ける場合は必要。|

### オモテ面、裏面の実装物

**※ 部品の実装には順番があります。特に、Pro Micro、キースイッチ、エンコーダ、の実装は最後になりますので先に実装しないよう注意ください。
実装の順番はこの後の手順に従ってください。**

#### 裏面には次の部品を実装します。
 - LED[Optional]
 - ダイオード
 - TRRSジャック
 - タクトスイッチ
 - Pro Micro

#### オモテ面
 - キースイッチ
 - エンコーダ


## 1 Backlight RGB LEDの取付け[Optional]
バックライト用のチップLED(SK6812mini)はPCBの下面側から実装します。向きに注意して穴に入れてください。
裏から見て、一番大きいパッド（5V）とシルクの○が同じ位置になります。
LEDはデータを直列に伝送する都合上、最上行は上面からみて右から左、2行目は左から右、3行目はまた右から左に…と並んでいます。
このため、偶数行と奇数行のLEDの向きが違うので十分ご注意ください。
はんだ付けが軌道に乗った矢先に向きを間違えがちです。その時のショックと言ったら。。。（経験者談）。
<img width="300" alt="RGB" src="https://github.com/3araht/giabalanai/blob/master/Picture/RGB.png">

温調半田ごてを使い、約220℃ではんだ付けします。温度が高いとLEDが壊れますので注意してください。温調できない半田ごてではすぐに焦げます＆壊れます（これも経験者談）。
<img width="300" alt="RGB" src="https://github.com/3araht/giabalanai/blob/master/Picture/RGB.png">
<img width="700" alt="RGB_LED" src="https://github.com/3araht/giabalanai/blob/master/Picture/RGB_LED.jpg">

LEDは、右手側Pro Microの1番ピン（Tx）から右手側基板の右上のLEDから直列繋ぎにデータを伝達し、右手側基板上の63個のLEDを通過したデータはTRRSケーブルを通じて左手側基板上面からみて右上のLEDから直列繋ぎにデータを伝達します。
右手側基板の下図の位置をはんだでジャンパします。
※左手側基板のこの部分はジャンパしません。左手側基板は後述するように別の部分をジャンパします。

1、右手側基板のここと、
<img width="700" alt="Jumper" src="https://github.com/3araht/giabalanai/blob/master/Picture/Jumper.png">

2、右手側基板のここ。
<img width="700" alt="Jumper" src="https://github.com/3araht/giabalanai/blob/master/Picture/Jumper.png">

また、左手側もLEDを点灯させる場合には、下図の位置もはんだでジャンパします。
3、右手側基板のここ
<img width="700" alt="Jumper" src="https://github.com/3araht/giabalanai/blob/master/Picture/Jumper.png">

4、左手側基板のここ
<img width="700" alt="Jumper" src="https://github.com/3araht/giabalanai/blob/master/Picture/Jumper.png">

LEDの情報は直列に伝送されますので、接続が途切れてしまうと正しくLEDが光らなくなります。


## 2 ダイオードの取付け
キーの数が多いキーボードではMatrixという手法を使ってキーが押されたかどうか判断します。
キーが必ず1個ずつしか押されないと保証されているのであれば、このダイオードは不要なのですが、
和音を弾くことがあるので複数のキーを同時に押す場面が出てきます。
このとき、Matrixという手法で複数同時押しを正しく判断するためにこのダイオードが必要になります。
詳しい説明については、[こちら](https://docs.qmk.fm/#/how_a_matrix_works)などをご覧ください。

ダイオードには向きがあります。キースイッチと干渉しないように、ダイオードは基板の裏面に実装します。
ダイオードの黒いほうが四角いフットプリントに合うように配置します。
<img width="300" alt="diode" src="https://github.com/3araht/giabalanai/blob/master/Picture/Diode2.png">
<img width="700" alt="diode" src="https://github.com/3araht/giabalanai/blob/master/Picture/Diode.jpg">

## 3 リセットスイッチとTRRSジャックの取付け
白い四角い枠のシルクに沿って裏側に取り付けます。浮いたり曲がった状態で実装しないようにマスキングテープなどで予め仮止めしてからはんだ付けするとミスが少なくなります。
<img width="700" alt="S_T" src="https://github.com/3araht/giabalanai/blob/master/Picture/Switch_TRRS.JPG">

## 4 Pro Micro用ピンヘッダの取付け
**※コンスルー（スプリングピンヘッダ）を使う場合はこの工程は不要です。**
白い四角い枠のシルクに沿って裏側にピンヘッダを取り付けます。
**この時点でPro Microを取り付けてはいけません。一度はんだ付けしてしまったPro Micro を取り外すのは至難の技です。充分ご注意ください。**


## 5 キースイッチの取付け
**スイッチを取り付ける前に部品の取付けやはんだ付けができているか確認します。**
（TRRSジャックとリセットスイッチは特に注意が必要です。）
<img width="700" alt="switch" src="https://github.com/3araht/giabalanai/blob/master/Picture/Switch.jpg">
※スプリングピンヘッダを使用する場合は6と8の工程を先に行い、動作確認をすると失敗する可能性が減ります。

## 6 Pro Microの取付け
**作業前にPro MicroをUSBでPCと繋げて動作を確認しておきましょう。**
取り付ける前にはんだ忘れがないか確認します。
左右の基板ともPro Microを表にして取り付けられるようになります。
取り付けたときにPro Microの浮きがないか確認し、浮きがあればPro Micro下のスイッチの足を少しカットします。

※コンスルーを使う場合はPro Micro側のみをはんだ付けします。
コンスルーの使い方は下記ページをご参照ください。
https://github.com/MakotoKurauchi/helix/blob/master/Doc/buildguide_jp.md#pro-micro

## 7 背面プレート、スペーサーの組み立て
図の赤丸の位置に4 mmのねじと 6 mmのスペーサーを取り付けます。
<img width="700" alt="spacer" src="https://github.com/3araht/giabalanai/blob/master/Picture/Spacer.png">

緑丸の位置にゴム足を取り付けます。
<img width="700" alt="gom" src="https://github.com/3araht/giabalanai/blob/master/Picture/Gom.png">

## 8 Firmwareの書き込み
以下を参考に書き込んでください。または、QMKで検索すると書き込み方がすぐに出てくるはずです。
https://docs.qmk.fm/#/getting_started_build_tools
giabalanai の Firmware は以下にあります。
https://github.com/qmk/qmk_firmware/tree/master/keyboards/giabalanai

コンパイル済のHEXファイルはこちらからダウンロードできます。
https://github.com/3araht/giabalanai/blob/master/3araht_giabalanai_default.hex

このキーボードでタイピングすることはあまり考えていないと思いますが、必要に応じてカスタマイズしてお使いください。

### default について

USBケーブルを接続したら、アコーディオンの配列になります。

エンコーダを右に回すと音量が大きくなり、左に回すと小さくなるようになっています。
エンコーダは押しボタンにもなっており、押すとミュートON/OFFを切り替えるようになっています。

エンコーダボタン（短押しだとミュート）を長押しながら右手側基板4行1列目のGの音を押すと
左手側基板の5行12列がQWERTY配列の基板になるようになっています（マイナス記号など一部配置されていないので簡易的なものになります）。
アコーディオンの配列に戻す場合は、エンコーダボタンを長押しながら右手側基板3行1列目のA♭の音を押します。
なお、電源を再投入（USB抜き差し）したら アコーディオンの配列に戻ります。

このキーボードでは、右手側がマスターとなっていますので、USBケーブルは必ず右手側に接続してください。

LED については、押したキーが光るようになっています。
エンコーダについてはMute状態のときに点灯します。


初めての方は以下のツールを使うことをお勧めします。（これらを使用する場合LED系は点灯しません。）
https://config.qmk.fm/#/giabalanai/LAYOUT
https://github.com/qmk/qmk_toolbox
