# Jazz 

Jazz is a program that intercepts your keybaord inputs before they reach any other program and turns certain combinations of keys into other keys. In this way you can input any symbol you need with minimal relearning and without moving your hands very far. It's kind of like Vim but much simpler, and works on top of every application on your computer.

I haven't actually made it yet though. This `README` is just a wishlist at the moment.

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
|`Ctrl+t`|Open a new tab|
|`Ctrl+w`|Close the current tab|
|`Alt+d`|Select all the text in the address bar|
|`Alt+Left`|Go back|

If you are not using these then you are suffering needlesly. (In the browser, `Ctrl+Shift+t` and `Ctrl+n` are also useful, but I'd forgive you for not knowing them.)

# How to Use Jazz

While jazz is running, the `j`, `x`, `z`, and `q` keys are repurposed to be combined with other keys to enter symbols that are harder to reach on the keyboard. These four keys are called the root keys. You can either press a root key once just to modify the next keypress, or you can hold a root key to modify several key presses. Here are the key pages for the four root keys, with the roots shown in red. You are intended to be able to enter any key combination you need without almost ever having to leave the keys shown in green:

![The key maps for the four root keys](layouts/pages.png)

As you can see, every key on the keyboard is brought close to your fingers on a standard American QWERTY keyboard using this scheme. `j`, `x`, `z`, and `q` can be found in the `j` page for when you need to type them normally. `y`, `b`, and `p` are also included because they are hard to reach normally, and `i` because it is hard to type `ik` or `ki`. When you enter `Ctrl` or `Alt` from the `x` page or `Shift` from the `j` page it behaves like a root key, so it will modify the next character entered, or can be held to modify multiple keys.

# Repository Structure

## layouts
This folder contains keyboard layouts in a `json` format meant to be used with `keyboard-layout-editor.com`. Copy and paste the layouts into their editor to view or edit them.

<!-- # Extensions and Internationalization
At the moment Jazz only works on Linux. I suspect that the best way to port it to Windows will be to rewrite it in AutoHotkey? I don't know what complications would arise in a port to Mac.

If anyone happens to like Jazz enough that they want to make a modified version either with their own extensions or with international characters, I think it would be best if we find a way to include it in this same repository and you make a pull request. That way we can keep all variations in the same place. -->
