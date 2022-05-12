# Jazz
<!-- 
  ,e,                       
   "   ,"Y88b 8P d8P 8P d8P 
  888 "8" 888 P d8P  P d8P  
  888 ,ee 888  d8P d  d8P d 
  888 "88 888 d8P d8 d8P d8 
  88P                       
  8"                         -->
<!-- Have you ever thought about how hilarious it is that `j` is right under your index finger on a QWERTY keyboard? I mean, what a joke. People try to remedy this by using alternative keyboard layouts. These help, but they take a long time to learn, and they still don't help you reach the numbers, punctuation keys, etc. In fact, I think that for a programer who needs easy access to all the letters and symbols on the keyboard, no homerow typing method will work because there just aren't enough keys within easy reach of your fingers. For a while I used an alternative method where I rested my fingers on `aser nio'` on a QWERTY keyboard, so that my fingers were on the most commonly used letters. This made several symbols easier to reach, and required minimal relearning because the layout was still the same. But I would still make mistakes all the time when pressing keys like `- = [ ] \`. So I created this program Jazz, which lets you chord the `j x z q` keys with other keys to access every key on the keyboard with hardly any hand movement. It's kind of like Vim but much simpler, and works on top of every application on your computer. Currently only works on linux. -->

Jazz is a program that repurposes the `j`, `z`, `x`, and `q` keys, letting you chord them together with other keys so that you have the whole keyboard at your disposal without moving your hands. Many numbers, symbols, and even some letters like `y` require you to move your hand, leading you to hit the wrong key unless you look down at your keyboard. With Jazz, these keys are moved to a two key sequence, like `z k` for `y` or `x i` for `backspace`.

Many people who are not satisfied with the QWERTY keyboard use alternative keyboard layouts like Dvorak, Colemak, or Workman. There are two reasons why this solution does not work for me, which lead me to create Jazz instead: the first is the learning curve. It takes a long time to get comfortable typing with a new layout. With Jazz, most of the letters are typed the same way as with QWERTY, making it much faster to learn. If you don't mind a learning curve, you could also combine Jazz with a different custom layout. The second reason is that even with an optimized layout, the numbers and symbols are still hard to reach without looking, which doesn't work for me as a programmer. I think that no home-row typing method will work for me, because there just aren't enough keys close to your fingers.

# Some Useful Hotkeys

Here are some hotkeys that everyone should know, whether or not you use Jazz. These work in most programs, i.e. most web browsers, text editors, terminals, etc.:

|||
|---|---|
|`Ctrl+Left`, `Ctrl+Right`|Move the cursor a full word left / right|
|`Ctrl+Backspace`, `Ctrl+Delete`|Delete a full word behind / in front of the cursor|
|`Home`, `End`|Jump to the start / end of the line|
|`Ctrl+Home`, `Ctrl+End`|Jump to the start / end of the document / text box|

These can also be combined with `Shift` to select text. The following are browser specific and are supported by most (all?) major browsers:

|||
|---|---|
|`Ctrl+T`|Open a new tab|
|`Ctrl+W`|Close the current tab|
|`Alt+D`|Select all the text in the address bar|
|`Alt+Left`|Go back|

If you are not using these then you are suffering needlesly. (In the browser, `Ctrl+Shift+T`, `Ctrl+R`, and `Ctrl+N` are also useful, but I'd forgive you for not knowing them.)

# Usage

`j`, `x`, `z`, and `q` are called the root keys, and all new key sequences added by Jazz start with one of these four keys. You can either press a root key once just to modify the next keypress, or you can hold a root key to modify several key presses. `Ctrl`, `Shift`, and `Alt` are also modified to work that way. Here are the four pages of chords starting with each root, with the roots shown in red. The green keys show roughly the area of the keyboard that is in use with Jazz:

![The key maps for the four root keys](layouts/pages.png)

As you can see, every key on the keyboard is brought close to your fingers on a standard American QWERTY keyboard using this scheme. `x`, `z`, and `q` can be found in the `j` page for when you need to type them normally, and `j` in the `z` page. `y`, `b`, and `p` are also included because they are hard to reach normally, and `i` because the `ik` and `ki` digraphs are particularly difficult on a QWERTY keyboard. The positions of `y`, `b`, and `p` are based on some analysis of digraph frequency that I did. This layout is unfinished and I will likely continue to change it for a while, and of course you can create your own layout to use with Jazz by editing `realbook.h`.

# Installation

To install Jazz:
1) Install [Interception Tools](https://gitlab.com/interception/linux/tools#installation)
2) Clone this repository
3) `sudo make install`. This will start Jazz, and make it start automatically when you turn on your computer. This will only change one file outside of the repository, which can easily be removed with `sudo make uninstall`, which will also stop Jazz. Interception tools has it's own Systemd service, and Jazz just adds itself as a plugin.

You can stop Jazz at any time by typing `bye` using the actual `b` and `y` keys, or with `sudo systemctl stop udevmon.service`. You can then start it again with `sudo systemctl restart udevmon.service`, which you can bind to a hotkey of your choice.

# Related work

[interception-k2k](https://github.com/zsugabubus/interception-k2k) is another interception tools plugin which is very similar to Jazz. [interception-vimproved](https://gitlab.com/interception/linux/tools#some-community-plugins) is also similar. Also check out the other [Interception Tools plugins](https://gitlab.com/interception/linux/tools#official-plugins).

# Repository Structure

The layouts folder contains keyboard layouts in a `json` format meant to be used with `keyboard-layout-editor.com`. Copy and paste the layouts into their editor to view or edit them. `evshow` is a simple test program that reads `input_event` structs on `stdin` and formats their contents to `stdout`. The Julia folder contains the code I used to analyze the digraph frequency data, which was taken from ["Case-sensitive letter and bigram frequency counts from large-scale English corpora"](https://doi.org/10.3758%2Fbf03195586)

<!-- # Extensions and Internationalization
At the moment Jazz only works on Linux. I suspect that the best way to port it to Windows will be to rewrite it in AutoHotkey? I don't know what complications would arise in a port to Mac.

If anyone happens to like Jazz enough that they want to make a modified version either with their own extensions or with international characters, I think it would be best if we find a way to include it in this same repository and you make a pull request. That way we can keep all variations in the same place. -->
