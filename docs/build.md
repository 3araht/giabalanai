# giabalanai Build Guide for rev.02
*rev.01用のビルドガイドは[こちら](https://github.com/3araht/giabalanai/blob/main/docs/build_r01.md)*

rev.01 か rev.02 かは基板に記載がありますのでご確認ください。

rev.01 と rev.02 の一番の違いは Pro Micro の裏表の実装方法です。rev.02 では 4 mm のシャコタンのため、Pro Micro の表側を実装する基板側に向けました。

**一度すべて読んでから組み立てることをお勧めします。**


## 0 ##
## パーツの確認、各部品の実装面の整理 ###
### キット付属品

| パーツ名 |  個数  |  備考  |
|--------|-------|-------|
|左手側基板|1枚|キーが平行四辺形に5行12列配置されているもの。|
|右手側基板|1枚|キーが上から12列、13列、12列、13列、12列配置されていて、右端にはエンコーダーが配置されているもの。|
|ボトムプレート|2枚|左手側基板も右手側基板も同じボトムプレートを使います。|
|M2 スペーサー |20個|左右各10個|
|M2 ネジ|40個|左右各20個|
|クッションシール|10個|左右各5個|
|TRRSジャック|2個|左右の基板を繋ぐTRRSケーブル用|
|リセットスイッチ|2個|ファームウェアを書き込むときに使います。|
|ダイオード 1N4148|99個|左手側は60個、右手側は38個＋エンコーダ用1個|

右手側は62ボタンありますが、そのうち24ボタンは音が重複しているボタンなので、ダイオードは24個少なくてよく、右手側は38個あれば良い事になります。
そこにエンコーダー分を加えて右手側はダイオードを39個使います。


### 別途用意いただく必要のあるもの

| パーツ名 |  個数  |  備考  |
|--------|-------|--------|
|[Pro Micro （コンスルー付き）](https://yushakobo.jp/shop/promicro-spring-pinheader/)|2個|ファームウェア なし をお選びください（別途書き込みます）。|
|キースイッチ(CherryMX 互換品)|122個|左手側60個＋右手側62個。（5pinタイプ推奨）|
|MX対応キーキャップ|122個|1U、左60個＋右62個。|
|[TRRSケーブル](https://yushakobo.jp/shop/trrs_cable/)|1本|AUXケーブルとも呼ばれている3.5mmオーディオ用の4極ケーブル(左手側のLEDも発光させる場合は4極ケーブルが必須)。|
|MicroUSBケーブル|1本|Pro Micro 側のコネクタの耐久性が低いためマグネット式を推奨。左右の基板のPro Micro にファームウェア書き込むときにとても便利です。また、データ通信ができるケーブルである必要がありますので、充電用のケーブルは使えません。Hex ファイルが書き込みできなかったらケーブルを確認してみてください。|

### [Optional]別途用意いただく必要のあるもの

| パーツ名 |  個数  |  備考  |
|--------|-------|-------|
|[ロータリーエンコーダ(ノブ付き)](https://yushakobo.jp/shop/pec12r-4222f-s0024/)|1個|右手側のキーボードに配置。押しボタン機能付きのものを選んでください（端子が上に2本（押しボタン用）、下に3本（エンコーダー用）生えてるやつ）。音量調整＋ミュート用のロータリーエンコーダを取り付ける場合は必要。長押し＋〇〇でレイヤー切り替えができますので、あったほうがよいと思います。|
|LED（SK6812mini）|123個|2の「Backlight RGB LED」を使う場合に必要。左60個＋右62個＋エンコーダ用1個。難しい半田付けを伴うので、半田付け初心者の方はLEDなしで組み立てられることをお勧め致します。|
|[キーボードアクリルプレート giabalanai スイッチプレート・左手・3mm](https://shop.yushakobo.jp/collections/services-auto/products/keyboard_acrylic_plate?variant=39732120518817)|1枚|キースイッチが3pinタイプのものをお使いの場合には、このプレートがあるとキースイッチのアライメントが簡単になります。|
|[キーボードアクリルプレート giabalanai スイッチプレート・右手・3mm](https://shop.yushakobo.jp/collections/services-auto/products/keyboard_acrylic_plate?variant=39732118683809)|1枚|同上|

### オモテ面、裏面の実装物

**※ 部品の実装には順番があります。特に、Pro Micro、キースイッチ、エンコーダ、の実装は最後になりますので先に実装しないよう注意ください。
実装の順番はこの後の手順に従ってください。**

基板の裏面には、ダイオードの実装場所やキーボード名が印字されています。

左手側 オモテ面<br>
<img width="700" alt="PCB" src="https://github.com/3araht/giabalanai/blob/main/pictures/left_front_pcb_r02.jpg">

左手側 裏面<br>
<img width="700" alt="PCB" src="https://github.com/3araht/giabalanai/blob/main/pictures/left_rear_pcb_r02.jpg">

右手側 オモテ面<br>
<img width="700" alt="PCB" src="https://github.com/3araht/giabalanai/blob/main/pictures/right_front_pcb_r02.jpg">

右手側 裏面<br>
<img width="700" alt="PCB" src="https://github.com/3araht/giabalanai/blob/main/pictures/right_rear_pcb_r02.jpg">


#### 裏面には次の部品を実装します
 - ダイオード
 - TRRSジャック
 - リセットスイッチ
 - Pro Micro
 - LED[Optional]

#### オモテ面には次の部品を実装します
 - キースイッチ
 - エンコーダ


## 1
## ダイオードの取付け ##
キーの数が多いキーボードではMatrixという手法を使ってキーが押されたかどうか判断します。
キーが必ず1個ずつしか押されないと保証されているのであれば、このダイオードは不要なのですが、
和音を弾くことがあるので複数のキーを同時に押す場面が出てきます。
このとき、Matrixという手法で複数同時押しを正しく判断するためにこのダイオードが必要になります。
詳しい説明については、[こちら](https://docs.qmk.fm/#/how_a_matrix_works)などをご覧ください。

ダイオードには向きがあります。また、図のように足を曲げておきます。
ダイオードをつまんで両端の足を同時に曲げると図の右のように比較的ちょうどいい形になります。<br>
<img width="700" alt="diode" src="https://github.com/3araht/giabalanai/blob/main/pictures/diode_bend.jpg">

キースイッチと干渉しないように、ダイオードは基板の裏面に実装します。
ダイオードの黒い線のほうが四角いフットプリント（Kと印字されている方, K はKathode（独）の頭文字らしいですが、黒（Kuro) の K で。）に合うように配置します。<br>
<img width="700" alt="diode" src="https://github.com/3araht/giabalanai/blob/main/pictures/diode_align1.jpg">

足を曲げて基板に這わせてダイオードを仮止めします。<br>
<img width="700" alt="diode" src="https://github.com/3araht/giabalanai/blob/main/pictures/diode_flatten.jpg">

オモテ面から見た図<br>
<img width="700" alt="diode" src="https://github.com/3araht/giabalanai/blob/main/pictures/diode_flatten2.jpg">

オモテ面から半田付けします。<br>
<img width="700" alt="diode" src="https://github.com/3araht/giabalanai/blob/main/pictures/diode_soldered.jpg">

足をニッパでカットします。足は勢いよく飛んで行くので、足を押さえながら切ると良いです。<br>
<img width="700" alt="diode" src="https://github.com/3araht/giabalanai/blob/main/pictures/diode_feet_cut.jpg">

これを左手側基板は60箇所、右手側基板は39箇所半田付けします。

なお、下図のR1 には何も実装しません。<br>
<img width="700" alt="diode" src="https://github.com/3araht/giabalanai/blob/main/pictures/R1_NoSolder.jpg">


## 2 ##
## Backlight RGB LEDの取付け[Optional] ##
イメージトレーニングが重要なので、まずは ”SK6812mini はんだ付け” で半田付けの様子を紹介している動画をチェックしてみてください。<br>
また、以下を使うことが成功の鍵となります。<br>
- 温度調整機能付き半田ごてで温度を200℃〜220℃に設定する
- 融点の低い 鉛入り半田（共晶半田）を使う

バックライト用のチップLED(SK6812mini)はPCBの裏面から実装します。向きに注意して穴に入れてください。
LEDの裏から見て、一番大きいパッド（5V）とシルク（印字の事）の○が同じ位置になります。
LEDはデータを直列に伝送する都合上、最上行はオモテ面からみて左から右、2行目は右から左、3行目はまた左から右に…と並んでいます（右手側の場合）。<br>
<img width="700" alt="RGB_LED" src="https://github.com/3araht/giabalanai/blob/main/pictures/LED_serial.jpg">

このため、偶数行と奇数行のLEDの向きが違うので十分ご注意ください。
半田付けが軌道に乗った矢先に向きを間違えがちです。
その時のショックと言ったら。。。（経験者談）。<br>
<img width="700" alt="RGB_LED" src="https://github.com/3araht/giabalanai/blob/main/pictures/SK6812mini_alignment.jpg">

温調半田ごてを使い、約220℃で半田付けします。温度が高いとLEDが壊れますので注意してください。
温調できない半田ごてではすぐに焦げます＆壊れます（これも経験者談）。

こてを斜めにして接触面積を広げるとやり易いという事がわかりました。<br>
<img width="700" alt="RGB_LED" src="https://github.com/3araht/giabalanai/blob/main/pictures/LED_solder_iron.jpg">

**注意点**<br>
右手側の Pro Micro のすぐ隣の LED を実装する際には、B6 ピンにつかないように十分注意してください。<br>
<img width="700" alt="RGB_LED" src="https://github.com/3araht/giabalanai/blob/main/pictures/warning_right_pcb_r02.jpg">

LEDは、右手側 Pro Micro の1番ピン（Tx）から右手側基板の左上のLEDから直列繋ぎにデータを伝達し、右手側基板上の63個のLEDを通過したデータはTRRSケーブルを通じて左手側基板上面からみて右上のLEDから直列繋ぎにデータを伝達します。

右手側基板および左手側基板の下図の位置を半田でジャンパします。

1、右手側基板の2箇所と、<br>
<img width="700" alt="Jumper" src="https://github.com/3araht/giabalanai/blob/main/pictures/LED_right_jumper_r02.jpg">

2、左手側基板のここ。<br>
<img width="700" alt="Jumper" src="https://github.com/3araht/giabalanai/blob/main/pictures/LED_left_jumper_r02.jpg">

LEDの情報は直列に伝送されますので、接続が途切れてしまうと正しくLEDが光らなくなります。


## 3 ##
## リセットスイッチとTRRSジャックの取付け ##
左右の基板共、白い四角い枠のシルクに沿って裏側に取り付けます。浮いたり曲がった状態で実装しないようにマスキングテープなどで予め仮止めしてから半田付けするとミスが少なくなります。<br>
<img width="700" alt="TRRS_ResetSW" src="https://github.com/3araht/giabalanai/blob/main/pictures/TRRS_ResetSW_r02.jpg">

## 4 ##
## Pro Micro 用ピンヘッダの取付け ##
**※コンスルー（スプリングピンヘッダ）を使う場合はこの工程は不要です。**
白い四角い枠のシルクに沿って裏側にピンヘッダを取り付けます。
**この時点で Pro Micro を取り付けてはいけません。一度半田付けしてしまった Pro Micro を取り外すのは至難の技です。充分ご注意ください。**


## 5 ##
## 基板へのスペーサーのネジ止め ##
スペーサーを左右の基板の裏面にネジで固定します（ネジをオモテ面に挿し、スペーサーが裏面にくるようにします）。<br>
キースイッチを半田付けした後にはネジを挿入することが難しい箇所があるため、キースイッチを半田付けする前に基板にネジを固定します(なむれすさん、組み立て手順についてアドバイスいただきありがとうございます)。<br>
ただし、半田ごてがスペーサーに触れてしまうとスペーサーが溶けてしまうので、半田付けする際には十分ご注意ください。<br>
<img width="700" alt="switch" src="https://github.com/3araht/giabalanai/blob/main/pictures/Spacer_r02.jpg">

## 6 ##
## キースイッチの取付けと、エンコーダ（Option）の取付け ##
**スイッチを取り付ける前に部品の取付けや半田付けができているか確認します。**<br>
（1 のダイオードは必ず済ませておいてください。）<br>

※スプリングピンヘッダを使用する場合は6と8の工程を先に行い、動作確認(下図のようにキースイッチ部をピンセットなどでショートさせ、MIDI機器を認識するソフトで音が出るか確かめる事)をすると失敗する可能性が減ります。<br>
**動作確認する際には、①左右の基板両方にHEXファイル書き込み済の Pro Micro を実装し、②左右の基板を繋ぐTRRSケーブルを奥までしっかり挿して接続してから、③USBケーブルを右手側基板に挿して実施してください。**<br>
<img width="700" alt="switch" src="https://github.com/3araht/giabalanai/blob/main/pictures/Keysw_test.jpg">

キースイッチをオモテ側からしっかり奥まで差し込みます。このとき、端子が曲がっていると実装穴に端子が入らないので注意してください。1行ずつキースイッチをしっかり差し込んでから半田付けしていった方が差し込み不良は減らせると思います。<br>
<img width="700" alt="switch" src="https://github.com/3araht/giabalanai/blob/main/pictures/Keysw_front_r02.jpg"><br>
<img width="700" alt="switch" src="https://github.com/3araht/giabalanai/blob/main/pictures/Keysw_rear_r02.jpg">

**注意点**<br>
右手側の Pro Micro のすぐ隣の キースイッチ を実装する際には、B5 ピンにつかないように十分注意してください。<br>
<img width="700" alt="RGB_LED" src="https://github.com/3araht/giabalanai/blob/main/pictures/warning_right_pcb_r02.jpg">

ロータリーエンコーダーを実装する場合はここで右手側基板に実装します。
<img width="700" alt="RotaryEncorder" src="https://github.com/3araht/giabalanai/blob/main/pictures/rotary_encorder.jpg">


## 7 ##
## Pro Micro の取付け ##
**作業前に Pro Micro をUSBでPCと繋げて動作を確認しておきましょう。**
取り付ける前に半田忘れがないか確認します。
左右の基板とも Pro Micro を表にして取り付けられるようになります。
取り付けたときに Pro Micro の浮きがないか確認し、浮きがあれば Pro Micro 下のスイッチの足を少しカットします。

※コンスルーを使う場合は Pro Micro 側のみを半田付けします。<br>
<img width="700" alt="CT" src="https://github.com/3araht/giabalanai/blob/main/pictures/Con_through.jpg">

コンスルーを斜めに半田付けしないように、基板の**裏面から**コンスルーを差しておいてピンが垂直になるようにします。
下図のように、Pro Micro 側(側面に空いている小さな穴が近い方)を上にして基板にコンスルーを差し込みます。
このとき、図のように、コンスルーの向きを揃えておきます（＝2つとも側面の小さな穴が空いている方向を揃えます）。<br>
<img width="700" alt="CT" src="https://github.com/3araht/giabalanai/blob/main/pictures/Con_through_onPCB_r02.jpg">

*Pro Micro の上下の向きに注意。Pro Micro の TxD ピンが基板の TxD に刺さるように向きが合っているか確認します。<br>
<img width="700" alt="CT" src="https://github.com/3araht/giabalanai/blob/main/pictures/PinAlignment.jpg"><br>

コンスルーを基板の裏面から差し、TxD の位置を見て向きが揃っていることを確認したら、コンスルーと Pro Micro を半田付けします。<br>
**Pro Micro が浮きやすいので、Pro Micro をしっかり押さえながら最初に四隅を半田付けすると作業が楽になります。**<br>
**一度半田付けしたコンスルーを外すのは困難を極めますので、十分注意してください。**

コンスルーを Pro Micro に実装した様子<br>
<img width="700" alt="CT" src="https://github.com/3araht/giabalanai/blob/main/pictures/ProMicro_TxD_r02.jpg"><br>
<img width="700" alt="CT" src="https://github.com/3araht/giabalanai/blob/main/pictures/ProMicro_front_r02.jpg"><br>

## 8 ##
## Firmwareの書き込み ##
左右の基板の Pro Micro に同じHEXファイルを書き込みます。

### 8.1 ###
### コーディングはちょっと自信がない／とりあえず動作させたい、という方 ###
選択肢を2つご用意しておりますが、まずは giabalanai, giabaLEnai, giabaRInai の場合は 8.1.1 の全部入り版を使ってみてください。
giabaRInaix2 の方は 全部入り版は対象外なので、8.1.2 のgiabaRInaix2 専用のファームウェアをお使いください。

#### 8.1.1 ####
#### （giabalanai, giabaLEnai, giabaRInai）とりあえず全部入り版、という方 ####

LEDが光ったり、[下記](https://github.com/3araht/giabalanai/blob/main/docs/build.md#layers)に示す、みなさまのご要望にお答えし増やしたレイヤーなどが盛り込まれた全部入り版のHEXファイル(giabalanai_3araht.hex)などいくつかファームウェアを用意しています。<br>

Remap を使うととても簡単に Promicro にファームウェアを書き込むことが可能です。

Remap Catalog から、 giabalanai キーボードを探します。<br>
<img width="700" alt="RemapKeyboardCatalog" src="https://github.com/3araht/giabalanai/blob/main/pictures/RemapKeyboardCatalog.png"><br>

<img width="700" alt="Remap_giabalanai" src="https://github.com/3araht/giabalanai/blob/main/pictures/Remap_giabalanai.png"><br>

書き込むファームウェアを選択します。<br>
<img width="700" alt="RemapFirmwareSelect" src="https://github.com/3araht/giabalanai/blob/main/pictures/RemapFirmwareSelect.png"><br>

Elite-C をお使いの場合は bootloader として dfu を、それ以外の場合は caterina を選択してファームウェアを書き込みます。書き込み方の詳細は画面に示されている手順に従ってください。<br>
<img width="700" alt="RemapFlash" src="https://github.com/3araht/giabalanai/blob/main/pictures/RemapFlash.png"><br>

他の書き込み方も色々あります。サリチル酸さんの[記事](https://salicylic-acid3.hatenablog.com/entry/qmk-toolbox)がとても参考になります(サリチル酸さん、どうもありがとうございます)。

#### 8.1.2 ####

#### （giabalanai, giabaLEnai, giabaRInai) 全部入り版使った後で、LED光らなくていいし、レイヤーたくさんいらないけど、REMAP でキー配列をちょっと変更したい、という方 か、giabaRInaix2 をお使いの方

MIDIを使ったキーボードなのに、VIA 機能を有効にし、REMAP で動的にキー配列を変更できるようになりました！！！<br>
一部制限（※）はございますが、QWERTY のキーの配列を変えたい場合や、MIDI 機能の別のキー（サスティン、ピッチベンドなど）を割り当てたいけどコーディングは面倒、という方、お待たせしました！<br>
VIA に対応したファームウェア（[giabalanai_via.hex](https://github.com/3araht/giabalanai/blob/main/giabalanai_via_hex.zip) ）を上で示したツールで書き込んでください(このファームウェアは gibaRInaix2 以外に対応。giabaRInaix2版は[こちら](https://github.com/3araht/giabalanai/blob/main/giabalanai_via_giabaRInaix2_hex.zip))。<br>

ここまでで default のキー配列で動作します。もしキー配列を変更したい場合は、
[REMAP](https://remap-keys.app/) でキー配列を自由に変更することが可能です。<br>

[REMAP](https://remap-keys.app/) で MIDI 関連のキーにも対応いただいた、Yoichiro さん、ありがとうございました。<br>

（※）一部制限 1、左手側に配列している、和音はコーディングで実現しているため、REMAPで編集することはできません。左手側のキーに別のキーを割り当てることは可能ですが、新たに任意の和音指定ができない、という意味です。<br>
（※）一部制限 2、VIA は EEPROM を使うため、使えるキーの数＆レイヤーの数に制限があります。そのため、レイヤー数が 3 になっています。<br>


### 8.2 ###
### コーディングに慣れている方、チャレンジされる方

以下を参考に書き込んでください。または、QMKで検索すると書き込み方がすぐに出てくるはずです。<br>
https://docs.qmk.fm/#/getting_started_build_tools

giabalanai の Firmware は以下にあります。<br>
https://github.com/qmk/qmk_firmware/tree/master/keyboards/giabalanai

#### 8.2.1 ####
#### ソースの使い方
1. まず、qmk_firmware を clone してきます。
https://github.com/qmk/qmk_firmware

2. サスティン問題回避<br>
MIDIソフトによっては、同じ音を重ねて鳴らしたときにその音にUSBケーブルを抜き差しするまでサスティンがかかってしまう現象がありました。
~~対策方法がわかりましたので、それを適用します（こちらも pull request 中。正式に採用されるまでの暫定対策）。~~<br>
2020/10/5 pull request が メインブランチにマージされました。最新のソフトを clone いただければOKです。<br>
2021/04/13 残念ながら、2021/3/25 の process_midi.c の更新により、再びこの問題が復活しています。
2023/09/23 以下の Pull Request から下記ファイルを取得し、`process_midi.c` を差し替えてください。

https://github.com/qmk/qmk_firmware/pull/22114
https://github.com/qmk/qmk_firmware/blob/e8906ed2ea0b9f20291b2759d4d65fc6c334ab39/quantum/process_keycode/process_midi.c

```
quantum/process_keycode/process_midi.c
```

3. カスタマイズ！<br>
~~かなり Staggered なので、このキーボードでタイピングすることはあまり考えていないと思いますが、必要に応じてカスタマイズしてお使いください。~~<br>
意外と打てました。左手側のキーボードを5x12の60％キーボードとして使えそうです。<br>
（また、register switch 機能を付与するなどのカスタマイズは面白いかもしれませんね。）


### 8.3 ###
**(これ以降、8章は giabalanai, giabaLEnai, giabaRInai の内容になります。)**
### defaultのHEXファイル (giabalanai_via.hex) について ###

USBケーブルを接続したら、アコーディオンの配列になります。<br>
**このキーボードでは、右手側がマスターとなっていますので、USBケーブルは必ず右手側に接続してください。**

エンコーダを右に回すと音量が大きくなり、左に回すと小さくなるようになっています。
エンコーダは押しボタンにもなっており、押すとミュートON/OFFを切り替えるようになっています。

エンコーダボタン（短押しだとミュート）を長押しながら左手側キーボード 2行1列目のD♭Majorのコードのキーを押すと
左手側キーボード の5行12列がQWERTY配列のキーボード になるようになっています（マイナス記号など一部配置されていないので簡易的なものになります）。
アコーディオンの配列に戻す場合は、エンコーダボタンを長押しながら左手側キーボード 1行1列目のD♭のキーを押します。
なお、電源を再投入（USB抜き差し）したら
~~アコーディオンの配列（C-System）に戻ります。~~ 最後に使っていたアコーディオン配列に戻ります(default のファームウェアを書かれた場合 C-System しかないのでそこに戻ります。)
。

### 8.4 ###
### 上記全部入り版のHEXファイル (giabalanai_3araht.hex) について ###

**全部入り版のHEXファイルは上記に示すdefault 設定に加えて、1. LEDが実装されていれば押したキーのLED が発光、2. QWERTY配列からADJUSTレイヤーへの移動が可能、3. さまざまなレイヤーに対応、 4. オクターブ調整が可能なようになっています。**

右手側下3行だけはB-systemにすることもできます。エンコーダーボタン長押し＋左手側キーボード 1行2列目のA♭のキーを押します（誤白川さん、アイデアありがとうございます）。

また、左手側のベース音を2列にした Counter Bass レイアウトにも変更可能です。エンコーダーボタン長押し＋左手側キーボード 1行3列目のE♭のキーを押します（チャラン・ポ・ランタン 小春さん、ご要望いただきありがとうございます）。

さらに、Daihuku さん経由で Tomotuns さんからのご質問（右手キーボードの長い版のお問い合わせ）に対する提案として、
左右キーボードに単音割り当てのレイヤーも追加しました。<br>

1つの長いキーボードを作ってしまうと、強度の問題や持ち運び性などで弊害が出てくるのですが、レイヤー切り替えならその辺りも解消するのではないか、と考えています。<br>
折りたたみ式（！？）右手キーボードに変身させることが可能ですね。<br>
Daihukuさん & Tomotunsさん、ご要望いただきありがとうございました。<br>

さらにさらに、クロマトーン（Chromatone）配列のレイヤーも追加しました（ヤマケンさん、ご要望いただきありがとうございます）。

オクターブ調整もできるようになりました。

また、ベース音を単音と2和音の切り替えができるようになりました
（9290kenji さん、ご要望いただきありがとうございました）。<br>

さらに、giabaLEnai リリースに伴い、USBケーブルを右側から出したい、というご要望にお答えすべく C-System （右手側）の180°反転版のレイヤーを追加しました
（benjaminbworks さん、ご要望いただきありがとうございました）。<br>
180°しても5列全てC-Systemの配列として使えます。<br>
（想定してました。嘘です。結果オーライ大ショットです。）

MIDI の Ch を分ける機能を追加しました。これにより、メロディーを弾く右手側のボタン、和音、ベース音それぞれに音源ソフト側で違う音色を載せたり、音量を個別に調整できるようになります。（GHEIM さん、ありがとうございました）。

メロディースイッチ機能追加しました（GHEIM さん、ありがとうございました）。

フリーベースレイヤーを追加しました。（しきほう さん、ありがとうございました）。

#### layers ####
|                               操作                    |       変更先レイヤー（配列）  | 記号 |
|------------------------------------------------------|----------------------------|-----|
| エンコーダーボタン長押し＋左手側キーボード 1行1列目のD♭ | アコーディオン配列（C-System）＝初期設定| CSYSTEM |
| エンコーダーボタン長押し＋左手側キーボード 1行2列目のA♭ | アコーディオン配列（B-System、ただし下3行のみ)| BSYSTEM |
| エンコーダーボタン長押し＋左手側キーボード 1行3列目のE♭ | アコーディオン配列（C-System, Counter Bass版 = dim コード無し）| CNTBASC |
| エンコーダーボタン長押し＋左手側キーボード 1行4列目のB♭ | アコーディオン配列（C-System, 左右のキーボード共に単音配列）| CSYSALL |
| エンコーダーボタン長押し＋左手側キーボード 1行5列目のF  | クロマトーン配列(Chromatone, 左右のキーボード共に単音配列）| CHRTONE |
| エンコーダーボタン長押し＋左手側キーボード 1行6列目のC  | アコーディオン配列 (C-System 右手側180°反転版。左手はCounter Bass反転せず）| CFLIP2B |
| エンコーダーボタン長押し＋左手側キーボード 1行7列目のG  | アコーディオン配列 (C-System Free Bass）| CSYSFBS |
| エンコーダーボタン長押し＋左手側キーボード 1行8列目のD  | アコーディオン配列（B-System, Counter Bass版 = dim コード無し）| CNTBASB|
| エンコーダーボタン長押し＋左手側キーボード 1行12列目のF# | LED ON/OFF 切り替え（LED を実装している場合）| RGB_TOG |
| エンコーダーボタン長押し＋左手側キーボード 2行1列目のD♭Major | QWERTY 配列（左手側キーボード）| DF_QWER |
| エンコーダーボタン長押し＋左手側キーボード 2行2列目のA♭Major | Bass 音 単音 or 2和音 切り替え（初期設定： 2和音）| TGLBASS |
| エンコーダーボタン長押し＋左手側キーボード 3行12列目のF#Minor | 全ボタン MIDI Ch1を使うか、Ch1:右手側、Ch2：和音、Ch3：ベースに分けるか | TGLMICH |
|||
|エンコーダーボタン長押し＋右手側キーボード 3行1列目のG# | 2オクターブ低く| MI_OCT_N2 |
|エンコーダーボタン長押し＋右手側キーボード 3行2列目のB | 1オクターブ低く| MI_OCT_N1 |
|エンコーダーボタン長押し＋右手側キーボード 3行3列目のD | 基準の音階| MI_OCT_0 |
|エンコーダーボタン長押し＋右手側キーボード 3行4列目のF | 1オクターブ高く| MI_OCT_1 |
|エンコーダーボタン長押し＋右手側キーボード 3行5列目のG# | 2オクターブ高く| MI_OCT_2 |
|エンコーダーボタン長押し＋右手側キーボード 3行11列目のD | ファームウェアのバージョン表示| VERSION |
|エンコーダーボタン長押し＋右手側キーボード 3行12列目のF | 初期設定に戻す| EEP_RST |
|エンコーダーボタン長押し＋右手側キーボード 4行10列目のA#  | ベロシティを下げる | MI_VELD|
|エンコーダーボタン長押し＋右手側キーボード 4行11列目のC#  | ベロシティを上げる | MI_VELU|
|エンコーダーボタン長押し＋右手側キーボード 5行9列目のA    | 下に示すボタンでユニゾンを有効にしたときのオクターブ音のベロシティを（基準音のベロシティ - 30）にする（デフォルト）か、基準音のベロシティと同じにするか切り替え | TGLUVEL|
|エンコーダーボタン長押し＋右手側キーボード 5行10列目のC  | 右手側 2 dyad (root_note + 1octave 低い音) | MELDYAL|
|エンコーダーボタン長押し＋右手側キーボード 5行11列目のD# | 右手側 単音   （root_note）| MELODYS |
|エンコーダーボタン長押し＋右手側キーボード 5行12列目のF# | 右手側 2 dyad (root_note + 1octave 高い音) | MELDYAH |
| USB ケーブル抜き差し | 前回最後に使っていたアコーディオン配列 & Bass 音設定（単音 or 2和音） に戻ります。オクターブは基準音階に戻ります。|  |


さらに、左手側に配置されていた設定キーを一部右手側にも追加しました。
下の「エンコーダボタン長押ししたときの様子 Function(FN) Layer」をご覧ください。<br>

音符のレイアウト一覧<br>
<img width="700" alt="Layer" src="https://github.com/3araht/giabalanai/blob/main/pictures/20230314_giabalanai_notes_layout_3araht.png"><br>

エンコーダボタン長押ししたときの様子 Function(FN) Layer<br>
<img width="700" alt="Layer" src="https://github.com/3araht/giabalanai/blob/main/pictures/20230526_giabalanai_FN_layer.png"><br>

QWERTY 配列<br>
<img width="700" alt="Layer" src="https://github.com/3araht/giabalanai/blob/main/pictures/20200927_giabalanai_QWERTY_layout_comment.png"><br>

ADJUST レイヤー<br>
<img width="700" alt="Layer" src="https://github.com/3araht/giabalanai/blob/main/pictures/20200927_giabalanai_Adjust_layer.png"><br>

### 8.5 ###
### (新登場)コンパイル済のHEXファイル(giabalanai_2firmware.hex) について ###
この[HEXファイル](https://github.com/3araht/giabalanai/blob/main/giabalanai_2firmware_hex.zip)を使うには、左右のキーボードに別々のコマンドでファームウェアを書き込む必要があります。<br>
>左手用：<br>
```
make giabalanai:2firmware:avrdude-split-left<br>
```

>右手用：<br>
```
make giabalanai:2firmware:avrdude-split-right<br>
```

(2021/04/03 追記。Pro Micro Web Updater でも左右のSplit keyboard の指定が可能で、書き込みが可能です。せきごんさんに感謝。)
Pro Micro Web Updater<br>
https://sekigon-gonnoc.github.io/promicro-web-updater/index.html

では、何のメリットがあるかと申しますと、USBケーブルを左側のキーボードに接続したときは
QWERTY配列がデフォルトとなるようにしました（Haruさん、ご要望いただきありがとうございます）。
つまり、いつも通り右手側のUSBに接続すればアコーディオン配列がデフォルト、左手側のUSBに接続すればタイピング用のQWERTY配列がデフォルト、という使い方ができるようになりました。
なお、デフォルトがQWERTY、というだけて、その後レイヤーを切り替えればアコーディオン配列としても使えます。
上記のようにファームウェアを左右の基板に書き込む方法がちょっと違うのですが、そこさえ許せれば使い勝手が少しUPするようになりました（書き込むHEX自体は1つ。コマンドがEEPROMに書き込むデータを切り替えているようです）。

上記以外の機能は giabalanai_3araht.hex と同じです。<br>
ただし、USBを左手側に接続した場合は、LEDが光りません（右手側基板から左手側基板にLEDのデータ転送をしていたため）。<br>
ここは、若干ハードウェアでのジャンパー変更およびソフトの変更により、左右どちらにUSBを刺してもLEDが光るようにはできるだろう、とは思います（まだ未対応）。<br>


## 9 ##
## チェックポイント ##
簡単なチェック項目を挙げます。参考になれば幸いです。

【全体】
- Pro Micro は左右の基板共にしっかり基板に刺さっている。
- Pro Micro のピンと基板のピンは一致させた状態で接続できている（Pro Micro の上下の向き確認）。
- USB ケーブルは通信可能なものを使っている（充電器の付属品などは要注意）。
- Pro Micro にファームウェアを書き込んである（左右同じHEXファイルを書き込みます）。
- TRRS ケーブルはしっかり奥まで刺さっている（少しきついのでこれが問題となりがちです。ご注意ください。）
  また、TRRSケーブル内に 5V と GND 線が走っており、電源投入中に抜き差しするとショートする恐れがあるので、活線挿抜はお控えください。
- MIDI機器に対応したソフトを起動している。
- USBケーブルは右手側のキーボードに接続されている（giabalanai_2firmware.hexを使われた場合はどちらに接続してもOK）。
- 半田付けに問題はないか（ダイオードの向き、赤目、富士山、など）。

【Backlight RGB LED編】<br>
動作チェック用にUSB繋いだら全てのLEDが点灯するファームウェアを作成しました。デバッグの手助けになれば幸いです。<br>
[giabalanai_party.hex](https://github.com/3araht/giabalanai/blob/main/giabalanai_party_hex.zip) って名前は派手ですが、最初本当に派手すぎて消費電流が大きすぎてしまうことが懸念されたので、発光量はかなり絞ってます。<br>

LED の光らせ方を変更するボタンはこちら。押すたびに変わります。<br>
<img width="700" alt="Layer" src="https://github.com/3araht/giabalanai/blob/main/pictures/partymode_RGB_MOD.png"><br>

以下、チェック項目です。
- テスター（マルチメータ）をお持ちの場合は、基板からProMicro、ケーブル類を全て外した状態で、＋端子を5Vに、−端子をGND に当てて 抵抗測定してみてください。
  ~~もしも 1 MΩ以上の高抵抗値であれば正常。数十 kΩ程度かそれ以下の場合はLEDが一部破損 or LEDの向きが間違っている可能性があります。~~<br>
  嘘つきました。LED の 5V - GND 端子間の抵抗値が 100 kΩ 程度しか無いので、数十個の LED を並列繋ぎにしているため、抵抗値は 1 kΩ 程度しかありませんでした。<br>
  ⇨ テスターで 5V - GND 間の抵抗を測定しても、あまり参考にはならないです。
- LEDの向きが正しいか(一番大きいパッド（5V）とシルク（印字の事）の○が同じ位置か確認)。
- 4つの端子が基板にしっかり半田付けできているか。数が多いので、数個半田が甘かった、ということはよくあります。
- TRRSケーブルをしっかり差し込んでいるか（差し込みが中途半端だと、TRRSコネクタ部で5VとGNDがショートする可能性があります）。
- あるところから先の LED が全く光らない場合は、その境界のLEDの信号線で半田不良 or LED 破損の可能性があります。
  LED の並びについては、上記 2 Backlight RGB LEDの取付け[Optional] をご覧ください。
- あるところから先の LED の光り方が変な場合は、その境界の LED の電源線（5V か GND）の半田不良 or LED 破損の可能性があります。
- LED は光るものの、他のLEDに比べて暗い場合は、その LED が半田ごてに熱でやられている可能性があります。

また、遊舎工房さんの[サポートサイト](https://yushakobo.zendesk.com/hc/ja)が参考になると思います。併せてご覧ください。

## 10 ##
## ボトムプレートの組み立て ##
全てのキースイッチが正しく動作するのを確認したら、左右の基板に取り付けたスペーサーにボトムプレートを固定します。
ボトムプレートの図の赤丸の位置 10 箇所に M2 のねじでを挿入して固定します。<br>
<img width="700" alt="spacer" src="https://github.com/3araht/giabalanai/blob/main/pictures/BottomPlate_r02.jpg"><br>

ネジ止めは、たすき掛けで均一に締めつけますが、強く締めつけすぎないようにします。

緑丸の位置にクッションシールを取り付けます。<br>
<img width="700" alt="feet" src="https://github.com/3araht/giabalanai/blob/main/pictures/Cushon_r02.jpg">

#### お疲れ様でした。以上で giabalanai キーボードの完成です！


## 11 ##
## その他、変更点 ##
- 2021/04/13 Velocity の初期値を、QMK の初期値である 127 から 117 （MI_VELD 1回分下げた値）に変更。これは、GHEIM さんから、一部の音源では 127 という値に特別な意味を持たせている場合がある、とのご意見をいただいて少し低めの値にしています（GHEIMさんご意見いただきありがとうございます）。
- 2021/04/18 LEDの光量が強めなので少し抑えました。
- 2021/04/18 現在のレイヤーに応じて、LEDの色を変えてみました（HARUさん、御要望いただきありがとうございます。）。色は好みが大きく出るところなので、難しいですね。ダサい、たえらえん！という方はぜひソースをちょいと修正して使ってください。


---
##### 12 #####
##### (アーカイブ) 過去のご案内 #####
- 2020/09/08 r01 ビルドガイド ([こちら](https://github.com/3araht/giabalanai/blob/main/docs/build_r01.md))
- 2020/09/20 サスティン問題回避方法 ([こちら](https://github.com/3araht/giabalanai/blob/main/docs/old/20200920.md))
- 2020/09/23 ダイオード員数不足のお詫びと確認のお願い ([こちら](https://github.com/3araht/giabalanai/blob/main/docs/old/20200923.md))


---
