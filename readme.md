<p align=center>
<img width="700" alt="giabalanai_logo" src="https://github.com/3araht/giabalanai/blob/master/pictures/giabalanai_logo.png">
</p>

![giabalanai overview](https://github.com/3araht/giabalanai/blob/master/pictures/giabalanai_overview.jpg)

giabalanai keyboard is a simple-design Chromatic Button Accordion-ish MIDI keyboard (60 bass + C-system 62 keys = 38 notes) which doesn't have bellows nor register switches.
A rotary encoder can be used for adjusting system volume of your computer (PC / Mac).

# How it looks & how it works
Check these short videos ([video1](https://github.com/3araht/giabalanai/blob/master/videos/giabalanai_keyboard.mp4), [video2](https://github.com/3araht/giabalanai/blob/master/videos/62buttons_38notes.mp4)) to see what it's like.

Here's another [video](https://github.com/3araht/giabalanai/blob/master/videos/giabala_dangi_ep.16_theme_song_feat.Mr.Seto.mp4), trying to play (pardon my poor playing skills) a theme song of Giabala-Dangi (https://www.youtube.com/watch?v=WSVRJk6kDiM).

# Keyboard kit
The keyboard kit is available [here](https://yushakobo.jp/shop/consign_giabalanai/).

# Firmware

The giabalanai uses QMK for its firmware, and the codes for it will be available here as the push request is accepted:
[QMK - giabalanai directory](https://github.com/qmk/qmk_firmware/tree/master/keyboards/giabalanai)

Temporarily, please download codes from [here](https://github.com/3araht/giabalanai/blob/master/temp/qmk_firmware/keyboards/giabalanai) as a "beta" version.

Or, use this pre-compiled [hex file](https://github.com/3araht/giabalanai/blob/master/giabalanai_3araht.hex) for your convenience (RGB_LIGHTING enabled).

# Known issue and workaround

When multiple chords are played and when the chords share the same note(s), it activates a sustain effect that stays until you unplug the keyboard.
When you are using GarageBand, the symptom can be fixed by clicking "Revert" button on the bottom left corner on the GarageBand window.

The symptom is seen with Logic Pro, Piano 10 (Windows), as well.
However, this won't occur with Ableton Live 10.
Ableton Live 10 has a different symtpom that the duplicate notes turn off at the earliest release of the button.
Here's an example from github, reported from jakobkg. Thank you, jakobkg!!!


>I press MI_CH_C so the notes C, E and G play. I keep that held and press MI_CH_CDom7. MI_CH_CDom7 plays the notes C, E and Bb so the C and E are re-triggered and a Bb is played, while the G keeps ringing.
>I then release MI_CH_C, and the notes C, E and G are all stopped. This means that the only note still playing is Bb even though I'm still holding MI_CH_CDom7.

(2020/9/18) Luckily, I just found a solution.  
I call this "workaround" since this modification is not officially approved yet.

See below diff log for the modification to the qmk_firmware/quantum/process_midi.c.

```
diff --git a/quantum/process_keycode/process_midi.c b/quantum/process_keycode/process_midi.c
index b2fb902eb..e52577014 100644
--- a/quantum/process_keycode/process_midi.c
+++ b/quantum/process_keycode/process_midi.c
@@ -68,10 +68,12 @@ bool process_midi(uint16_t keycode, keyrecord_t *record) {
             uint8_t tone     = keycode - MIDI_TONE_MIN;
             uint8_t velocity = compute_velocity(midi_config.velocity);
             if (record->event.pressed) {
-                uint8_t note = midi_compute_note(keycode);
-                midi_send_noteon(&midi_device, channel, note, velocity);
-                dprintf("midi noteon channel:%d note:%d velocity:%d\n", channel, note, velocity);
-                tone_status[tone] = note;
+                if (tone_status[tone] == MIDI_INVALID_NOTE) {
+                    uint8_t note = midi_compute_note(keycode);
+                    midi_send_noteon(&midi_device, channel, note, velocity);
+                    dprintf("midi noteon channel:%d note:%d velocity:%d\n", channel, note, velocity);
+                    tone_status[tone] = note;
+                }
             } else {
                 uint8_t note = tone_status[tone];
                 if (note != MIDI_INVALID_NOTE) {
```

The uploaded hex file has this patch applied.



# Build Guide

[Japanese Build Guide](https://github.com/3araht/giabalanai/blob/master/docs/build.md)

# Contact
If you need any help, you know where to find me.  
http://twitter.com/3araht
